#include "Functions.h"

void runGame()
{
    char board[3][3];
	initBoard(board);
    char player = 'X';
    int turns = 0;
    while (true)
    {
        std::cout << "Enter coordinate for " << player << ". Input should be X Y" << std::endl;
        int xcoord, ycoord;
        std::cin >> xcoord >> ycoord;
        placeAPiece(xcoord, ycoord, player, board);
        displayBoard(board);
        turns++;
        if (checkForWinner(player, board) == true)
        {
            std::cout << player << " Won" << std::endl;
            if (playAgain() == true)
            {
                initBoard(board);
                player = 'X';
                turns = 0;
            }
            else
            {
                std::cout << "Done" << std::endl;
                break;
            }
        }
        if (checkForDraw(board) == true)
        {
            std::cout << "Draw" << std::endl;
            if (playAgain() == true)
            {
                initBoard(board);
                player = 'X';
                turns = 0;
            }
            else
            {
                std::cout << "Done" << std::endl;
                break;
            }
        }

        if (turns % 2 == 1)
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }
}

bool playAgain()
{
    char again;
    std::cout << "Do you want to play again?" << std::endl;
    std::cin >> again;
    if (again == 'y' | again == 'Y')
    {
        return true;
    }
    return false;
}

void initBoard(char board[3][3])
{
    // Given board[3][3], a 2-D array, make it empty with char '-'
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void placeAPiece(int x, int y, char piece, char board[3][3])
{
    board[x][y] = piece;
}


bool checkForWinner(char piece, char board[3][3])
{
    // true if there is a winner, else false
    for (int i = 0; i < 3; i++)
    {
        // columns
        if (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece)
        {
            return true;
        }

        // rows
        if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece)
        {
            return true;
        }
    }
    /* diag like '\' */
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece)
    {
        return true;
    }

    // diag like /
    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece)
    {
        return true;
    }
    return false;
}

bool checkForDraw(char board[3][3])
{
    // true if there is a draw, else false
    int fill_count = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != '-')
            {
                fill_count++;
            }
        }
    }
    if (fill_count == 9)
    {
        return true;
    }
    return false;
}


void displayBoard(char board[3][3])
{
    /* Display the board
    
    X|X|X
    -----    
    X|X|X
    -----
    X|X|X

    */

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j];

            if (j != 2)
            {
                std::cout << '|';
            }
        }
        std::cout << '\n';
        if (i != 2)
        {
            std::cout << "-----\n";
        }
    }
}
