/*--------------------------------------------
   Program 2: Knight Escape
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
		       
   Course: CS 141, Spring 2022, Tues 9am Lab
   System: Mac using Visual Studio Code
   Author: Jennifer Le 
 ---------------------------------------------*/

#include <iostream>		// for input and output
#include <cctype>		   // for toupper()
using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the 25 board positions.

string p1,  p2,  p3,  p4,  p5,  p6,  p7,  p8,  p9,  p10, p11, p12, p13,
       p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25;

// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.

const string WhiteKnight = "\u2658";		// White knight character
const string BlackKnight = "\u265E";		// Black knight character
const string BlankPosition = " ";			// Blank position character

//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage()
{
   cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n\n"
         << "The objective of this puzzle is to get the white knight"
		 << "up to the empty square in the top right corner of the board.\n\n"
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n\n"
		 << "This means that a knight can only move either\n"
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR \n"
		 << "2) two squares in a vertical direction, then one in a horizontal direction.\n\n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n\n"
		 << "Try to complete the puzzle with the smallest number of valid moves!\n";
}//end displayWelcomeMessage()

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board

void displayBoard()
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} //end displayBoard()

// checks to see if moves are in an L-shape, recieves the source and destination position as parameters
// returns a boolean value, true if move is L-shaped and false if move is not L-shaped
bool LMove(int sourcePosition, int dP) {    // dP = destinationPosition

	if (sourcePosition == 1)  { return (dP == 8 || dP == 12); }
	if (sourcePosition == 2)  { return (dP == 9 || dP == 11 || dP == 13); }
	if (sourcePosition == 3)  { return (dP == 6 || dP == 10 || dP == 12 || dP == 14); }
	if (sourcePosition == 4)  { return (dP == 7 || dP == 13 || dP == 15); }
	if (sourcePosition == 5)  { return (dP == 8 || dP == 14); }
	if (sourcePosition == 6)  { return (dP == 3 || dP == 13 || dP == 17); }
	if (sourcePosition == 7)  { return (dP == 4 || dP == 14 || dP == 16 || dP == 18); }
	if (sourcePosition == 8)  { return (dP == 1 || dP == 11 || dP == 5 || dP == 15 || dP == 17 || dP == 19); }
	if (sourcePosition == 9)  { return (dP == 2 || dP == 12 || dP == 18 || dP == 20); }
	if (sourcePosition == 10) { return (dP == 3 || dP == 13 || dP == 19); }
	if (sourcePosition == 11) { return (dP == 2 || dP == 8 || dP == 18 || dP == 22); }
	if (sourcePosition == 12) { return (dP == 1 || dP == 3 || dP == 9 || dP == 19 || dP == 21 || dP == 23); }
	if (sourcePosition == 13) { return (dP == 2 || dP == 4 || dP == 6 || dP == 16 || dP == 22 || dP == 24 || dP == 10 || dP == 20); }
	if (sourcePosition == 14) { return (dP == 3 || dP == 5 || dP == 7 || dP == 17 || dP == 23 || dP == 25); }
	if (sourcePosition == 15) { return (dP == 4 || dP == 8 || dP == 18 || dP == 24); }
	if (sourcePosition == 16) { return (dP == 7 || dP == 13 || dP == 23); }
	if (sourcePosition == 17) { return (dP == 6 || dP == 8 || dP == 14 || dP == 24); }
	if (sourcePosition == 18) { return (dP == 7 || dP == 9 || dP == 11 || dP == 21 || dP == 15 || dP == 25); }
	if (sourcePosition == 19) { return (dP == 8 || dP == 10 || dP == 12 || dP == 22); }
	if (sourcePosition == 20) { return (dP == 9 || dP == 13 || dP == 23); }
	if (sourcePosition == 21) { return (dP == 12 || dP == 18); }
	if (sourcePosition == 22) { return (dP == 11 || dP == 13 || dP == 19); }
	if (sourcePosition == 23) { return (dP == 12 || dP == 14 || dP == 16 || dP == 20); }
	if (sourcePosition == 24) { return (dP == 13 || dP == 15 || dP == 17); }
	if (sourcePosition == 25) { return (dP == 14 || dP == 18); }
}

// checks to see if the source position has a black or white knight, recieves the source position as a parameter
// returns a boolean value, true if there is a knight, false if there isn't
bool hasKnight(int sourcePosition) {
	string p_[25] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,
			  p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25};
	
	return (p_[sourcePosition - 1] == BlackKnight || p_[sourcePosition - 1] == WhiteKnight);  
}

