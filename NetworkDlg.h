#if !defined(AFX_NETWORKDLG_H__33A28BEB_6DED_437B_A368_489D344C25BB__INCLUDED_)
#define AFX_NETWORKDLG_H__33A28BEB_6DED_437B_A368_489D344C25BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NetworkDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNetworkDlg dialog

class CNetworkDlg : public CDialog
{
// Construction
public:
	CNetworkDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkDlg)
	enum { IDD = IDD_NETWORK };
	int		m_Client;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNetworkDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKDLG_H__33A28BEB_6DED_437B_A368_489D344C25BB__INCLUDED_)
