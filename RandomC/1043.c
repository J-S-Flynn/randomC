/*
*jaosn Flynn 201037312
*assignment 2 
*comp 281 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	int i, j, n, m, y, x, sLength ;
	char stringHold[100] ;
	char **pFirstArray ;
	char **pSecondArray ;
	char *pFstringL ;
	char *pSstringL ;
	
	scanf("%d", &n) ;
	
	pFirstArray = malloc(n*sizeof(char*)) ;
	pFstringL = malloc(n*sizeof(int)) ;
	
	for (i = 0 ; i < n ; i++) {
		scanf("%s", stringHold) ;
		
		sLength = strlen(stringHold) ;
		pFstringL[i] = strlen(stringHold) ;
		pFirstArray[i] = malloc(sLength*sizeof(char)) ;
		
		for(j = 0 ; j < sLength ; j++){
		pFirstArray[i][j] = stringHold[j] ;
		
		}
		
	}
	
	scanf("%d", &m) ;
	
	pSecondArray = malloc(m*sizeof(char*)) ;
	pSstringL = malloc(m*sizeof(int)) ;
	
	for (i = 0 ; i < m ; i++) {
		scanf("%s", stringHold) ;
			
		sLength = strlen(stringHold) ;
		pSstringL[i] = strlen(stringHold) ;
		pSecondArray[i] = malloc(sLength*sizeof(char)) ;
			
		for(j = 0 ; j < sLength ; j++){
			pSecondArray[i][j] = stringHold[j] ;
		}
	}		
		
	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < n ; j++) {
			if (pFstringL[j] < pFstringL[i]) {
				x = pFstringL[i] ;
				pFstringL[i] = pFstringL[j] ;
				pFstringL[j] = x ;
			}
		}
	}
	for (i = 0 ; i < m ; i++) {
			for (j = 0 ; j < m ; j++) {
				if (pSstringL[j] < pSstringL[i]) {
					x = pSstringL[i] ;
					pSstringL[i] = pSstringL[j] ;
					pSstringL[j] = x ;
				}
			}
		}

	for (i = 0 ; i < n+m ; i ++) {
		if(pFstringL[x] > pSstringL[y]){
			for (j = 0 ; j < n ; j++) {
				if(strlen(&pFirstArray[i][j]) == pFstringL[x]){
				
				   printf("%c", pFirstArray[i][j]) ;
				}
				}	
			}
		}

		
	for (i = 0 ; i < n ; i++) {
		printf("\n") ;
		for (j = 0 ; j < pFirstArray[i][j] ; j++) {
			printf("%c", pFirstArray[i][j]) ;
		}
		
	}	
}