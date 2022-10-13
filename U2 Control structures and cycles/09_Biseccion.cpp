/*
Date: 13/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

*/

#include <iostream>
# include <cmath>
using namespace std;

float ResolverEcuacion(float valor){

    return pow(valor,2)+3*(valor)+8;
}

int main(){

    float a=0,b=0,c=0,ya=0,yb=0,yc=0;
    cout<<"Give me the value of a: ";cin>>a;
    cout<<"Give me the value of b: ";cin>>b;
    c=(a+b)/2;
    ya=ResolverEcuacion(a);
    yb=ResolverEcuacion(b);
    yc=ResolverEcuacion(c);
    cout<<ya<<yb<<yc;
    return 0;
}