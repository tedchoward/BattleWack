// Grid.h: interface for the Grid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRID_H__5EB42744_B4D7_4B20_B946_1CCF164DFAE7__INCLUDED_)
#define AFX_GRID_H__5EB42744_B4D7_4B20_B946_1CCF164DFAE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ShipDlg.h"

/////////////////////////////////////////////////////////////////////////////
// Grid: Creates & Maintains a 10x10 int matrix representing the playing grid
//

class Grid  
{
	public:
		Grid();
		virtual ~Grid();
		bool ChangeGrid(CShipDlg&);
		bool UpdateGrid(int, int, int, bool);
		bool IsHit(int, int);
		bool AlreadyHit(int, int);
		int  Identity(int, int);
		void HitShip(int, int);
		
	private:
		int  grid[10][10];	//10x10 int matrix that represents the playing grid

};

#endif // !defined(AFX_GRID_H__5EB42744_B4D7_4B20_B946_1CCF164DFAE7__INCLUDED_)