/**
*Jason Flynn : 201037312
*Run ID : 71516
*Assignment 2 Comp 281 
*1029.c 
**/

//include standered I/O librery 
#include <stdio.h>

// main thread 
int main() {
	
    char storeString ; // variable declaration 
	
	//while the loop is active it will take in one input one at a time,
	//evaluating whetehr the charicters ASKII value falls between the given values
	//if it does, add three to the ASKII value and print it
	//all printouts are stored in the output buffer untill the system reads the 
	//escape sequence \n is used, then the programe will print the new string to the screen.
	//if the ASKII value does not fall between the given values it will print as it is. 
	while (scanf("%c", &storeString) != EOF) {
		
		//tests to see if the input is alphabetical and upper case
		if(storeString > 64 && storeString < 91 ){
			
			storeString = storeString + 3 ; // incraments the ASKKII value by 3 
			
			//these two lines a required to rap the output for boundry letters
			if(storeString > 90) storeString += -90 + 64 ; 
			if(storeString < 65) storeString += -64 + 90 ; 
			
			printf("%c", storeString) ;// prints the new charicter 
		
		}
		
		// tests if the input is alphabetical and lower case 
		else if(storeString > 96 && storeString < 123 ){
					
			storeString = storeString + 3 ; // increaments the ASKII value by 3 
			
			//these two lines ar required to rap the boundy input such as xyz 
			if(storeString > 122) storeString += -122 + 96 ; 
			if(storeString < 97) storeString += -96 + 122 ; 
			
			printf("%c", storeString) ; // prints the new charicter 
				
		}
		
		// checks to see if input is a new line 
		else if (storeString == '\n') {
						break ; 
		}
		
		// if the input is not within the bounds of the upper/lower case letters and is not
		// the escape sequence \n, simply print out the input 
		else {
			printf("%c", storeString) ;
		}
	}

	return 0 ; 
}