/**
*Jason Flynn : 201037312
*Run ID : 68218
*Assignment 2 Comp 281 
*1041.c
**/

#include <stdio.h> //include standered I/O libraray
#include <stdlib.h> //include standered librery 

// main thread 
int main(int argc, char *argv[]) {
	
	//declaration of variables 
	int n, m, p, i, j, k, sum ;
	int **largMat  ;  //large mat is a pionter to a pionter, this will help 
	int **smallMat ;  //to allocate space from the heap later. the same is true 
	int **sumMat   ;  //for smallMat and sumMat. 
	int lMat ;
	
	scanf("%d", &n) ; // gets number of rows for the first matrix 
	scanf("%d", &m) ; // gets columbs for first matrix and rows for second 
	scanf("%d", &p) ; // gets colomds for second matrix
	
	//following are space allocation for the three matrix we will be using 
	//to store the input matrix and the matrix used to store the calculation of
	//Two matrix. The space needed for each will be the rows * columbs 
	
	largMat = malloc(n*sizeof(int*)) ; //reserves space from the heap for the rows 
	
	//the loop will reserve enough space for the columbs according t the 
	// number of rows
	for (i = 0 ; i < n ; i++) {
		largMat[i] = malloc(m*sizeof(int)) ;
	}

	smallMat = malloc(m*sizeof(int*)) ; //reserves space from the heap for the rows 
	
	//the loop will reserve enough space for the columbs according t the 
	// number of rows
	for (i = 0 ; i < m ; i++) {
		smallMat[i] = malloc(p*sizeof(int)) ;
	}
	
	
	sumMat = malloc(n*sizeof(int*)) ; //reserves space from the heap for the rows
	
	//the loop will reserve enough space for the columbs according t the 
		// number of rows
	for (i = 0 ; i < n ; i++) {
		sumMat[i] = malloc(p*sizeof(int)) ;
	}
	
	//now that we have the size of the Matrix the next two loops
	//will take input for the two Matrix 
	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < m ; j++) {
			scanf("%d", &largMat[i][j]) ;
		}
	}
	for (i = 0 ; i < m ; i++) {
		for (j = 0 ; j < p ; j++) {
			scanf("%d", &smallMat[i][j]) ;
		}
	}
	  
	//the tripple loop will cycle true the two matrix calculating the product
	//of the two matrix and save the result two a third matrix. 
	for(i = 0;i < n; i++){
	    for(j = 0; j < p; j++){
	         
			sumMat[i][j]=0;
	        for(k = 0 ; k < m; k++){
	           sumMat[i][j] = sumMat[i][j] + largMat[i][k] * smallMat[k][j] ;
	         }
	 	}
	}
	
    // this nested loop will print of the matrix holding the product 
	// of the two input matrix.     
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++){
            printf("%i", sumMat[i][j]);
            if(i<n-1 && j==p-1){
                printf("\n");
            }
            if (j%2==0){
                printf(" ");
            }
        }
    }
	
	//Free the space allocated from the Heap. 	
	free(largMat) ;
	free(smallMat) ;
	free(sumMat) ;
}