/*******************************************************************************************
* File Name          : assign1.c
* Description        : Prog8130 - Assignment 1: Linked Lists
*                      This program uses linked lists to hold and print a list of words
*                      organized by order number assosciated with each word. Each word can
*                      consist of maximum 30 characters.
*
* Author:              Naren Subburaj
* Date:                02/06/2022
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_DATA_ITEMS   10                               // the number of data items to be used in list
// should be less than or equal 10

typedef struct {
    char name[30];
    int  order;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
    char                            NameData[30];           // the name to be stored
    int                             order;                  // the order to be stored
    struct LinkedListNode* ptrNextNode;           // pointer to next node in list (NULL if the end)
} LinkedListNodeDef;
struct LinkedListNode* ptrHead = NULL;
// prototypes
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder);
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder);
void PrintLinkedList(LinkedListNodeDef* ptrHead);

// data used for test
// start iData
int count, i;
inputData iData[10] = {
    { "kiwi",1 },
    { "water",3 },
    { "carrot",3 },
    { "pickels",7 },
    { "chocolate",5 },
    { "fish",4 },
    { "candy",7 },
    { "orange",4 },
    { "airplane",9 },
    { "butter",5 }
};
// end iData
// end of data for assignment

// Correct order after inserting into list is:
// kiwi,1
// water,3
// carrot,3 -- will be removed
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

// Final output (care for the format! one word each line! and there should be no other output)
// kiwi,1
// water,3
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

void main(void) {
    int i;

    // define linked list head
    struct LinkedListNode* ptrHead = NULL;

    // Print out the input data
    printf("Data before Linked List is:\n");
	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
		printf("%s , %d\n", iData[i].name, iData[i].order);
	}

    // insert the data into Linked List
    for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
        ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].order);
    }

    ptrHead = RemoveFromLinkedList(ptrHead, iData[2].name, iData[2].order);

    // now print out the list in order it is stored starting at head
    PrintLinkedList(ptrHead);
}

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder) {
    // put code in here to add the item(s) to the linked list
    LinkedListNodeDef* p = NULL;
    LinkedListNodeDef* nodeA = NULL;
    LinkedListNodeDef* nodeB = NULL;

    //Memory allocation for p
    p = (LinkedListNodeDef*)malloc(sizeof(LinkedListNodeDef)); 

    //Copying the Name data to Node p's data
    strcpy(p->NameData, NameData);

    //Copying the Data order to Node p's order
    p->order = DataOrder;

    //Make ptrNextNode of p as NULL
    p->ptrNextNode = NULL;

    //Check whether ptrHead is null or not
    if (ptrHead == NULL)
    {
        //Move P address into ptrhead
        ptrHead = p;
    }
    else
    {
        //Move prtHead address into node1
        nodeA = ptrHead; 

        //Compare dataorder value and ptrhead's order
        if (DataOrder < ptrHead->order)
        {
            //ptrhead address is moved to p's next node
            p->ptrNextNode = ptrHead; 

            //p values moves to ptrHead
            ptrHead = p;
        }
        else
        {
            //nodeA value goes to nodeB
            nodeB = nodeA;

            //nodeA order value is compaered with DataOrder
            while (nodeA && nodeA->order < DataOrder) 
            {
                //nodeA value goes to nodeB
                nodeB = nodeA;

                //nodeA's ptrnextnode address goes to nodeA
                nodeA = nodeA->ptrNextNode;
            }
            //if nodeA is not
            if (!nodeA)
            {
                //p address goes to nodeB's ptrnextnode
                nodeB->ptrNextNode = p;
            }
            else
            {
                //NodeA address goes to p's ptrnextnode
                p->ptrNextNode = nodeA;

                //P's address goes to nodeB's ptrnextnode
                nodeB->ptrNextNode = p;
            }
        }
    }
    return ptrHead;
}

// FUNCTION      : RemoveFromLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder)  {
    // put code in here to add the item(s) to the linked list

    //NodeA as NUll
    LinkedListNodeDef* nodeA = NULL;

    //NodeB as Null
    LinkedListNodeDef* nodeB = NULL;

    //ptrhead address goes to nodeA
    nodeA = ptrHead;

    //When nodeA's order is not equal to DataOrder
    while (nodeA->order != DataOrder)
    {
        //nodeA address goes to nodeB
        nodeB = nodeA;

        //nodeA's ptrnextnode address moves to nodeA
        nodeA = nodeA->ptrNextNode;

        //check whether nodeA->order is equal to dataorder
        if (nodeA->order == DataOrder)
        {
            //strcmp will return 0 if the string are equal
            if (strcmp(nodeA->NameData, NameData) == 0)
            {
                //nodeA's ptrnextnode address is moved to nodeB's ptrnextnode
                nodeB->ptrNextNode = nodeA->ptrNextNode;
            }
        }
    }
	return ptrHead;
}


// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//                 and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef* ptrHead) {
	// put code in here to print the linked list out

    //ptrHead value is moved to temp
	LinkedListNodeDef* temp = ptrHead; 
    printf("\nFinal output\n");

    //Checks whether temp is null or not
	while (temp != NULL) 
	{
        //Prints Name data and order
		printf("%s,%d\n", temp->NameData, temp->order);	

        //temp's next address is moved to temp
		temp = temp->ptrNextNode; 

	}
}
