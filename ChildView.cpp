// ChildView.cpp : implementation of the CChildView class
//						This is where all the maguc happens!

#include "stdafx.h"
#include "BattleWack.h"
#include "ChildView.h"
#include <strstream>
#include <stdlib.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//===================================================
// Default Constructor - Initializes member variables
//===================================================
CChildView::CChildView()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);	//creates a socket
	assert(sock>=0);
	bound = false;
	clickCount = 0;
	hitCount = 0;
	strcpy(FriendName, "YOUR SHIPS");
	strcpy(FoeName, "THEIR SHIPS");
	inGame = false;
	greyed = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()	// Left button up
	ON_COMMAND(ID_FILE_NEWGAME, OnNew)
	ON_COMMAND(ID_HELP_ASKT, OnAskT)
	ON_COMMAND(ID_HELPME, OnHelp)
	ON_COMMAND(ID_HIGHSCORES, OnHighScores)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEWGAME, OnUpdateNewGame)

END_MESSAGE_MAP()

//=============================================
// PreCreateWindow - Generated Function
//=============================================
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}


//=============================================
// CChildView message handlers
//=============================================


//================================================================================================
// OnLButtonUp - When the Left Mouse Button is clicked, this function checks to see if there is a
//					game in session.  If so, it makes sure the click is in the Foe Grid.  If so,
//					it converts the CPoint passed by the operating system to a set of coordinates
//					relative to our 10x10 grid, draws the appropriate color square in that
//					location, makes the appropriate record in the FoeGrid, and sends the
//					coordinates to the other computer for processing.  If it was a hit
//					the function then determines if the hit caused a ship to sink, and outputs the
//					appropriate dialog.  Then it checks if all the ships have been sunk.  If so
//					it ends the game, if not, it waits for the other player to move.
//================================================================================================
afx_msg void CChildView::OnLButtonUp(UINT flags, CPoint point)
{
	//only does anything if a game is in session
	if(inGame == true)
	{
		bool ShipHit;		//flag for whether a ship has been hit
		bool AlreadyHit;	//flag for whether a square has already been clicked
		int  Identity;		//holds the index value of a ship
		char dialog[100];	//output string for the sunk ship message box
		ostrstream ostr(dialog, sizeof(dialog));
	
		// Converts actual clicked coordinates to coordinates that correspond to our 2 dimensional
		// 10x10 array
		pt.x = (point.x - 69) / 35;				
		pt.y = (point.y - 175) / 35;

		//only exectutes if we clicked inside the FoeGrid
		if(InBound(pt.x, pt.y))
		{
			// Only executes the following code if we haven't already clicked in that square
			AlreadyHit = FoeGrid.AlreadyHit(pt.x, pt.y);
			if(AlreadyHit == false)
			{
				clickCount++;							// counts as a click for score computation
				ShipHit = FoeGrid.IsHit(pt.x, pt.y);	// Did we hit a ship?
				CreateSquare(pt.x, pt.y, ShipHit, true);// Colors the square the appropriate color
			
				// only executed following if we hit a ship
				if(ShipHit == true)
				{
					hitCount++;							// counts as a hit for score computation
					Identity = FoeGrid.Identity(pt.x, pt.y); //gets index of ship hit
					Foe[Identity].ShipHit();				 //records a hit for that ship
					if(Foe[Identity].IsSunk() == true)		 //if the ship is sunk, outputs a
					{										 //		dialog notifing the player

						ostr << "You sunk the " << Foe[Identity].ShipType << " '" 
							 << Foe[Identity].name << "' SUCKA!" << ends;
						MessageBox(dialog, "Mr.T Says");
					}
				}
				
				// Records a hit for that position in our 10x10 array
				FoeGrid.HitShip(pt.x, pt.y);	

				//sends the coordinates of the click to the other computer for processing
				ret = sendto(sock, (char*) &pt, sizeof(pt), 0, (sockaddr*) &from, len);

				//if all ships are sunk, ends the game
				if(Foe[0].IsSunk() && Foe[1].IsSunk() && Foe[2].IsSunk() &&
				   Foe[3].IsSunk())
				{
					PlaySound("ifyoubelieve.wav",NULL,SND_FILENAME|SND_ASYNC);
					
					char WinDlg[100];
					ostrstream ted(WinDlg, sizeof(WinDlg));
					ted << "Winner: " << FriendName << ends;
					MessageBox("When you believe in yourself, drink your school, stay in drugs, and don't do milk, you can get work!",
								WinDlg);
					
					Exit();
				}

				else	//otherwise waits on the other player to make a move
				{
					ret = recvfrom(sock, (char*) &pt, sizeof(pt), 0, (sockaddr*) &from, &len);
			
					ProcessFriendHit(pt.x, pt.y);
				}
			}
		}
	}
}


