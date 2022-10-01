/*
Date: 22/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

The tax brackets for the declaration of income in a given country are the following:

Income tax rate
Less than $10,000 5%
Between $10,000 and $20,000 15%
Between $20,000 and $35,000 20%
Between $35,000 and $60,000 30%
More than $60,000 45%
Write a program that asks the user for their annual income and displays by
display the corresponding tax rate.
*/

#include <iostream>
using namespace std;

int main(){
    //Declaration of variables
    int renta,porcentaje;
    float impositivo;

    //It asks the user for their annual income and saves it
    cout<<"What is your annual income in pesos? "; cin>>renta;

    //Check that the user entered his income correctly
    if(renta<=0){
        cout<<"Please check the value of your rent well"<<endl;
    }

    //Check the income to see what percentage of tax corresponds
    else{
        if(renta<10000){
            porcentaje=5;
        }    
        
        else if(renta>=10000 && renta<20000){
            porcentaje=15;
        }

       else if(renta>=20000 && renta<35000){
            porcentaje=20;
        }

       else if(renta>=35000 && renta<60000){
            porcentaje=30;
        }    
            
         else if(renta>=60000){
            porcentaje=45;
         }

         //Prints the percentage and the value of the tax
        impositivo=renta*porcentaje/100;
        cout<<"Your tax is "<<porcentaje <<"%  and it will pay $"<<impositivo<<endl;
    }    

        

    return 0;
}

