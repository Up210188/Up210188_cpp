/*
Date: 18/09/2022
Unidad:1
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description: Data types in C++
*/

//Library for managing screen inputs and outputs
#include <iostream>

//Using the namespace to avoid the std::
using namespace std;

//integer main function
int main()
{

    int entero = 6;
    float flotante = 4.54638291876;
    double grande = 4.54638291876;
    char caracter = 37;
    
    cout << "This program shows the types of data. \n";
    cout << "The whole number is: " << entero << endl;
    cout << "The size of the integer is: " << sizeof(entero) << "bytes" << endl;
    cout << "The float number is:" << flotante << endl;
    cout << "The float size is: " << sizeof(flotante)<< "bytes" << endl;
    cout << "The double number is: " << grande << endl;
    cout << "The size of the double is: " << sizeof(grande)<< "bytes" << endl;
    cout << "The char character is: " << caracter << endl;
    cout << "The char size is: " << sizeof(caracter)<< "byte" << endl;
    
    return 0;
}
