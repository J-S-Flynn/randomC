/**
*Jason Flynn : 201037312
*Run ID : 75853
*Assignment 2 Comp 281
*1046.c
*prgramme is designed to creat a matrix of size n * n and then sum up adjacent m values 
**/

#include <stdio.h> // include the standered I/O library
#include <stdlib.h> // include the standered library

//main thread
int main() {

    //variable declaration
    int **pMatrix ; // matrix to store values
    int n, m, i, j, x, y, tempSum, maxSum ; // implementable variables, temporary store for sum and greatest sum
    n = m = maxSum = 0 ;// variable assignment

    scanf("%d", &n) ;//scan in n to create n*n matrix
    scanf("%d", &m) ;//scan in m, number of adjacent elements to sum for each case

    //initialise the matrix number of rows
    pMatrix = (int **) malloc(n * sizeof(int*));

    //initialises the matrix number of column elements
    for (i = 0; i < n ; ++i) {
        pMatrix[i] = (int *) malloc(n * sizeof(int));
    }

    //traverses each element of the matrix and takes a value to store in that element
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n ; j++) {
            scanf("%d", &pMatrix[i][j]);
        }
    }

    //the code below is responcible for traversing the matrix in any direction 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            tempSum = 0 ;

			// Horizontal traversal. The if statment serves to stop 
			// the programe form accessing non exsistent eliments 
            if((j + m) < (n + 1)) {
	
				//takes the value of the current eliment and then adds the value of the next 
				//m eliments in a striat line Horazontily.	
                for (x = j; x < (j + m); x++) {

                    tempSum = tempSum + pMatrix[i][x]; // sums the elements for m elements 
					
					// if the total sum of the last loop is greater than the current value 
					// of maxSum make the curent sum the new max sum . 
                    if(tempSum > maxSum){
                        maxSum = tempSum ;
                    }
                }

                tempSum = 0 ;// set tempSum back to 0
				//Vertical traversal  
				//takes the value of the current eliment and then adds the value of the next 
				//m eliments in a striat line Vertically			
                for (x = j; x < (j + m); x++) {

                    tempSum = tempSum + pMatrix[x][i]; // sums the elements for m elements

					// if the total sum of the last loop is greater than the current value 
					// of maxSum make the curent sum the new max sum . 
                    if(tempSum > maxSum){
                        maxSum = tempSum ;
                    }
                }
            }


            tempSum = 0 ; // set temp sum back to 0

			//diagnol right
			//takes the value of the current eliment and then adds the value of the next 
			//m eliments in a striat line diagnoly 
			//the if statment keeps the programme from accessing elemennts outside of the bondrys of the matrix 
			if((j+m) < (n+1) && (i+m) < (n+1)){

                y = 0 ;// initalises y to 0


                for (x = j; x < (j + m)  ; x++) {

                    tempSum = tempSum + pMatrix[i+y][j+y]; // sums the elements for m elements


					// if the total sum of the last loop is greater than the current value 
					// of maxSum make the curent sum the new max sum . 
                    if(tempSum > maxSum){
                        maxSum = tempSum ;
                    }

                    y++ ; // increaments y
                }
            }


            tempSum = 0 ; // sets tempSum back to 0 

			// diagnanl left 
			//takes the value of the current eliment and then adds the value of the next 
			//m eliments in a striat line diagnoly 
			//the if statment keeps the programme from accessing elemennts outside of the bondrys of the matrix 
            if((j-m) < (n+1) && (i+m) < (n+1) && (j) >= (m-1)){

                y = 0 ; // sets y back to 0 

                for (x = j; x < (j + m)  ; x++) {

                    tempSum = tempSum + pMatrix[i+y][j-y]; // sums the elements for m elements


					// if the total sum of the last loop is greater than the current value 
					// of maxSum make the curent sum the new max sum . 
                    if(tempSum > maxSum){
                        maxSum = tempSum ;
                    }

                    y++ ; // incraments y 
                }
            }


        }
    }

    printf("%d", maxSum) ; // print out the final value of maxSum 

	// the loop will free all the elements within the matrix 
    for (i = 0; i < n ; ++i) {
        free(pMatrix[i]) ;
    }
    free(pMatrix) ;

    return 0;
}