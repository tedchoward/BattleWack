// NetworkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BattleWack.h"
#include "NetworkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetworkDlg dialog


CNetworkDlg::CNetworkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetworkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetworkDlg)
	m_Client = 1;
	//}}AFX_DATA_INIT
}


void CNetworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworkDlg)
	DDX_Radio(pDX, IDC_RADIO_CLIENT, m_Client);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNetworkDlg, CDialog)
	//{{AFX_MSG_MAP(CNetworkDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworkDlg message handlers
