


#include <iostream>
using namespace std;

int main(){
;
    int menu,ingredientes;
    string pizza,ingredientesPalabra;

    
    cout<<"Do you want a vegetarian pizza? yes=1 no=2 ";cin>>menu;

    if(menu==1){
        cout<<"Please choose only one ingredient"<<endl;
        cout<<"Do you want a peppers? yes=1"<<endl<<"Do you want a tofu? yes=2 "<<endl<<"You answer is: ";
        cin>>ingredientes;
        if(ingredientes==1){
            cout<<" Your pizza is vegetarian and the ingredient is pappers"<<endl;
        }
        else if(ingredientes==2){
            cout<<" Your pizza is vegetarian and the ingredient is tofu"<<endl;
        }

        else{
            cout<<"Please choose a ingredient"<<endl;
        }
    }
    
    else if(menu==2){
        cout<<"Please choose only one ingredient"<<endl;
        cout<<"Do you want a peppers? yes=1"<<endl<<"Do you want a tofu? yes=2 "<<endl<<"You answer is: ";
        cin>>ingredientes;
        if(ingredientes==1){
            cout<<" Your pizza is vegetarian and the ingredient is pappers"<<endl;
        }
        else if(ingredientes==2){
            cout<<" Your pizza is vegetarian and the ingredient is tofu"<<endl;
        }

        else{
            cout<<"Please choose a ingredient"<<endl;
        }
    }
    return 0;
}