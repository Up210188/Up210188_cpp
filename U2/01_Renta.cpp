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
    //Declaración de variables
    int renta,porcentaje;
    float impositivo;

    //Pregunta al usuario su renta anual y lo guarda
    cout<<"¿Cuál es su renta anual en pesos? "; cin>>renta;

    //Checa que el usuario digito bien su renta
    if(renta<=0){
        cout<<"Favor de checar bien el valor de su renta"<<endl;
    }

    //Checa la renta para ver que porcentaje de impositivo le corresponde
    else{
        if(renta<10000){
            porcentaje=5;
        }    
        
        if(renta>=10000 && renta<20000){
            porcentaje=15;
        }

        if(renta>=20000 && renta<35000){
            porcentaje=20;
        }

        if(renta>=35000 && renta<60000){
            porcentaje=30;
        }    
            
         if(renta>=60000){
            porcentaje=45;
         }

         //Imprime el porsentaje y el valor del impositivo
        impositivo=renta*porcentaje/100;
        cout<<"Su impositivo es de "<<porcentaje <<"% y se va a pagar $"<<impositivo<<endl;
    }    

        
    return 0;
}

