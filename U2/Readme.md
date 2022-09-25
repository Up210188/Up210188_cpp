# UNIT 2 PROGRAMS
 
 ## ***Exercise 1***
  ### Description:
  ##### This program asks the user how much his annual income is and if it is less than 10,000 he pays 5% tax, if it is from 10,000 to 20,000 he pays 15%, if the income is from 20,000 to 35,000 he pays 20%, if it is from 35,000 to 60,000 pay 30% and if it is more than 60,000 pay 45%.
  ### Tax selection section:
  ///c++
    if(renta<10000){
            porcentaje=5;
        }    
        
        if(renta>=10000 && renta<20000){
            porcentaje=15;
        }

        if(renta>=20000 && renta<35000){
            porcentaje=20;
        }

        if(renta>=35000 && renta<60000){
            porcentaje=30;
        }    
            
         if(renta>=60000){
            porcentaje=45;
         }
  ///       
         
 
