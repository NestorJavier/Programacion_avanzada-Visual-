; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CControles_ComunesView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Controles_Comunes.h"
LastPage=0

ClassCount=8
Class1=CControles_ComunesApp
Class2=CControles_ComunesDoc
Class3=CControles_ComunesView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDR_MENU1
Resource4=IDD_ABOUTBOX (Spanish (Modern))
Class6=CProgress
Resource5=IDD_SPIN
Class7=CSlider
Resource6=IDD_SLIDER
Class8=CSpin
Resource7=IDD_PROGRESS
Resource8=IDR_TOOLBAR1
Resource9=IDR_MAINFRAME (Spanish (Modern))

[CLS:CControles_ComunesApp]
Type=0
HeaderFile=Controles_Comunes.h
ImplementationFile=Controles_Comunes.cpp
Filter=N

[CLS:CControles_ComunesDoc]
Type=0
HeaderFile=Controles_ComunesDoc.h
ImplementationFile=Controles_ComunesDoc.cpp
Filter=N

[CLS:CControles_ComunesView]
Type=0
HeaderFile=Controles_ComunesView.h
ImplementationFile=Controles_ComunesView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_PROGRESS


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Controles_Comunes.cpp
ImplementationFile=Controles_Comunes.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROGRESS]
Type=1
Class=CProgress
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PROGRESS1,msctls_progress32,1350565893
Control4=IDC_PROGRESS2,msctls_progress32,1342177285
Control5=IDC_PROGRESS3,msctls_progress32,1342177285
Control6=IDC_ACCION,button,1342242816

[CLS:CProgress]
Type=0
HeaderFile=Progress.h
ImplementationFile=Progress.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ACCION
VirtualFilter=dWC

[DLG:IDD_SLIDER]
Type=1
Class=CSlider
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SLIDER1,msctls_trackbar32,1342242840
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SLIDER2,msctls_trackbar32,1342242840
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ACCION,button,1342242816
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552

[CLS:CSlider]
Type=0
HeaderFile=Slider.h
ImplementationFile=Slider.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSlider

[CLS:CSpin]
Type=0
HeaderFile=Spin.h
ImplementationFile=Spin.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDM_PROGRESS

[DLG:IDD_SPIN]
Type=1
Class=CSpin
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SPIN1,msctls_updown32,1342177328
Control4=IDC_EDIT1,edit,1350631552

[MNU:IDR_MENU1]
Type=1
Class=CControles_ComunesView
Command1=IDM_PROGRESS
Command2=IDM_SLIDER
Command3=IDM_SPIN
CommandCount=3

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_PROGRESS
Command2=IDM_SLIDER
Command3=IDM_SPIN
CommandCount=3

