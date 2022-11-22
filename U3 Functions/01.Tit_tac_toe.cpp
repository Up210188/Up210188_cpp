#include <iostream>
#include <time.h>

using namespace std;

void ConstruirTablero();
int SeleccionarMove();
char AreaJuego[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void ConstruirTableroImaginario();
int Turnojugador = 1;
bool comprobarCasiilaOcupada(int Move);
bool comprobarCasiilaOcupadaImaginaria(int Move);
void remplazarCasilla(int Move);
void remplazarCasillaImaginario(int Move, char juador);
bool Ganar();
bool GanarImaginario(int Move);
int MejorMove(char jugador);
int TurnoPC();
char PC = 'O';
char HUMANO = 'X';
char Areadejuegoimaginario[3][3];
int main()
{
    int Move;
    bool casillaOcupada = true;
    bool ganador = false;
    int ModoDeJuego = 0;
    do{
    cout << "1-Single player"<<endl<< "2-Multiplayer "<<endl<<"Select game mode: ";
    cin >> ModoDeJuego;

    if (ModoDeJuego == 2)
    {
        ConstruirTablero();

        do
        {
            do
            {
                Move = SeleccionarMove();
                casillaOcupada = comprobarCasiilaOcupada(Move);
                if (casillaOcupada == true)
                {
                    cout << "otra vez ";
                }

            } while (casillaOcupada == true);

            if (casillaOcupada == false)
            {
                system("clear");
                remplazarCasilla(Move);
                ConstruirTablero();
                Turnojugador++;
            }

            ganador = Ganar();
            if (ganador == true)
            {
                cout << "CONGRATULATIONS THE PLAYER " << Turnojugador % 2 + 1 <<" WON "<< endl;
            }

            if (Turnojugador > 9)
            {
                cout << "IS A TIE" << endl;
                break;
            }

        } while (ganador == false);
    }
    /*--------------compu--------------------------------------------*/
    else if (ModoDeJuego == 1)
    {
        ConstruirTablero();

        do
        {
            do
            {
                if (Turnojugador % 2 != 0)
                {
                    Move = SeleccionarMove();
                }
                else
                {
                    Move = TurnoPC();
                }
                casillaOcupada = comprobarCasiilaOcupada(Move);
                if (casillaOcupada == true)
                {

                    cout << "AGAIN, ";
                }

            } while (casillaOcupada == true);

            if (casillaOcupada == false)
            {
                system("clear");
                remplazarCasilla(Move);
                ConstruirTablero();
                Turnojugador++;
            }

            ganador = Ganar();
            if (ganador == true)
            {
                cout << "CONGRATULATIONS THE PLAYER " << Turnojugador % 2 + 1 <<" WON "<< endl;
            }

            if (Turnojugador > 9)
            {
                cout << "IS A TIE" << endl;
                break;
            }

        } while (ganador == false);
    
    }

    else{
        cout<<"PLEASE SELECT THE GAME MODE"<<endl;
    }
    }while (ModoDeJuego!=1 && ModoDeJuego!=2);
     
    
     
    return 0;
}

void ConstruirTablero()
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

                    if (AreaJuego[x][y] == 'X')
                    {
                        cout << " "
                             << "\033[0;31m" << AreaJuego[x][y] << "\033[0m"
                             << " ";
                        y++;
                    }
                    else if (AreaJuego[x][y] == 'O')
                    {
                        cout << " "
                             << "\033[0;34m" << AreaJuego[x][y] << "\033[0m"
                             << " ";
                        y++;
                    }

                    else
                    {
                        cout << " " << AreaJuego[x][y] << " ";
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

int SeleccionarMove()
{
    int Move;
    do
    {
        cout << "GIVE ME THE PLAY:  ";
        cin >> Move;
    } while (Move < 1 && Move > 10);

    return Move;
}

bool comprobarCasiilaOcupada(int Move)
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

    if (AreaJuego[row][col] == 'X' || AreaJuego[row][col] == 'O')
    {
        return true; //  la casilla esta ocupada
    }
    else
    {
        return false;
    }
}

void remplazarCasilla(int Move)
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

    if (Turnojugador % 2 == 0)
    {
        AreaJuego[row][col] = 'O';
    }
    else
    {

        AreaJuego[row][col] = 'X';
    }
}

