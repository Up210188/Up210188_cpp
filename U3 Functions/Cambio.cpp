/*
Date: 24/10/2022
Unidad:3
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:get the change in coins and bills

*/

#include <iostream>

using namespace std;

void obtenerCambio(int);
void obtenerMonedas(int);
void imprimirCambio();

int quinientos=0,docientos=0,cien=0,cincuenta=0,veinte=0;
int diez=0, cinco=0, dos=0, uno=0;


int main(){
    
    int dinero;

    cout<<"Enter the money: ";cin>>dinero;

    obtenerCambio(dinero);
    imprimirCambio();


    return 0;
}

void obtenerCambio(int monto){

    if (monto>=500){

        quinientos=monto/500;
        monto=monto%500;

    }
    if(monto>=200){
        docientos=monto/200;
        monto=monto%200;
    }

    if(monto>=100){
        cien=monto/100;
        monto=monto%100;
    }

    if (monto>=50){
    
        cincuenta=monto/50;
        monto=monto%50;
    }

    if (monto>=20)
    {
        veinte=monto/20;
        monto=monto%20;
    }

    obtenerMonedas(monto);
       
    
}

void obtenerMonedas(int monto){
    if (monto>=10)
    {
        diez=monto/10;
        monto=monto%10;
    }

    if(monto>=5){
        cinco=monto/5;
        monto=monto%5;

    }

    if (monto>=2)
    {
        dos=monto/2;
        monto=monto%2;
    }

    if (monto>=1)
    {
        uno=monto/1;

    }
}

void imprimirCambio (){

    
    cout<<"El total en monedas y billetes es: "<<endl;
    cout<<"Los billetes de quimientos son: "<<quinientos<<endl;
    cout<<"Los billetes de docientos son: "<<docientos<<endl;
    cout<<"Los billetes de cien son: "<<cien<<endl;
    cout<<"Los billetes de cincuenta son: "<<cincuenta<<endl;
    cout<<"Los billetes de veinte son: "<<veinte<<endl;
    cout<<"las monedas de diez son: "<<diez<<endl;
    cout<<"las monedas de cinco son: "<< cinco<<endl;
    cout<<"las monedas de dos son: "<<dos<<endl;
    cout<<"las monedas de uno son: "<<uno<<endl;
    

   
}