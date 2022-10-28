/*
Date: 27/10/2022
Unidad:3
Author:Osvaldo Esparza Gutierrez
Email: up210188@alumnos.upa.edu.mx
Description:get the change in coins and bills using arrays

*/

#include <iostream>

using namespace std;

void obtenerCambio(int);
void imprimirCambio();

int denominaciones[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int cantidadBilletes[9] = {0};

int main()
{

    int dinero;

    cout << "Enter the money: ";
    cin >> dinero;

    obtenerCambio(dinero);

    imprimirCambio();
    

    return 0;
}

void obtenerCambio(int monto)
{
    int residuo =0;
    for (int denominacion = 0; denominacion < 9; denominacion++)
    {
        residuo = (denominacion == 0) ? monto : residuo;
        cantidadBilletes[denominacion] = residuo / denominaciones[denominacion];
        residuo = residuo % denominaciones[denominacion];
    }
}

void imprimirCambio(){

for(int posicion=0;posicion<9;posicion++){

    string tipo= (posicion<5)? "billetes":"monedas";

    cout<<tipo<<"de $"<<denominaciones[posicion]<<" son : "<<cantidadBilletes[posicion]<<endl;
}

}