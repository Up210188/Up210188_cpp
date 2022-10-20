/*
Date: //2022
Unidad:3
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

*/

#include <iostream>

using namespace std;
int getMaxVal(int num1, int num2);
int main(){
    int numero1,numero2,valorMax;

    cout<<"dame el primer numero: ";cin>>numero1;
    cout<<"dame el segundo numero: ";cin>>numero2;

    valorMax=getMaxVal(numero1,numero2);

    cout<<"el numero mayor es: "<<valorMax;



    

    return 0;
}

int getMaxVal(int num1, int num2){

    return (num1>num2)?num1:num2;
}