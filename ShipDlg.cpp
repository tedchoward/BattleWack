// ShipDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BattleWack.h"
#include "ShipDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShipDlg dialog


CShipDlg::CShipDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShipDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShipDlg)
	m_B_Row = 4;
	m_B_ShipName = _T("T's Ship");
	m_B_Column = 2;
	m_C_Column = 9;
	m_C_Row = 5;
	m_C_ShipName = _T("Murdock's Ship");
	m_D_Column = 0;
	m_D_Row = 8;
	m_D_ShipName = _T("Hannibal's Ship");
	m_S_Column = 5;
	m_S_Row = 1;
	m_S_ShipName = _T("Face's Ship");
	m_B_Orientation = 1;
	m_C_Orientation = 0;
	m_D_Orientation = 1;
	m_S_Orientation = 0;
	//}}AFX_DATA_INIT
}


void CShipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShipDlg)
	DDX_Text(pDX, IDC_EDIT_B_ROW, m_B_Row);
	DDV_MinMaxInt(pDX, m_B_Row, 0, 9);
	DDX_Text(pDX, IDC_EDIT_B_SN, m_B_ShipName);
	DDV_MaxChars(pDX, m_B_ShipName, 32);
	DDX_Text(pDX, IDC_EDIT_B_COL, m_B_Column);
	DDV_MinMaxInt(pDX, m_B_Column, 0, 9);
	DDX_Text(pDX, IDC_EDIT_C_COL, m_C_Column);
	DDV_MinMaxInt(pDX, m_C_Column, 0, 9);
	DDX_Text(pDX, IDC_EDIT_C_ROW, m_C_Row);
	DDV_MinMaxInt(pDX, m_C_Row, 0, 9);
	DDX_Text(pDX, IDC_EDIT_C_SN, m_C_ShipName);
	DDV_MaxChars(pDX, m_C_ShipName, 32);
	DDX_Text(pDX, IDC_EDIT_D_COL, m_D_Column);
	DDV_MinMaxInt(pDX, m_D_Column, 0, 9);
	DDX_Text(pDX, IDC_EDIT_D_ROW, m_D_Row);
	DDV_MinMaxInt(pDX, m_D_Row, 0, 9);
	DDX_Text(pDX, IDC_EDIT_D_SN, m_D_ShipName);
	DDV_MaxChars(pDX, m_D_ShipName, 32);
	DDX_Text(pDX, IDC_EDIT_S_COL, m_S_Column);
	DDV_MinMaxInt(pDX, m_S_Column, 0, 9);
	DDX_Text(pDX, IDC_EDIT_S_ROW, m_S_Row);
	DDV_MinMaxInt(pDX, m_S_Row, 0, 9);
	DDX_Text(pDX, IDC_EDIT_S_SN, m_S_ShipName);
	DDV_MaxChars(pDX, m_S_ShipName, 32);
	DDX_Radio(pDX, IDC_RADIO_B_V, m_B_Orientation);
	DDX_Radio(pDX, IDC_RADIO_C_V, m_C_Orientation);
	DDX_Radio(pDX, IDC_RADIO_D_V, m_D_Orientation);
	DDX_Radio(pDX, IDC_RADIO_S_V, m_S_Orientation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShipDlg, CDialog)
	//{{AFX_MSG_MAP(CShipDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShipDlg message handlers
