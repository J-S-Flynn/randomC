/*
*Run ID : 57266
*Jason Flynn : 201037312
*Assignment One Comp 281
*/

// include the satndered i/o librery 
#include <stdio.h> 

// main thread 
int main() {
	
	char store ; //store letters to send to buffer
	char omit ; // stores letter to be omited 
	
	scanf("%c", &omit) ; // scans in letter to omit
	scanf("%c", &store) ; // scans in all other letters 
	
	
	// while loop runs until the end of file 
	// if it incounters an escape sequence \n 
	while (scanf("%c", &store) != EOF) {
		
		// if the letter being stored is not the same as omit
		// print it out. stored in the display buffer
		// if it is not we can ignore it compleatly 
		if (store != omit) {
			printf("%c", store) ;
		}
		if (store == '\n') {
			break ; 
		}
		
	}
	
	return 0 ;
	
}