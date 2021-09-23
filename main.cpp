/* ----------------------------------------------------------------------
    Program 2: Great 13
        Peg puzzle. Jump pegs to try and leave only a single peg.

    Course: CS 141, Fall 2021
    System: Mac using CLion
    Author: Maxwell Olmen

    Running the program looks like:
        Class: CS 141
        Program: #2 Great 13

        Make a series of jumps until there is a single piece left in the
        middle. On each move you must jump an adjacent piece into an empty
        square, jumping horizontally, vertically, or diagonally.
        Input of 'R' resets the board back to the beginning, and input of
        'X' exits the game.'


             Board    Position
               #          A
             # # #      B C D
           # # . # #  E F G H I
             # # #      J K L
               #          M

        1. Enter positions from, jump, and to (e.g. EFG):
   ----------------------------------------------------------------------
*/
#include <iostream>
#include <cctype>   // for toupper()

using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the following:
//   - 13 board pieces
//   - The letter positions you are moving from, jumping over, and moving to
//   - The number of pieces on the board (to know when there is a win)
char pA, pB, pC, pD, pE, pF, pG, pH, pI, pJ, pK, pL, pM;
char moveFrom, moveJump, moveTo;
short numBoardPieces, moveNumber;


// ----------------------------------------------------------------------
// Display the game instructions.
void displayInstructions() {
    cout << "Class: CS 141             \n"
    << "Program: #2 Great 13      \n"
    << "  \n"
    << "Make a series of jumps until there is a single piece left in the   \n"
    << "middle. On each move you must jump an adjacent piece into an empty \n"
    << "square, jumping horizontally, vertically, or diagonally.           \n"
    << "Input of 'R' resets the board back to the beginning, and input of  \n"
    << "'X' exits the game.'   \n"
    << endl;
} //end displayInstructions()

// Set up the board, including display characters and totals.
void setupBoard() {
    pA = pB = pC = pD = pE = pF = pH = pI = pJ = pK = pL = pM = '#';
    pG = '.';
    numBoardPieces = 12;
    moveNumber = 1;
}

// ----------------------------------------------------------------------
// Display the board, using the global variables pA..pM
void displayBoard() {
    cout << "\n "
    << "    Board   " << " Position \n"
    << "       " << pA << "          A    \n"
    << "     " << pB << " " << pC << " " << pD << "      B C D  \n"
    << "   " << pE << " " << pF << " " << pG << " " << pH << " " << pI << "  E F G H I\n"
    << "     " << pJ << " " << pK << " " << pL << "      J K L  \n"
    << "       " << pM << "          M    \n"
    << endl;
} //end displayBoard()

// Checks and returns whether the current requested move follows a proper line
bool isAdjacent() {
    // Check first character, then check that the second and third character are in line
    // After checking first character, every possible line combination for the second and third are checked
    if (moveFrom == 'A') {
        if ((moveJump == 'B' && moveTo == 'E')
        || (moveJump == 'C' && moveTo == 'G')
        || (moveJump == 'D' && moveTo == 'I')) {
            return true;
        }
    } else if (moveFrom == 'B') {
        if ((moveJump == 'C' && moveTo == 'D')
        || (moveJump == 'F' && moveTo == 'J')
        || (moveJump == 'G' && moveTo == 'L')) {
            return true;
        }
    } else if (moveFrom == 'C' && moveJump == 'G' && moveTo == 'K') {
        return true;
    } else if (moveFrom == 'D') {
        if ((moveJump == 'C' && moveTo == 'B')
        || (moveJump == 'G' && moveTo == 'J')
        || (moveJump == 'H' && moveTo == 'L')) {
            return true;
        }
    } else if (moveFrom == 'E') {
        if ((moveJump == 'B' && moveTo == 'A')
        || (moveJump == 'F' && moveTo == 'G')
        || (moveJump == 'J' && moveTo == 'M')) {
            return true;
        }
    } else if (moveFrom == 'F' && moveJump == 'G' && moveTo == 'H') {
        return true;
    } else if (moveFrom == 'G') {
        if ((moveJump == 'C' && moveTo == 'A')
        || (moveJump == 'F' && moveTo == 'E')
        || (moveJump == 'H' && moveTo == 'I')
        || (moveJump == 'K' && moveTo == 'M')) {
            return true;
        }
    } else if (moveFrom == 'H' && moveJump == 'G' && moveTo == 'F') {
        return true;
    } else if (moveFrom == 'I') {
        if ((moveJump == 'D' && moveTo == 'A')
        || (moveJump == 'H' && moveTo == 'G')
        || (moveJump == 'L' && moveTo == 'M')) {
            return true;
        }
    } else if (moveFrom == 'J') {
        if ((moveJump == 'F' && moveTo == 'B')
        || (moveJump == 'G' && moveTo == 'D')
        || (moveJump == 'K' && moveTo == 'L')) {
            return true;
        }
    } else if (moveFrom == 'K' && moveJump == 'G' && moveTo == 'C') {
        return true;
    } else if (moveFrom == 'L') {
        if ((moveJump == 'H' && moveTo == 'D')
        || (moveJump == 'G' && moveTo == 'B')
        || (moveJump == 'K' && moveTo == 'J')) {
            return true;
        }
    } else if (moveFrom == 'M') {
        if ((moveJump == 'J' && moveTo == 'E')
        || (moveJump == 'K' && moveTo == 'G')
        || (moveJump == 'L' && moveTo == 'I')) {
            return true;
        }
    }

    return false;
}

