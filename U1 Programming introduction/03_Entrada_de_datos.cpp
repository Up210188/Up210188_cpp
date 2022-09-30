/*
Date: 21/09/2022
Unidad:1
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description: data entry in C++
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int numero;
    float flotante;
    double grande;
    char caracter;

    //------------WEARING IOSTREAM--------------
    //print an integer
    cout<<"Wearing iostream"<<endl;
    cout<<"type an integer number: "; cin>>numero;

    cout<< "The saved number is: "<<numero<<endl;
    // print a float number
    cout<<"type a floating type number: " ;cin>>flotante;
      
    cout<< "The saved number is: "<<flotante<<endl;
    // print a double number
    cout<<"type a number of type double: "; cin>>grande;
     
    cout<< "The saved number is: "<<grande<<endl;

    // print a digit in char
    cout<<"type a chart: "; cin>>caracter;
     
    cout<< "The saved character is: "<<caracter<<endl;

    //------------------WEARING STDIO.H-------------------------
    cout<<endl;
    cout<< "Print with stdio.h \n";
   
    //integer integer number
    printf("give me an integer number: ");
    scanf("%d",&numero);
    printf("The number is: %d",numero);
    printf("\n");

    //floating number
    printf("give me an floating number: ");
    scanf("%f",&flotante);
    printf("The number is: %f",flotante);
    printf("\n");

    // double number
    printf("Give me a double number: ");
    scanf("%lf",&grande);
    printf("The number is: %lf",grande);
    printf("\n");


    //character 
    printf("Give me a character: ");
    scanf("%s",&caracter);
    printf("The character is: %c",caracter);
    printf("\n");


    return 0;


}



