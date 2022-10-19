/*
Date: 13/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:

*/

#include <iostream>
# include <cmath>
#include <iomanip>
using namespace std;

float ResolverEcuacion(float valor){

    return pow(valor,2)+(valor)-6;
}

int main(){
    int raiz=0;
    float a=0,b=0,c=0,ya=0,yb=0,yc=0,error=0.01;
    cout<<"Give me the value of a: ";cin>>a;
    cout<<"Give me the value of b: ";cin>>b;
    cout<<endl;
    
    cout<<"|a\t|"<<"b\t|"<<"c\t|"<<"ya\t|"<<"yb\t|"<<"yc\t|"<<endl;
    for(int guion=0;guion<49;guion++){
            cout<<"-";
         }
    cout<<endl;
    do
    {
        c=(a+b)/2;
        ya=ResolverEcuacion(a);
        yb=ResolverEcuacion(b);
        yc=ResolverEcuacion(c);

        
         cout<< fixed <<setprecision(2)<<"|"<<a<<"\t|"<<b<<"\t|"<<c<<"\t|"<<ya<<"\t|"<<yb<<"\t|"<<yc<<"\t|"<<endl;
         for(int guion=0;guion<49;guion++){
            cout<<"-";
         }
         cout<<endl;
         if(ya*yc<0){
            b=c;

        }
        else if(yb*yc<0){
            a=c;
        }
        else{
            
            raiz=1;
            cout<<"The root does not exist in this interval"<<endl;
            break;
        }
        
    } while (abs(yc)>=error);
    cout<<endl;
    if(raiz=0){
    cout<<"The root is: "<<c<<endl;
    }
    return 0;
}