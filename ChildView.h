// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__FFA0E662_C93E_4899_A2B6_ACFB1BE10443__INCLUDED_)
#define AFX_CHILDVIEW_H__FFA0E662_C93E_4899_A2B6_ACFB1BE10443__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

#include "SquareList.h"
#include "Grid.h"
#include "PlayerDlg.h"
#include "CompDlg.h"
#include "ShipDlg.h"
#include "NetworkDlg.h"
#include "InitialDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CChildView:	This is the main Window View for our program
//				This class handles everything for our program


class CChildView : public CWnd
{

public:
	CChildView();
	afx_msg void OnLButtonUp(UINT, CPoint);	
	afx_msg void OnNew();					
	afx_msg void OnAskT();					
	afx_msg void OnHelp();					
	afx_msg void OnHighScores();			
	afx_msg void OnUpdateNewGame(CCmdUI*);
	void DrawGrid(CDC&);
	void FriendLetters(CDC&);
	void DrawLetter(int, int, char*, CDC&);
	void PlaceShips(CShipDlg&);
	bool ShipPlaceCheck(int, int, int, bool, CString);
	void OnConnect();
	void OnAccept();
	void ProcessFriendHit(int x, int y);
	void CreateSquare(int, int, bool, bool);
	bool InBound(int, int);
	void Exit();
	
private:
	bool inGame;	//Flag that only allows clicks to be processed if a game is in session
	bool greyed;	//Flag that causes File-New Game to be greyed after a game is played
	SquareList list;//contains an array of pointers to every colored square on both grids
	CPoint pt;		//contains coordinates of a click that get passed to the other computer
	HighScore score;//contains High Score information

	//network socket
	SOCKET	sock;		// socket descriptor
	bool	bound;		// whether socket's address has been bound
	sockaddr_in from;	// address of the other computer
	int len;			// will contain the size of the computer address
	int ret;			// will accept returned values from sendto() and recvfrom()

	Grid FoeGrid;		// 10x10 int matrix representing the opponent's grid
	Grid FriendGrid;	// 10x10 int matrix representing the player's grid

	Ship Foe[4];		// creates the 4 enemy ships
	Ship Friend[4];		// creates the player's 4 ships

	char FoeName[33];	// holds the opponent's name (32 chars + NULL byte)
	char FriendName[33];// holds the player's name (32 chars + NULL byte)

	//used to compute high scores
	float clickCount;	// counts the number of squares the player clicks
	float hitCount;		// counts the number of times the player hits a ship

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__FFA0E662_C93E_4899_A2B6_ACFB1BE10443__INCLUDED_)
