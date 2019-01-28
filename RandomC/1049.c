/**
*Jason Flynn : 201037312
*Run ID : there is no run ID for this as i could not get it to run 
*Assignment 2 Comp 281
*1049.c
**/

#include <stdio.h> // include stadndered I/O library 
#include <stdlib.h> // include standered library 
#include <string.h> // include string functions 

// structuer to store the values for the linkeds list 
struct queueNode{
    int priorityValue ; // priority value 
    int value ; // value to store in the list 
    struct queueNode * nextNode ; // pionter to the next node in the list 
};

// other nosdes we will need 
struct queueNode *head ;
struct queueNode *temp ;
struct queueNode *newNode ;

// Main thread 
int main() {

	// declare Variables 
    int priHold ; // temp variable for the priority value 
    int valHold ; // temp place holder for the value to be stored 

    char operation[7] ; // string to store the operation you want to performe 
    char insert[7] = "Insert" ; // string to compare operation to 
    char pop[7] = "Pop" ; // string to compare operation to 

	// whale there is no end of file continue the loop 
    while(scanf("%s",operation) != EOF){

		// if operation = incert enter this block of code 
        if(strcmp(operation, insert) == 0 ){

            scanf("%d %d", &valHold, &priHold); // scan th value to be stored and the priority value 

			// create a new node to be used in the queue 
            newNode =  malloc(1 * sizeof(struct queueNode)); // allocate space on the heap for the node 
            newNode -> nextNode = NULL ;  // set the next node pionter to NULL 
            newNode -> value = valHold ; // transfer sacned value to be stored into te node 
            newNode -> priorityValue = priHold ; // transfer the priority value to the node 
			
			// if the queue is empty creat a new node 
            if (head == NULL){
                head = newNode;
            }
            else{
	
				temp = head ; // set temp to head 
				
				
				// this block of code is not working the way that it should 
				// i cannot seem to figuer out hy this is , other than im clearly operating with falty logic 
				
				// while temp is not NULL continue 
                while(temp != NULL){
		
					// if the newNode priority value is 1 make it the head 
					if( priHold == 1 ){
						temp -> nextNode = head ; 
						head = temp ; 
					}// else if it is greater than one go in to this block of code 
					else if (priHold > 1) {
						
						
						if(temp -> priorityValue < priHold){
							temp = temp -> nextNode ;
						}
						else if(temp -> priorityValue == priHold){
							
							newNode -> nextNode = temp -> nextNode ;
							temp -> nextNode = newNode ;
						}
						else if(priHold > temp -> priorityValue && temp -> nextNode == NULL){
							temp -> nextNode = newNode ; 
						}
						else if(priHold > temp -> priorityValue && priHold < temp -> nextNode -> priorityValue){
							newNode -> nextNode = temp -> nextNode ;
							temp -> nextNode = newNode ;
						}
						
					
						
					}
				}
            }
        }

		// pop the node with the greatest priority 
        if(strcmp(operation, pop) == 0 ){

            temp = head ; // set temp = to head
			
			// if head is null print -1
            if(temp == NULL){
                printf("-1 \n") ;
            } // if head is not null enter this code 
            else{
                temp = temp -> nextNode; // set temp to the nextNode node 
                printf("%d\n", head -> value ) ; // print the value being popped 
                free(head) ; // free the head 
                head = temp ; // set the temp ode to the new head 
           }
        }
    }
    return 0;
}