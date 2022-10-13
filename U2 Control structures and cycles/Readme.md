# UNIT 2 CONTROL STRUCTURES AND CYCLES
 
 <img alt="Cycles" height="400" src="https://github.com/Up210188/Up210188_cpp/blob/main/imagenes/ciclos-de-programacion.jpg"/>
 
## ***DESCRIPTION***
In this unit we are going to work with some cycles such as: while, do while and for. We are also going to have to use creativity and intelligence to be able to develop a fast and efficient program.
 
 ## ***UNIT EXERCISES***

 ## ***EXERCISE 1***

 ### Description:
 This program asks the user how much his annual income is and if it is less than 10,000 he pays 5% tax, if it is from 10,000 to 20,000 he pays 15%,  if the income is from 20,000 to 35,000 he pays 20%, if it is from 35,000 to 60,000 pay 30% and if it is more than 60,000 pay 45%.

 ### Data entry:
```c++
        //It asks the user for their annual income and saves it
        cout<<"What is your annual income in pesos? "; cin>>renta;
```

 ### Process:
  
  ```c++
        //Check that the user entered his income correctly
        if(renta<=0){
        cout<<"Please check the value of your rent well"<<endl;
        }

        //Check the income to see what percentage of tax corresponds
        else{
            if(renta<10000){
            porcentaje=5;
            }    
        
            else if(renta>=10000 && renta<20000){
            porcentaje=15;
            }

            else if(renta>=20000 && renta<35000){
            porcentaje=20;
            }

            else if(renta>=35000 && renta<60000){
            porcentaje=30;
            }    
            
            else if(renta>=60000){
            porcentaje=45;
            }

            //Prints the percentage and the value of the tax
            impositivo=renta*porcentaje/100;
            cout<<"Your tax is "<<porcentaje <<"%  and it will pay $"<<impositivo<<endl;
        }
  ```    
  ### Data output:
  ``` c++
        cout<<"Please check the value of your rent well"<<endl;
       
        cout<<"Your tax is "<<porcentaje <<"%  and it will pay $"<<impositivo<<endl;
  ```
### Explanation:
1.- first ask the user what his annual income is.

2.- Then check that the rent is correct and if it is incorrect it prints Error.

3.-Afterwards, with an if, compare the income to know which tax percentage corresponds to it.

4.- Then multiply the percentage by the rent and divide by 100.

5.- Finally, print the corresponding tax.
   ### Tests:
Case A: The user mistyped the rent.

<img alt="1.1" height="50" src="../imagenes/1.1.png"/> 

Case B: The user pays less than 10,000.

<img alt="1.2" height="40" src="../imagenes/1.2.png"/> 

Case C: The user pays between 10,000 and 20,000.

<img alt="1.3" height="40" src="../imagenes/1.3.png"/> 

Case D: The user pays between 20,000 and 35,000.

<img alt="1.6" height="40" src="../imagenes/1.6.png"/> 

Case E: The user pays between 35,000 and 60,000.

<img alt="1.4" height="40" src="../imagenes/1.4.png"/> 

Case F: The user pays more than 60,000.

<img alt="1.5" height="40" src="https://github.com/Up210188/Up210188_cpp/blob/main/imagenes/1.5.png"/>  

## ***EXERCISE 2***
### Description:
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
*Thank you very much for choosing us! We hope to serve you again.
 
### Data entry:
```c++
        //Ask the user for the employee's qualification
          cout<<"Enter the qualification of the worker: "; cin>>calificacion;
```

### Process:
  
  ```c++
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
  ```    
### Data output:
  ``` c++
        cout<<"Your bonus percentage is "<<porcentaje<<"% and your benefit is $"<<dineroConseguido<<endl;
        cout<<"Please check your rating "<<endl;
  ```
### Explanation:
1.-First ask the qualification of the worker.

2.- Then, with an if, analyze that the rating is 0.0 or 0.4 or greater than 0.6 and less than 1.

3.- If the rating is incorrect, print Please check your rating.

4.- If the rating is correct, multiply the rating by 24000 and then multiply the rating by 100 to get the percentage.

5.- Finally, print the percentage and benefit.

### Tests:
Case A:

<img alt="2.1" height="40" src="../imagenes/2.1.png"/> 

Case B:

<img alt="2.2" height="40" src="../imagenes/2.2.png"/> 


Case C:

<img alt="2.3" height="40" src="../imagenes/2.3.png"/> 

Case D:

<img alt="2.4" height="40" src="../imagenes/2.4.png"/> 

## ***EXERCISE 3***
### Description:
 
### Data entry:

  ```c++
       
  ```   

### Process:
  
  ```c++
       
  ```    
### Data output:
  ``` c++
        
  ```
### Explanation:

### Tests:
Case A:

<img alt="3.1" height="40" src="../imagenes/3.1.png"/> 

Case B:

<img alt="3.2" height="40" src="../imagenes/3.2.png"/> 

Case C:

<img alt="3.3" height="40" src="../imagenes/3.3.png"/> 

Case D:

<img alt="3.4" height="40" src="../imagenes/3.4.png"/> 

## ***EXERCISE 4***
### Description:
 
### Data entry:

    ```c++
        
    ```

### Process:
  
  ```c++
       
  ```    
### Data output:
  ```c++
       
  ``` 
### Explanation:

### Tests:

Case A:

<img alt="4.1" height="75" src="../imagenes/4.1.png"/> 

Case B:

<img alt="4.2" height="75" src="../imagenes/4.2.png"/> 

Case C:

<img alt="4.3" height="75" src="../imagenes/4.3.png"/> 

Case D:

<img alt="4.4" height="75" src="../imagenes/4.4.png"/> 

Case E:

<img alt="4.5" height="75" src="../imagenes/4.5.png"/> 

Case F:

<img alt="4.6" height="75" src="../imagenes/4.6.png"/> 

Case G:

<img alt="4.7" height="75" src="../imagenes/4.7.png"/> 

Case H:

<img alt="4.8" height="60" src="../imagenes/4.8.png"/> 

## ***EXERCISE 5***
### Description:
 
### Data entry:
    ```c++
       
  ``` 


### Process:
  
  ```c++
       
  ```    
### Data output:
  ``` c++
        
  ```
### Explanation:

### Tests:

## ***EXERCISE 6***
### Description:
 
### Data entry:
    ```c++
       

    ``` 

### Process:
  
  ```c++
       
  ```    
### Data output:
  ``` c++
        
  ```
### Explanation:

### Tests:

## ***EXERCISE 7***
### Description:
 
### Data entry:
    ```c++
       
    ``` 


### Process:
  
  ```c++
       
  ```    
### Data output:
  ``` c++
        
  ```
### Explanation:

### Tests:

## ***EXERCISE 8***
### Description:
 
### Data entry:
    ```c++
       
  ``` 


### Process:
  
  ```c++
       
  ```    
### Data output:
  ``` c++
        
  ```
### Explanation:

### Tests: