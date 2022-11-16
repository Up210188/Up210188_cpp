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
const char PC = 'O';
const char HUMANO = 'X';
int main(){
    int jugada;
    bool casillaOcupada=true;
    bool ganador=false;
    int ModoDeJuego=0;

    cout<<"Seleccione el modo de juego: solo=1 multiplayer=2 ";cin>>ModoDeJuego;


    
    if(ModoDeJuego==2){
        ConstruirTablero();

        do{
            do
        {
        jugada=SeleccionarJugada();
        casillaOcupada=comprobarCasiilaOcupada(jugada);
        if(casillaOcupada==true){
            cout<<"otra vez ";
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

  /* else if(ModoDeJuego==1){
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
            cout<<"otra vez ";
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
    
    */
    
    
    


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
        col=1;
    }
    else if(jugada==3){
        row=0;
        col=2;
    }
    else if(jugada==4){
        row=1;
        col=0;
    }
     else if(jugada==5){
        row=1;
        col=1;
    }
    else if(jugada==6){
        row=1;
        col=2;
    }
    else if(jugada==7){
        row=2;
        col=0;
    }
    else if(jugada==8){
        row=2;
        col=1;
    }
    else if(jugada==9){
        row=2;
        col=2;
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

void remplazarCasilla(int jugada){
    int row=0, col=0;
      if(jugada==1){
        row=0;
        col=0;
    }
    else if(jugada==2){
        row=0;
        col=1;
    }
    else if(jugada==3){
        row=0;
        col=2;
    }
    else if(jugada==4){
        row=1;
        col=0;
    }
     else if(jugada==5){
        row=1;
        col=1;
    }
    else if(jugada==6){
        row=1;
        col=2;
    }
    else if(jugada==7){
        row=2;
        col=0;
    }
    else if(jugada==8){
        row=2;
        col=1;
    }
    else if(jugada==9){
        row=2;
        col=2;
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

bool Ganar(){
    if(AreaJuego[0][0]==AreaJuego[0][1]&&AreaJuego[0][0]==AreaJuego[0][2]&&AreaJuego[0][1]==AreaJuego[0][2]){
        return true;
    }
    else if(AreaJuego[1][0]==AreaJuego[1][1]&&AreaJuego[1][0]==AreaJuego[1][2]&&AreaJuego[1][1]==AreaJuego[1][2]){
        return true;
    }
    else if(AreaJuego[2][0]==AreaJuego[2][1]&&AreaJuego[2][0]==AreaJuego[2][2]&&AreaJuego[2][1]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][0]==AreaJuego[1][0]&&AreaJuego[0][0]==AreaJuego[2][0]&&AreaJuego[1][0]==AreaJuego[2][0]){
        return true;
    }
    else if(AreaJuego[0][1]==AreaJuego[1][1]&&AreaJuego[0][1]==AreaJuego[2][1]&&AreaJuego[1][1]==AreaJuego[2][1]){
        return true;
    }
    else if(AreaJuego[0][2]==AreaJuego[1][2]&&AreaJuego[0][2]==AreaJuego[2][2]&&AreaJuego[1][2]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][0]==AreaJuego[1][1]&&AreaJuego[0][0]==AreaJuego[2][2]&&AreaJuego[1][1]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][2]==AreaJuego[1][1]&&AreaJuego[0][2]==AreaJuego[2][0]&&AreaJuego[1][1]==AreaJuego[2][0]){
        return true;
    }
    else{
        return false;
    }

}


/*
int TurnoPC(){
    
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
*/


void ConstruirTableroImaginario(){
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

bool comprobarCasiilaOcupadaImaginaria(int jugada){
    int row=0,col=0;
    if(jugada==1){
        row=0;
        col=0;
    }
    else if(jugada==2){
        row=0;
        col=1;
    }
    else if(jugada==3){
        row=0;
        col=2;
    }
    else if(jugada==4){
        row=1;
        col=0;
    }
     else if(jugada==5){
        row=1;
        col=1;
    }
    else if(jugada==6){
        row=1;
        col=2;
    }
    else if(jugada==7){
        row=2;
        col=0;
    }
    else if(jugada==8){
        row=2;
        col=1;
    }
    else if(jugada==9){
        row=2;
        col=2;
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

bool GanarImaginario(){
    if(AreaJuego[0][0]==AreaJuego[0][1]&&AreaJuego[0][0]==AreaJuego[0][2]&&AreaJuego[0][1]==AreaJuego[0][2]){
        return true;
    }
    else if(AreaJuego[1][0]==AreaJuego[1][1]&&AreaJuego[1][0]==AreaJuego[1][2]&&AreaJuego[1][1]==AreaJuego[1][2]){
        return true;
    }
    else if(AreaJuego[2][0]==AreaJuego[2][1]&&AreaJuego[2][0]==AreaJuego[2][2]&&AreaJuego[2][1]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][0]==AreaJuego[1][0]&&AreaJuego[0][0]==AreaJuego[2][0]&&AreaJuego[1][0]==AreaJuego[2][0]){
        return true;
    }
    else if(AreaJuego[0][1]==AreaJuego[1][1]&&AreaJuego[0][1]==AreaJuego[2][1]&&AreaJuego[1][1]==AreaJuego[2][1]){
        return true;
    }
    else if(AreaJuego[0][2]==AreaJuego[1][2]&&AreaJuego[0][2]==AreaJuego[2][2]&&AreaJuego[1][2]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][0]==AreaJuego[1][1]&&AreaJuego[0][0]==AreaJuego[2][2]&&AreaJuego[1][1]==AreaJuego[2][2]){
        return true;
    }
    else if(AreaJuego[0][2]==AreaJuego[1][1]&&AreaJuego[0][2]==AreaJuego[2][0]&&AreaJuego[1][1]==AreaJuego[2][0]){
        return true;
    }
    else{
        return false;
    }

}

void remplazarCasillaImaginario(int jugada){
    int row=0, col=0;
      if(jugada==1){
        row=0;
        col=0;
    }
    else if(jugada==2){
        row=0;
        col=1;
    }
    else if(jugada==3){
        row=0;
        col=2;
    }
    else if(jugada==4){
        row=1;
        col=0;
    }
     else if(jugada==5){
        row=1;
        col=1;
    }
    else if(jugada==6){
        row=1;
        col=2;
    }
    else if(jugada==7){
        row=2;
        col=0;
    }
    else if(jugada==8){
        row=2;
        col=1;
    }
    else if(jugada==9){
        row=2;
        col=2;
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


int MejorJugada(char jugador){
    bool Casillaocupada = false;
    bool Ganador = false;
    int JugadaPC = 0;

    ConstruirTableroImaginario();

    if(jugador=='X'){
         do
        {
            JugadaPC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(JugadaPC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(JugadaPC);
                Ganador = GanarImaginario(JugadaPC);
            }
            ConstruirTableroImaginario();
        } while (JugadaPC <=9 && Ganador == false);
    }


    else
    {
        do
        {
              JugadaPC++;
            Casillaocupada = comprobarCasiilaOcupadaImaginaria(JugadaPC);
            if (Casillaocupada == false)
            {
                remplazarCasillaImaginario(JugadaPC);
                Ganador = GanarImaginario(JugadaPC);
            }
            ConstruirTableroImaginario();
        } while (JugadaPC <= 9 && Ganador == false);
        
    }
    if (JugadaPC >= 10)
    {
        JugadaPC= -1;
    }
    return JugadaPC;
    
}