//=============================================================================================
// OnNew - When the user chooses File->New Game, the function prompts them for their name, and
//				then gets the users ship information, redraws the grid revealing their ship
//				positions, and then asks the user if they will be the Client or the Server, and
//				calls the appropriate function.
//=============================================================================================

afx_msg void CChildView::OnNew()
{	
	
	//Get Player Name
	CPlayerDlg PDlg;
	
	if(PDlg.DoModal() == IDOK)
	{
		strcpy(FriendName, PDlg.m_PlayerName);	//stores the name in our member variable
	}

	CShipDlg SDlg;		

	PlaceShips(SDlg);	//places the ships (see the function for more info)

	CClientDC dc(this);
	DrawGrid(dc);		//redraws the grids reflecting the new player name
	FriendLetters(dc);	//draws the letters on the friend grid representing the ship postions

	CNetworkDlg NDlg;	
	
	if(NDlg.DoModal() == IDOK)	//if they click OK, inGame = true (clicks in the foeGrid will
	{							//		now be processed), and the appropriate function will
		inGame = true;			//		be called depending on whether they selected Client
		if(NDlg.m_Client == 1)	//		or Server.  If the X out of the window, nothing happens
			OnAccept();			//		but they can choose NewGame again and replace their ships
		else
			OnConnect();
	}

}

//===============================================================================================
// OnAskT - When the user chooses Help->Ask T, a message box will appear with some words of wisdom
//				from Mr. T.  If the game has already been finished, T will instruct the user to
//				close the program.
//===============================================================================================

afx_msg void CChildView::OnAskT()
{	
	if(greyed == true)
		MessageBox("GAME'S OVER, Quit the program SUCKA!", "Mr.T Says");
	else
	{
		int random = rand() % 5 + 1;

		if(random == 1)
			MessageBox("Sink the ship, SUCKA!", "Mr.T Says");

		if(random == 2)
			MessageBox("I'll SQUASH that ship!", "Mr.T Says");

		if(random == 3)
			MessageBox("I PITY THA FOOL who sinks my ship!", "Mr.T Says");

		if(random == 4)
			MessageBox("C++ is THA SQUIDOD!", "Mr.T Says");

		if(random == 5)
			MessageBox("I PITY THA FOOL who uses numerical operators as boolean evaluators!"
			, "Mr.T Says");
	}

}

//=============================================================================================
// OnHelp - When the user chooses Help->How To Play, the function will create a MessageBox with
//				instructions on how to play
//=============================================================================================

afx_msg void CChildView::OnHelp()
{
	char help[500];
	ostrstream ostr(help, sizeof(help));

	ostr << "To start a game go to File -> New Game." << endl
		 << "The person who chooses to be the Client goes first." << endl
		 << "If you don't want to play just go to File -> Exit." << endl
		 << "If you want to reset your ships before you start the" << endl
		 << "   game just exit the Client/Server dialog and then" << endl
		 << "   go to File -> New Game. Once you are satisfied" << endl
		 << "   with your ship positions choose Client or Server" << endl
		 << "   then click OK." << ends;
	MessageBox(help, "Mr T. Says");
}

//==============================================================================================
// OhHighScored - When the user chooses View->High Scores or the game is over, the function will
//						create a MessageBox with the top 5 high scores for that machine
//==============================================================================================

afx_msg void CChildView::OnHighScores()
{
	char output[200];
	score.Print(output);
	MessageBox(output, "High Scores");
}