bool Ganar()
{
    if (AreaJuego[0][0] == AreaJuego[0][1] && AreaJuego[0][0] == AreaJuego[0][2] && AreaJuego[0][1] == AreaJuego[0][2])
    {
        return true;
    }
    else if (AreaJuego[1][0] == AreaJuego[1][1] && AreaJuego[1][0] == AreaJuego[1][2] && AreaJuego[1][1] == AreaJuego[1][2])
    {
        return true;
    }
    else if (AreaJuego[2][0] == AreaJuego[2][1] && AreaJuego[2][0] == AreaJuego[2][2] && AreaJuego[2][1] == AreaJuego[2][2])
    {
        return true;
    }
    else if (AreaJuego[0][0] == AreaJuego[1][0] && AreaJuego[0][0] == AreaJuego[2][0] && AreaJuego[1][0] == AreaJuego[2][0])
    {
        return true;
    }
    else if (AreaJuego[0][1] == AreaJuego[1][1] && AreaJuego[0][1] == AreaJuego[2][1] && AreaJuego[1][1] == AreaJuego[2][1])
    {
        return true;
    }
    else if (AreaJuego[0][2] == AreaJuego[1][2] && AreaJuego[0][2] == AreaJuego[2][2] && AreaJuego[1][2] == AreaJuego[2][2])
    {
        return true;
    }
    else if (AreaJuego[0][0] == AreaJuego[1][1] && AreaJuego[0][0] == AreaJuego[2][2] && AreaJuego[1][1] == AreaJuego[2][2])
    {
        return true;
    }
    else if (AreaJuego[0][2] == AreaJuego[1][1] && AreaJuego[0][2] == AreaJuego[2][0] && AreaJuego[1][1] == AreaJuego[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int TurnoPC()
{

    int Move;
    bool casillaocupada = false;
    Move = MejorMove(PC);
    if (Move != -1)
    {
        return Move;
    }

    Move = MejorMove(HUMANO);
    if (Move != -1)
    {
        return Move;
    }
    while (casillaocupada == false)
    {
        casillaocupada = comprobarCasiilaOcupada(Move);
        Move = 1 + rand() % 9; // En caso de que ninguno ni otro, aleatoria
    }
    return Move;
}

void ConstruirTableroImaginario()
{
    int x = 0, y = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            Areadejuegoimaginario[row][col] = AreaJuego[row][col];
        }
    }
}

bool comprobarCasiilaOcupadaImaginaria(int Move)
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

    if (Areadejuegoimaginario[row][col] == 'X' || Areadejuegoimaginario[row][col] == 'O')
    {
        return true; //  la casilla esta ocupada
    }
    else
    {
        return false;
    }
}

bool GanarImaginario(int Move)
{
    if (Areadejuegoimaginario[0][0] == Areadejuegoimaginario[0][1] && Areadejuegoimaginario[0][0] == Areadejuegoimaginario[0][2] && Areadejuegoimaginario[0][1] == Areadejuegoimaginario[0][2])
    {
        return true;
    }
    else if (Areadejuegoimaginario[1][0] == Areadejuegoimaginario[1][1] && Areadejuegoimaginario[1][0] == Areadejuegoimaginario[1][2] && Areadejuegoimaginario[1][1] == Areadejuegoimaginario[1][2])
    {
        return true;
    }
    else if (Areadejuegoimaginario[2][0] == Areadejuegoimaginario[2][1] && Areadejuegoimaginario[2][0] == Areadejuegoimaginario[2][2] && Areadejuegoimaginario[2][1] == Areadejuegoimaginario[2][2])
    {
        return true;
    }
    else if (Areadejuegoimaginario[0][0] == Areadejuegoimaginario[1][0] && Areadejuegoimaginario[0][0] == Areadejuegoimaginario[2][0] && Areadejuegoimaginario[1][0] == Areadejuegoimaginario[2][0])
    {
        return true;
    }
    else if (Areadejuegoimaginario[0][1] == Areadejuegoimaginario[1][1] && Areadejuegoimaginario[0][1] == Areadejuegoimaginario[2][1] && Areadejuegoimaginario[1][1] == Areadejuegoimaginario[2][1])
    {
        return true;
    }
    else if (Areadejuegoimaginario[0][2] == Areadejuegoimaginario[1][2] && Areadejuegoimaginario[0][2] == Areadejuegoimaginario[2][2] && Areadejuegoimaginario[1][2] == Areadejuegoimaginario[2][2])
    {
        return true;
    }
    else if (Areadejuegoimaginario[0][0] == Areadejuegoimaginario[1][1] && Areadejuegoimaginario[0][0] == Areadejuegoimaginario[2][2] && Areadejuegoimaginario[1][1] == Areadejuegoimaginario[2][2])
    {
        return true;
    }
    else if (Areadejuegoimaginario[0][2] == Areadejuegoimaginario[1][1] && Areadejuegoimaginario[0][2] == Areadejuegoimaginario[2][0] && Areadejuegoimaginario[1][1] == Areadejuegoimaginario[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void remplazarCasillaImaginario(int Move, char jugador)
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

    if (jugador == PC)
    {
        Areadejuegoimaginario[row][col] = 'O';
    }
    else
    {

        Areadejuegoimaginario[row][col] = 'X';
    }
}

int MejorMove(char jugador)
{
    bool Casillaocupada = false;
    bool Ganador = false;
    int MovePC = 0;

    ConstruirTableroImaginario();

    if (jugador == PC)
    {
        do
        {
            MovePC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(MovePC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(MovePC, PC);
                Ganador = GanarImaginario(MovePC);
            }
            ConstruirTableroImaginario();
        } while (MovePC <= 9 && Ganador == false);
    }

    else
    {
        do
        {
            MovePC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(MovePC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(MovePC, HUMANO);
                Ganador = GanarImaginario(MovePC);
            }
            ConstruirTableroImaginario();
        } while (MovePC <= 9 && Ganador == false);
    }
    if (MovePC >= 10)
    {
        MovePC = -1;
    }
    return MovePC;
}
