/*
Date:
Authors: Enrique Abel Herrera Vargas
         Angel de Jesús Martínez Guevara
         Osvaldo Esparza Gutierrez
Emails: up210894@alumnos.upa.edu.mx
        up210553@alumnos.upa.edu.mx
        up210188@alumnos.upa.edu.mx
Description:
-----Problem-----
*/

#include <iostream>
#include <unistd.h>
#include <stdalign.h>
#include <time.h>

// Namespace avoid using std:: on all input and output
using namespace std;

//-----------MAIN FUNTION---------
void gotoxy(int x, int y);
void menu();
void tablero();
// void imprimirtablero();
bool preguntardondecolocarjugada();
int orientacioncolocarjugada();
bool comprobarsilaorientacionesvalida(int orientacion);
void colocarbarco(int orintacion);
void elegirbarcos();
bool comprobarsieltamanodelbarcoesvalido();
bool comprobarsilascasillasestanocupadas(int orientacion);
void conteobarcos();
bool permitirbarco();
void CrearTablero();
void tableroJ1();
void definirorientacionJ1();
void definirpocicionJ1();
bool comprobarsilascasillasestanocupadasJ1();
void colocarbarcoJ1();
void ataqueinteligente();

// Jugador 2
void tableroJ2();
void definirorientacionJ2();
void definirpocicionJ2();
bool comprobarsilascasillasestanocupadasJ2();
void colocarbarcoJ2();
bool atacarBarcos();
void preguntardondeatacar();
bool generarnumeroataque();
void decirquebarcotiraste();

int matriz[10][10];
int matrizJ1[10][10];
int tamanodelbarcoJ1[5] = {2, 3, 3, 4, 5};
int matrizJ2[10][10];
int tamanodelbarcoJ2[5] = {2, 3, 3, 4, 5};
int y, x;
int yJ1, xJ1;
int yJ2, xJ2;
int t = 2;
int t1;
int numerodebarcos = 5;
int numerodebarcosJ1 = 5;
int numerodebarcosJ2 = 5;
int numerodebarcosvivos = 17;
int numerodebarcosvivosJ1 = 17;
int numerodebarcosvivosJ2 = 17;
int barcos2 = 1;
int barcos3 = 2;
int barcos4 = 1;
int barcos5 = 1;
int ya;
int x1;
int turno = 1;
int orientacionJ1;
int pociciontamanoJ1 = 0;
int orientacionJ2;
int pociciontamanoJ2 = 0;
int turnodejugador = 1;
int xatacar;
int yatacar;
bool golpeobarco;
int numerodetablero;
bool permitirAleatorio = true;
int direccionamiento = 1;
bool inteligencia = false;
int xg, yg;
int mododejuego;
int limitedetres = 1;

