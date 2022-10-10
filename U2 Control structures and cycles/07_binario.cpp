/*
Date: 5/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
*/
#include <iostream>

using namespace std;
int main(){

    int decimal;
    string resultado;

    
    do
    {
        cout<<"Enter an integrer greater than zero: ";cin>>decimal;
        if (decimal>0)
        {
            while (decimal !=0)
            {
                resultado=to_string(decimal%2)+resultado;
                decimal/=2;
            }
            cout<<"The number binary is: "<<resultado<<endl;
        }
        else if(decimal==0){
            cout<<"The number in binary is: "<<decimal<<endl;
        }

        else {
            cout<<"ERROR: Please Enter an integrer greater than zero "<<endl;

        }
        
        
    } while (decimal!=0);
    


    return 0;
}