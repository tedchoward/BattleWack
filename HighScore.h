// HighScore.h: interface for the HighScore class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HIGHSCORE_H__A2168FCE_AF3A_45E6_B283_5365CDDCC3ED__INCLUDED_)
#define AFX_HIGHSCORE_H__A2168FCE_AF3A_45E6_B283_5365CDDCC3ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////
// HighScore: Stores high scores in a linked list & displays them
//

class HighScore  
{
public:
	HighScore();
	virtual ~HighScore();
	void Print(char*) const;
    void Insert(char*, float);
    void Save() const;

private:
	int count;					//counter to make sure we only store 5 records
	struct NodeType				//the node for the linked list
	{
		char PlayerName[4];		//stores the players initials
		float HighScore;		//stores the players score
	    NodeType *link;			//points to the next node in the list
	};
	NodeType* head;				//points to the first node in the list
};

#endif // !defined(AFX_HIGHSCORE_H__A2168FCE_AF3A_45E6_B283_5365CDDCC3ED__INCLUDED_)
