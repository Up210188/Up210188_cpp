#include <iostream>
#include <time.h>

using namespace std;

void ConstruirTablero();
int SeleccionarJugada();
char AreaJuego[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void ConstruirTableroImaginario();
int Turnojugador = 1;
bool comprobarCasiilaOcupada(int jugada);
bool comprobarCasiilaOcupadaImaginaria(int jugada);
void remplazarCasilla(int jugada);
void remplazarCasillaImaginario(int jugada, char juador);
bool Ganar();
bool GanarImaginario(int jugada);
int MejorJugada(char jugador);
int TurnoPC();
char PC = 'O';
char HUMANO = 'X';
char Areadejuegoimaginario[3][3];
int main()
{
    int jugada;
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
                jugada = SeleccionarJugada();
                casillaOcupada = comprobarCasiilaOcupada(jugada);
                if (casillaOcupada == true)
                {
                    cout << "otra vez ";
                }

            } while (casillaOcupada == true);

            if (casillaOcupada == false)
            {
                system("clear");
                remplazarCasilla(jugada);
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
                    jugada = SeleccionarJugada();
                }
                else
                {
                    jugada = TurnoPC();
                }
                casillaOcupada = comprobarCasiilaOcupada(jugada);
                if (casillaOcupada == true)
                {

                    cout << "AGAIN, ";
                }

            } while (casillaOcupada == true);

            if (casillaOcupada == false)
            {
                system("clear");
                remplazarCasilla(jugada);
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

int SeleccionarJugada()
{
    int Jugada;
    do
    {
        cout << "GIVE ME THE PLAY:  ";
        cin >> Jugada;
    } while (Jugada < 1 && Jugada > 10);

    return Jugada;
}

bool comprobarCasiilaOcupada(int jugada)
{
    int row = 0, col = 0;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
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

void remplazarCasilla(int jugada)
{
    int row = 0, col = 0;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
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

    int Jugada;
    bool casillaocupada = false;
    Jugada = MejorJugada(PC);
    if (Jugada != -1)
    {
        return Jugada;
    }

    Jugada = MejorJugada(HUMANO);
    if (Jugada != -1)
    {
        return Jugada;
    }
    while (casillaocupada == false)
    {
        casillaocupada = comprobarCasiilaOcupada(Jugada);
        Jugada = 1 + rand() % 9; // En caso de que ninguno ni otro, aleatoria
    }
    return Jugada;
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

bool comprobarCasiilaOcupadaImaginaria(int jugada)
{
    int row = 0, col = 0;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
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

bool GanarImaginario(int jugada)
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

void remplazarCasillaImaginario(int jugada, char jugador)
{
    int row = 0, col = 0;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
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

int MejorJugada(char jugador)
{
    bool Casillaocupada = false;
    bool Ganador = false;
    int JugadaPC = 0;

    ConstruirTableroImaginario();

    if (jugador == PC)
    {
        do
        {
            JugadaPC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(JugadaPC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(JugadaPC, PC);
                Ganador = GanarImaginario(JugadaPC);
            }
            ConstruirTableroImaginario();
        } while (JugadaPC <= 9 && Ganador == false);
    }

    else
    {
        do
        {
            JugadaPC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(JugadaPC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(JugadaPC, HUMANO);
                Ganador = GanarImaginario(JugadaPC);
            }
            ConstruirTableroImaginario();
        } while (JugadaPC <= 9 && Ganador == false);
    }
    if (JugadaPC >= 10)
    {
        JugadaPC = -1;
    }
    return JugadaPC;
}
