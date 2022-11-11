/*
Date: 28/10/2022
Unidad:3
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
Make the cat videogame
*/

#include <iostream>

using namespace std;

void ConstruirTablero();
char PosiblesJugadas();
int tablero[3][3];
int main(){

/*
    tablero[0][0]=1;
    tablero[0][1]=2;
    tablero[0][2]=3;
    tablero[1][0]=4;
    tablero[1][1]=5;
    tablero[1][2]=6;
    tablero[2][0]=7;
    tablero[2][1]=8;
    tablero[2][2]=9;*/

    
    
ConstruirTablero();
PosiblesJugadas();
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
                cout<<" "<<tablero[x][y]<<" ";
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

char PosiblesJugadas(){
    cout<<"OPCIONES DE JUEGO";
    int contador=0;
    string opciones="123456789";

    for(int row=0;row<3;row++){
        for (int col = 0; col < 3; col++)
        {
            cout<<opciones[contador]<<")["<<row<<","<<col<<"]";
            if(tablero[row][col]!=0){
                cout<<"OCUPADO";

            }
            cout<<endl;
            contador++;
        }
        
    }
    char jugada;
    cout<<"elegi una juegada: ";cin>>jugada;
    




}