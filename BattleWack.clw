; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInitialDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BattleWack.h"
LastPage=0

ClassCount=10
Class1=CBattleWackApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=7
Resource1=IDD_PLACESHIPS
Resource2=IDR_MAINFRAME
Class2=CChildView
Class5=CSplashWnd
Class6=CPlayerDlg
Resource3=IDD_COMPNAME
Class7=CCompDlg
Resource4=IDD_ABOUTBOX
Class8=CShipDlg
Resource5=IDD_PLAYERNAME
Class9=CNetworkDlg
Resource6=IDD_NETWORK
Class10=CInitialDlg
Resource7=IDD_INITIALS

[CLS:CBattleWackApp]
Type=0
HeaderFile=BattleWack.h
ImplementationFile=BattleWack.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N
LastObject=CChildView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=BattleWack.cpp
ImplementationFile=BattleWack.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEWGAME
Command2=ID_APP_EXIT
Command3=ID_VIEW_TOOLBAR
Command4=ID_VIEW_STATUS_BAR
Command5=ID_HIGHSCORES
Command6=ID_HELPME
Command7=ID_HELP_ASKT
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEWGAME
Command2=ID_HELP_ASKT
Command3=ID_APP_ABOUT
CommandCount=3

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

[DLG:IDD_PLAYERNAME]
Type=1
Class=CPlayerDlg
ControlCount=4
Control1=IDC_EDIT_PLAYER,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342177280

[CLS:CPlayerDlg]
Type=0
HeaderFile=PlayerDlg.h
ImplementationFile=PlayerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPlayerDlg

[DLG:IDD_COMPNAME]
Type=1
Class=CCompDlg
ControlCount=4
Control1=IDC_EDIT_COMPNAME,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352

[CLS:CCompDlg]
Type=0
HeaderFile=CompDlg.h
ImplementationFile=CompDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCompDlg

[DLG:IDD_PLACESHIPS]
Type=1
Class=CShipDlg
ControlCount=45
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_C_SN,edit,1350631552
Control3=IDC_EDIT_C_ROW,edit,1350631552
Control4=IDC_EDIT_C_COL,edit,1350631552
Control5=IDC_EDIT_B_SN,edit,1350631552
Control6=IDC_EDIT_B_ROW,edit,1350631552
Control7=IDC_EDIT_B_COL,edit,1350631552
Control8=IDC_EDIT_D_SN,edit,1350631552
Control9=IDC_EDIT_D_ROW,edit,1350631552
Control10=IDC_EDIT_D_COL,edit,1350631552
Control11=IDC_EDIT_S_SN,edit,1350631552
Control12=IDC_EDIT_S_ROW,edit,1350631552
Control13=IDC_EDIT_S_COL,edit,1350631552
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_RADIO_C_V,button,1342308361
Control21=IDC_RADIO_C_H,button,1342177289
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_RADIO_B_V,button,1342308361
Control29=IDC_RADIO_B_H,button,1342177289
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_RADIO_D_V,button,1342308361
Control37=IDC_RADIO_D_H,button,1342177289
Control38=IDC_STATIC,button,1342177287
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_STATIC,static,1342308352
Control44=IDC_RADIO_S_V,button,1342308361
Control45=IDC_RADIO_S_H,button,1342177289

[CLS:CShipDlg]
Type=0
HeaderFile=ShipDlg.h
ImplementationFile=ShipDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CShipDlg
VirtualFilter=dWC

[DLG:IDD_NETWORK]
Type=1
Class=CNetworkDlg
ControlCount=4
Control1=IDC_RADIO_CLIENT,button,1342308361
Control2=IDC_RADIO_SERVER,button,1342177289
Control3=IDOK,button,1342242817
Control4=IDC_STATIC,button,1342177287

[CLS:CNetworkDlg]
Type=0
HeaderFile=NetworkDlg.h
ImplementationFile=NetworkDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_CLIENT

[DLG:IDD_INITIALS]
Type=1
Class=CInitialDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_INITIALS,edit,1350631552

[CLS:CInitialDlg]
Type=0
HeaderFile=InitialDlg.h
ImplementationFile=InitialDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CInitialDlg

