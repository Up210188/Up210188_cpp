/*
Date: //2022
Unidad:3
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

*/

#include <iostream>

void capturaDatos();
void imprimeDatos();

int conjunto[5][5];



using namespace std;

int main(){

    capturaDatos();

    imprimeDatos();
    

    return 0;
}


void capturaDatos(){

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout<<"Dame los valores de los 5 valores de la matriz: ";cin>>conjunto[row][col];
        }
        
    }
    
}

void imprimeDatos(){

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout<<conjunto[row][col]<<"\t";
        }
        cout<<endl;
    }

}