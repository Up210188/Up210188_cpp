/*
Date: 24/11/2022
Unidad:3
Author:Osvaldo Esparza Gutierrez
Email: up210188@alumnos.upa.edu.mx
Description:elaborate tic tac toe game

*/

#include <iostream>

using namespace std;

void buildBoard();
int selectPlay();
char playArea[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void buildImaginaryBoard();
int playerTurn = 1;
bool checkBusyBox(int Move);
bool checkImaginaryBusyBox(int Move);
void replaceBox(int Move);
void replaceImaginaryBox(int Move, char juador);
bool verifyWinner();
bool checkImaginaryWinner(int Move);
int selectBestPlay(char player);
int TurnPC();
char PC = 'O';
char Human = 'X';
char imaginaryPlayArea[3][3];
int main()
{
    int Move;
    bool occupiedBox = true;
    bool winner = false;
    int gameMode = 0;
    do
    {
        // Ask the game mode
        cout << "1-Single player" << endl
             << "2-Multiplayer " << endl
             << "Select game mode: ";
        cin >> gameMode;

        // multiplayer game

        if (gameMode == 2)
        {
            buildBoard();

            do
            {
                do
                {
                    Move = selectPlay();
                    occupiedBox = checkBusyBox(Move);
                    if (occupiedBox == true)
                    {
                        cout << "Again,";
                    }

                } while (occupiedBox == true);

                if (occupiedBox == false)
                {
                    system("clear");
                    replaceBox(Move);
                    buildBoard();
                    playerTurn++;
                }

                winner = verifyWinner();
                if (winner == true)
                {
                    cout << "CONGRATULATIONS THE PLAYER " << playerTurn % 2 + 1 << " WON " << endl;
                }

                if (playerTurn > 9)
                {
                    cout << "IS A TIE" << endl;
                    break;
                }

            } while (winner == false);
        }
        /*--------------PC--------------------------------------------*/

        // single game
        else if (gameMode == 1)
        {
            buildBoard();

            do
            {
                do
                {
                    if (playerTurn % 2 != 0)
                    {
                        Move = selectPlay();
                    }
                    else
                    {
                        Move = TurnPC();
                    }
                    occupiedBox = checkBusyBox(Move);
                    if (occupiedBox == true && playerTurn % 2 != 0)
                    {

                        cout << "AGAIN, ";
                    }

                } while (occupiedBox == true);

                if (occupiedBox == false)
                {
                    system("clear");
                    replaceBox(Move);
                    buildBoard();
                    playerTurn++;
                }

                winner = verifyWinner();
                if (winner == true)
                {
                    cout << "CONGRATULATIONS THE PLAYER " << playerTurn % 2 + 1 << " WON " << endl;
                }

                if (playerTurn > 9)
                {
                    cout << "IS A TIE" << endl;
                    break;
                }

            } while (winner == false);
        }
        // check game mode
        else
        {
            cout << "PLEASE SELECT THE GAME MODE" << endl;
        }
    } while (gameMode != 1 && gameMode != 2);

    return 0;
}

void buildBoard()
// build the board
{
    int x = 0, y = 0;
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row < 5 && row % 2 == 1)
            {

                cout << "___";
            }
            else
            {
                if (row < 5)
                {

                    if (playArea[x][y] == 'X')
                    {
                        cout << " "
                             << "\033[0;31m" << playArea[x][y] << "\033[0m"
                             << " ";
                        y++;
                    }
                    else if (playArea[x][y] == 'O')
                    {
                        cout << " "
                             << "\033[0;34m" << playArea[x][y] << "\033[0m"
                             << " ";
                        y++;
                    }

                    else
                    {
                        cout << " " << playArea[x][y] << " ";
                        y++;
                    }
                }

                else
                {
                    cout << "   ";
                }
            }

            if (col < 2)
            {
                cout << "|";
            }
        }
        y = 0;
        if (row % 2 == 0)
        {
            x++;
        }

        cout << endl;
    }
}

int selectPlay()

// ask for the play
{
    int Move;
    do
    {
        cout << "GIVE ME THE PLAY:  ";
        cin >> Move;
    } while (Move < 1 && Move > 10);

    return Move;
}

