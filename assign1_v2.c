/*******************************************************************************************
* File Name          : assign1skeleton_v2.c
* Description        : Prog8130 - Assignment 1 (V2): Doubly Linked Lists
*                      This program uses linked lists to hold and print a list of names
*                      organized by order number assosciated with each name. Each name can
*                      consist of maximum 30 characters.
*
* Author:              Naren Subburaj
* Date:                20-March-2022
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define string_length 30  //Define the string length as 30 characters
#define NO_OF_DATA_ITEMS 4 //Index value is 4


// structure/typedef used for holding data
typedef struct {
    char name[30];
    int  order;
} inputData;

// definition of linked list data nodes
typedef struct node {
    char                  name[30];        // the name to be stored
    int                   order;           // the order to be stored
    struct node           *next;           // pointer to next node in list (NULL if the end)
    struct node           *prev;           // pointer to prev node in list (NULL if the front)
} Node;

// define linked list front and rare as global variables
Node *front = NULL;
Node *rare = NULL;

//Index value is 4 which is already defined in the header
int indexs[NO_OF_DATA_ITEMS]; 

// prototypes
void AddToLinkedList(char *name, int order);
void PrintLinkedListFront(Node *front);
void PrintLinkedListRare(Node *rare);

// data used for test
// start iData
inputData iData[] = {
    { "orange", 3 },
    { "kiwi", 1 },
    { "apple", 2 },
    { "lemon", 4 }
};
// end iData
// end of data for assignment

int main(void) {
    int i;

    // Print out the input data
    printf("Data before Linked List is:\n");
    for (i = 0; i < sizeof(iData)/sizeof(inputData); i++) {
        printf("%s,%d\n", iData[i].name, iData[i].order);
    }
    printf("--\n");

    // insert the data into Linked List
    for (i = 0; i < sizeof(iData)/sizeof(inputData); i++) {
        AddToLinkedList(iData[i].name, iData[i].order);
    }

    printf("Data after adding (front):\n");
    PrintLinkedListFront(front);
    printf("--\n");

    printf("Data after adding (rare):\n");
    PrintLinkedListRare(rare);
    printf("--\n");

    return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input a name and an order and
//                 place it in a linked list organized by priority of order number.
// PARAMETERS    : char *name               - Array of Characters with data
//                 int order                - Order of the item
// RETURNS       : void
void AddToLinkedList(char* name, int order) {
    // put code in here to add the item(s) to the linked list
    // malloc to store the new node
    // check if empty
    // check if should insert before front
    // check if should insert after rare
    // general case

    //Declerating static interger nextdata 
    static int nextdata = 0;

    //Declerating newmode to null
    Node* newnode = NULL;

    //Declerating newmode to null
    Node* p = NULL;

    //Declerating nodeA to null
    static Node* nodeA = NULL;

    //Declerating nodeB to null
    //static Node* nodeB = NULL;

    //Declerating dynamic memory for newnode
    newnode = (Node*)malloc(sizeof(Node));

    //Getting the order value into indexs array
    indexs[nextdata] = order;

    //Checks if the condition newnode
    if (newnode)
    {

        //using strcpy to move data from name into newnode->name
        strcpy(newnode->name, name);

        //move order data to newnode->order
        newnode->order = order;

        //Make newnode->node as NULL
        newnode->next = NULL;

        //Make newnode->prevs as NULL
        newnode->prev = NULL;

        //Make front inot NULL
        if (front == NULL)
        {
            //Move newnode address into front
            front = newnode;
        }
        else if ((front)->order >= newnode->order)
        {
            //Move prtHead address into node1
            newnode->next = front;
            newnode->next->prev = newnode;
            front = newnode;
        }
        else
        {
            //nodeA value goes to nodeB
            nodeA = front;

            //nodeA->next order value is compaered with nodeA->next->order
            while (nodeA->next != NULL && nodeA->next->order < order)
                newnode->next = nodeA->next;

            //Checks whether nodeA->next is not equal to NULL
            if (nodeA->next != NULL)
                newnode->next->prev = newnode;
            
            //newnode value into nodeA->next
            nodeA->next = newnode;

            //nodeA value into newnode->prev
            newnode->prev = nodeA;
        }
    }

    //If newnode is null
    if (newnode->next = NULL)
     {
        //newnode address moves into rare
        rare = newnode;
     }
return;
}

// FUNCTION      : PrintLinkedListFront() / PrintLinkedListRare()
// DESCRIPTION   : These functions take an input of the front/rare of the doubly linked list, then loops through
//                 and prints each word in the doubly linked list.
// PARAMETERS    : Node *
// RETURNS       : void

void PrintLinkedListFront(Node *front) {
    // put code in here to print the linked list out


    Node* temp = front;

    //Checks whether temp is null or not
    while (temp != NULL)
    {
        //Prints Name data and order
        printf("%s,%d\n", temp->name, temp->order);

        //temp's next address is moved to temp
        temp = temp->next;

    }
}

void PrintLinkedListRare(Node *rare) {
    // put code in here to print the linked list out

    Node* temp = rare;

    //Checks whether temp->next is null or not
    while (temp->next != NULL) {
    //Data of temp->next moves into temp
        temp = temp->next;
    }
 
    //Checks whether temp is null or not
    while (temp != NULL)  
    {
        //Prints Name data and order
        printf("%s,%d\n", temp->name, temp->order);

        //temp's next address is moved to temp
        temp = temp->next;

    }
}
