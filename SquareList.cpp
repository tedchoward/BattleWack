// SquareList.cpp: implementation of the SquareList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BattleWack.h"
#include "SquareList.h"
#include <assert.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//===============================================================
// SquareList constructor - Set current object count to zero.
//===============================================================
SquareList::SquareList() :  count(0) 
{
}

SquareList::~SquareList()
{
}

//===============================================================
// AddSquare - Store pointer into array.  
//===============================================================
void SquareList::AddSquare(Square *ptr)
{
	assert( count < MAX_SQUARES );
	list[count++] = ptr;
}

//===============================================================
// draw - Tell every square to draw itself
//===============================================================
void SquareList::draw(CDC& dc)
{
	for(int i = 0; i < count; i++)
		list[i]->draw(dc);
}