bool checkBusyBox(int Move)
// check that the move is valid
{
    int row = 0, col = 0;
    if (Move == 1)
    {
        row = 0;
        col = 0;
    }
    else if (Move == 2)
    {
        row = 0;
        col = 1;
    }
    else if (Move == 3)
    {
        row = 0;
        col = 2;
    }
    else if (Move == 4)
    {
        row = 1;
        col = 0;
    }
    else if (Move == 5)
    {
        row = 1;
        col = 1;
    }
    else if (Move == 6)
    {
        row = 1;
        col = 2;
    }
    else if (Move == 7)
    {
        row = 2;
        col = 0;
    }
    else if (Move == 8)
    {
        row = 2;
        col = 1;
    }
    else if (Move == 9)
    {
        row = 2;
        col = 2;
    }

    if (playArea[row][col] == 'X' || playArea[row][col] == 'O')
    {
        return true; // The box is occupied
    }
    else
    {
        return false;
    }
}

void replaceBox(int Move)
// place the play
{
    int row = 0, col = 0;
    if (Move == 1)
    {
        row = 0;
        col = 0;
    }
    else if (Move == 2)
    {
        row = 0;
        col = 1;
    }
    else if (Move == 3)
    {
        row = 0;
        col = 2;
    }
    else if (Move == 4)
    {
        row = 1;
        col = 0;
    }
    else if (Move == 5)
    {
        row = 1;
        col = 1;
    }
    else if (Move == 6)
    {
        row = 1;
        col = 2;
    }
    else if (Move == 7)
    {
        row = 2;
        col = 0;
    }
    else if (Move == 8)
    {
        row = 2;
        col = 1;
    }
    else if (Move == 9)
    {
        row = 2;
        col = 2;
    }

    if (playerTurn % 2 == 0)
    {
        playArea[row][col] = 'O';
    }
    else
    {

        playArea[row][col] = 'X';
    }
}

