// Square.cpp: implementation of the Square class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BattleWack.h"
#include "Square.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//===============================================================================================
// Square Constructor - Given a grid location, whether it's a hit or miss, and which grid it's on,
//							creates the appropriate color square in the appropriate location and
//							plays the appropriate sound.
//===============================================================================================
Square::Square(int x, int y, bool ShipHit, bool Foe)
{
	COLORREF color;
	
	//if it's on the FoeGrid, converts the points to actual on screen coordinates in the
	//	opponents grid
	if(Foe == true)
	{
		x = (x * 35) + 69;
		y = (y * 35) + 175;
	}

	//if it's on the FriendGrid, converts the points to actual on screen coordinates in the
	//	player's own grid
	else
	{
		x = (x * 35) + 605;
		y = (y * 35) + 175;
	}
	
	outline.left = x;
	outline.top = y;
	outline.bottom = y + 35;
	outline.right = x + 35;

	//if a ship is hit, color the square red and play the hit sound
	if(ShipHit == true)
	{
		PlaySound("launcher.wav",NULL,SND_FILENAME|SND_ASYNC);
		color = RGB(255, 0, 0);		
	}

	//if it's a miss. color the square blue and play the miss sound
	else 
	{
		PlaySound("water.wav",NULL,SND_FILENAME|SND_ASYNC);
		color = RGB(100, 205, 255);				
	}

	// set brush color
	brush.CreateSolidBrush(color);
}

Square::~Square()
{
}

//===============================================================================================
// draw - Draws the square
//===============================================================================================
void Square::draw(CDC& dc)
{
	dc.SelectObject(&brush);
	dc.Rectangle(outline);
}