//=============================================================================================
// OnUpdateNewGame - When the game is over, this function greys out the File->New Game option.
//						The Operating systep passes it a pointer to a CCmdUI which contains the
//						function that allows us to grey out a menu option.
//=============================================================================================
afx_msg void CChildView::OnUpdateNewGame(CCmdUI* pCmdUI)
{
	if(greyed == true)
		pCmdUI->Enable(false);
}

//===============================================================================================
// OnPaint - Whenever the screen is minimized, maximized, resized, etc, OnPaint redraws the grids,
//				player names, letters representing ships on the friend grid, and all the colored
//				squares representing all hits and misses.
//===============================================================================================
void CChildView::OnPaint() 
{
	CPaintDC dc(this);	// device context for painting
	DrawGrid(dc);		// draws grids and player names
	FriendLetters(dc);	// draws letters on friend grid
	list.draw(dc);		// draws all colored squares on both grids
}


//===============================================================================================
// DrawGrid - This function is passed an address to a CDC which gives it drawing functions.  When
//					called, it colors the background grey, draws the two grids, and puts the 
//					player names below the appropriate grid.
//===============================================================================================
void CChildView::DrawGrid(CDC &dc)
{
	CBrush silver(RGB(192, 192, 192));
	CBrush gray(RGB(100, 100, 100));

	CBrush *origBrush = dc.SelectObject(&gray);

	//Text boxes
	CRect rect1, rect2;

	//square to contain the Foe Grid
	rect1.left = 69;
	rect1.top = 530;
	rect1.right = 419;
	rect1.bottom = 552;

	//square to contain the Friend Grid
	rect2.left = 605;
	rect2.top = 530;
	rect2.right = 955;
	rect2.bottom = 552;


	//square that contains the entire area of the window & therefore colors the window dark gray
	dc.Rectangle(0, 0, 1024, 768);

	//changes the fill color to a light silver
	dc.SelectObject(&silver);

	//draws the squares the will contain the friend & foe grids & colors them silver
	dc.Rectangle(69, 175, 419, 525);

	dc.Rectangle(605, 175, 955, 525);

	
	//draws the grid lines
	int i;
	
	//Vertical Lines for Foe Grid
	for(i=69;i<=419;i+=35)
	{
		dc.MoveTo(i, 175);
		dc.LineTo(i, 525);
	}
	
	//Horizontal Lines for Foe Grid
	for(i=175;i<=525;i+=35)
	{
		dc.MoveTo(69, i);
		dc.LineTo(419, i);
	}

	//Vertical Lines for Friend Grid
	for(i=605;i<=955;i+=35)
	{
		dc.MoveTo(i, 175);
		dc.LineTo(i, 525);
	}

	//Horizontal Lines for Friend Grid
	for(i=175;i<=525;i+=35)
	{
		dc.MoveTo(605, i);
		dc.LineTo(955, i);
	}

	//Sets the color for the text background
	dc.SetBkColor(RGB(192, 192, 192));

	//Sets the color for the text
	dc.SetTextColor(RGB(255, 0, 0));
	
	CFont font;

	//selects a font for writing the player names
	font.CreatePointFont(120, "Papyrus", &dc);

	dc.SelectObject(&font);

	//draws the player names below their respective grids;
	dc.DrawText(FoeName, rect1, DT_CENTER);
	dc.DrawText(FriendName, rect2, DT_CENTER);

}

//===============================================================================================
// Friend Letters - This function gets passed an address to a CDC, giving it drawing functions.
//						When called, this function draws letters on the friend grid representing
//						the ships.
//===============================================================================================
void CChildView::FriendLetters(CDC &dc)
{
	int Identity;
	int i, j;
	for(i=0;i<10;i++)				//cycles through the FriendGrid looking for valid ship indexes
		for(j=0;j<10;j++)			//	when it finds one, it draws the letter in that spot
		{
			Identity = FriendGrid.Identity(i, j);
			if(Identity != 9)
			{
				switch(Identity)
				{
				case 0:
					DrawLetter(i, j, "S", dc);
					break;
				case 1:
					DrawLetter(i, j, "D", dc);
					break;
				case 2:
					DrawLetter(i, j, "B", dc);
					break;
				case 3:
					DrawLetter(i, j, "C", dc);
					break;
				};
			}
		}
}