int main()
{
    int orientacion;
    bool comprobar;
    bool existejugada;
    bool existebarco;
    bool desocupada;
    bool permitir;
    bool desocupadaJ1;
    bool desocupadaJ2;

    
    do
    {
        menu();
        system("clear");
        // Eleccion de barcos jugador
        if (mododejuego == 1)
        {
            do
            {
                numerodetablero = 3;
                // Pruebas J1
                // cout << tamanodelbarcoJ1[pociciontamanoJ1];
                // definirorientacionJ1();
                // definirpocicionJ1();
                // cout << "h" << xJ1 <<yJ1;
                // comprobarsilascasillasestanocupadasJ1();
                // colocarbarcoJ1();
                // tableroJ1();
                // CrearTablero();

                tablero();
                cout << endl;
                cout << endl;
                cout << "\033[1;31m"
                     << "ＰＬＡＹＥＲ  ＢＯＡＲＤ"
                     << "\033[0m" << endl;
                CrearTablero();
                elegirbarcos();
                existebarco = comprobarsieltamanodelbarcoesvalido();
                if (existebarco == true)
                {
                    permitir = permitirbarco();
                    if (permitir == true)
                    {
                        existejugada = preguntardondecolocarjugada();
                        if (existejugada == true)
                        {
                            orientacion = orientacioncolocarjugada();
                            comprobar = comprobarsilaorientacionesvalida(orientacion);
                            if (comprobar == true)
                            {
                                desocupada = comprobarsilascasillasestanocupadas(orientacion);
                                if (desocupada == true)
                                {
                                    colocarbarco(orientacion);
                                    conteobarcos();
                                }
                            }
                        }
                    }
                }
                system("clear");
            } while (numerodebarcos > 0);
            // imprimirtablero();
            cout << endl;
            cout << endl;
            cout << "\033[1;31m"
                 << "ＰＬＡＹＥＲ  ＢＯＡＲＤ"
                 << "\033[0m" << endl;
            CrearTablero();
            numerodetablero = 2;
            do
            {

                definirorientacionJ2();
                definirpocicionJ2();
                desocupadaJ2 = comprobarsilascasillasestanocupadasJ2();
                if (desocupadaJ2 == true)
                {
                    colocarbarcoJ2();
                    pociciontamanoJ2++;
                }
            } while (numerodebarcosJ2 > 0);
            tableroJ2();
            cout << endl;
            cout << endl;
            cout << "\033[1;34m"
                 << "ＰＣ ＢＯＡＲＤ"
                 << "\033[0m" << endl;
            cout << endl;
            CrearTablero();

            do
            {
                if (turnodejugador == 1)
                {
                    preguntardondeatacar();
                    golpeobarco = atacarBarcos();
                    if (golpeobarco == true)
                    {
                        turnodejugador = 1;
                    }
                    else
                    {
                        turnodejugador = 2;
                    }
                }
                else
                {
                    if (permitirAleatorio == true)
                    {
                        inteligencia = generarnumeroataque();
                    }
                    else
                    {
                        turnodejugador = 1;
                    }

                    if (inteligencia == true)
                    {
                        xg = xatacar;
                        yg = yatacar;
                        ataqueinteligente();
                    }
                    else
                    {
                        turnodejugador = 1;
                    }
                }
                system("clear");
                numerodetablero = 3;
                cout << endl;
                cout << endl;
                cout << "\033[1;31m"
                     << "ＰＬＡＹＥＲ  ＢＯＡＲＤ"
                     << "\033[0m" << endl;
                cout << endl;
                CrearTablero();
                numerodetablero = 2;
                cout << endl;
                cout << endl;
                cout << "\033[1;34m"
                     << "ＰＣ ＢＯＡＲＤ"
                     << "\033[0m" << endl;
                cout << endl;
                CrearTablero();

            } while (numerodebarcosvivos > 0 && numerodebarcosvivosJ2 > 0);
            system("clear");
            if (numerodebarcosvivos < numerodebarcosvivosJ2)
            {
                
                gotoxy(5, 32);
                cout << "\033[0;34m"<<"██╗░░░██╗░█████╗░██╗░░░██╗  ██╗░░░░░░█████╗░░██████╗███████╗"<< "\033[0m" << endl;
                gotoxy(5, 33);
                cout << "\033[0;34m"<<"╚██╗░██╔╝██╔══██╗██║░░░██║  ██║░░░░░██╔══██╗██╔════╝██╔════╝"<< "\033[0m" << endl;
                gotoxy(5, 34);
                cout << "\033[0;34m"<<"░╚████╔╝░██║░░██║██║░░░██║  ██║░░░░░██║░░██║╚█████╗░█████╗░░"<< "\033[0m" << endl;
                gotoxy(5, 35);
                cout << "\033[0;34m"<<"░░╚██╔╝░░██║░░██║██║░░░██║  ██║░░░░░██║░░██║░╚═══██╗██╔══╝░░"<< "\033[0m" << endl;
                gotoxy(5, 36);
                cout << "\033[0;34m"<<"░░░██║░░░╚█████╔╝╚██████╔╝  ███████╗╚█████╔╝██████╔╝███████╗"<< "\033[0m" << endl;
                gotoxy(5, 37);
                cout << "\033[0;34m"<<"░░░╚═╝░░░░╚════╝░░╚═════╝░  ╚══════╝░╚════╝░╚═════╝░╚══════╝"<< "\033[0m" << endl;

                gotoxy(7, 38);
                cout << "              ()" << endl;
                gotoxy(7, 39);
                cout << "              ||" << endl;
                gotoxy(7, 40);
                cout << "              ||" << endl;
                gotoxy(7, 41);
                cout << "   (,---------------------,)" << endl;
                cout << "          ',       "
                     << "\033[1;32m"
                     << "q888p"
                     << "\033[0m"
                     << "       ,'" << endl;
                gotoxy(7, 42);
                cout << "      )       "
                     << "\033[1;32m"
                     << "986"
                     << "\033[0m"
                     << "       (" << endl;
                gotoxy(7, 43);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8p, d8b ,q8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 44);
                cout << "        )"
                     << "\033[1;32m"
                     << " 888a888a888"
                     << "\033[0m"
                     << " (" << endl;
                gotoxy(7, 45);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8b` q8p `d8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 46);
                cout << "      ) "
                     << "\033[1;32m"
                     << "      689 "
                     << "\033[0m"
                     << "      (  " << endl;
                gotoxy(7, 47);
                cout << "     ) "
                     << "\033[1;32m"
                     << "      d888b "
                     << "\033[0m"
                     << "      ( " << endl;
                gotoxy(7, 48);
                cout << "   ,'_____________________'," << endl;
                gotoxy(7, 49);
                cout << "   (`__________L|_________`)" << endl;
                gotoxy(7, 50);
                cout << "   [___________|___________]" << endl;
                gotoxy(7, 51);
                cout << "\033[0;31m"
                     << "     }:::|:::::}::|::::::{ " << endl;
                gotoxy(7, 52);
                cout << "\033[0;31m"
                     << "      '|::::}::|:::::{:|' " << endl;
                gotoxy(7, 53);
                cout << "\033[0;31m"
                     << "       '|}:::::|::{:::|'" << endl;
                gotoxy(7, 54);
                cout << "\033[0;31m"
                     << "         '|:}::|::::|'" << endl;
                gotoxy(7, 55);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
                gotoxy(7, 56);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
            }

            else {
                    gotoxy(3, 25);
                cout << "\033[0;33m"
                     << "░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗"
                     << "\033[0m" << endl;
                gotoxy(3, 26);
                cout << "\033[0;33m"
                     << "██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝"
                     << "\033[0m" << endl;
                gotoxy(3, 27);
                cout << "\033[0;33m"
                     << "██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░"
                     << "\033[0m" << endl;
                gotoxy(3, 28);
                cout << "\033[0;33m"
                     << "██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗"
                     << "\033[0m" << endl;
                gotoxy(3, 29);
                cout << "\033[0;33m"
                     << "╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝"
                     << "\033[0m" << endl;
                gotoxy(3, 30);
                cout << "\033[0;33m"
                     << "░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░"
                     << "\033[0m" << endl;

                gotoxy(5, 32);
                cout << "\033[0;31m"<<" ██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗"<< "\033[0m" << endl;
                gotoxy(5, 33);
                cout << "\033[0;31m"<<" ╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║"<< "\033[0m" << endl;
                gotoxy(5, 34);
                cout << "\033[0;31m"<<" ░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║"<< "\033[0m" << endl;
                gotoxy(5, 35);
                cout << "\033[0;31m"<<" ░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║"<< "\033[0m" << endl;
                gotoxy(5, 36);
                cout << "\033[0;31m"<<" ░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║"<< "\033[0m" << endl;
                gotoxy(5, 37);
                cout << "\033[0;31m"<<" ░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝"<< "\033[0m" << endl;
                gotoxy(7, 38);
                cout << "              ()" << endl;
                gotoxy(7, 39);
                cout << "              ||" << endl;
                gotoxy(7, 40);
                cout << "              ||" << endl;
                gotoxy(7, 41);
                cout << "   (,---------------------,)" << endl;
                cout << "          ',       "
                     << "\033[1;32m"
                     << "q888p"
                     << "\033[0m"
                     << "       ,'" << endl;
                gotoxy(7, 42);
                cout << "      )       "
                     << "\033[1;32m"
                     << "986"
                     << "\033[0m"
                     << "       (" << endl;
                gotoxy(7, 43);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8p, d8b ,q8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 44);
                cout << "        )"
                     << "\033[1;32m"
                     << " 888a888a888"
                     << "\033[0m"
                     << " (" << endl;
                gotoxy(7, 45);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8b` q8p `d8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 46);
                cout << "      ) "
                     << "\033[1;32m"
                     << "      689 "
                     << "\033[0m"
                     << "      (  " << endl;
                gotoxy(7, 47);
                cout << "     ) "
                     << "\033[1;32m"
                     << "      d888b "
                     << "\033[0m"
                     << "      ( " << endl;
                gotoxy(7, 48);
                cout << "   ,'_____________________'," << endl;
                gotoxy(7, 49);
                cout << "   (`__________L|_________`)" << endl;
                gotoxy(7, 50);
                cout << "   [___________|___________]" << endl;
                gotoxy(7, 51);
                cout << "\033[0;31m"
                     << "     }:::|:::::}::|::::::{ " << endl;
                gotoxy(7, 52);
                cout << "\033[0;31m"
                     << "      '|::::}::|:::::{:|' " << endl;
                gotoxy(7, 53);
                cout << "\033[0;31m"
                     << "       '|}:::::|::{:::|'" << endl;
                gotoxy(7, 54);
                cout << "\033[0;31m"
                     << "         '|:}::|::::|'" << endl;
                gotoxy(7, 55);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
                gotoxy(7, 56);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
            }
        }
        else if (mododejuego == 2)
        {
            turno = 2;
            numerodetablero = 1;

            // Crear tablero J1
            do
            {

                definirorientacionJ1();
                definirpocicionJ1();
                desocupadaJ1 = comprobarsilascasillasestanocupadasJ1();
                if (desocupadaJ1 == true)
                {
                    colocarbarcoJ1();
                    pociciontamanoJ1++;
                }
            } while (numerodebarcosJ1 > 0);
            tableroJ1();
            cout << endl;
            cout << endl;
            cout << "\033[1;34m"
                 << "ＰＬＡＹＥＲ １ ＢＯＡＲＤ"
                 << "\033[0m" << endl;
            cout << endl;
            CrearTablero();
            turnodejugador = 2;
            numerodetablero = 2;

            // crear tablero 2
            do
            {

                definirorientacionJ2();
                definirpocicionJ2();
                desocupadaJ2 = comprobarsilascasillasestanocupadasJ2();
                if (desocupadaJ2 == true)
                {
                    colocarbarcoJ2();
                    pociciontamanoJ2++;
                }
            } while (numerodebarcosJ2 > 0);
            tableroJ2();
            cout << endl;
            cout << endl;
            cout << "\033[1;31m"
                 << "ＰＬＡＹＥＲ ２ ＢＯＡＲＤ"
                 << "\033[0m" << endl;
            cout << endl;
            CrearTablero();
            turnodejugador = 1;
            do
            {
                if (turnodejugador == 1)
                {
                    preguntardondeatacar();
                    golpeobarco = atacarBarcos();
                    if (golpeobarco == true)
                    {
                        turnodejugador = 1;
                    }
                    else
                    {
                        turnodejugador = 2;
                    }
                }
                else
                {
                    preguntardondeatacar();
                    golpeobarco = atacarBarcos();
                    if (golpeobarco == true)
                    {
                        turnodejugador = 2;
                    }
                    else
                    {
                        turnodejugador = 1;
                    }
                }
                system("clear");
                numerodetablero = 1;
                cout << endl;
                cout << endl;
                cout << "\033[1;34m"
                     << "ＰＬＡＹＥＲ １ ＢＯＡＲＤ"
                     << "\033[0m" << endl;
                cout << endl;
                CrearTablero();
                numerodetablero = 2;
                cout << endl;
                cout << endl;
                cout << "\033[1;31m"
                     << "ＰＬＡＹＥＲ ２ ＢＯＡＲＤ"
                     << "\033[0m" << endl;
                cout << endl;
                CrearTablero();
                decirquebarcotiraste();
            } while (numerodebarcosvivosJ1 > 0 && numerodebarcosvivosJ2 > 0);
            system("clear");
            if (numerodebarcosvivosJ1 < numerodebarcosvivosJ2)
            {
                cout << endl;

                gotoxy(3, 25);
                cout << "\033[0;33m"
                     << "░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗"
                     << "\033[0m" << endl;
                gotoxy(3, 26);
                cout << "\033[0;33m"
                     << "██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝"
                     << "\033[0m" << endl;
                gotoxy(3, 27);
                cout << "\033[0;33m"
                     << "██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░"
                     << "\033[0m" << endl;
                gotoxy(3, 28);
                cout << "\033[0;33m"
                     << "██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗"
                     << "\033[0m" << endl;
                gotoxy(3, 29);
                cout << "\033[0;33m"
                     << "╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝"
                     << "\033[0m" << endl;
                gotoxy(3, 30);
                cout << "\033[0;33m"
                     << "░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░"
                     << "\033[0m" << endl;

                gotoxy(5, 32);
                cout << "\033[0;31m"
                     << "██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░  ██████╗░  ░██╗░░░░░░░██╗██╗███╗░░██╗░██████╗"
                     << "\033[0m" << endl;
                gotoxy(5, 33);
                cout << "\033[0;31m"
                     << "██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗  ╚════██╗  ░██║░░██╗░░██║██║████╗░██║██╔════╝"
                     << "\033[0m" << endl;
                gotoxy(5, 34);
                cout << "\033[0;31m"
                     << "██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝  ░░███╔═╝  ░╚██╗████╗██╔╝██║██╔██╗██║╚█████╗░"
                     << "\033[0m" << endl;
                gotoxy(5, 35);
                cout << "\033[0;31m"
                     << "██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗  ██╔══╝░░  ░░████╔═████║░██║██║╚████║░╚═══██╗"
                     << "\033[0m" << endl;
                gotoxy(5, 36);
                cout << "\033[0;31m"
                     << "██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║  ███████╗  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██████╔╝"
                     << "\033[0m" << endl;
                gotoxy(5, 37);
                cout << "\033[0;31m"
                     << "╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ╚══════╝  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░"
                     << "\033[0m" << endl;

                gotoxy(7, 38);
                cout << "              ()" << endl;
                gotoxy(7, 39);
                cout << "              ||" << endl;
                gotoxy(7, 40);
                cout << "              ||" << endl;
                gotoxy(7, 41);
                cout << "   (,---------------------,)" << endl;
                cout << "          ',       "
                     << "\033[1;32m"
                     << "q888p"
                     << "\033[0m"
                     << "       ,'" << endl;
                gotoxy(7, 42);
                cout << "      )       "
                     << "\033[1;32m"
                     << "986"
                     << "\033[0m"
                     << "       (" << endl;
                gotoxy(7, 43);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8p, d8b ,q8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 44);
                cout << "        )"
                     << "\033[1;32m"
                     << " 888a888a888"
                     << "\033[0m"
                     << " (" << endl;
                gotoxy(7, 45);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8b` q8p `d8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 46);
                cout << "      ) "
                     << "\033[1;32m"
                     << "      689 "
                     << "\033[0m"
                     << "      (  " << endl;
                gotoxy(7, 47);
                cout << "     ) "
                     << "\033[1;32m"
                     << "      d888b "
                     << "\033[0m"
                     << "      ( " << endl;
                gotoxy(7, 48);
                cout << "   ,'_____________________'," << endl;
                gotoxy(7, 49);
                cout << "   (`__________L|_________`)" << endl;
                gotoxy(7, 50);
                cout << "   [___________|___________]" << endl;
                gotoxy(7, 51);
                cout << "\033[0;31m"
                     << "     }:::|:::::}::|::::::{ " << endl;
                gotoxy(7, 52);
                cout << "\033[0;31m"
                     << "      '|::::}::|:::::{:|' " << endl;
                gotoxy(7, 53);
                cout << "\033[0;31m"
                     << "       '|}:::::|::{:::|'" << endl;
                gotoxy(7, 54);
                cout << "\033[0;31m"
                     << "         '|:}::|::::|'" << endl;
                gotoxy(7, 55);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
                gotoxy(7, 56);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
            }
            else
            {

                gotoxy(3, 25);
                cout << "\033[0;33m"
                     << "░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗██╗░░░██╗██╗░░░░░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗"
                     << "\033[0m" << endl;
                gotoxy(3, 26);
                cout << "\033[0;33m"
                     << "██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝"
                     << "\033[0m" << endl;
                gotoxy(3, 27);
                cout << "\033[0;33m"
                     << "██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░██║░░░██║██║░░░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░"
                     << "\033[0m" << endl;
                gotoxy(3, 28);
                cout << "\033[0;33m"
                     << "██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗"
                     << "\033[0m" << endl;
                gotoxy(3, 29);
                cout << "\033[0;33m"
                     << "╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░╚██████╔╝███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝"
                     << "\033[0m" << endl;
                gotoxy(3, 30);
                cout << "\033[0;33m"
                     << "░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░"
                     << "\033[0m" << endl;
                gotoxy(5, 32);
                cout << "\033[0;34m"
                     << "██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░  ░░███╗░░  ░██╗░░░░░░░██╗██╗███╗░░██╗░██████╗"
                     << "\033[0m" << endl;
                gotoxy(5, 33);
                cout << "\033[0;34m"
                     << "██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗  ░████║░░  ░██║░░██╗░░██║██║████╗░██║██╔════╝"
                     << "\033[0m" << endl;
                gotoxy(5, 34);
                cout << "\033[0;34m"
                     << "██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝  ██╔██║░░  ░╚██╗████╗██╔╝██║██╔██╗██║╚█████╗░"
                     << "\033[0m" << endl;
                gotoxy(5, 35);
                cout << "\033[0;34m"
                     << "██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗  ╚═╝██║░░  ░░████╔═████║░██║██║╚████║░╚═══██╗"
                     << "\033[0m" << endl;
                gotoxy(5, 36);
                cout << "\033[0;34m"
                     << "██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║  ███████╗  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██████╔╝"
                     << "\033[0m" << endl;
                gotoxy(5, 37);
                cout << "\033[0;34m"
                     << "╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ╚══════╝  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░"
                     << "\033[0m" << endl;

                gotoxy(7, 38);
                cout << "              ()" << endl;
                gotoxy(7, 39);
                cout << "              ||" << endl;
                gotoxy(7, 40);
                cout << "              ||" << endl;
                gotoxy(7, 41);
                cout << "   (,---------------------,)" << endl;
                cout << "          ',       "
                     << "\033[1;32m"
                     << "q888p"
                     << "\033[0m"
                     << "       ,'" << endl;
                gotoxy(7, 42);
                cout << "      )       "
                     << "\033[1;32m"
                     << "986"
                     << "\033[0m"
                     << "       (" << endl;
                gotoxy(7, 43);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8p, d8b ,q8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 44);
                cout << "        )"
                     << "\033[1;32m"
                     << " 888a888a888"
                     << "\033[0m"
                     << " (" << endl;
                gotoxy(7, 45);
                cout << "       )"
                     << "\033[1;32m"
                     << "  8b` q8p `d8"
                     << "\033[0m"
                     << "  (" << endl;
                gotoxy(7, 46);
                cout << "      ) "
                     << "\033[1;32m"
                     << "      689 "
                     << "\033[0m"
                     << "      (  " << endl;
                gotoxy(7, 47);
                cout << "     ) "
                     << "\033[1;32m"
                     << "      d888b "
                     << "\033[0m"
                     << "      ( " << endl;
                gotoxy(7, 48);
                cout << "   ,'_____________________'," << endl;
                gotoxy(7, 49);
                cout << "   (`__________L|_________`)" << endl;
                gotoxy(7, 50);
                cout << "   [___________|___________]" << endl;
                gotoxy(7, 51);
                cout << "\033[0;31m"
                     << "     }:::|:::::}::|::::::{ " << endl;
                gotoxy(7, 52);
                cout << "\033[0;31m"
                     << "      '|::::}::|:::::{:|' " << endl;
                gotoxy(7, 53);
                cout << "\033[0;31m"
                     << "       '|}:::::|::{:::|'" << endl;
                gotoxy(7, 54);
                cout << "\033[0;31m"
                     << "         '|:}::|::::|'" << endl;
                gotoxy(7, 55);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
                gotoxy(7, 56);
                cout << "\033[0;34m"
                     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
                     << "\033[0m" << endl;
            }
        }

        else
        {
            cout << "PEMEX" << endl;
        }
    } while (mododejuego != 2 && mododejuego != 1);
    return 0;
}

