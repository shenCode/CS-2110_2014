#include <stdlib.h>
#include "./list.h"

/**
 * pushFront
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the head of the list, and increment size
 */
void pushFront(LIST *list, int data)
{
    NODE *node = (NODE*)malloc(sizeof(node));
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
	// empty list
    if(list -> size == 0){
        list -> head = node;
        list -> tail = node;
        list->size++;
    }

    else {
        node -> next = list -> head;
        list -> head -> prev = node;
        list -> head = node;
        (list->size)++;
    }
    
}

/**
 * pushFront
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the tail of the list, and increment size
 */
void pushBack(LIST *list, int data)
{
    NODE *node = (NODE*)malloc(sizeof(node));
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    // empty list
    if(list -> size == 0){
        list -> head = node;
        list -> tail = node;
    }

    else {
        list -> tail -> next= node;
        node -> prev = list -> tail;
        list -> tail = node;
    }
	(list->size)++;
}

int popBack(LIST *list)
{
    int data = 0;
	// your code here
    if(list -> size == 0){
        return data;
    }
    
	NODE *freeTail = list->tail;
    if (list->size==1) {

        int data=freeTail->data;
        list -> head = NULL;
        list -> tail = NULL;
    }
	else {
		NODE *node2=list -> tail -> prev;
		int data=freeTail->data;
		node2 -> next = NULL;
		list -> tail = node2;
	}
	
    (list-> size)--;
    free(freeTail);
    return data;

}


/**
 * popFront
 * Takes in ptr to a list
 * Remove and free node at the front of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */
int popFront(LIST *list)
{
    int data = 0;
	// your code here
    if(list -> size == 0){
        return data;
    }
    
	NODE *freeHead = list->head;
    if (list->size==1) {

        int data=freeHead->data;
        list -> head = NULL;
        list -> tail = NULL;
    }
	else {
		NODE *node2=list -> head -> next;
		int data=freeHead->data;
		node2 -> prev = NULL;
		list -> head = node2;
	}
	
    (list-> size)--;
    free(freeHead);
    return data;
}

/**
 * popBack
 * Takes in ptr to a list
 * Remove and free node at the back of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */


