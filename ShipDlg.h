#if !defined(AFX_SHIPDLG_H__2A6B7856_A283_4BF8_86AD_B1B0D15882D4__INCLUDED_)
#define AFX_SHIPDLG_H__2A6B7856_A283_4BF8_86AD_B1B0D15882D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShipDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShipDlg dialog

class CShipDlg : public CDialog
{
// Construction
public:
	CShipDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShipDlg)
	enum { IDD = IDD_PLACESHIPS };
	int		m_B_Row;
	CString	m_B_ShipName;
	int		m_B_Column;
	int		m_C_Column;
	int		m_C_Row;
	CString	m_C_ShipName;
	int		m_D_Column;
	int		m_D_Row;
	CString	m_D_ShipName;
	int		m_S_Column;
	int		m_S_Row;
	CString	m_S_ShipName;
	int		m_B_Orientation;
	int		m_C_Orientation;
	int		m_D_Orientation;
	int		m_S_Orientation;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShipDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShipDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIPDLG_H__2A6B7856_A283_4BF8_86AD_B1B0D15882D4__INCLUDED_)
