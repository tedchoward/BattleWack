#if !defined(AFX_INITIALDLG_H__7AC006F0_13D7_4D2D_BDB0_8A8CDC02925A__INCLUDED_)
#define AFX_INITIALDLG_H__7AC006F0_13D7_4D2D_BDB0_8A8CDC02925A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InitialDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInitialDlg dialog

class CInitialDlg : public CDialog
{
// Construction
public:
	CInitialDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInitialDlg)
	enum { IDD = IDD_INITIALS };
	CString	m_Initials;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInitialDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInitialDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INITIALDLG_H__7AC006F0_13D7_4D2D_BDB0_8A8CDC02925A__INCLUDED_)
