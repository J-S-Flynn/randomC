/**
*Jason Flynn : 201037312
*Run ID : 71498
*Assignment 2 Comp 281 
*1032.c
**/

/*
*i have no run id for this as i cannot seem to get it to work on online judge. on my system i am 
*get the correct answer for every test i run, but cannot replicate it for OJ. 
*/

#include <stdio.h> // include the standered I/O library 

//main thread 
int main() {
	
	//declaration of variables 
	char strOne[100] ; //arrays for holding string vallues. strOne is the string to be checked
	char strTwo[100] ; //strTwo is the first string that we are checking for
	char strThree[100] ; //strThree is the second string we are testing for 
	
	int i, j, k, l, subOne, subTwo ;
 	i = j = k = l = subOne = subTwo = 0 ;
	
	fgets(strOne, 100, stdin) ; // get string one
	fgets(strTwo, 100, stdin) ; // get string two
	fgets(strThree, 100, stdin) ; //get string three
	
	
	//loop that will test the first letter of ether of the given strings against that of the first string.
	//if they match then mive to the next letter of ether of the strings we are searching for. 
	//if this continue until the search string reachis the escape sequence \0 then we can assume 
	//that the string is there. 
	while (strOne[i] != '\0') {
		
		if(strTwo[j] == strOne[i]){
			j++ ; //incraments to the next value in strTwo if the first letter is found
		}
		else{
			j = 0 ; //if strTwo[j] != strOne[i] return strTwo back to the first element
		}           
		if (strTwo[j+1] == '\0'){//if we reach the end of strTwo set back to the first element incramet
			j = 0 ;              //subOne  
			subOne ++ ;
		}
		
		if(strThree[k] == strOne[i]){
			k++ ; //incraments to the next value in strThree if the first letter is found
		}
		else{
			k = 0 ; //if strThree[k] != strOne[i] return strTwo back to the first element
		}
		if (strThree[k+1] == '\0'){//if we reach the end of strTwo set back to the first element incramet
			k = 0 ;                //subTne
			subTwo ++ ;
		}
		i++ ; //incraments value of i to itterate thru the array of strOne
	} 

	
	printf("%d %d", subOne, subTwo) ; //print subOne and subTwo 

	return 0 ;
}

