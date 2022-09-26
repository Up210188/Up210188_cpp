/*
Date: 26/09/2022
Unidad:2
Author:Osvaldo Esparza Gutierrez 
Email: up210188@alumnos.upa.edu.mx
Description:
En una determinada empresa, sus empleados son evaluados al final de cada año. 
Los puntos que pueden obtener en la evaluación comienzan en 0.0 y pueden ir aumentando, 
traduciéndose en mejores beneficios. Los puntos que pueden conseguir 
los empleados pueden ser 0.0, 0.4, 0.6 o más, pero no valores intermedios 
entre las cifras mencionadas. A continuación se muestra una tabla con los 
niveles correspondientes a cada puntuación. La cantidad de dinero conseguida
en cada nivel es de $2,400 multiplicada por la puntuación del nivel.

Nivel	Puntuación
Inaceptable	0.0
Aceptable	0.4
Meritorio	0.6 o más
Escribir un programa que lea la puntuación del usuario e indique su nivel de rendimiento, 
así como la cantidad de dinero que recibirá el usuario.
*¡Muchas gracias por preferirnos! Esperamos poder servirte nuevamente.*/

#include <iostream>

using namespace std;


int main(){
    //Declaración de vavriables
    double calificacion;
    float porcentaje,dineroConseguido;

    //Pregunta al usuario la calificacion del empleado
    cout<<"Digite la calificacion del trabajador: "; cin>>calificacion;

    //Analiza la calificacion para saber que porcentaje del bono obtendra el empleado
    if(calificacion==0.0||calificacion==0.4||calificacion>=0.6&&calificacion<=1){

        dineroConseguido= 2400*calificacion;
        porcentaje=calificacion*100;
        cout<<"Su porcentaje de bono es "<<porcentaje<<"% y su beneficio es $"<<dineroConseguido<<endl;
    }

    //Revisa que la calificación se puso bien
    else{
        cout<<"Favor de revisar su calificación "<<endl;
    }

    

    return 0;
}

    

