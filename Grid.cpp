// Grid.cpp: implementation of the Grid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BattleWack.h"
#include "Grid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//===============================================================================================
// Grid Constructor - initilizes all values to 9
//===============================================================================================
Grid::Grid()
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			grid[i][j] = 9;
}

Grid::~Grid()
{
}

//===============================================================================================
// ChangeGrid - Given variables from the ship placement dialog, resets all values to 9, and
//					places the ships in the grid according to index.  Outputs a MessageBox if
//					the ship positions overlap each other.  Returns false if no ships overlap.
//===============================================================================================
bool Grid::ChangeGrid(CShipDlg &SDlg)
{
	bool overlap = false;
	bool C, B, D, S;
	
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			grid[i][j] = 9;

	C = UpdateGrid(SDlg.m_C_Column, SDlg.m_C_Row, 5, SDlg.m_C_Orientation);
	B = UpdateGrid(SDlg.m_B_Column, SDlg.m_B_Row, 4, SDlg.m_B_Orientation);
	D = UpdateGrid(SDlg.m_D_Column, SDlg.m_D_Row, 3, SDlg.m_D_Orientation);
	S = UpdateGrid(SDlg.m_S_Column, SDlg.m_S_Row, 2, SDlg.m_S_Orientation);

	if(C==true || B==true || D==true || S==true)
	{
		AfxMessageBox("Your ships are overlappin SUCKA!");
		overlap = true;
	}
	return overlap;
}

//===============================================================================================
// UpdateGrid - given grid coordinates of the top/left space, size, and orientation of the ship,
//					places the ship in the grid.  If the ship overlaps another ship, returns
//					true.
//===============================================================================================
bool Grid::UpdateGrid(int x, int y, int size, bool horizontal)
{
	bool overlap = false;
	int i;
	int index = size - 2;
	
	//if the ship is horizontal, starts at the left-most space and places its values in the grid
	//	moving right as many spaces as the size
	if(horizontal == true)
		for(i=x;i<(size+x);i++)
		{
			if(grid[i][y] == 9)
				grid[i][y] = index;
			else overlap = true;
		}
	else 
		//if the ship is vertical, starts at the top space and places its values in the grid
		//	moving down as many space as the size
		for(i=y;i<(size+y);i++)
		{
			if(grid[x][i] == 9)
				grid[x][i] = index;
			else overlap = true;
		}
	
	return overlap;
}

//===============================================================================================
//IsHit - Returns true if the given location contains a ship.
//===============================================================================================
bool Grid::IsHit(int x, int y)
{
	if(grid[x][y] != 9)
		return true;
	else return false;
}

//===============================================================================================
// AlreadyHit - Returns true if the given location has already been clicked on.
//===============================================================================================
bool Grid::AlreadyHit(int x, int y)
{
	if(grid[x][y] == 8)
		return true;
	else return false;
}

//===============================================================================================
// Identity - Returns the index given a location
//===============================================================================================
int Grid::Identity(int x, int y)
{
	return grid[x][y];
}

//===============================================================================================
// HitShip - Replaces that location with an 8 to indicate the spot has already been fired on
//===============================================================================================
void Grid::HitShip(int x, int y)
{
	grid[x][y] = 8;
}