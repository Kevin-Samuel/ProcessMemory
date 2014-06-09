// ProcessMemoryDlg.h : header file
//

#if !defined(AFX_PROCESSMEMORYDLG_H__53265F3B_61E3_44BF_A2DC_316F8F6FB77A__INCLUDED_)
#define AFX_PROCESSMEMORYDLG_H__53265F3B_61E3_44BF_A2DC_316F8F6FB77A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProcessMemoryDlg dialog

class CProcessMemoryDlg : public CDialog
{
// Construction
public:
	void GetData();
	BOOL GetEnumProcesses();
	HANDLE GetProcessHandle(int nID);
	DWORD Processes[1024 * 2];
	DWORD cbNeeded;
	DWORD cProcesses;
	CProcessMemoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessMemoryDlg)
	enum { IDD = IDD_PROCESSMEMORY_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessMemoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProcessMemoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSMEMORYDLG_H__53265F3B_61E3_44BF_A2DC_316F8F6FB77A__INCLUDED_)
