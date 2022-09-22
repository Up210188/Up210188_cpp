/*
Date: 22/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

Los tramos impositivos para la declaración de la renta en un determinado país son los siguientes:

Renta	Tipo impositivo
Menos de $10,000	5%
Entre $10,000 y $20,000	15%
Entre $20,000 y $35,000	20%
Entre $35,000 y $60,000	30%
Más de $60,000	45%
Escribir un programa que pregunte al usuario su renta anual y muestre por 
pantalla el tipo impositivo que le corresponde.
*/

#include <iostream>
using namespace std;

int main(){
    int renta;
    float impositivo;

    cout<<"¿Cuál es su renta anual en pesos? "; cin>>renta;


    if(renta<=0){
        cout<<"Favor de checar bien el valor de su renta"<<endl;
    }

    else{
        if(renta<10000){
            impositivo=renta*0.05;
            cout<<"Su tipo de impositivo es de 5% y el total a pagar es de "<<impositivo<<" pesos"<<endl;
        }

        if(renta>=10000 && renta<20000){
            impositivo=renta*0.15;
            cout<<"Su tipo de impositivo es de 15% y el total a pagar es de "<<impositivo<<" pesos"<<endl;
        }

        if(renta>=20000 && renta<35000){
            impositivo=renta*0.20;
            cout<<"Su tipo de impositivo es de 20% y el total a pagar es de "<<impositivo<<" pesos"<<endl;
        }

        if(renta>=35000 && renta<60000){
            impositivo=renta*0.30;
            cout<<"Su tipo de impositivo es de 30% y el total a pagar es de "<<impositivo<<" pesos"<<endl;
        }

         if(renta>=60000){
            impositivo=renta*0.45;
            cout<<"Su tipo de impositivo es de 45% y el total a pagar es de "<<impositivo<<" pesos"<<endl;
        }
    }    

        
    return 0;
}

