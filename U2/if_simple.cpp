/*
Date: 22/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description: sentencia if
*/
#include <iostream>  
using namespace std; 

int main(){

    int numero, dato=1;

    //sentencia if ==, !=, <, >, <=, >=

    cout<<"ingresa un numero: ";cin>>numero;

    if(numero== dato){
        cout<<"El numero es igual al dato"<<endl;
    }

    if(numero> dato){
        cout<<"El numero es mayor al dato"<<endl;
    }

    if(numero< dato){
        cout<<"El numero es menor al dato"<<endl;
    }

    if(numero !=dato){
        cout<<"El numero es diferente al dato"<<endl;
    }

    if(numero <=dato){
        cout<<"El numero es menor o igual al dato"<<endl;
    }

    if(numero >=dato){
        cout<<"El numero es mayor o igual al dato"<<endl;
    }
    return 0;
}
