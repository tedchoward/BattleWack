// Ship.cpp: implementation of the Ship class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BattleWack.h"
#include "Ship.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//===============================================================================================
// Ship Constructor - Initilizes the hit counter to 0
//===============================================================================================
Ship::Ship()
{
	count = 0;
}

Ship::~Ship()
{
}

//===============================================================================================
// MakeShip - Given size, name, orientation, location of top/left space, and type, Stores these
//				values in the class members, also calculates the index value
//===============================================================================================
void Ship::MakeShip(int ShipSize, CString ShipName, bool ShipOrientation, int x, int y, char *type)
{
	size = ShipSize;
	index = size - 2;
	strcpy(name, ShipName);
	strcpy(ShipType, type);
	horizontal = ShipOrientation;
	x_pos = x;
	y_pos = y;
}

//===============================================================================================
// ShipHit - Increases the hit counter if the ship gets hit.
//===============================================================================================
void Ship::ShipHit()
{
	count++;
}

//===============================================================================================
// IsSunk - When the hit counter becomes the same value as the size the ship is sunk, and it
//				returns true
//===============================================================================================
bool Ship::IsSunk()
{
	if(count < size)
		return false;
	else return true;
}