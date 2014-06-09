// ProcessMemory.h : main header file for the PROCESSMEMORY application
//

#if !defined(AFX_PROCESSMEMORY_H__0F5BEA56_BF5C_493B_A5E3_24A283CA84A3__INCLUDED_)
#define AFX_PROCESSMEMORY_H__0F5BEA56_BF5C_493B_A5E3_24A283CA84A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcessMemoryApp:
// See ProcessMemory.cpp for the implementation of this class
//

class CProcessMemoryApp : public CWinApp
{
public:
	CProcessMemoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessMemoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcessMemoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSMEMORY_H__0F5BEA56_BF5C_493B_A5E3_24A283CA84A3__INCLUDED_)
