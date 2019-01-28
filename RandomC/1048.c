/**
*Jason Flynn : 201037312
*Run ID : 84712
*Assignment 2 Comp 281
*1048.c
*progreamme is designed to sort the dates given in the format Month Day Year 
*it also alows the user to input input a numerical format of the date to see if the date is 
*part of the programmes infut 
**/

#include <stdio.h> // include standered I/O library 
#include <stdlib.h> // include standered library 
#include <string.h> // include string 

//structuere defines the input of date. taking a selection of intigers and 
//treating them as a single value. 
struct date{
    int month ;
    int year ;
    int day ;
};

//comp is used to compare the values of any two given date structs to evauate which is the highest 
//it is needed to use the qsort and qsort will need to refer to it as the sorting citeria 
//takes in two date date structs and sorts them  
int comp(const void *dateOne , const void *dateTwo){
	
	
	struct date *one = (struct date *)dateOne ; //assign first struct date to one 
	struct date *two = (struct date *)dateTwo ; //assignes second date struct to two 
	
	// evaluates whether year one is greater than year two
	// if it is return -1 else return 1 
	if(one -> year > two -> year ){
		return -1 ;
	}
	else if(one -> year < two -> year){
		return 1 ;
	}
	
	// evaluates whether month one is greater than month two
	// if it is return -1 else return 1
	if(one -> month > two -> month ){
		return -1 ;
	}
	else if(one -> month < two -> month){
		return 1 ;
	}
	
	// evaluates whether day one is greater than year day
	// if it is return -1 else return 1
	if(one -> day > two -> day ){
		return -1 ;
	}
	else if(one -> day < two -> day){
		return 1 ;
	}
	
	return 0 ;
}

// the main thread 
int main() {

	//declaration of veriables 
    int n, i, j, dayHold , yearHold, monthNum;
    
	//declaration of struct's we will use 
	struct date *dates ; // creates the basic node we weill use to store information 
	struct date *answer ; // creates the node we will need to return of the searched date exsists
	struct date  isIn ; // creats the node that will store the serced for date 
	
	char monthHold[10] ;// takes input for the string value of month 
	
	// monthCom if used to compeare the incoming string 
    const char *monthComp [] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};

    scanf("%d", &n) ; // scan the number of dates you wish to input 

    dates = malloc(n * sizeof(struct date)); // alaocate enough space on the heap for n number of structs 

	// while i is less than n take in date values 
    for(i = 0 ; i < n ; i++){

        scanf("%s", monthHold) ; // hold the string value of month 
		scanf("%d", &dayHold) ;  // stores the value of day 
		scanf("%d", &yearHold) ; // stores the value of year 

		// loop with take in the string value of Month and lopp thrue monthComp untill it findes a string that matchis the input 
		// once the input is found the loop will assign the numerical value of that month to the 
		// variable monthNum 
        for(j = 0 ; j < 12 ; j++){
            if(strcmp(monthHold, monthComp[j]) == 0 ){
                monthNum = j + 1 ;
            }
        }

        dates[i].month = monthNum ; // sets struct date's month value to monthNum 
        dates[i].day = dayHold ;    // sets date's day value to dayHold 
        dates[i].year = yearHold ;  // sets date's year value to yearHold 

		// for the comprarison to work corectly we need the true year value
		// other wise we will get inacurate comparisons for years such as 00 which would represent 2000
		if(dates[i].year < 89){
			dates[i].year += 2000;
		} 
		else if(dates[i].year > 89){
			dates[i].year += 1900;
		} 
		
    }

	qsort(dates, n, sizeof(struct date), &comp) ; // sorts the dates input useing the qsort function 

	scanf("%d", &isIn.month) ; //scan in the numerical month value of the searched for date 
	scanf("%d", &isIn.day) ;   //scan in the numerical day value of the searched for date  
	scanf("%d", &isIn.year) ;  //scan in the numerical year value of the searched for date 
	
	//set the year to the full date for use in the comparison function 
	if(isIn.year < 89){
		isIn.year += 2000;
	} 
	else if(isIn.year > 89){
		isIn.year += 1900;
	} 
	
	answer = bsearch(&isIn, dates, n, sizeof(struct date), comp) ; // useing the bsearch search for the date stored in isIn 
	
	// the loop will work thru the now sorted structs and print them 
	for (i = 0 ; i < n ; i++) {
		
		// retern the year value back to its origonal input value in order to print out 
		if(dates[i].year > 1999){
			dates[i].year -= 2000;
		}
		else if(dates[i].year > 1989){
		    dates[i].year -= 1900;
		} 	
		
		//prints the dates in sorted order. the numerical value of dates is used in 
		//the monthComp char array to find the string value of month 
		printf("%s %d %.2d\n", monthComp[dates[i].month - 1], dates[i].day, dates[i].year) ; 
	}
	

	// if the searched for string is found then print yes, else print no 
	if(answer != NULL){
		printf("Yes") ;
	}
	else{
		printf("No") ;
	}
	
		free(dates) ; // free the space used for dates on the heap . 
	
    return 0;
}
