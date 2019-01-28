/*
*Run ID : 57251
*Jason Flynn : 201037312
*Assignment One Comp 281
*/

// include standered i/o library 
#include <stdio.h>

// main thread 
int main() {
	
	// veariable declaration and assignment 
	int input ; // user input 
	int out[10] = {0}; // array to store output 
	int eveHold[10] = {0}; // array to store any ven numbers for sorting 
	int j, x, y ; // incramneter vars 
	j = x = y = 0 ;

	// while i < 10 take int from user 
	for (int i = 0; i < 10 ; i++) {
		scanf("%d", &input) ; // scans in the int 
		
		// if the input % 2 results in zero add to eveHold 
		if (input % 2 == 0) {
			eveHold[x] = input ;
			x++ ; y++ ;	// incraments both arrays to hold space for merging 				
		}else {
			out[y] = input ;// if %2 != 0 store input in out 
			y++ ; // incrament the out arry only 
		}
	}
	
	//beginging at 0 for eveHold messures the next value in the list 
	//for all values to see if it is greter than it. if it is switch the two values
	for (x = 0 ; x < 10 ; x++ ) {
		for (int k = 0 ; k < 10 ; k++) {
			if(eveHold[k] > eveHold[x] && eveHold[x] != 0){
				int temp = eveHold[x] ; // temp takes value of eveHold[x]
				eveHold[x] = eveHold[k] ;// eveHold[x] takes value of eveHold[k]
				eveHold[k] = temp ; // eveHold[k] takes value of temp (origanal val of eveHold[x]
			}	
		}
	}
	
	// intergarts the sorted array into the empty locations of the out array 	// each value is then printed out 
	for (x = 0 ; x < 10 ; x++) {
		
		// if x % 2 returns 1 ignor it and check the next val
		// if it does not return 1 add val of x = j  
		if(out[x] % 2 != 1 ){
			out[x] = eveHold[j] ;
			j++ ;  
		}
		printf("%d ", out[x]) ; // prints out val of Array[x]
	} 
	
	return 0 ; 
}