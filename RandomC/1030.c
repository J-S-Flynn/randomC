/*
*Run ID : 57692
*Jason Flynn : 201037312
*Assignment One Comp 281
*/

// include standered i/o library 
#include<stdio.h>

// main thread 
int main() {
	
	// declaration of variables 
	int a, b, n, output, mult ;
	int divHold, remHold ; 
	
	mult = 10 ; // assigns 10 to mult 

// loops while there are inputs greater than 6000 
while (a > 6000 || b > 6000 || n > 6000) {
	scanf("%d", &a) ;// assigns input value for a to memory 
	scanf("%d", &b) ;// assigns input value for b to memory  
	scanf("%d", &n) ;// assigns input value for n to memory 
}	
	remHold = a % b ; // assigns the remander of the a % b to remHold 
	
	// the loop will multiply untill it finds the int 
	// equil in position to the valu of n 
	for (int i = 0 ; i < n ; i++) {
		
		int temp = remHold * mult % b ; // temp stors the value of remHold * 10 mod b 
		divHold = remHold * mult / b ; // divHold stores val of remHold * 10 divided by b 
		remHold = temp ;  // sets the value of remHold to temp 
		
	}
	printf("%d", divHold) ; // prints out divHold 
	
	return 0 ; 
}