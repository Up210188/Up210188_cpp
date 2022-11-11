#include <iostream>

using namespace std;

void ConstruirTablero();
int SeleccionarJugada();
char AreaJuego[3][3]={'1','2','3','4','5','6','7','8','9'};
int Turnojugador=0;
bool comprobarCasiilaOcupada(int jugada);
int main(){
    int jugada;
    bool casillaOcupada=true;


 
    ConstruirTablero();
    do
    {
    jugada=SeleccionarJugada();
    casillaOcupada=comprobarCasiilaOcupada(jugada);
    if(casillaOcupada==true){
        cout<<"otra vez";
    }
    
    } while (casillaOcupada==true);

  cout<<casillaOcupada<<endl;



    return 0;
}

void ConstruirTablero(){
    int x=0, y=0;
    for(int row=0; row<6; row++){
        for (int col = 0; col < 3; col++)
        {
            if(row<5 && row%2==1){

                cout<<"___";
            }
            else {
                if(row<5){
                cout<<" "<<AreaJuego[x][y]<<" ";
                  y++;
                }
                else{
                    cout<<"   ";
                }
            }

            if(col<2){
                cout<<"|";
            }

            
        }
        y=0;
        if( row%2==0){
            x++;
        }


        cout<<endl;
    }

    

}

int SeleccionarJugada()
{
    int Jugada;
    do
    {
        cout << "dame la jugada: ";
        cin >> Jugada;
    } while (Jugada < 0 && Jugada > 9);

    return Jugada;
}

bool comprobarCasiilaOcupada(int jugada){
    int row=0,col=0;
    if(jugada==1){
        row=0;
        col=0;
    }
    else if(jugada==2){
        row=0;
        col=0;
    }
    else if(jugada==3){
        row=0;
        col=0;
    }
    else if(jugada==4){
        row=0;
        col=0;
    }
     else if(jugada==5){
        row=0;
        col=0;
    }
    else if(jugada==6){
        row=0;
        col=0;
    }
    else if(jugada==7){
        row=0;
        col=0;
    }
    else if(jugada==8){
        row=0;
        col=0;
    }
    else if(jugada==9){
        row=0;
        col=0;
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

