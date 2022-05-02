/*******************************************************************************************
* File Name          : stack.c
* Description        : Prog8130 - Assignment 3: Stack
*                      This program should implement a stack to push/pop a list of
*                      positive numbers
*
* Author:              Naren Subburaj
* Date:                27/03/2021
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define empty (-1) ///Defining empty as -1

// structure used for holding data
typedef struct node {
    int number;
    struct node *next;
} Node;

// stack top
Node *top = NULL;

// stack functions
void push(const int number);
int pop();

int main(int argc, char *argv[]) {
        int number;             // to store new number
        int i;                  // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            // if it is a pop operation
            if (!strcmp(argv[i], "pop")) {
                printf("%s ", argv[i]);
                printf("%d\n", pop(top));
            } else {
                number = atoi(argv[i]);
                printf("push %d\n", number);
                push(number);
            }
        }
        return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : push
//
// DESCRIPTION   :
//   This function will push a new number into a stack
//
// PARAMETERS    :
//   number - the number that is to be stored in the stack
//
// RETURNS       :
//   Nothing
void push(const int number) {
    // your code

    //Defining dynamic malloc location for newNode
    Node* newNode = (Node*)malloc(sizeof(Node));

    //Checks whether newNode is equal to NULl or not
    if (newNode == NULL)
    {

        //if newnNode is NULL return nothing
        return;
    }

    //Move number data into newNode's number
    newNode->number = number;

    //Move top data into newNode's next
    newNode->next = top;

    //Make top as newNode
    top = newNode;
}

// FUNCTION      : pop
//
// DESCRIPTION   :
//   This function will pop a number from a stack
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the number poped or -1 if the stack is empty
int pop() {
    // your code

    //Check whether top is NULL or not
    if (top == NULL)
    {

        //If top is NULL the return EMPTY which is -1
        return empty;
    }

    //Initialize a integer value which gets the value of top's number
    int value = top->number;

    //Get the top value into temp which has Node structure
    Node* temp = top;

    //Move the data from top's next into top
    top = top->next;

    //Free the temp value
    free(temp);

    //Return the value which has the top's number value
    return value;
}