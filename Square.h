// Square.h: interface for the Square class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQUARE_H__50164C23_4B94_4179_A324_3F8DE8E2F7E2__INCLUDED_)
#define AFX_SQUARE_H__50164C23_4B94_4179_A324_3F8DE8E2F7E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////
// Square: creates & draws colored squares on the grids to represent
//				hits & misses

class Square  
{
	public:
		Square(int, int, bool, bool);
		virtual ~Square();
		void draw(CDC&);
	
	private:
		CBrush brush;		//stores color information
		CRect outline;		//stores coordinates for the square to be drawn
};

#endif // !defined(AFX_SQUARE_H__50164C23_4B94_4179_A324_3F8DE8E2F7E2__INCLUDED_)