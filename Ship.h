// Ship.h: interface for the Ship class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHIP_H__6650596B_12D5_46C3_ACA9_ECE824428276__INCLUDED_)
#define AFX_SHIP_H__6650596B_12D5_46C3_ACA9_ECE824428276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////
// Ship: Contains information for a ship
//

class Ship  
{
	public:
		Ship();
		virtual ~Ship();
		void MakeShip(int, CString, bool, int, int, char*);
		void ShipHit();
		bool IsSunk();
		
		char name[33];		//The Name of the ship (32 chars + NULL byte)
		bool horizontal;	//Whether the ship is oriented horizontally or vertically
		int  size;			//The size of the ship (ex: the carria is 5 spaces)
		int  x_pos;			//The X coordinate of the top/left space of the ship
		int  y_pos;			//The Y coordinate of the top/left space of the ship
		int  count;			//Counter that increments each time ship is hit
							//	when it == size the ship is sunk
		int index;			//Index representing the ship (since ships will be created as an
							//	array the ships will be referred to with this number & they
							//	will be represented on the grid with this number as well
		char ShipType[12];	//The type of the ship(Carria, BattleWack, Destroya, or SubMarino)
};

#endif // !defined(AFX_SHIP_H__6650596B_12D5_46C3_ACA9_ECE824428276__INCLUDED_)