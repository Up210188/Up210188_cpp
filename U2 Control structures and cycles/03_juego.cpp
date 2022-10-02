/*
Date: 28/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
Write a program for a company that has game rooms for all ages and wants 
to automatically calculate the price to charge its customers to enter. The
The program must ask the user for the customer's age and display the price of the ticket. Yes
the client is under 4 years old can enter for free, if they are between 4 and 18 years old they 
must pay $5 and if they are over 18 years old, $10.
*/

#include <iostream>
using namespace std;

int main(){
    //Declaration of variables
    int edad,precio;

    //ask the client's age
    cout<<"How is the age of the client? "; cin>>edad;

    //check that the age is correct
    if(edad<0){
        cout<<"Please check the age"<<endl;
    }
    //check the age to see how much the client will pay
    else{
         if(edad>=0&&edad<4){
            precio=0;
        }
        else if(edad>=4&&edad<=18){
            precio=5;
        }
        else {
            precio=10;
        }

        //print the price of the ticket
        cout<<"The price of the ticket is $"<<precio<<endl;
    }



    return 0;
}