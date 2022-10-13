/*
Date: 5/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
Make a program that reads indefinitely quantities of products and their price, and at the end
indicate the total of the invoice. To know that the purchase has been completed, you must
enter a 0 in the amount.
*/

#include <iostream>

using namespace std;

int main(){
    //Declaration of variables
    int productos ;
    float precio=0,total=0;


    do
    {
        //ask the user how many products there are
        cout<<"How many products were sold? "; cin>>productos;
        //Check if the user finalized the invoice
        if(productos > 0){
            //Ask the user the price of the product
            cout<<"whitch are the price? "; cin>>precio;
            //multiply the price by the number of products
            total +=(precio*productos);
        }
    //repeat all the products that the user wants
    } while (productos > 0);
    //print the invoice price
    cout<<"The total bill is: $"<<total<<endl;
    return 0;

}