// Gets the character (either # or .) at the position specified by letter-code
char& getChar(char position) {
    // Switch letter-code position to match to existing char variable, then return variable as reference
    switch (position) {
        case 'A':
            return pA;
            case 'B':
                return pB;
                case 'C':
                    return pC;
                    case 'D':
                        return pD;
                        case 'E':
                            return pE;
                            case 'F':
                                return pF;
                                case 'G':
                                    return pG;
                                    case 'H':
                                        return pH;
                                        case 'I':
                                            return pI;
                                            case 'J':
                                                return pJ;
                                                case 'K':
                                                    return pK;
                                                    case 'L':
                                                        return pL;
                                                        case 'M':
                                                            return pM;
    }

    return pA;
}

// Sets character (normally with either # or .) to the letter-code position specified
void setChar(char position, char c) {
    getChar(position) = c;
}

// Checks and returns whether the character at the specified letter-code position contains a piece (#)
bool hasPiece(char position) {
    return getChar(position) == '#';
}

bool checkErrors() {
    // Ensure set of pieces (from, jump, to) are adjacent.  If they aren't, then
    // continue back up to re-run the while(...) loop.
    if (!isAdjacent()) {
        cout << endl << "   *** Pieces must be adjacent. Please retry" << endl << endl;
        return false;
    }

    // Ensure location we're moving FROM has a PlayerPiece in it. If it doesn't, then
    // continue back up to re-run the while(...) loop.
    if (!hasPiece(moveFrom)) {
        cout << endl << "   *** Source must have a piece. Please retry" << endl << endl;
        return false;
    }

    // Ensure piece being jumped isn't blank. If it is, then
    // continue back up to re-run the while(...) loop.
    if (!hasPiece(moveJump)) {
        cout << endl << "   *** Must jump a piece. Please retry" << endl << endl;
        return false;
    }

    // Ensure location we're moving TO is blank. If it is not, then
    // continue back up to re-run the while(...) loop.
    if (hasPiece(moveTo)) {
        cout << endl << "   *** Destination must be blank. Retry" << endl << endl;
        return false;
    }

    return true;
}

// Checks and returns whether the requested move is legal, once known that it is a proper line
// Moves are only legal when line reads ##.
bool isLegal(char moveFrom, char moveJump, char moveTo) {
    return getChar(moveFrom) == '#' && getChar(moveJump) == '#' && getChar(moveTo) == '.';
}

// Checks and returns whether there is a legal move at any given time
// If this function returns false, it is known that the game is over
// Followed by a check of piece count to determine win/loss
bool hasMove() {
    // Check legality of every possible move (manually entered)
    if (isLegal('A', 'B', 'E') || isLegal('A', 'C', 'G') || isLegal('A', 'D', 'I')
    || isLegal('B', 'C', 'D') || isLegal('B', 'G', 'L') || isLegal('B', 'F', 'J')
    || isLegal('C', 'G', 'K') || isLegal('D', 'C', 'B') || isLegal('D', 'G', 'J')
    || isLegal('D', 'H', 'L') || isLegal('E', 'B', 'A') || isLegal('E', 'F', 'G')
    || isLegal('E', 'J', 'M') || isLegal('F', 'G', 'H') || isLegal('G', 'C', 'A')
    || isLegal('G', 'F', 'E') || isLegal('G', 'H', 'I') || isLegal('G', 'K', 'M')
    || isLegal('H', 'G', 'F') || isLegal('I', 'D', 'A') || isLegal('I', 'H', 'G')
    || isLegal('I', 'L', 'M') || isLegal('J', 'F', 'B') || isLegal('J', 'G', 'D')
    || isLegal('J', 'K', 'L') || isLegal('K', 'G', 'C') || isLegal('L', 'K', 'J')
    || isLegal('L', 'G', 'B') || isLegal('L', 'H', 'D') || isLegal('M', 'J', 'E')
    || isLegal('M', 'K', 'G') || isLegal('M', 'L', 'I')) {
        return true;
    }

    return false;
}

// ----------------------------------------------------------------------
// Main section of the program, containing the game play loop
int main() {
    // Display instructions and initialize board
    displayInstructions();
    setupBoard();

    // Game play loop
    displayBoard();
    while (numBoardPieces > 1) {
        cout << moveNumber << ". " << "Enter positions from, jump, and to (e.g. EFG): ";
        cin >> moveFrom;                // Read just the first user input, handling inputs 'X' or 'R'
        moveFrom = toupper(moveFrom);  // Fold input into upper case to simplify later comparisons

        // If 'X' to exit was chosen, break out of game play loop
        if (moveFrom == 'X') {
            cout << "Exiting" << endl;
            break;
        }

        // If 'R' to reset the board was chosen, reinitialize everything
        // display the board, and continue back up to re-run the while(...) loop
        if (moveFrom == 'R') {
            cout << endl << "   *** Restarting" << endl;
            setupBoard();
            displayBoard();

            continue;
        }

        // Additionally now also read the piece-to-jump and destination inputs.
        cin >> moveJump;
        cin >> moveTo;

        // Fold inputs again into upper case to simplify later comparisons
        moveJump = toupper(moveJump);
        moveTo = toupper(moveTo);

        if (!checkErrors()) {
            continue;
        }

        // Make the move and display the board
        setChar(moveFrom, '.');
        setChar(moveJump, '.');
        setChar(moveTo, '#');
        displayBoard();

        // Increment move number and decrement total number of pieces
        moveNumber++;
        numBoardPieces--;

        // If there are no legal moves, break from the game loop (game over)
        if (!hasMove()) {
            break;
        }
    } //end while( numberOfPieces > 1)

    // Check for a win
    // If numBoardPieces != 1, there are more, likely 2 or 3, and the player lost
    if (numBoardPieces == 1) {
        cout << endl << "Congratulations, you did it!" << endl;
    } else {
        cout << endl << "Better luck next time." << endl;
    }

    cout << "Done." << endl;
    return 0;
} //end main()
