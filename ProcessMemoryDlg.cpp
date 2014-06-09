// ProcessMemoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProcessMemory.h"
#include "ProcessMemoryDlg.h"
#include <windows.h>
#include <PSAPI.H>
#include <PROCESS.H>
#pragma comment(lib,"Psapi.Lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessMemoryDlg dialog

CProcessMemoryDlg::CProcessMemoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessMemoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcessMemoryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcessMemoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcessMemoryDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProcessMemoryDlg, CDialog)
	//{{AFX_MSG_MAP(CProcessMemoryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnReadMemory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessMemoryDlg message handlers

BOOL CProcessMemoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// initialize the list view control
	LONG lStyle; 
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style 
	DWORD dwStyle = m_list.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	m_list.SetExtendedStyle(dwStyle); //设置扩展风格 
	
	// set the column of list view
	m_list.InsertColumn(0, "ID", LVCFMT_LEFT, 40);
	m_list.InsertColumn(1, "Name", LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, "PageFaultCount", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, "PeakWorkingSetSize", LVCFMT_LEFT, 120);
	m_list.InsertColumn(4, "WorkingSetSize", LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, "QuotaPeakPagedPoolUsage", LVCFMT_LEFT, 180);
	m_list.InsertColumn(6, "QuotaPagedPoolUsage", LVCFMT_LEFT, 150);
	m_list.InsertColumn(7, "QuotaPeakNonPagedPoolUsage", LVCFMT_LEFT, 180);
	m_list.InsertColumn(8, "QuotaNonPagedPoolUsage", LVCFMT_LEFT, 150);
	m_list.InsertColumn(9, "PagefileUsage", LVCFMT_LEFT, 100);
	m_list.InsertColumn(10,"PeakPagefileUsage", LVCFMT_LEFT, 120);

	//GetData()
	GetData();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProcessMemoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProcessMemoryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProcessMemoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HANDLE CProcessMemoryDlg::GetProcessHandle(int nID)
{
	return ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, nID);
}

BOOL CProcessMemoryDlg::GetEnumProcesses()
{
	BOOL flag = EnumProcesses(Processes, sizeof(Processes), &cbNeeded);
	cProcesses = cbNeeded / sizeof(DWORD);
	return flag;
}

void CProcessMemoryDlg::GetData()
{
	if (!GetEnumProcesses())
	{
		MessageBox("Fail to Enum the Processes!");
	}
	for (unsigned int i = 0; i< cProcesses; ++i) 
	{
		//ProcessInfo oneProcess;
		const DWORD& processID = Processes[i]; //进程ID

		CString txt;
		txt.Format("%d", processID);
		int row = m_list.GetItemCount();
		m_list.InsertItem(row, txt);
		

		
		//通过进程ID获得进程句柄
		HANDLE hProcess = GetProcessHandle(processID);
		if (NULL != hProcess )  
		{  
			HMODULE hMod;  
			DWORD cbNeeded;  
			
			//目前该函数只能对32位进程进行处理
			if(::EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded) )
			{  
				//获得进程名
				TCHAR processName[MAX_PATH];
				::GetModuleBaseName(hProcess, hMod, processName, sizeof(processName)/sizeof(TCHAR) );
				txt.Format("%s",processName);
				m_list.SetItemText(row, 1, txt);

			}  
			PROCESS_MEMORY_COUNTERS processMemCounters;
			//读取进程的内存信息
			if (::GetProcessMemoryInfo(hProcess, &processMemCounters, sizeof(processMemCounters))){
				txt.Format("%d", processMemCounters.PageFaultCount);
				m_list.SetItemText(row, 2, txt);
				
				txt.Format("%d", processMemCounters.PeakWorkingSetSize);
				m_list.SetItemText(row, 3, txt);

				txt.Format("%d", processMemCounters.WorkingSetSize);
				m_list.SetItemText(row, 4, txt);

				txt.Format("%d", processMemCounters.QuotaPeakPagedPoolUsage);
				m_list.SetItemText(row, 5, txt);

				txt.Format("%d", processMemCounters.QuotaPagedPoolUsage);
				m_list.SetItemText(row, 6, txt);

				txt.Format("%d", processMemCounters.QuotaPeakNonPagedPoolUsage);
				m_list.SetItemText(row, 7, txt);

				txt.Format("%d", processMemCounters.QuotaNonPagedPoolUsage);
				m_list.SetItemText(row, 8, txt);

				txt.Format("%d", processMemCounters.PagefileUsage);
				m_list.SetItemText(row, 9, txt);

				txt.Format("%d", processMemCounters.PeakPagefileUsage);
				m_list.SetItemText(row, 10, txt);

			}
			CloseHandle(hProcess);  
		}  
	}
}

void CProcessMemoryDlg::OnReadMemory(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NMLISTVIEW* pNMListView = (NMLISTVIEW*)pNMHDR;
	int row = pNMListView->iItem;
	int column = pNMListView->iSubItem;
	CString IDstr = m_list.GetItemText(row, column);
	int nID = _ttoi(IDstr);
	HANDLE hProcess = GetProcessHandle(nID);
	int tmp;
	DWORD dwNumberOfBytesRead;
	if (ReadProcessMemory(hProcess, (LPCVOID)0x100, &tmp, 16, &dwNumberOfBytesRead)){
		CString txt;
		txt.Format("%d", tmp);
		MessageBox(txt);
	}
	else{
		MessageBox("Fail to Read data from Memory! The memory maybe unavailable!");
	}
	*pResult = 0;
}
