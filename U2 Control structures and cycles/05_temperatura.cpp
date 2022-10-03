/*
Date: 3/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:Make a program in which 6 temperatures are entered and determine the average, the most
low and the highest.*/


#include <iostream>
using namespace std;

int main(){
    int contador=0;
    float temperatura,temAcum=0,temMayor=-273.15,temMenor=1000000;

    do{

        cout<<"Give me the temperature: "; cin>>temperatura;
        temAcum += temperatura;
        contador++;
    
        if(temperatura>=temMayor){
            temMayor=temperatura;
        }
        else if(temperatura<=temMenor){
            temMenor=temperatura;
        }

    }while(contador< 6);

    cout<<"The average of temperature today is: "<< temAcum/6<<endl;
    cout<<"The higher temperature is: "<<temMayor<<endl;
    cout<<"The lower temperature is: "<<temMenor<<endl;
    return 0;
}