

#include <iostream>

using namespace std;
void ConstruirTablero();

int main(){
    
  

   
    

    return 0;
}

ConstruirTablero(){
  

    for(int i=0; i<6; i++){
        for (int j = 0; j < 3; j++)
        {
            if(i<5 && i%2==1){

                cout<<"___";
            }
            else {
                cout<<"   ";
            }

            if(j<2){
                cout<<"|";
            }
            cout<<endl;
        }
        
    }

}