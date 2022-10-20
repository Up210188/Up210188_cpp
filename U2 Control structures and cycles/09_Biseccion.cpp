/*
Date: 13/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
write a program that solves a root by the bisection method
*/

#include <iostream>
# include <cmath>
#include <iomanip>
using namespace std;


//Function to evaluate the function
float ResolverEcuacion(float valor){
    //function declaration
    return pow(valor,2)+(valor)-6;
}

int main(){
    int raiz=0;
    float a=0,b=0,c=0,ya=0,yb=0,yc=0,error=0.01;
    //Ask the value of A
    cout<<"Give me the value of a: ";cin>>a;
    //Ask the value of B
    cout<<"Give me the value of b: ";cin>>b;
    cout<<endl;
    //Print the title of the table
    cout<<"|a\t|"<<"b\t|"<<"c\t|"<<"ya\t|"<<"yb\t|"<<"yc\t|"<<endl;
    for(int guion=0;guion<49;guion++){
            cout<<"-";
         }
    cout<<endl;
    do
    {
        //Get the value of C
        c=(a+b)/2;
        ya=ResolverEcuacion(a);
        yb=ResolverEcuacion(b);
        yc=ResolverEcuacion(c);

        //prints the value of a, b, c, ya, yb, yc
         cout<< fixed <<setprecision(2)<<"|"<<a<<"\t|"<<b<<"\t|"<<c<<"\t|"<<ya<<"\t|"<<yb<<"\t|"<<yc<<"\t|"<<endl;
        
        //print the table
        for(int guion=0;guion<49;guion++){
            cout<<"-";
        }
        //verify that in the multiplication of ya and yc the sign changes
         cout<<endl;
        if(ya*yc<0){
            b=c;

        }
        //verify that in the multiplication of yb and yc the sign changes
        else if(yb*yc<0){
            a=c;
        }
        //prints that the root does not exist
        else{
            
            raiz=1;
            cout<<"The root does not exist in this interval"<<endl;
            break;
        }
       //the loop ends when yc is equal to the error 
    } while (abs(yc)>=error);
    cout<<endl;

    //verify that root exists
    if(raiz!=1){
        //print the root
        cout<<"The root is: "<<c<<endl;
    }
    return 0;
}

