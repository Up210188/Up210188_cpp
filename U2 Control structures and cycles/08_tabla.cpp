/*
Date: 12/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
make a program that asks the user what number he wants to multiply and to where and prints it in a table
*/

#include <iostream>
using namespace std;

int main(){
    //Declaration of variables
    int numeroMult,hastaDonde;

    //asks the user what number he wants to multiply
    cout<<"What number do you want to multiply? ";cin>>numeroMult;
    //asks the user how many numbers he wants to multiply
    cout<<"Up to what number do you want the table? ";cin>>hastaDonde;cout<<endl;

    //prints the number multiplied to where the user said
    for (int contador=1;contador<=hastaDonde;contador++){
        cout<<"|"<<contador<<"\t|"<<"x\t|"<<numeroMult<<"\t"<<"|=\t|"<<contador*numeroMult<<"\t|"<<endl;

        //print the multiplications in a table
        for (int guion=1; guion<42; guion++)
        {
            cout<<"-";
        }
        
        cout<<endl; 
    }


    


    return 0;
}