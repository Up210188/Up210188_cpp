/*
Date: 5/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
Write a program that converts from decimal to binary, only for numbers.
integers greater than 0. The result can be displayed as an integer variable or in a
character set.
*/
#include <iostream>

using namespace std;
int main(){
    //Declaration of variables
    int decimal;
    string resultado;

    
    do
    {
        //asks the user for the decimal number
        cout<<"Enter an integrer greater than zero: ";cin>>decimal;
        if (decimal>0)
        {
            //check that the number is greater than 0
            while (decimal !=0)
            {
                resultado=to_string(decimal%2)+resultado;
                decimal/=2;
            }
            cout<<"The number binary is: "<<resultado<<endl;
        }
        //check that the number is equal to 0
        else if(decimal==0){
            cout<<"The number in binary is: "<<decimal<<endl;
        }

        else {
            cout<<"ERROR: Please Enter an integrer greater than zero "<<endl;

        }
        
        
    } while (decimal!=0);
    


    return 0;
}