//===============================================================================================
// DrawLetter - Recieves the location, letter to draw, and the drawing functions(CDC&)
//					When called by FriendLetters, it draws the given letter in the given grid
//					coordinates
//===============================================================================================
void CChildView::DrawLetter(int x, int y, char* letter, CDC &dc)
{
	//Sets the color for the text background
	dc.SetBkColor(RGB(192, 192, 192));

	//Sets the color for the text
	dc.SetTextColor(RGB(255, 0, 0));
	
	//converts the grid points to coordinates of the top/left point of the square in the grid
	//	on the screen
	x = (x * 35) + 605;
	y = (y * 35) + 185;

	CRect rect;
	//creates a square with the coordinates given
	rect.left = x;
	rect.top = y;
	rect.right = x+35;
	rect.bottom = y+35;
	
	//draws the letter in the square
	dc.DrawText(letter, 1, rect, DT_CENTER);
}

//===============================================================================================
// PlaceShipe - When called from OnNew, the function is passed the address of an already created
//					instance of a ship dialog.  The function displays the dialog, and if the user
//					clicks OK it validates the ship information given and if it is all good, it
//					assigns the information to the ships, and places the on the grid.  If the
//					information is invalid( if ChangeGrid returns a true some ships are
//					overlapping, if ShipPlaceCheck returns a true then a ship is out of bounds)
//					the user is notified of their mistake and the dialog box appears.
//===============================================================================================
void CChildView::PlaceShips(CShipDlg &SDlg)
{	
	bool overlap;
	do
	{
		if(SDlg.DoModal() == IDOK)
		{
			PlaySound("sonarping.wav",NULL,SND_FILENAME|SND_ASYNC);

			Friend[3].MakeShip(5, SDlg.m_C_ShipName, SDlg.m_C_Orientation, SDlg.m_C_Column, SDlg.m_C_Row, "Carria");
			Friend[2].MakeShip(4, SDlg.m_B_ShipName, SDlg.m_B_Orientation, SDlg.m_B_Column, SDlg.m_B_Row, "BattleWack");
			Friend[1].MakeShip(3, SDlg.m_D_ShipName, SDlg.m_D_Orientation, SDlg.m_D_Column, SDlg.m_D_Row, "Destroya");
			Friend[0].MakeShip(2, SDlg.m_S_ShipName, SDlg.m_S_Orientation, SDlg.m_S_Column, SDlg.m_S_Row, "SubMarino");
		
			overlap = FriendGrid.ChangeGrid(SDlg);
		}

	}
	while (ShipPlaceCheck(SDlg.m_C_Column, SDlg.m_C_Row, 5, SDlg.m_C_Orientation, SDlg.m_C_ShipName) == true || 
			ShipPlaceCheck(SDlg.m_B_Column, SDlg.m_B_Row, 4, SDlg.m_B_Orientation, SDlg.m_B_ShipName) == true || 
			ShipPlaceCheck(SDlg.m_D_Column, SDlg.m_D_Row, 3, SDlg.m_D_Orientation, SDlg.m_D_ShipName) == true || 
			ShipPlaceCheck(SDlg.m_S_Column, SDlg.m_S_Row, 2, SDlg.m_S_Orientation, SDlg.m_S_ShipName) == true ||
			overlap == true);	
}

//===============================================================================================
// ShipPlaceCheck - Gets passed the row & col of the top/left space of the ship, the ship's size,
//						the ships orientation, and the name of the ship.  The function checks
//						to see if the ship goes out of bounds by checking whether the distance
//						from the top/left value (depending on the orientation) to the end of the
//						grid is greater than the size of the ship.  If the ship is bigger than 
//						that distance, then the ship is off the grid and in an invalid position.
//						This function will then output a MessageBox telling the user the name of
//						the ship and that it is off the grid, and return a value of true, causing
//						the ship dialog box to reappear.
//===============================================================================================
bool CChildView::ShipPlaceCheck(int x, int y, int size, bool orientation, CString name)
{	
	char SName[33];
	strcpy(SName, name);
	bool needShipBox = false;
	
	char dialog[100];
	ostrstream ostr(dialog, sizeof(dialog));

	// checks for ships to be off the grid
	if(x > (10-size) && orientation == true)
	{
		ostr << SName << " is off the grid FOO!  Choose again SUCKA!" << ends;
		MessageBox(dialog, "Mr. T Says");
		needShipBox = true;
	}
	else if(y > (10-size) && orientation == false)
	{
		ostr << SName << " is off the grid FOO!  Choose again SUCKA!" << ends;
		MessageBox(dialog, "Mr. T Says");
		needShipBox = true;
	}
	return needShipBox;
}

