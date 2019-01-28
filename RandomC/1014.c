/*
*Run ID : 57347
*Jason Flynn : 201037312
*Assignment One Comp 281
*/

//include standered i/o library 
#include <stdio.h>

 // main thread 
 int main(){
	
	//variable declaration 
	int radOne, radTwo ; 
	double totArea, totCircum, tempArea, tempCircum, pi;
		
	pi = 3.14 ; // assigns value of pi 
		
	// while the value of radius 2 < value of radius 1
	// continue taking input from the user 	
 	do{
	   scanf("%d", &radOne) ; // sacn in value of small radius 
	   scanf("%d", &radTwo) ; // scan in value of large radius 
	}while (radTwo < radOne);	
	
	// while the value of the smaller radius is not equal to 
	// the value of the larger radius plus one 
	// continiue the loop. 	
	do{
	   tempArea = pi * (radOne * radOne) ; // calc the area of a single circe 
	   tempCircum =  (2 * pi) * radOne ;  // calc the circumfrence of a single circle 
			
	   totArea = totArea + tempArea ; // add single area calc to total 
	   totCircum = totCircum + tempCircum ; // add single circumfrence calc to total 
			
	   radOne++ ; //incraments the size of radius of smaller circle by 1  
	}while (radOne != radTwo + 1 ) ;
			
       printf("%.3f\n", totArea) ; // prints the total area 
       printf("%.3f\n", totCircum) ; // prints the total circumfrence 

	return 0 ;
}