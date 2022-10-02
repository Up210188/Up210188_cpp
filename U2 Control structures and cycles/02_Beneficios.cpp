/*
Date: 26/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
In a certain company, its employees are evaluated at the end of each year.
The points that can be obtained in the evaluation start at 0.0 and can go up,
translating into better benefits. The points you can get
employees can be 0.0, 0.4, 0.6 or more, but not intermediate values
between the figures mentioned. Below is a table with the
levels corresponding to each score. The amount of money earned
on each level is $2,400 multiplied by the level score.

Level Score
Unacceptable 0.0
Acceptable 0.4
Merit 0.6 or more
Write a program that reads the user's score and indicates their level of performance,
as well as the amount of money the user will receive.
*Thank you very much for choosing us! We hope to serve you again.*/

#include <iostream>

using namespace std;


int main(){
    //Declaration of variables
    double calificacion;
    float porcentaje,dineroConseguido;

    //Ask the user for the employee's qualification
    cout<<"Enter the qualification of the worker: "; cin>>calificacion;

    //Analyze the qualification to know what percentage of the bonus the employee will obtain
    if(calificacion==0.0||calificacion==0.4||calificacion>=0.6&&calificacion<=1){

        dineroConseguido= 2400*calificacion;
        porcentaje=calificacion*100;
        cout<<"Your bonus percentage is "<<porcentaje<<"% and your benefit is $"<<dineroConseguido<<endl;
    }

    //Check that the rating was correct
    else{
        cout<<"Please check your rating "<<endl;
    }

    

    return 0;
}

    

