#if !defined(AFX_PLAYERDLG_H__64B1CEFA_B871_449C_BBF2_F1B5A13B985D__INCLUDED_)
#define AFX_PLAYERDLG_H__64B1CEFA_B871_449C_BBF2_F1B5A13B985D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlayerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg dialog

class CPlayerDlg : public CDialog
{
// Construction
public:
	CPlayerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayerDlg)
	enum { IDD = IDD_PLAYERNAME };
	CString	m_PlayerName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayerDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYERDLG_H__64B1CEFA_B871_449C_BBF2_F1B5A13B985D__INCLUDED_)