void tablero()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matriz[i][j] != 2 && matriz[i][j] != 3 && matriz[i][j] != 9 && matriz[i][j] != 4 && matriz[i][j] != 5)
            {
                matriz[i][j] = 1;
            }
        }
    }
}

void CrearTablero()
{
    int x = 0;
    int y = 0;

    for (int row = 0; row < 23; row++)
    {
        for (int col = 0; col < 23; col++)
        {
            if (row % 2 == 0)
            {
                if (col % 2 == 0)
                {

                    cout << "\033[0;34m"
                         << "+"
                         << "\033[0m";
                }

                else
                {
                    cout << "\033[0;34m"
                         << "---"
                         << "\033[0m";
                }
            }
            else
            {
                if (col % 2 == 0)
                {

                    cout << "\033[0;34m"
                         << "|"
                         << "\033[0m";
                }
                else if (row == 1 && col == 1)
                {
                    cout << "\033[1;32m"
                         << " X "
                         << "\033[0m";
                }

                else if (row == 1 && col == 3)
                {
                    cout << "\033[1;33m"
                         << " 1 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 5)
                {
                    cout << "\033[1;33m"
                         << " 2 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 7)
                {
                    cout << "\033[1;33m"
                         << " 3 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 9)
                {
                    cout << "\033[1;33m"
                         << " 4 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 11)
                {
                    cout << "\033[1;33m"
                         << " 5 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 13)
                {
                    cout << "\033[1;33m"
                         << " 6 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 15)
                {
                    cout << "\033[1;33m"
                         << " 7 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 17)
                {
                    cout << "\033[1;33m"
                         << " 8 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 19)
                {
                    cout << "\033[1;33m"
                         << " 9 "
                         << "\033[0m";
                }
                else if (row == 1 && col == 21)
                {
                    cout << "\033[1;33m"
                         << " 10"
                         << "\033[0m";
                }
                else if (row == 3 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " A "
                         << "\033[0m";
                }
                else if (row == 5 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " B "
                         << "\033[0m";
                }
                else if (row == 7 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " C "
                         << "\033[0m";
                }
                else if (row == 9 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " D "
                         << "\033[0m";
                }
                else if (row == 11 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " E "
                         << "\033[0m";
                }
                else if (row == 13 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " F "
                         << "\033[0m";
                }
                else if (row == 15 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " G "
                         << "\033[0m";
                }
                else if (row == 17 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " H ";
                }
                else if (row == 19 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " I "
                         << "\033[0m";
                }
                else if (row == 21 && col == 1)
                {
                    cout << "\033[1;33m"
                         << " J "
                         << "\033[0m";
                }

                else
                {
                    if (numerodetablero == 3)
                    {
                        cout << " " << matriz[x][y] << " ";
                        //}
                        x++;
                        if (x == 10)
                        {
                            y++;
                            x = 0;
                        }
                    }
                    else
                    {
                        // if(matrizJ1[x][y] == 0){
                        // cout<<" o ";
                        //}
                        // else{
                        if (numerodetablero == 1)
                        {

                            cout << " " << matrizJ1[x][y] << " ";
                            //}
                            x++;
                            if (x == 10)
                            {
                                y++;
                                x = 0;
                            }
                        }

                        else
                        {
                            cout << " " << matrizJ2[x][y] << " ";
                            //}
                            x++;
                            if (x == 10)
                            {
                                y++;
                                x = 0;
                            }
                        }
                    }
                }
            }
        }

        cout << endl;
    }
}

void elegirbarcos()
{
    gotoxy(60,10);
    cout << "\033[1;31m"<< "𝘗𝘓𝘈𝘊𝘌 𝘠𝘖𝘜𝘙 𝘚𝘏𝘐𝘗𝘚" << "\033[0m"<< endl;
    gotoxy(60,11);
    cout << barcos2 << "\033[0;37m"<< "  𝑩𝑶𝑨𝑻 𝑺𝑰𝒁𝑬 𝑻𝑾𝑶"<< "\033[0m" << endl;
    gotoxy(60,12);
    cout << barcos3 << "\033[0;37m"<< "  𝑩𝑶𝑨𝑻 𝑶𝑭 𝑺𝑰𝒁𝑬 𝑻𝑯𝑹𝑬𝑬"<< "\033[0m" << endl;
    gotoxy(60,13);
    cout << barcos4 << "\033[0;37m"<< "  𝑩𝑶𝑨𝑻 𝑶𝑭 𝑺𝑰𝒁𝑬 𝑭𝑶𝑼𝑹" << "\033[0m"<< endl;
    gotoxy(60,14);
    cout << barcos5 << "\033[0;37m"<< "  𝑩𝑶𝑨𝑻 𝑶𝑭 𝑺𝑰𝒁𝑬 𝑭𝑰𝑽𝑬" << "\033[0m"<< endl;

    gotoxy(60,16);
    cout << "\033[1;33m"<< "𝘌𝘕𝘛𝘌𝘙 𝘛𝘏𝘌 𝘚𝘐𝘡𝘌 𝘖𝘍 𝘛𝘏𝘌 𝘉𝘖𝘈𝘛:"<< "\033[0m" ;
    gotoxy(90,16);
    cin >> t;
    t1 = t;
}

bool comprobarsieltamanodelbarcoesvalido()
{
    if (t != 2 && t != 3 && t != 4 && t != 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool permitirbarco()
{
    if (t == 2)
    {
        if (barcos2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (t == 3)
    {
        if (barcos3 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (t == 4)
    {
        if (barcos4 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (t == 5)
    {
        if (barcos5 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

bool preguntardondecolocarjugada()
{
    char letra;
    gotoxy(60,17);
    cout << "\033[1;37m"
         << "𝐶𝐻𝑂𝑂𝑆𝐸 𝐴 𝑁𝑈𝑀𝐵𝐸𝑅: "
         << "\033[0m";
    gotoxy(80,17);
    cin >> x;
    gotoxy(60,18);
    cout << "\033[1;37m"
         << "𝐶𝐻𝑂𝑂𝑆𝐸 𝐴 𝐿𝐸𝑇𝑇𝐸𝑅: "
         << "\033[0m";
    gotoxy(80,18);
    cin >> letra;
    if (letra == 'A' || letra == 'a')
    {
        y = 0;
    }
    else if (letra == 'B' || letra == 'b')
    {
        y = 1;
    }
    else if (letra == 'C' || letra == 'c')
    {
        y = 2;
    }
    else if (letra == 'D' || letra == 'd')
    {
        y = 3;
    }
    else if (letra == 'E' || letra == 'e')
    {
        y = 4;
    }
    else if (letra == 'F' || letra == 'f')
    {
        y = 5;
    }
    else if (letra == 'G' || letra == 'g')
    {
        y = 6;
    }
    else if (letra == 'H' || letra == 'h')
    {
        y = 7;
    }
    else if (letra == 'I' || letra == 'i')
    {
        y = 8;
    }
    else if (letra == 'J' || letra == 'j')
    {
        y = 9;
    }
    else
    {
        y = 10;
    }
    x = x - 1;
    if (x < 10 && x >= 0 && y < 10 && y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int orientacioncolocarjugada()
{
    int orientacion;
    gotoxy(60,20);
    cout << "\033[1;31m"<< "𝑂𝑅𝐼𝐸𝑁𝑇𝐴𝑇𝐼𝑂𝑁"<< "\033[0m" << endl;
    gotoxy(60,21);
    cout << "\033[0;37m"<<"1=𝑼𝑷"<< "\033[0m" << endl;
    gotoxy(60,22);
    cout << "\033[0;37m"<< "2=𝑫𝑶𝑾𝑵"<< "\033[0m" << endl;
    gotoxy(60,23);
    cout << "\033[0;37m"<< "3=𝑹𝑰𝑮𝑯𝑻"<< "\033[0m" << endl;
    gotoxy(60,24);
    cout << "\033[0;37m"<< "4=𝑳𝑬𝑭𝑻"<< "\033[0m" << endl;
    gotoxy(60,25);
    cout<< "\033[1;33m"<< "𝐸𝑁𝑇𝐸𝑅 𝑇𝐻𝐸 𝑂𝑅𝐼𝐸𝑁𝑇𝐴𝑇𝐼𝑂𝑁: "<< "\033[0m" ;
    gotoxy(84,25);
    cin >> orientacion;
    return orientacion;
}

bool comprobarsilaorientacionesvalida(int orientacion)
{
    int comprobar;
    if (orientacion == 1)
    {
        comprobar = y - t;
        if (comprobar >= -1)
        {
            ya = comprobar;
            x1 = x;
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (orientacion == 2)
    {
        comprobar = y + t;
        if (comprobar <= 10)
        {
            ya = comprobar;
            x1 = x;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (orientacion == 3)
    {
        comprobar = x + t;
        if (comprobar <= 10)
        {
            x1 = comprobar;
            ya = y;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (orientacion == 4)
    {
        comprobar = x - t;

        if (comprobar >= -1)
        {
            x1 = comprobar;
            ya = y;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool comprobarsilascasillasestanocupadas(int orientacion)
{
    bool desocupada = true;
    if (orientacion == 1)
    {
        do
        {
            ya++;
            if (matriz[x][ya] == 1)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && ya < y);
        return desocupada;
    }
    else if (orientacion == 2)
    {
        do
        {
            ya--;
            if (matriz[x][ya] == 1)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && ya > y);
        return desocupada;
    }
    else if (orientacion == 3)
    {
        do
        {
            x1--;
            if (matriz[x1][y] == 1)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && x1 > x);
        return desocupada;
    }
    else if (orientacion == 4)
    {
        do
        {
            x1++;
            if (matriz[x1][y] == 1)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && x1 < x);
        return desocupada;
    }
    else
    {
        return false;
    }
}

void colocarbarco(int orientacion)
{
    int ficha;

    if (t == 2)
    {
        ficha = 2;
    }
    else if (t == 3)
    {
        if (limitedetres == 1)
        {
            ficha = 3;
            limitedetres--;
        }
        else
        {
            ficha = 9;
        }
    }
    else if (t == 4)
    {
        ficha = 4;
    }
    else
    {
        ficha = 5;
    }

    if (orientacion == 1)
    {
        while (t > 0)
        {
            matriz[x][y] = ficha;
            y--;
            t--;
        }
        numerodebarcos--;
    }

    else if (orientacion == 2)
    {
        while (t > 0)
        {
            matriz[x][y] = ficha;
            y++;
            t--;
        }
        numerodebarcos--;
    }
    else if (orientacion == 3)
    {
        while (t > 0)
        {
            matriz[x][y] = ficha;
            x++;
            t--;
        }
        numerodebarcos--;
    }
    else if (orientacion == 4)
    {
        while (t > 0)
        {
            matriz[x][y] = ficha;
            x--;
            t--;
        }
        numerodebarcos--;
    }
}

void conteobarcos()
{
    if (t1 == 2)
    {
        barcos2--;
    }
    else if (t1 == 3)
    {
        barcos3--;
    }
    else if (t1 == 4)
    {
        barcos4--;
    }
    else if (t1 == 5)
    {
        barcos5--;
    }
}

void tableroJ1()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrizJ1[i][j] != 2 && matrizJ1[i][j] != 3 && matrizJ1[i][j] != 4 && matrizJ1[i][j] != 5 && matrizJ1[i][j] != 9)
            {
                matrizJ1[i][j] = 0;
            }
        }
    }
}

void definirorientacionJ1()
{
    srand(time(NULL));
    orientacionJ1 = 1 + rand() % (5 - 1);
}

void definirpocicionJ1()
{
    if (tamanodelbarcoJ1[pociciontamanoJ1] == 2)
    {
        if (orientacionJ1 == 1)
        {
            srand(time(NULL));
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 1 + rand() % (9 - 1);
        }
        else if (orientacionJ1 == 2)
        {
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 0 + rand() % (8 - 0);
        }
        else if (orientacionJ1 == 3)
        {
            xJ1 = 0 + rand() % (8 - 0);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ1 == 4)
        {
            xJ1 = 1 + rand() % (9 - 1);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ1[pociciontamanoJ1] == 3)
    {
        if (orientacionJ1 == 1)
        {
            srand(time(NULL));
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 2 + rand() % (9 - 2);
        }
        else if (orientacionJ1 == 2)
        {
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 0 + rand() % (7 - 0);
        }
        else if (orientacionJ1 == 3)
        {
            xJ1 = 0 + rand() % (7 - 0);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ1 == 4)
        {
            xJ1 = 2 + rand() % (9 - 2);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ1[pociciontamanoJ1] == 4)
    {
        if (orientacionJ1 == 1)
        {
            srand(time(NULL));
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 3 + rand() % (9 - 3);
        }
        else if (orientacionJ1 == 2)
        {
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 0 + rand() % (6 - 0);
        }
        else if (orientacionJ1 == 3)
        {
            xJ1 = 0 + rand() % (6 - 0);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ1 == 4)
        {
            xJ1 = 3 + rand() % (9 - 3);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ1[pociciontamanoJ1] == 5)
    {
        if (orientacionJ1 == 1)
        {
            srand(time(NULL));
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 4 + rand() % (9 - 4);
        }
        else if (orientacionJ1 == 2)
        {
            xJ1 = 0 + rand() % (9 - 0);
            yJ1 = 0 + rand() % (5 - 0);
        }
        else if (orientacionJ1 == 3)
        {
            xJ1 = 0 + rand() % (5 - 0);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ1 == 4)
        {
            xJ1 = 4 + rand() % (9 - 4);
            yJ1 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else
    {
    }
}

bool comprobarsilascasillasestanocupadasJ1()
{
    bool desocupada;
    int yJ1prueba;
    int xJ1prueba;

    if (orientacionJ1 == 1)
    {

        yJ1prueba = yJ1 - tamanodelbarcoJ1[pociciontamanoJ1];
        do
        {
            yJ1prueba++;
            if (matrizJ1[xJ1][yJ1prueba] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && yJ1prueba < yJ1);
        return desocupada;
    }
    else if (orientacionJ1 == 2)
    {
        int yJ1prueba = yJ1 + tamanodelbarcoJ1[pociciontamanoJ1];
        do
        {
            yJ1prueba--;
            if (matrizJ1[xJ1][yJ1prueba] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && yJ1prueba > yJ1);
        return desocupada;
    }
    else if (orientacionJ1 == 3)
    {
        xJ1prueba = xJ1 + tamanodelbarcoJ1[pociciontamanoJ1];
        do
        {
            xJ1prueba--;
            if (matrizJ1[xJ1prueba][yJ1] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && xJ1prueba > xJ1);
        return desocupada;
    }
    else if (orientacionJ1 == 4)
    {
        xJ1prueba = xJ1 - tamanodelbarcoJ1[pociciontamanoJ1];
        do
        {
            xJ1prueba++;
            if (matrizJ1[xJ1prueba][yJ1] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && xJ1prueba < xJ1);
        return desocupada;
    }
    else
    {
        return false;
    }
}

void colocarbarcoJ1()
{
    int fichas[5] = {2, 3, 9, 4, 5};
    int tamanodelbarco = tamanodelbarcoJ1[pociciontamanoJ1];

    if (orientacionJ1 == 1)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ1[xJ1][yJ1] = fichas[pociciontamanoJ1];
            yJ1--;
            tamanodelbarco--;
        }
        numerodebarcosJ1--;
    }

    else if (orientacionJ1 == 2)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ1[xJ1][yJ1] = fichas[pociciontamanoJ1];
            yJ1++;
            tamanodelbarco--;
        }
        numerodebarcosJ1--;
    }
    else if (orientacionJ1 == 3)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ1[xJ1][yJ1] = fichas[pociciontamanoJ1];
            xJ1++;
            tamanodelbarco--;
        }
        numerodebarcosJ1--;
    }
    else if (orientacionJ1 == 4)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ1[xJ1][yJ1] = fichas[pociciontamanoJ1];
            xJ1--;
            tamanodelbarco--;
        }
        numerodebarcosJ1--;
    }
}

// Generar tablero 2

void tableroJ2()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrizJ2[i][j] != 2 && matrizJ2[i][j] != 3 && matrizJ2[i][j] != 4 && matrizJ2[i][j] != 5 && matrizJ2[i][j] != 9)
            {
                matrizJ2[i][j] = 0;
            }
        }
    }
}

void definirorientacionJ2()
{
    srand(time(NULL));
    orientacionJ2 = 1 + rand() % (5 - 1);
}

void definirpocicionJ2()
{
    if (tamanodelbarcoJ2[pociciontamanoJ2] == 2)
    {
        if (orientacionJ2 == 1)
        {
            srand(time(NULL));
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 1 + rand() % (9 - 1);
        }
        else if (orientacionJ2 == 2)
        {
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 0 + rand() % (8 - 0);
        }
        else if (orientacionJ2 == 3)
        {
            xJ2 = 0 + rand() % (8 - 0);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ2 == 4)
        {
            xJ2 = 1 + rand() % (9 - 1);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ2[pociciontamanoJ2] == 3)
    {
        if (orientacionJ2 == 1)
        {
            srand(time(NULL));
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 2 + rand() % (9 - 2);
        }
        else if (orientacionJ2 == 2)
        {
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 0 + rand() % (7 - 0);
        }
        else if (orientacionJ2 == 3)
        {
            xJ2 = 0 + rand() % (7 - 0);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ2 == 4)
        {
            xJ2 = 2 + rand() % (9 - 2);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ2[pociciontamanoJ2] == 4)
    {
        if (orientacionJ2 == 1)
        {
            srand(time(NULL));
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 3 + rand() % (9 - 3);
        }
        else if (orientacionJ2 == 2)
        {
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 0 + rand() % (6 - 0);
        }
        else if (orientacionJ2 == 3)
        {
            xJ2 = 0 + rand() % (6 - 0);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ2 == 4)
        {
            xJ2 = 3 + rand() % (9 - 3);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else if (tamanodelbarcoJ2[pociciontamanoJ2] == 5)
    {
        if (orientacionJ2 == 1)
        {
            srand(time(NULL));
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 4 + rand() % (9 - 4);
        }
        else if (orientacionJ2 == 2)
        {
            xJ2 = 0 + rand() % (9 - 0);
            yJ2 = 0 + rand() % (5 - 0);
        }
        else if (orientacionJ2 == 3)
        {
            xJ2 = 0 + rand() % (5 - 0);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else if (orientacionJ2 == 4)
        {
            xJ2 = 4 + rand() % (9 - 4);
            yJ2 = 0 + rand() % (9 - 0);
        }
        else
        {
        }
    }
    else
    {
    }
}

bool comprobarsilascasillasestanocupadasJ2()
{
    bool desocupada;
    int yJ2prueba;
    int xJ2prueba;

    if (orientacionJ2 == 1)
    {

        yJ2prueba = yJ2 - tamanodelbarcoJ2[pociciontamanoJ2];
        do
        {
            yJ2prueba++;
            if (matrizJ2[xJ2][yJ2prueba] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && yJ2prueba < yJ2);
        return desocupada;
    }
    else if (orientacionJ2 == 2)
    {
        int yJ2prueba = yJ2 + tamanodelbarcoJ2[pociciontamanoJ2];
        do
        {
            yJ2prueba--;
            if (matrizJ2[xJ2][yJ2prueba] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && yJ2prueba > yJ2);
        return desocupada;
    }
    else if (orientacionJ2 == 3)
    {
        xJ2prueba = xJ2 + tamanodelbarcoJ2[pociciontamanoJ2];
        do
        {
            xJ2prueba--;
            if (matrizJ2[xJ2prueba][yJ2] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && xJ2prueba > xJ2);
        return desocupada;
    }
    else if (orientacionJ2 == 4)
    {
        xJ2prueba = xJ2 - tamanodelbarcoJ2[pociciontamanoJ2];
        do
        {
            xJ2prueba++;
            if (matrizJ2[xJ2prueba][yJ2] == 0)
            {
                desocupada = true;
            }
            else
            {
                desocupada = false;
            }
        } while (desocupada == true && xJ2prueba < xJ2);
        return desocupada;
    }
    else
    {
        return false;
    }
}

void colocarbarcoJ2()
{
    int fichas[5] = {2, 3, 9, 4, 5};
    int tamanodelbarco = tamanodelbarcoJ2[pociciontamanoJ2];

    if (orientacionJ2 == 1)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ2[xJ2][yJ2] = fichas[pociciontamanoJ2];
            yJ2--;
            tamanodelbarco--;
        }
        numerodebarcosJ2--;
    }

    else if (orientacionJ2 == 2)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ2[xJ2][yJ2] = fichas[pociciontamanoJ2];
            yJ2++;
            tamanodelbarco--;
        }
        numerodebarcosJ2--;
    }
    else if (orientacionJ2 == 3)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ2[xJ2][yJ2] = fichas[pociciontamanoJ2];
            xJ2++;
            tamanodelbarco--;
        }
        numerodebarcosJ2--;
    }
    else if (orientacionJ2 == 4)
    {
        while (tamanodelbarco > 0)
        {
            matrizJ2[xJ2][yJ2] = fichas[pociciontamanoJ2];
            xJ2--;
            tamanodelbarco--;
        }
        numerodebarcosJ2--;
    }
}

void preguntardondeatacar()
{
    char letra;
    int xatacar2;
    if (turnodejugador == 1)
    {
        if (mododejuego == 1)
        {
            gotoxy(50, 15);
            cout << "\033[1;31m"
                 << "𝙿𝙻𝙰𝚈𝙴𝚁 𝚃𝚄𝚁𝙽 "
                 << "\033[0m" << endl;
        }
        else
        {
            gotoxy(50, 15);
            cout << "\033[1;34m"
                 << "𝙿𝙻𝙰𝚈𝙴𝚁 𝚃𝚄𝚁𝙽 𝟷"
                 << "\033[0m" << endl;
        }
    }
    else
    {
        if (mododejuego == 1)
        {
            gotoxy(50, 15);
            cout << "Turno de PC";
        }
        else
        {
            gotoxy(50, 15);
            cout << "\033[1;31m"
                 << "𝙿𝙻𝙰𝚈𝙴𝚁 𝚃𝚄𝚁𝙽 𝟤"
                 << "\033[0m";
        }
    }
    if (mododejuego == 2 || turnodejugador == 1)
    {
        cout << endl;
        gotoxy(50, 16);
        cout << "\033[1;32m"
             << "𝖠𝖳𝖳𝖠𝖢𝖪"
             << "\033[0m" << endl;
        cout << endl;
        do
        {
            gotoxy(50, 17);
            cout << "\033[1;37m"
                 << "𝐶𝐻𝑂𝑂𝑆𝐸 𝐴 𝑁𝑈𝑀𝐵𝐸𝑅: "
                 << "\033[0m" << endl;
            gotoxy(68, 17);
            cin >> xatacar2;
            xatacar = xatacar2 - 1;
            cout << endl;
            gotoxy(50, 18);
            cout << "\033[1;37m"
                 << "𝐶𝐻𝑂𝑂𝑆𝐸 𝐴 𝐿𝐸𝑇𝑇𝐸𝑅: "
                 << "\033[0m" << endl;
            gotoxy(68, 18);
            cin >> letra;
            if (letra == 'A' || letra == 'a')
            {
                yatacar = 0;
            }
            else if (letra == 'B' || letra == 'b')
            {
                yatacar = 1;
            }
            else if (letra == 'C' || letra == 'c')
            {
                yatacar = 2;
            }
            else if (letra == 'D' || letra == 'd')
            {
                yatacar = 3;
            }
            else if (letra == 'E' || letra == 'e')
            {
                yatacar = 4;
            }
            else if (letra == 'F' || letra == 'f')
            {
                yatacar = 5;
            }
            else if (letra == 'G' || letra == 'g')
            {
                yatacar = 6;
            }
            else if (letra == 'H' || letra == 'h')
            {
                yatacar = 7;
            }
            else if (letra == 'I' || letra == 'i')
            {
                yatacar = 8;
            }
            else if (letra == 'J' || letra == 'j')
            {
                yatacar = 9;
            }
            else
            {
                yatacar = 10;
            }

        } while (xatacar < 0 || xatacar > 9 || yatacar < 0 || yatacar > 9);
    }
}

bool generarnumeroataque()
{
    xatacar = 0 + rand() % (9 - 0);
    yatacar = 0 + rand() % (9 - 0);

    if (matriz[xatacar][yatacar] == 1)
    {
        matriz[xatacar][yatacar] = 6;
        return false;
    }
    else if (matriz[xatacar][yatacar] == 2 || matriz[xatacar][yatacar] == 3 || matriz[xatacar][yatacar] == 4 || matriz[xatacar][yatacar] == 5 || matriz[xatacar][yatacar] == 9)
    {
        matriz[xatacar][yatacar] = 7;
        numerodebarcosvivos--;
        return true;
    }
    else
    {
        return false;
    }
}

bool atacarBarcos()
{
    if (turnodejugador == 1)
    {
        if (matrizJ2[xatacar][yatacar] == 0)
        {
            matrizJ2[xatacar][yatacar] = 6;
            return false;
        }
        else if (matrizJ2[xatacar][yatacar] == 2 || matrizJ2[xatacar][yatacar] == 3 || matrizJ2[xatacar][yatacar] == 4 || matrizJ2[xatacar][yatacar] == 5 || matrizJ2[xatacar][yatacar] == 9)
        {
            matrizJ2[xatacar][yatacar] = 7;
            numerodebarcosvivosJ2--;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (matrizJ1[xatacar][yatacar] == 0)
        {
            matrizJ1[xatacar][yatacar] = 6;
            return false;
        }
        else if (matrizJ1[xatacar][yatacar] == 2 || matrizJ1[xatacar][yatacar] == 3 || matrizJ1[xatacar][yatacar] == 4 || matrizJ1[xatacar][yatacar] == 5 || matrizJ1[xatacar][yatacar] == 9)
        {
            matrizJ1[xatacar][yatacar] = 7;
            numerodebarcosvivosJ1--;
            return true;
        }
        else
        {
            return false;
        }
    }
}
void gotoxy(int x, int y)
{

    cout << "\033[" << y << ";" << x << "f";
}

void decirquebarcotiraste()
{
    int contador1barco2 = 0;
    int contador1barco3 = 0;
    int contador1barco9 = 0;
    int contador1barco4 = 0;
    int contador1barco5 = 0;

    int contador2barco2 = 0;
    int contador2barco3 = 0;
    int contador2barco9 = 0;
    int contador2barco4 = 0;
    int contador2barco5 = 0;

    if (turnodejugador == 2)
    {

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matrizJ1[i][j] == 2)
                {
                    contador1barco2++;
                }
                else if (matrizJ1[i][j] == 3)
                {
                    contador1barco3++;
                }
                else if (matrizJ1[i][j] == 9)
                {
                    contador1barco9++;
                }
                else if (matrizJ1[i][j] == 4)
                {
                    contador1barco4++;
                }
                else if (matrizJ1[i][j] == 5)
                {
                    contador1barco5++;
                }
                else
                {
                }
            }
        }
        gotoxy(100, 15);
        cout << "\033[1;33m"
             << "𝗣𝗟𝗔𝗬𝗘𝗥 𝟭 𝗙𝗔𝗟𝗟𝗘𝗡 𝗦𝗛𝗜𝗣𝗦"
             << "\033[0m" << endl;
        if (contador1barco2 == 0)
        {
            gotoxy(100, 16);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 2"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador1barco3 == 0)
        {
            gotoxy(100, 17);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 3"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador1barco9 == 0)
        {
            gotoxy(100, 18);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 3"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador1barco4 == 0)
        {
            gotoxy(100, 19);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 4"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador1barco5 == 0)
        {
            gotoxy(100, 20);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 5"
                 << "\033[0m" << endl;
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matrizJ2[i][j] == 2)
                {
                    contador2barco2++;
                }
                else if (matrizJ2[i][j] == 3)
                {
                    contador2barco3++;
                }
                else if (matrizJ2[i][j] == 9)
                {
                    contador2barco9++;
                }
                else if (matrizJ2[i][j] == 4)
                {
                    contador2barco4++;
                }
                else if (matrizJ2[i][j] == 5)
                {
                    contador2barco5++;
                }
                else
                {
                }
            }
        }
        gotoxy(100, 15);
        cout << "\033[1;33m"
             << "𝗣𝗟𝗔𝗬𝗘𝗥 𝟮 𝗙𝗔𝗟𝗟𝗘𝗡 𝗦𝗛𝗜𝗣𝗦"
             << "\033[0m" << endl;
        if (contador2barco2 == 0)
        {
            gotoxy(100, 16);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 2"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador2barco3 == 0)
        {
            gotoxy(100, 17);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 3"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador2barco9 == 0)
        {
            gotoxy(100, 18);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 3"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador2barco4 == 0)
        {
            gotoxy(100, 19);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 4"
                 << "\033[0m" << endl;
            cout << endl;
        }
        if (contador2barco5 == 0)
        {
            gotoxy(100, 20);
            cout << "\033[1;37m"
                 << "𝑌𝑂𝑈 𝐾𝑁𝑂𝐶𝐾𝐸𝐷 𝐷𝑂𝑊𝑁 𝐵𝑂𝐴𝑇 𝑂𝐹 5"
                 << "\033[0m" << endl;
            cout << endl;
        }
    }
}

void menu()
{
    for (int x = 50; x > 10; x--)
    {
        system("clear");
        gotoxy(x, 1);
        cout << "              __'__     __'__      __'__" << endl;
        gotoxy(x, 2);
        cout << "             /    /    /    /     /    /" << endl;
        gotoxy(x, 3);
        cout << "            /____/    /____/     /____/  " << endl;
        gotoxy(x, 4);
        cout << "          / ___|___   ___|___    ___|___ " << endl;
        gotoxy(x, 5);
        cout << "        // (      (  (      (   (      (" << endl;
        gotoxy(x, 6);
        cout << "      / /  (______(  (______(   (______(" << endl;
        gotoxy(x, 7);
        cout << "    /  /   ____|_____ ___|______ ____|_____" << endl;
        gotoxy(x, 8);
        cout << "   /   /   /         //         //         /" << endl;
        gotoxy(x, 9);
        cout << " /    /   |         ||         ||         |" << endl;
        gotoxy(x, 10);
        cout << "/____/     (         ((        ((         (" << endl;
        gotoxy(x, 11);
        cout << "    (      (_________((_________((_________((" << endl;
        gotoxy(x, 12);
        cout << "    (         |          |         |" << endl;
        gotoxy(x, 13);
        cout << "     (________|__________|_________|________/" << endl;
        gotoxy(x, 14);
        cout << "       (|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_/|" << endl;

        gotoxy(x, 15);
        cout << "\033[0;34m"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "\033[0m" << endl;
        gotoxy(x, 16);
        cout << "\033[0;34m"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "\033[0m" << endl;
        gotoxy(40, 18);
        cout << "\033[1;37m"
             << "░ ░ ░ █░░ █▀█ ▄▀█ █▀▄ █ █▄░█ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ ░ ░ ░"
             << "\033[0m" << endl;
        gotoxy(40, 19);
        cout << "\033[1;37m"
             << "▄ ▄ ▄ █▄▄ █▄█ █▀█ █▄▀ █ █░▀█ █▄█   █▄█ █▀█ █░▀░█ ██▄ ▄ ▄ ▄"
             << "\033[0m" << endl;
        usleep(100000);
        system("clear");
    }
    gotoxy(20, 1);
    cout << "\033[0;33m"
         << "██████╗░░█████╗░████████╗████████╗██╗░░░░░███████╗  ░██████╗██╗░░██╗██╗██████╗░"
         << "\033[0m" << endl;
    gotoxy(20, 2);
    cout << "\033[0;33m"
         << "██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║░░░░░██╔════╝  ██╔════╝██║░░██║██║██╔══██╗"
         << "\033[0m" << endl;
    gotoxy(20, 3);
    cout << "\033[0;33m"
         << "██████╦╝███████║░░░██║░░░░░░██║░░░██║░░░░░█████╗░░  ╚█████╗░███████║██║██████╔╝"
         << "\033[0m" << endl;
    gotoxy(20, 4);
    cout << "\033[0;33m"
         << "██╔══██╗██╔══██║░░░██║░░░░░░██║░░░██║░░░░░██╔══╝░░  ░╚═══██╗██╔══██║██║██╔═══╝░"
         << "\033[0m" << endl;
    gotoxy(20, 5);
    cout << "\033[0;33m"
         << "██████╦╝██║░░██║░░░██║░░░░░░██║░░░███████╗███████╗  ██████╔╝██║░░██║██║██║░░░░░"
         << "\033[0m" << endl;
    gotoxy(20, 6);
    cout << "\033[0;33m"
         << "╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░░░░╚═╝░░░╚══════╝╚══════╝  ╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░░░░"
         << "\033[0m" << endl;

    gotoxy(50, 8);
    cout << "\033[1;34m"
         << "▒█▀▄▀█ ▒█▀▀▀ ▒█▄░▒█ ▒█░▒█"
         << "\033[0m" << endl;
    gotoxy(50, 9);
    cout << "\033[1;34m"
         << "▒█▒█▒█ ▒█▀▀▀ ▒█▒█▒█ ▒█░▒█ "
         << "\033[0m" << endl;
    gotoxy(50, 10);
    cout << "\033[1;34m"
         << "▒█░░▒█ ▒█▄▄▄ ▒█░░▀█ ░▀▄▄▀"
         << "\033[0m" << endl;

    gotoxy(50, 13);
    cout << "１．－ＳＩＮＧＬＥ ＰＬＡＹＥＲ" << endl;
    gotoxy(50, 15);
    cout << "２．－ＭＵＬＴＩＰＬＡＹＥＲ" << endl;
    gotoxy(50, 17);
    cout << "ＣＨＯＯＳＥ ＴＨＥ ＧＡＭＥ ＭＯＤＥ：" << endl;
    gotoxy(90, 17);
    cin >> mododejuego;
}

void ataqueinteligente()
{

    if (direccionamiento == 1)
    {
        if (matriz[xg][yg + 1] == 2 || matriz[xg][yg + 1] == 3 || matriz[xg][yg + 1] == 4 || matriz[xg][yg + 1] == 5 || matriz[xg][yg + 1] == 9)
        {
            do
            {
                yg++;
                if (matriz[xg][yg] == 2 || matriz[xg][yg] == 3 || matriz[xg][yg] == 4 || matriz[xg][yg] == 5 || matriz[xg][yg] == 9)
                {
                    matriz[xg][yg] = 7;
                    numerodebarcosvivos--;
                }
                else
                {
                    matriz[xg][yg] = 6;
                    turnodejugador = 1;
                    permitirAleatorio = true;
                    direccionamiento = 1;
                }
            } while (matriz[xg][yg] == 7);
        }
        else
        {
            matriz[xg][yg + 1] = 6;
            turnodejugador = 1;
            direccionamiento++;
            permitirAleatorio = false;
        }
    }
    else if (direccionamiento == 2)
    {
        if (matriz[xg][yg - 1] == 2 || matriz[xg][yg - 1] == 3 || matriz[xg][yg - 1] == 4 || matriz[xg][yg - 1] == 5 || matriz[xg][yg - 1] == 9)
        {
            do
            {
                yg--;
                if (matriz[xg][yg] == 2 || matriz[xg][yg] == 3 || matriz[xg][yg] == 4 || matriz[xg][yg] == 5 || matriz[xg][yg] == 9)
                {
                    matriz[xg][yg] = 7;
                    numerodebarcosvivos--;
                }
                else
                {
                    matriz[xg][yg] = 6;
                    turnodejugador = 1;
                    permitirAleatorio = true;
                    direccionamiento = 1;
                }
            } while (matriz[xg][yg] == 7);
        }
        else
        {
            matriz[xg][yg - 1] = 6;
            turnodejugador = 1;
            direccionamiento++;
            permitirAleatorio = false;
        }
    }
    else if (direccionamiento == 3)
    {
        if (matriz[xg + 1][yg] == 2 || matriz[xg + 1][yg] == 3 || matriz[xg + 1][yg] == 4 || matriz[xg + 1][yg] == 5 || matriz[xg + 1][yg] == 9)
        {
            do
            {
                xg++;
                if (matriz[xg][yg] == 2 || matriz[xg][yg] == 3 || matriz[xg][yg] == 4 || matriz[xg][yg] == 5 || matriz[xg][yg] == 9)
                {
                    matriz[xg][yg] = 7;
                    numerodebarcosvivos--;
                }
                else
                {
                    matriz[xg][yg] = 6;
                    turnodejugador = 1;
                    permitirAleatorio = true;
                    direccionamiento = 1;
                }
            } while (matriz[xg][yg] == 7);
        }
        else
        {
            matriz[xg + 1][yg] = 6;
            turnodejugador = 1;
            direccionamiento++;
            permitirAleatorio = false;
        }
    }
    else
    {
        if (matriz[xg - 1][yg] == 2 || matriz[xg - 1][yg] == 3 || matriz[xg - 1][yg] == 4 || matriz[xg - 1][yg] == 5 || matriz[xg - 1][yg] == 9)
        {
            do
            {
                xg--;
                if (matriz[xg][yg] == 2 || matriz[xg][yg] == 3 || matriz[xg][yg] == 4 || matriz[xg][yg] == 5 || matriz[xg][yg] == 9)
                {
                    matriz[xg][yg] = 7;
                    numerodebarcosvivos--;
                }
                else
                {
                    matriz[xg][yg] = 6;
                    turnodejugador = 1;
                    permitirAleatorio = true;
                    direccionamiento = 1;
                }
            } while (matriz[xg][yg] == 7);
        }
        else
        {
            matriz[xg - 1][yg] = 6;
            turnodejugador = 1;
            direccionamiento++;
            permitirAleatorio = false;
        }
    }
}