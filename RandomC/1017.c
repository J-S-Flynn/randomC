/**
*Jason Flynn : 201037312
*Run ID : 70480
*Assignment 2 Comp 281 
*1017.c
**/

#include <stdio.h> //include standered I/O library
#include <stdlib.h> //include standerd library

// main Thread 
 int main(int argc, char** argv){

	 // declaration of variables 
	 int n, i, j ;
	 int **pArrayHold ; // pArrayHold and pColSizw will be used to creat a jagged array
	 int *pSumHold ;    // pSumHold will hold the product of each columb 
	 int *pColSize ;
	 
	 scanf("%d", &n); // scanst in number of eliments for array pArrayHold and pSumHold
	 
	 pArrayHold = malloc(n*sizeof(int*)); // alocate space for pArray on the heap
	 pSumHold = malloc(n*sizeof(int));    // allocate space for the calculation on the heap
	 pColSize = malloc(n*sizeof(int)) ;   // allocate the sixze for pColSize
	
	 // for loop will allocate the size
	 // i am sure that this is the wrong way of doing this, but i cannot see to think of a better way.
	 for(i = 0; i < n; i++){
		 scanf("%d", &pColSize[i]) ;
		 pArrayHold[i] = malloc(pColSize[i]*sizeof(int));
	 } 

		          
	// calculates the product of each of the columbs 
	 for(i = 0; i < n; i++){
		 for(j = 0; j < n; j++){
			 if(i < pColSize[j]){
				
				 scanf("%d", &pArrayHold[i][j]); // scans in the value for position [i][j]
				
				//if i == 0 make the value of pSumhold [j] the value of pArrayHold[i][j]
				//else add the value to the total of pSumHold
				if(i == 0 ){
					pSumHold[j] = pArrayHold[i][j] ; 
				}
				else{
				 pSumHold[j] = pSumHold[j] * pArrayHold[i][j];
				}
			 }
		 }
	}
	
	//print out the values of pSumHold	
	for(i = 0; i < n; i++){
	 printf("%d ", pSumHold[i]);	
	}
	
	// free all space used from the heap.
	free(pArrayHold) ;
	free(pSumHold) ;
	free(pColSize) ;
	
	return 0 ;
}