/*
Date: 12/10/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
*/

#include <iostream>
using namespace std;

int main(){
    //Declaration of variables
    int numeroMult,hastaDonde;

    cout<<"What number do you want to multiply? ";cin>>numeroMult;
    cout<<"Up to what number do you want the table? ";cin>>hastaDonde;cout<<endl;

    for (int i=1;i<=hastaDonde;i++){
        cout<<"|"<<i<<"\t|"<<"x\t|"<<numeroMult<<"\t"<<"|=\t|"<<i*numeroMult<<"\t|"<<endl;
        for (int guion=1; guion<42; guion++)
        {
            cout<<"-";
        }
        
        cout<<endl; 
    }


    


    return 0;
}