// SquareList.h: interface for the SquareList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQUARELIST_H__4AE1D189_5F03_4A9B_BB7C_ACB1025E28C3__INCLUDED_)
#define AFX_SQUARELIST_H__4AE1D189_5F03_4A9B_BB7C_ACB1025E28C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////
// SquareList: Stores pointers to every square created so they may be
//					redrawn everytime OnPaint is called

#include "Square.h"

class SquareList  
{
public:
	SquareList();
	virtual ~SquareList();
	void AddSquare(Square*);
	void draw(CDC&);

private:
	enum {MAX_SQUARES = 200};		//Maximum number of squares that could be created is 200
	Square *list[MAX_SQUARES];		//each pointer in the array will point to a unique square
	int count;						//counts how many squares are created
};

#endif // !defined(AFX_SQUARELIST_H__4AE1D189_5F03_4A9B_BB7C_ACB1025E28C3__INCLUDED_)