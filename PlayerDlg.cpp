// PlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BattleWack.h"
#include "PlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg dialog


CPlayerDlg::CPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayerDlg)
	m_PlayerName = _T("");
	//}}AFX_DATA_INIT
}


void CPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayerDlg)
	DDX_Text(pDX, IDC_EDIT_PLAYER, m_PlayerName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg message handlers
