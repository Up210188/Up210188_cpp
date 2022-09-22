/*
Date: 21/09/2022
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description: Entrada de datos en C++
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int numero;
    float flotante;
    double grande;
    char caracter;
//imprime un numero entero con iostream
   /* cout<<"teclee un numero de tipo entero: "; cin>>numero;

    cout<< "El numero guardado es: "<<numero<<endl;
// imprime un numero flotante
      cout<<"teclee un numero de tipo flotante: " ;cin>>flotante;
      
    cout<< "El numero guardado es: "<<flotante<<endl;
// imprime un numero  double
      cout<<"teclee un numero de tipo  double: "; cin>>grande;
     
    cout<< "El numero guardado es: "<<grande<<endl;

    // imprime un digito en char
      cout<<"teclee un caracter: "; cin>>caracter;
     
    cout<< "El caracter guardado es: "<<caracter<<endl;

//------------------usando stdio.h-------------------------
    cout<<endl;
    cout<< "imprime con stdio.h \n";
    
//numero entero
   printf("Dame un numero entero: ");
    scanf("%d",&numero);
    printf("El numero es: %d",numero);
    printf("\n");*/

//numero flotante
    printf("Dame un numero flotante: ");
    scanf("%f",&flotante);
    printf("El numero es: %f",flotante);
    printf("\n");


//caracter 
    printf("Dame un caracter: ");
    scanf("%c",&caracter);
    printf("El caracter es: %c",caracter);
    printf("\n");


    return 0;


}