// checks to see if the destination position is empty, recieves the destination position as a parameter
// returns a boolean value, true if it is empty, false if it is not empty
bool isEmpty(int destinationPosition) {
	string p_[25] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,
			  p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25};
	
	return (p_[destinationPosition - 1] == BlankPosition); 
}

// swaps the values of two different pieces of corresponding source and destination position 
// recieves the source and destination position as parameters and displays board after swap 
void swapANDdisplay(int sP, int dP) {    // sP = sourcePosition, dP = destinationPosition

	if (sP == 1)  {
		if (dP == 8)  {string temp = p1; p1 = p8; p8 = temp; }
		if (dP == 12) {string temp = p1; p1 = p12; p12 = temp; } }

	if (sP == 2)  {
		if (dP == 9)  {string temp = p2; p2 = p9; p9 = temp; }
		if (dP == 11) {string temp = p2; p2 = p11; p11 = temp; }
		if (dP == 13) {string temp = p2; p2 = p13; p13 = temp; } }
	
	if (sP == 3)  {
		if (dP == 6)  {string temp = p3; p3 = p6; p6 = temp; }
		if (dP == 10) {string temp = p3; p3 = p10; p10 = temp; }
		if (dP == 12) {string temp = p3; p3 = p12; p12 = temp; }
		if (dP == 14) {string temp = p3; p3 = p14; p14 = temp; } }

	if (sP == 4)  {
		if (dP == 7)  {string temp = p4; p4 = p7; p7 = temp; }
		if (dP == 13) {string temp = p4; p4 = p13; p13 = temp; }
		if (dP == 15) {string temp = p4; p4 = p15; p15 = temp; } }

	if (sP == 5)  {
		if (dP == 8)  {string temp = p5; p5 = p8; p8 = temp; }
		if (dP == 14) {string temp = p5; p5 = p14; p14 = temp; } }

	if (sP == 6)  {
		if (dP == 3)  {string temp = p6; p6 = p3; p3 = temp; }
		if (dP == 13) {string temp = p6; p6 = p13; p13 = temp; }
		if (dP == 17) {string temp = p6; p6 = p17; p17 = temp; } }

	if (sP == 7)  {
		if (dP == 4)  {string temp = p7; p7 = p4; p4 = temp; }
		if (dP == 14) {string temp = p7; p7 = p14; p14 = temp; }
		if (dP == 16) {string temp = p7; p7 = p16; p16 = temp; }
		if (dP == 18) {string temp = p7; p7 = p18; p18 = temp; } }

	if (sP == 8)  {
		if (dP == 1)  {string temp = p8; p8 = p1; p1 = temp; }
		if (dP == 11) {string temp = p8; p8 = p11; p11 = temp; }
		if (dP == 5)  {string temp = p8; p8 = p5; p5 = temp; }
		if (dP == 15) {string temp = p8; p8 = p15; p15 = temp; }
		if (dP == 17) {string temp = p8; p8 = p17; p17 = temp; }
		if (dP == 19) {string temp = p8; p8 = p19; p19 = temp; } }

	if (sP == 9)  {
		if (dP == 2)  {string temp = p9; p9 = p2; p2 = temp; }
		if (dP == 12) {string temp = p9; p9 = p12; p12 = temp; }
		if (dP == 18) {string temp = p9; p9 = p18; p18 = temp; }
		if (dP == 20) {string temp = p9; p9 = p20; p20 = temp; } }

	if (sP == 10)  {
		if (dP == 3)  {string temp = p10; p10 = p3; p3 = temp; }
		if (dP == 13) {string temp = p10; p10 = p13; p13 = temp; }
		if (dP == 19) {string temp = p10; p10 = p19; p19 = temp; } }

	if (sP == 11)  {
		if (dP == 2)  {string temp = p11; p11 = p2; p2 = temp; }
		if (dP == 8)  {string temp = p11; p11 = p8; p8 = temp; }
		if (dP == 18) {string temp = p11; p11 = p18; p18 = temp; }
		if (dP == 22) {string temp = p11; p11 = p22; p22 = temp; } }

	if (sP == 12)  {
		if (dP == 1) {string temp = p12; p12 = p1; p1 = temp; }
		if (dP == 3) {string temp = p12; p12 = p3; p3 = temp; }
		if (dP == 9) {string temp = p12; p12 = p9; p9 = temp; }
		if (dP == 19) {string temp = p12; p12 = p19; p19 = temp; }
		if (dP == 21) {string temp = p12; p12 = p21; p21 = temp; }
		if (dP == 23) {string temp = p12; p12 = p23; p23 = temp; } }

	if (sP == 13)  {
		if (dP == 2)  {string temp = p13; p13 = p2; p2 = temp; }
		if (dP == 4)  {string temp = p13; p13 = p4; p4 = temp; }
		if (dP == 6)  {string temp = p13; p13 = p6; p6 = temp; }
		if (dP == 16) {string temp = p13; p13 = p16; p16 = temp; }
		if (dP == 22) {string temp = p13; p13 = p22; p22 = temp; }
		if (dP == 24) {string temp = p13; p13 = p24; p24 = temp; }
		if (dP == 10) {string temp = p13; p13 = p10; p10 = temp; }
		if (dP == 20) {string temp = p13; p13 = p20; p20 = temp; } }

	if (sP == 14)  {
		if (dP == 3)  {string temp = p14; p14 = p3; p3 = temp; }
		if (dP == 5)  {string temp = p14; p14 = p5; p5 = temp; }
		if (dP == 7)  {string temp = p14; p14 = p7; p7 = temp; }
		if (dP == 17) {string temp = p14; p14 = p17; p17 = temp; }
		if (dP == 23) {string temp = p14; p14 = p23; p23 = temp; }
		if (dP == 25) {string temp = p14; p14 = p25; p25 = temp; } }

	if (sP == 15)  {
		if (dP == 4)  {string temp = p15; p15 = p4; p4 = temp; }
		if (dP == 8)  {string temp = p15; p15 = p8; p8 = temp; }
		if (dP == 18) {string temp = p15; p15 = p18; p18 = temp; }
		if (dP == 24) {string temp = p15; p15 = p24; p24 = temp; } }

	if (sP == 16)  {
		if (dP == 7)  {string temp = p16; p16 = p7; p7 = temp; }
		if (dP == 13) {string temp = p16; p16 = p13; p13 = temp; }
		if (dP == 23) {string temp = p16; p16 = p23; p23 = temp; } }

	if (sP == 17)  {
		if (dP == 6)  {string temp = p17; p17 = p6; p6 = temp; }
		if (dP == 8)  {string temp = p17; p17 = p8; p8 = temp; }
		if (dP == 14) {string temp = p17; p17 = p14; p14 = temp; }
		if (dP == 24) {string temp = p17; p17 = p24; p24 = temp; } }

	if (sP == 18)  {
		if (dP == 7)  {string temp = p18; p18 = p7; p7 = temp; }
		if (dP == 9)  {string temp = p18; p18 = p9; p9 = temp; }
		if (dP == 11) {string temp = p18; p18 = p11; p11 = temp; }
		if (dP == 21) {string temp = p18; p18 = p21; p21 = temp; }
		if (dP == 15) {string temp = p18; p18 = p15; p15 = temp; }
		if (dP == 25) {string temp = p18; p18 = p25; p25 = temp; } }

	if (sP == 19)  {
		if (dP == 8)  {string temp = p19; p19 = p8; p8 = temp; }
		if (dP == 10) {string temp = p19; p19 = p10; p10 = temp; }
		if (dP == 12) {string temp = p19; p19 = p12; p12 = temp; }
		if (dP == 22) {string temp = p19; p19 = p22; p22 = temp; } }

	if (sP == 20)  {
		if (dP == 9)  {string temp = p20; p20 = p9; p9 = temp; }
		if (dP == 13) {string temp = p20; p20 = p13; p13 = temp; }
		if (dP == 23) {string temp = p20; p20 = p23; p23 = temp; } }

	if (sP == 21)  {
		if (dP == 18) {string temp = p21; p21 = p18; p18 = temp; }
		if (dP == 12) {string temp = p21; p21 = p12; p12 = temp; } }

	if (sP == 22)  {
		if (dP == 11) {string temp = p22; p22 = p11; p11 = temp; }
		if (dP == 13) {string temp = p22; p22 = p13; p13 = temp; }
		if (dP == 19) {string temp = p22; p22 = p19; p19 = temp; } }

	if (sP == 23)  {
		if (dP == 12) {string temp = p23; p23 = p12; p12 = temp; }
		if (dP == 14) {string temp = p23; p23 = p14; p14 = temp; }
		if (dP == 16) {string temp = p23; p23 = p16; p16 = temp; }
		if (dP == 20) {string temp = p23; p23 = p20; p20 = temp; } }

	if (sP == 24)  {
		if (dP == 13) {string temp = p24; p24 = p13; p13 = temp; }
		if (dP == 15) {string temp = p24; p24 = p15; p15 = temp; } 
		if (dP == 17) {string temp = p24; p24 = p17; p17 = temp; }}

	if (sP == 25)  {
		if (dP == 14) {string temp = p25; p25 = p14; p14 = temp; }
		if (dP == 18) {string temp = p25; p25 = p18; p18 = temp; } }
	
	displayBoard ();
} 
// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {
   
   displayWelcomeMessage();
	
	// Set board values to the default starting position
	p1 = p2 = p3 = p4 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = BlackKnight;
	p14 = p15 = p16 = p17 = p18 = p19 = p20 = p22 = p23 = p24 = p25 = BlackKnight;
	p5 = BlankPosition, p21 = WhiteKnight;

   	displayBoard();
   
  	// Loop that controls game play
	int currentScore = 500;
	int moveNumber = 1;
	char menuOption;
	int sourcePosition;
	int destinationPosition;

   while(currentScore > 0) {
        cout << "Current score: " << currentScore << endl << endl; 
        cout << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";

		cin >> menuOption;
		menuOption = toupper(menuOption); // convert user input to uppercase
		
		// If the user entered 'X' to exit,
		// break out of this loop that controls game play
		if (menuOption == 'X') {
		   	cout << "Exiting...\n";
			break;
		}
		
		// If the user entered 'R' to reset,
		// reset the board back to the beginning
		if (menuOption == 'R') {
			cout << "   * * * Restarting \n";
			currentScore = 500;
			moveNumber = 1;
		   
			p1 = p2 = p3 = p4 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = BlackKnight;
	        p14 = p15 = p16 = p17 = p18 = p19 = p20 = p22 = p23 = p24 = p25 = BlackKnight;
	    	p5 = BlankPosition, p21 = WhiteKnight; 
	
        	displayBoard();
		}
		
		// If the user entered 'M' to move a knight,
		// ask for the position of the knight to be moved
		if (menuOption == 'M') {
        	cout << "Enter the positions from and to, separated by a space "
                 << "(e.g. 14 5 to move the knight in position 14 to position 5): ";
        	cin >> sourcePosition >> destinationPosition; 
        	cout << "\n\nYou have chosen to move a knight from position " << sourcePosition
                 << " to position " << destinationPosition << "." << endl;
			
			if (sourcePosition >= 1 && sourcePosition <= 25) {                         // checks if sourcePosition is between 1 and 25 
				if (destinationPosition >= 1 && destinationPosition <= 25) {           // checks if destinationPosition is between 1 and 25 
					if (hasKnight(sourcePosition)) {                                   // checks if sourcePosition has a knight
						if (isEmpty(destinationPosition)) {                            // checks if destinationPosition is empty
							if (LMove(sourcePosition, destinationPosition)) {          // checks if move is L-shaped
								swapANDdisplay(sourcePosition, destinationPosition);
								if (p5 == WhiteKnight) { cout << "Congratulations, you did it!\n"; break; }  // checks for a win
								currentScore -= 5;
								moveNumber++;
							}
							else { cout << "Invalid move. Knights can only move in an L-shape. Try again.\n\n";
								currentScore -= 10;  }
						} 
						else { cout << "The destination position should be empty. Try again.\n\n";
							currentScore -= 10;  }
					} 
					else { cout << "The source position should have a knight. Try again.\n\n";
						currentScore -= 10;  }
				}
				else { cout << "The destination position should be a valid position on the board (1-25). Try again.\n\n";
					currentScore -= 10; }
			}
			else { cout << "The source position should be a valid position on the board (1-25). Try again.\n\n"; 
				currentScore -= 10;}
		}
	} // end loop for game play
	
	// displays message if the score is less than or equal to zero
	if (currentScore <= 0) { 
	   cout << "Current score: " << currentScore << endl; 
	   cout << "You have run out of moves. Try to do better next time!\n"; }
	   
	cout << "Thank you for playing!" << endl;

	return 0;
}