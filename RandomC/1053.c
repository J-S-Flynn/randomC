/**
*Jason Flynn : 201037312
*Run ID : 84856
*Assignment 2 Comp 281
*1053.c
*programme is designed to implament a stack structuer, useing the standered FFIFO ,PUSH AND POP 
**/

#include <stdio.h> //include standered I/O Library 
#include <stdlib.h> // include stndered libraray 
#include <string.h> // include string functions 

// node to stare the value to be added to the stack and the 
// pionter to the next node in the stack , implaments a linked list 
struct stackNode {
    int value ;
    struct stackNode *nextNode ;
};

// node structuers to fix the head and temp nodes when poping 
struct stackNode *head ; // stors the value of the head
struct stackNode *temp ; // stores the value of the node to be popped 

int main(){

	//declaration of variables
    char operation[5] ; 
    int numHold = 0 ;
    char push[5] = "Push" ; //string to compare push input to 
    char pop[5] = "Pop" ; //string to compare pop input to 

	// the loop will not end until it reaches the end of an input file. 
	// scans in the operation you want to perform 
    while(scanf("%s", operation) != EOF){

		// if operation = push go in to this code 
        if(strcmp(operation, push) == 0){

            scanf("%d", &numHold) ; // scans the value to be pushed onto the stack 
			
			// if the head is null and there is no value on the stack creat a new one 
            if(head == NULL){
                head = malloc(1 * sizeof(struct stackNode)); // allocate space for the struct on the heap  
                head -> nextNode = NULL ; // set varibale for the next node to null as the list is empty 
                head -> value = numHold ; // set the value stored in the node 

                printf("%d pushed\n", numHold) ; // print the value that has been place on the stack 
            }
           	else{  // if head is not null enter this block of code 
                temp = malloc(1 * sizeof(struct stackNode)); // allocate space for the temp struct on the heap 
                temp -> nextNode = head ; // set the value of next node to the head of the stack 
                temp -> value = numHold ; // set the value of the node 
                head = temp ; // make the temp node the new head node

                printf("%d pushed\n", numHold) ; // print the value that has been placed on the stack 
            }
        } // if operaion = pop enetr this block of code 
        else if(strcmp(operation, pop) == 0 ){

            temp = head ; // set a temp node = to the head of the stack 

            if(temp == NULL){ // if the temp node is empty stack is empty print -1
                printf("-1 popped\n") ;
            }
            else{ // if the stack is not empty enter this block of code 
                temp = temp -> nextNode; // set temp equal to the node that it is pionting to 
                printf("%d popped\n", head -> value); // print the value of the head node, that was previusly temp 
                free(head) ; // free the head node 
                head = temp ; // ,ake the temp node the new head

            }
        }
    }

    return 0 ; // return 0 if everything is working as it should 
}