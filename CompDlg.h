#if !defined(AFX_COMPDLG_H__EA502E42_833A_441A_8CBA_01BB9A60FB71__INCLUDED_)
#define AFX_COMPDLG_H__EA502E42_833A_441A_8CBA_01BB9A60FB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CompDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCompDlg dialog

class CCompDlg : public CDialog
{
// Construction
public:
	CCompDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCompDlg)
	enum { IDD = IDD_COMPNAME };
	CString	m_ComputerName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCompDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCompDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPDLG_H__EA502E42_833A_441A_8CBA_01BB9A60FB71__INCLUDED_)