//===============================================================================================
// OnConnect - When the user chooses to be the Client, this function will ask for the name of the
//					computer to connect to.  It will then retrieve that computer's IP address
//					and bind it to a socket.  Then it sends the players name to the other 
//					computer and recieves the opponents player name.  Then it sends the ship
//					info to the opponents computer and recieves the opponent's ship info.  It then
//					places the opponents ships on the FoeGrid.  When the function is finished,
//					the user is free to click on the opponent's grid on the screen.
//===============================================================================================
void CChildView::OnConnect()
{	
	CCompDlg CDlg;
	CDlg.DoModal();

	hostent *hostInfo;		// host info of server

	// Get host info for specified host
	hostInfo = gethostbyname(CDlg.m_ComputerName);
	if ( !hostInfo )
		AfxMessageBox("unable to get server address information!");

	// Populate server address structure
	from.sin_family = PF_INET;
	from.sin_port   = htons(4000);
	from.sin_addr.s_addr   = *((u_long *)hostInfo->h_addr);

	//send player name
	ret = sendto(sock, FriendName, strlen(FriendName)+1, 0, (struct sockaddr *) &from,  sizeof(from));
	len = sizeof(from);	// len is an in-out parm

	//recieve opponent player name
	ret = recvfrom(sock, FoeName, sizeof(FoeName), 0, (sockaddr*) &from, &len);

	//redraw the grids with the opponents player name
	CClientDC dc(this);
	DrawGrid(dc);
	FriendLetters(dc);
	
	//send ship information
	ret = sendto(sock, (char*) Friend, sizeof(Friend), 0, (struct sockaddr *) &from, sizeof(from));
	
	//recieve opponent's ship information
	ret = recvfrom(sock, (char*) Foe, sizeof(Foe), 0, (sockaddr*) &from, &len);

	//populates FoeGrid with opponents ship positions
	int i;
	for(i=0;i<4;i++)
		FoeGrid.UpdateGrid(Foe[i].x_pos, Foe[i].y_pos, Foe[i].size, Foe[i].horizontal);

}

//===============================================================================================
// OnAccept - When the user chooses to be the server, the computer binds it's address to the sock.
//				It then waits to recieve the opponents player name, sends our player name,
//				recieves the opponents ship information & populates the FoeGrid, sends our
//				ship information, and waits for the opponent to make the first move.  It then
//				processes the opponent's move.
//===============================================================================================
void CChildView::OnAccept()
{
	static sockaddr_in srvAddr;

	// bind our server address if we haven't already done so
	if ( !bound )
	{
		srvAddr.sin_family = PF_INET;
		srvAddr.sin_port   = htons(4000);
		srvAddr.sin_addr.s_addr = INADDR_ANY;
		ret = bind(sock, (sockaddr*) &srvAddr, sizeof(srvAddr));
		assert(ret != SOCKET_ERROR );
		bound = true;
	}

	len = sizeof(from);

	//recieves Client's player name
	ret = recvfrom(sock, FoeName, sizeof(FoeName), 0, (sockaddr*) &from, &len);

	//redraws grids to show opponent's name
	CClientDC dc(this);
	DrawGrid(dc);
	FriendLetters(dc);

	//sends our player name
	ret = sendto(sock, FriendName, strlen(FriendName)+1, 0, (struct sockaddr *) &from, len);

	//recieves Client ship positions
	ret = recvfrom(sock, (char*) Foe, sizeof(Foe), 0, (sockaddr*) &from, &len);
		
	//populates FoeGrid
	int i;
	for(i=0;i<4;i++)
		FoeGrid.UpdateGrid(Foe[i].x_pos, Foe[i].y_pos, Foe[i].size, Foe[i].horizontal);
	
	//sends our ship information
	ret = sendto(sock, (char*) Friend, sizeof(Friend), 0, (struct sockaddr *) &from, len);

	//recieves coordinated of opponents first attack
	ret = recvfrom(sock, (char*) &pt, sizeof(pt), 0, (sockaddr*) &from, &len);

	//processes first attack
	ProcessFriendHit(pt.x, pt.y);

}

