/*******************************************************************************************
* File Name          : queue.c
* Description        : Prog8130 - Assignment 3: Queue
*                      This program should implement a queue to enqueue/dequeue a list of
*                      positive numbers
*
* Author:              Naren Subburaj
* Date:                27/03/2021
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define empty (-1) //Defining empty as -1

// structure used for holding data
typedef struct node {
    int number;
    struct node *next;
} Node;

// queue head and tail
Node *head = NULL;
Node *tail = NULL;

// queue functions
void enqueue(const int number);
int dequeue();

int main(int argc, char *argv[]) {
        int number;             // to store new number
        int i;                  // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            // if it is a dequeue operation
            if (!strcmp(argv[i], "dequeue")) {
                printf("%s ", argv[i]);
                printf("%d\n", dequeue(head));
            } else {
                number = atoi(argv[i]);
                printf("enqueue %d\n", number);
                enqueue(number);
            }
        }
        return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : enqueue
//
// DESCRIPTION   :
//   This function will add a new number into a queue
//
// PARAMETERS    :
//   number - the number that is to be stored in the queue
//
// RETURNS       :
//   Nothing
void enqueue(const int number) {
    // your code

    //Defining dynami memory allocation for newNode
    Node* newNode = (Node*)malloc(sizeof(Node));

    //Checks whether newNode is NULl or not
    if (newNode == NULL)
    {

        //if the condition is true return nothing
        return;
    }

    //Move number data from newNode's number
    newNode->number = number;

    //Make newNode's next as NULL
    newNode->next = NULL;

    //Checks whether tail is not equal to NULL or not
    if (tail != NULL)
    {
        //Move the data from newNode to tail's next
        tail->next = newNode;
    }

    //Move the newNode data to tail
    tail = newNode;

    //Checks whethe head is NULL or not
    if (head == NULL)
    {

        //Move data from newNode to head
        head = newNode;
    }
}

// FUNCTION      : dequeue
//
// DESCRIPTION   :
//   This function will dequeue a number from a queue
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the number dequeued or -1 if the queue is empty
int dequeue() {
    // your code

    //Checks whether head is NULL or not
    if (head == NULL)
    {

        //If the condition is true return EMPTY which is -1
        return empty;
    }

    //Move the data from head to temp which is Node structure
    Node* temp = head;

    //Defining new interger to store temp's number
    int value = temp->number;

    //Get head's next into head
    head = head->next;

    //Checks whether head is NULL or not
    if (head == NULL)
    {

        //Make tail as NULL
        tail = NULL;
    }

    //free the temp value
    free(temp);

    //Return the value 
    return value;
}

