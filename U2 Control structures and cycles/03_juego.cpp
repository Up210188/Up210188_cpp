

#include <iostream>
using namespace std;

int main(){

    int edad,precio;

    cout<<"How is the age of the client? "; cin>>edad;

    if(edad<0){
        cout<<"Please check the age"<<endl;
    }

    else{
         if(edad>=0&&edad<4){
            precio=0;
        }
        else if(edad>=4&&edad<=18){
            precio=5;
        }
        else if(edad>18){
            precio=10;
        }

        cout<<"The price of the ticket is $"<<precio<<endl;
    }



    return 0;
}