//===============================================================================================
// ProcessFriendHit - Given grid coordinates, determines if a ship is hit or not, draws the 
//							appropriate color square.  If a ship is hit it determines if the hit
//							caused the ship to sink.  If so, it outputs a MessageBox saying which
//							ship was just sunk.  It then checks to see if all ships have been sunk.
//							If so, the game ends, if not the player is free to click on the 
//							opponents grid.
//===============================================================================================
void CChildView::ProcessFriendHit(int x, int y)
{
	bool ShipHit;
	int  Identity;
	char ItIsSunk[100];
	ostrstream ostr(ItIsSunk, sizeof(ItIsSunk));
	
	ShipHit = FriendGrid.IsHit(x, y);		// Did we hit a ship?
	CreateSquare(x, y, ShipHit, false);		// Colors the square the appropriate color

	// If we hit a ship, it checks to see if the ship has sunk, and notifies us appropriately
	if(ShipHit == true)
	{
		Identity = FriendGrid.Identity(x, y);
		
		Friend[Identity].ShipHit();
		if(Friend[Identity].IsSunk() == true)
		{
			ostr << "Your " << Friend[Identity].ShipType << " '" << Friend[Identity].name 
				 << "' is sunk sucka!" << ends;
			MessageBox(ItIsSunk, "Mr.T Says");
		}
	}
	
	// Records a hit for that position in our 10x10 array
	FriendGrid.HitShip(x, y);

	if(Friend[0].IsSunk() && Friend[1].IsSunk() && Friend[2].IsSunk()
		&& Friend[3].IsSunk())
	{
		char LoseDlg[100];
		ostrstream ted(LoseDlg, sizeof(LoseDlg));
		ted << "Winner: " << FoeName << ends;
		PlaySound("nexttime.wav",NULL,SND_FILENAME|SND_ASYNC);
		MessageBox("Next time stay in school!", LoseDlg);	
		Exit();
	}
}

//===============================================================================================
// CreateSquare - Given grid coordinates, whether a ship was hit, and which grid, this function
//						draws a square in the appropriate place in the appropriate color, and
//						adds it's address to the list (array of pointers to squares)
//===============================================================================================
void CChildView::CreateSquare(int x, int y, bool ShipHit, bool Foe)
{
	//if given a valid point
	if ( InBound(x, y) )
	{
		CClientDC dc(this);	
		Square *ptr;
		ptr = new Square(x, y, ShipHit, Foe);	//creates a new square
		ptr->draw(dc);							//draws the square
		list.AddSquare(ptr);					//adds it to the list
	}
}

//===============================================================================================
// InBound - Given grid coordinates, determines whether they are within the bounds of a grid
//===============================================================================================
bool CChildView::InBound(int x, int y)
{
	bool in = false;
	if (x>=0 && x<=9 && y>=0 && y<=9)
		in = true;
	return in;
}

//===============================================================================================
// Exit - When the game ends, asks the player for their initials, determines their score, adds
//				their initials and score to the high score linked list, saves the scores to a 
//				file, outputs the top 5 high scores, and greys out the New Game option.
//===============================================================================================
void CChildView::Exit()
{	
	CInitialDlg IDlg;
	IDlg.DoModal();
	char init[4];
	strcpy(init, IDlg.m_Initials);
	
	float ratio = (hitCount/clickCount) * 100;		//calculates player's score
	
	//reserves the perfect score for Harbert
	if(ratio == 100)
		MessageBox("Nobody can beat Harbert!", "Mr.T Says");

	else score.Insert(init, ratio);		//inserts the player's initials and score
	
	score.Save();						//saves the high scores
	OnHighScores();						//displays the top 5 high scores
	inGame = false;						//causes the program to ignore all clicks in the window
	greyed = true;						//greys out the New Game option
}