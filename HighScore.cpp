// HighScore.cpp: implementation of the HighScore class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BattleWack.h"
#include "HighScore.h"
#include <fstream>
#include <strstream>
#include <iomanip>

using namespace std;


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//===============================================================================================
// HighScore Constructor - Loads high scores from a file into the linked list, and counts the 
//								number of nodes;
//===============================================================================================
HighScore::HighScore()
{
	count = 0;
	ifstream file;
	file.open("scores.txt");

	NodeType *newNodePtr;
	NodeType *currPtr;
	newNodePtr = new NodeType;
	file >> newNodePtr->PlayerName >> newNodePtr->HighScore;
	count++;
	head = newNodePtr;
	while(file)
	{
		currPtr = newNodePtr;
		newNodePtr = new NodeType;
		currPtr->link = newNodePtr;
		file >> newNodePtr->PlayerName >> newNodePtr->HighScore;
		count++;
	}
}

HighScore::~HighScore()
{
}

//===============================================================================================
// Print - Given the address to a Char[] uses ostrstream to put the top 5 high scores from the
//				linked list into the string
//===============================================================================================
void HighScore::Print(char *output) const
{
    NodeType *currPtr = head;    // Loop control pointer	
	
	ostrstream ostr(output, 200);
	ostr << fixed << setprecision(0);
	ostr << setiosflags(ios::left) << setw(10) << currPtr->PlayerName << "  " << currPtr->HighScore << endl;
	currPtr = currPtr->link;
	ostr << setw(10) << currPtr->PlayerName << "	" << currPtr->HighScore << endl;
	currPtr = currPtr->link;
	ostr << setw(10) << currPtr->PlayerName << "	" << currPtr->HighScore << endl;
	currPtr = currPtr->link;
	ostr << setw(10) << currPtr->PlayerName << "	" << currPtr->HighScore << endl;
	currPtr = currPtr->link;
	ostr << setw(10) << currPtr->PlayerName << "	" << currPtr->HighScore << endl;
	ostr << ends;
}

//===============================================================================================
// Insert - Given a player's initials and score, it inserts them in the linked list in order by
//				score.  Then it deletes the bottom score, to only keep the top 5 high scores.
//===============================================================================================
void HighScore::Insert( char* name, float score )
{
    NodeType *currPtr;       // Moving pointer
    NodeType *prevPtr;       // Pointer to node before *currPtr
	NodeType *newNodePtr;	 // Pointer to new node
    
	// Set up node to be inserted	

	newNodePtr = new NodeType;
	strcpy (newNodePtr->PlayerName, name);
	newNodePtr->HighScore = score;
		
	// Find previous insertion point

	prevPtr = NULL;
	currPtr = head;
    
	//starts at the top of the list and moves until the new score is smaller than the score of
	//	the preceeding node
	while (currPtr != NULL && currPtr->HighScore > score)
    {
        prevPtr = currPtr;
        currPtr = currPtr->link;
    }

    // Insert new node

    newNodePtr->link = currPtr;
	prevPtr->link = newNodePtr;

	count++;

	//deletes extra high score records over the top 5
	if(count > 5)
	{
		while(currPtr != NULL)
		{
			prevPtr = currPtr;
			currPtr = currPtr->link;
		}

		delete prevPtr;
		count --;
	}
}

//===============================================================================================
// Save - Saves the linked list to a file
//===============================================================================================
void HighScore::Save() const
{
	NodeType *currPtr = head;    // Loop control pointer
	
	ofstream save;
			
	save.open("scores.txt");	//opens the file for saving
	
	//cycles through the linked list outputing the values into the file
	while (currPtr != NULL)
    {
		save << fixed << setprecision(0) <<
			endl << " " << currPtr->PlayerName << " " << currPtr->HighScore << endl;

		currPtr = currPtr->link;
	}

	save.close();			//closes the file
}