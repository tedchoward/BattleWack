// CompDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BattleWack.h"
#include "CompDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCompDlg dialog


CCompDlg::CCompDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCompDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCompDlg)
	m_ComputerName = _T("");
	//}}AFX_DATA_INIT
}


void CCompDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCompDlg)
	DDX_Text(pDX, IDC_EDIT_COMPNAME, m_ComputerName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCompDlg, CDialog)
	//{{AFX_MSG_MAP(CCompDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCompDlg message handlers