bool verifyWinner()
// check the winner
{
    if (playArea[0][0] == playArea[0][1] && playArea[0][0] == playArea[0][2] && playArea[0][1] == playArea[0][2])
    {
        return true;
    }
    else if (playArea[1][0] == playArea[1][1] && playArea[1][0] == playArea[1][2] && playArea[1][1] == playArea[1][2])
    {
        return true;
    }
    else if (playArea[2][0] == playArea[2][1] && playArea[2][0] == playArea[2][2] && playArea[2][1] == playArea[2][2])
    {
        return true;
    }
    else if (playArea[0][0] == playArea[1][0] && playArea[0][0] == playArea[2][0] && playArea[1][0] == playArea[2][0])
    {
        return true;
    }
    else if (playArea[0][1] == playArea[1][1] && playArea[0][1] == playArea[2][1] && playArea[1][1] == playArea[2][1])
    {
        return true;
    }
    else if (playArea[0][2] == playArea[1][2] && playArea[0][2] == playArea[2][2] && playArea[1][2] == playArea[2][2])
    {
        return true;
    }
    else if (playArea[0][0] == playArea[1][1] && playArea[0][0] == playArea[2][2] && playArea[1][1] == playArea[2][2])
    {
        return true;
    }
    else if (playArea[0][2] == playArea[1][1] && playArea[0][2] == playArea[2][0] && playArea[1][1] == playArea[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int TurnPC()
// does the turn of the pc
{

    int Move;
    bool occupiedBox = false;
    Move = selectBestPlay(PC);
    if (Move != -1)
    {
        return Move;
    }

    Move = selectBestPlay(Human);
    if (Move != -1)
    {
        return Move;
    }
    while (occupiedBox == false)
    {
        occupiedBox = checkBusyBox(Move);
        Move = 1 + rand() % 9; // Random number
    }
    return Move;
}

void buildImaginaryBoard()
{
    int x = 0, y = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            imaginaryPlayArea[row][col] = playArea[row][col];
        }
    }
}

bool checkImaginaryBusyBox(int Move)
{
    int row = 0, col = 0;
    if (Move == 1)
    {
        row = 0;
        col = 0;
    }
    else if (Move == 2)
    {
        row = 0;
        col = 1;
    }
    else if (Move == 3)
    {
        row = 0;
        col = 2;
    }
    else if (Move == 4)
    {
        row = 1;
        col = 0;
    }
    else if (Move == 5)
    {
        row = 1;
        col = 1;
    }
    else if (Move == 6)
    {
        row = 1;
        col = 2;
    }
    else if (Move == 7)
    {
        row = 2;
        col = 0;
    }
    else if (Move == 8)
    {
        row = 2;
        col = 1;
    }
    else if (Move == 9)
    {
        row = 2;
        col = 2;
    }

    if (imaginaryPlayArea[row][col] == 'X' || imaginaryPlayArea[row][col] == 'O')
    {
        return true; // The box is occupied
    }
    else
    {
        return false;
    }
}

bool checkImaginaryWinner(int Move)
// check the imaginary valid movement
{
    if (imaginaryPlayArea[0][0] == imaginaryPlayArea[0][1] && imaginaryPlayArea[0][0] == imaginaryPlayArea[0][2] && imaginaryPlayArea[0][1] == imaginaryPlayArea[0][2])
    {
        return true;
    }
    else if (imaginaryPlayArea[1][0] == imaginaryPlayArea[1][1] && imaginaryPlayArea[1][0] == imaginaryPlayArea[1][2] && imaginaryPlayArea[1][1] == imaginaryPlayArea[1][2])
    {
        return true;
    }
    else if (imaginaryPlayArea[2][0] == imaginaryPlayArea[2][1] && imaginaryPlayArea[2][0] == imaginaryPlayArea[2][2] && imaginaryPlayArea[2][1] == imaginaryPlayArea[2][2])
    {
        return true;
    }
    else if (imaginaryPlayArea[0][0] == imaginaryPlayArea[1][0] && imaginaryPlayArea[0][0] == imaginaryPlayArea[2][0] && imaginaryPlayArea[1][0] == imaginaryPlayArea[2][0])
    {
        return true;
    }
    else if (imaginaryPlayArea[0][1] == imaginaryPlayArea[1][1] && imaginaryPlayArea[0][1] == imaginaryPlayArea[2][1] && imaginaryPlayArea[1][1] == imaginaryPlayArea[2][1])
    {
        return true;
    }
    else if (imaginaryPlayArea[0][2] == imaginaryPlayArea[1][2] && imaginaryPlayArea[0][2] == imaginaryPlayArea[2][2] && imaginaryPlayArea[1][2] == imaginaryPlayArea[2][2])
    {
        return true;
    }
    else if (imaginaryPlayArea[0][0] == imaginaryPlayArea[1][1] && imaginaryPlayArea[0][0] == imaginaryPlayArea[2][2] && imaginaryPlayArea[1][1] == imaginaryPlayArea[2][2])
    {
        return true;
    }
    else if (imaginaryPlayArea[0][2] == imaginaryPlayArea[1][1] && imaginaryPlayArea[0][2] == imaginaryPlayArea[2][0] && imaginaryPlayArea[1][1] == imaginaryPlayArea[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void replaceImaginaryBox(int Move, char player)
// replaces the imaginary play
{
    int row = 0, col = 0;
    if (Move == 1)
    {
        row = 0;
        col = 0;
    }
    else if (Move == 2)
    {
        row = 0;
        col = 1;
    }
    else if (Move == 3)
    {
        row = 0;
        col = 2;
    }
    else if (Move == 4)
    {
        row = 1;
        col = 0;
    }
    else if (Move == 5)
    {
        row = 1;
        col = 1;
    }
    else if (Move == 6)
    {
        row = 1;
        col = 2;
    }
    else if (Move == 7)
    {
        row = 2;
        col = 0;
    }
    else if (Move == 8)
    {
        row = 2;
        col = 1;
    }
    else if (Move == 9)
    {
        row = 2;
        col = 2;
    }

    if (player == PC)
    {
        imaginaryPlayArea[row][col] = 'O';
    }
    else
    {

        imaginaryPlayArea[row][col] = 'X';
    }
}

int selectBestPlay(char player)
{
    bool occupiedBox = false;
    bool winner = false;
    int MovePC = 0;

    buildImaginaryBoard();

    // find the best play to win

    if (player == PC)
    {
        do
        {
            MovePC++;
            occupiedBox = checkImaginaryBusyBox(MovePC);
            if (occupiedBox == false)
            {
                replaceImaginaryBox(MovePC, PC);
                winner = checkImaginaryWinner(MovePC);
            }
            buildImaginaryBoard();
        } while (MovePC <= 9 && winner == false);
    }
    // look for the best move to not lose
    else
    {
        do
        {
            MovePC++;
            occupiedBox = checkImaginaryBusyBox(MovePC);
            if (occupiedBox == false)
            {
                replaceImaginaryBox(MovePC, Human);
                winner = checkImaginaryWinner(MovePC);
            }
            buildImaginaryBoard();
        } while (MovePC <= 9 && winner == false);
    }
    if (MovePC >= 10)
    {
        MovePC = -1;
    }
    return MovePC;
}
