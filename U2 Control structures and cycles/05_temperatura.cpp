/*
Date: 3/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
Make a program in which 6 temperatures are entered and determine the average, the most
low and the highest.*/


#include <iostream>
using namespace std;

int main(){
    //Declaration of variables
    int contador=0;
    float temperatura,temAcum=0,temMayor=-273.15,temMenor=1000000;

    do{
        //ask the user the 6 temperatures
        cout<<"Give me the temperature: "; cin>>temperatura;
        temAcum += temperatura;
        contador++;
        //Compare to know the highest temperature
        if(temperatura>=temMayor){
            temMayor=temperatura;
        }
        //Compare to know the lower temperature
        else if(temperatura<=temMenor){
            temMenor=temperatura;
        }

    }while(contador< 6);
    //prints average temperatures
    cout<<"The average of temperature today is: "<< temAcum/6<<endl;
    //prints the highest temperature
    cout<<"The higher temperature is: "<<temMayor<<endl;
    //prints the lowest temperature
    cout<<"The lower temperature is: "<<temMenor<<endl;
    return 0;
}