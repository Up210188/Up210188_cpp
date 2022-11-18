#include <iostream>
#include <time.h>

using namespace std;

void ConstruirTablero();
int SeleccionarJugada();
char AreaJuego[3][3]={'1','2','3','4','5','6','7','8','9'};
void ConstruirTableroImaginario();
int Turnojugador=1;
bool comprobarCasiilaOcupada(int jugada);
bool comprobarCasiilaOcupadaImaginaria(int jugada);
void remplazarCasilla(int jugada);
void remplazarCasillaImaginario(int jugada);
bool Ganar();
bool GanarImaginario(int jugada);
int MejorJugada(char jugador);
int TurnoPC();
char PC ='O';
char HUMANO ='X';
int main(){
    int jugada;
    bool casillaOcupada=true;
    bool ganador=false;
    int ModoDeJuego=0;

     
        ConstruirTablero();

        do{
            do
        {
            if(Turnojugador%2!=0){
        jugada=SeleccionarJugada();
            }
            else{
                jugada=TurnoPC();
            }
        casillaOcupada=comprobarCasiilaOcupada(jugada);
        if(casillaOcupada==true){
            if(jugada==Turnojugador){
            cout<<"otra vez ";
            }
        }
        
        } while (casillaOcupada==true);

        if (casillaOcupada == false)
            {
                system("clear");
                remplazarCasilla(jugada);
                ConstruirTablero();
                Turnojugador++;
            }

        ganador=Ganar();
        if(ganador==true){
            cout<<"felicidades gano el jugador "<<Turnojugador%2+1<<endl;
        }

        if(Turnojugador>9){
            cout<<"es empate"<<endl;
            break;
        }

        }while (ganador==false);

    }
    

    return 0;
}