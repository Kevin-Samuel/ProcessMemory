; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProcessMemoryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProcessMemory.h"

ClassCount=3
Class1=CProcessMemoryApp
Class2=CProcessMemoryDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROCESSMEMORY_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_PROCESSMEMORY_DIALOG (English (U.S.))

[CLS:CProcessMemoryApp]
Type=0
HeaderFile=ProcessMemory.h
ImplementationFile=ProcessMemory.cpp
Filter=N

[CLS:CProcessMemoryDlg]
Type=0
HeaderFile=ProcessMemoryDlg.h
ImplementationFile=ProcessMemoryDlg.cpp
Filter=D
LastObject=IDC_LIST
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ProcessMemoryDlg.h
ImplementationFile=ProcessMemoryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_PROCESSMEMORY_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CProcessMemoryDlg

[DLG:IDD_PROCESSMEMORY_DIALOG (English (U.S.))]
Type=1
Class=CProcessMemoryDlg
ControlCount=1
Control1=IDC_LIST,SysListView32,1350631684

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

