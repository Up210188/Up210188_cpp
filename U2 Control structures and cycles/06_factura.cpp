/*
Date: 5/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
*/

#include <iostream>

using namespace std;

int main(){

    int productos ;
    float precio=0,total=0;


    do
    {
        cout<<"How many products were sold? "; cin>>productos;
        if(productos > 0){
        cout<<"whitch are the price? "; cin>>precio;

        total +=(precio*productos);
        }

    } while (productos > 0);
    
    cout<<"The total bill is: $"<<total<<endl;
    return 0;

}