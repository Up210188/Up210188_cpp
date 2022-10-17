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

    return pow(valor,2)+(valor)-6;
}

int main(){

    float a=0,b=0,c=0,ya=0,yb=0,yc=0,error=0.01;
    cout<<"Give me the value of a: ";cin>>a;
    cout<<"Give me the value of b: ";cin>>b;
    c=(a+b)/2;

    do
    {
    
        ya=ResolverEcuacion(a);
        yb=ResolverEcuacion(b);
        yc=ResolverEcuacion(c);

cout <<a"\t"<<b"\t"<<c"\t"<<ya"\t"<<yb"\t"<<yc"\t"<<endl;
         if(ya*yc<0){
            b=c;

        }
        else if(yb*yc<0){
            a=c;
        }
        else{
            cout<<"The root does not exist in this interval"
        }
        
    } while (abs(yc)>=error);
    
    return 0;
}