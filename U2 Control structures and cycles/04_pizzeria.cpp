/*
Date: 29/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
The Bella Napoli pizzeria offers vegetarian and non-vegetarian pizzas to its customers. The
Ingredients for each type of pizza are listed below.
*Vegetarian ingredients: Pepper and tofu.
*Non-vegetarian ingredients: Pepperoni, Ham and Salmon.
Write a program that asks the user if he wants a vegetarian pizza or not, and in
Based on your answer, show you a menu with the ingredients available for you to choose from.
You can only choose one ingredient besides the mozzarella and the tomato that are in all the
pizza.
At the end it should be shown on the screen if the chosen pizza is vegetarian or not and all the
ingredients it contains.
*/

#include <iostream>
using namespace std;

int main(){
;   //Declaration of variables
    int menu,ingredientes;
    
    // ask the user whitch pizza he wants
    cout<<"Do you want a vegetarian pizza? yes=1 no=2 ";cin>>menu;

    //shows the ingredients of the vegetarian pizza
    if(menu==1){
        //the user can choose the ingredient for the vegetarian pizza
        cout<<"Please choose only one ingredient"<<endl;
        cout<<"Do you want a peppers? yes=1"<<endl<<"Do you want a tofu? yes=2 "<<endl<<"You answer is: ";
        cin>>ingredientes;
        if(ingredientes==1){
            cout<<" Your pizza is vegetarian and the ingredients are the mozzarella, the tomato and pappers"<<endl;
        }
        else if(ingredientes==2){
            cout<<" Your pizza is vegetarian and the ingredients are the mozzarella, the tomato and tofu"<<endl;
        }
        //print the error in the ingredients
        else{
            cout<<"Please choose a ingredient"<<endl;
        }
    }
    //shows the ingredients of the non-vegetarian pizza
    else if(menu==2){
        //the user can choose the ingredient for the non-vegetarian pizza
        cout<<"Please choose only one ingredient"<<endl;
        cout<<"Do you want a pepperoni? yes=1"<<endl<<"Do you want a ham? yes=2 "<<endl<<"Do you want a salmon? yes=3"<<endl<<"You answer is: ";
        cin>>ingredientes;
        if(ingredientes==1){
            cout<<" Your pizza isn't vegetarian and the ingredients are the mozzarella, the tomato and pepperoni "<<endl;
        }
        else if(ingredientes==2){
            cout<<" Your pizza isn't vegetarian and the ingredients are the mozzarella, the tomato and ham"<<endl;
        }

        else if(ingredientes==3){
            cout<<" Your pizza isn't vegetarian and the ingredients are the mozzarella, the tomato and salmon"<<endl;
        }
        //print the error in the ingredients
        else{
            cout<<"Please choose a ingredient"<<endl;
        }
    }
    //print the error in the pizza

    else{
        cout<<"Please choose a pizza"<<endl;
    }
    return 0;
}