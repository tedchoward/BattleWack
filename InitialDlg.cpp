// InitialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BattleWack.h"
#include "InitialDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInitialDlg dialog


CInitialDlg::CInitialDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInitialDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInitialDlg)
	m_Initials = _T("");
	//}}AFX_DATA_INIT
}


void CInitialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInitialDlg)
	DDX_Text(pDX, IDC_EDIT_INITIALS, m_Initials);
	DDV_MaxChars(pDX, m_Initials, 3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInitialDlg, CDialog)
	//{{AFX_MSG_MAP(CInitialDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInitialDlg message handlers
