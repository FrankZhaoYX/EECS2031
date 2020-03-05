/***********************************
* EECS2031 - Assignment 1
* Filename: list.c
* Author: Zhao,Yixi
* Email: frankzyx@my.yorku.ca
* Login ID: frankzyx
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *head, *tail;
char error_message1[20]="Insufficient memory!";
char error_message2[20]="Empty list!";
/* Display an error message. */

void prtError( char *errMsg )
{
    printf( "%s \n", errMsg );
}


/* Print the content of the list (ignoring the dummy node). */

void prtList()
{
    List *p;
    for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
    printf( "\n");
}



/* Initialize the list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node. */

List *init()
{
    head = ( List * ) malloc( sizeof( List ) );
    if ( head == NULL ) {
        prtError( "Insufficient memory!" );
        return( NULL );
    }
    head->data = -1;
    head->next = NULL;
    tail = head;
    return ( head );
}





/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertFirst( int d )
{

    /***** ADD YOUR CODE HERE *****/
    List *tmp = (List *)malloc(sizeof(List));
    if(tmp==NULL){
        prtError(error_message1);
        return NULL;
    }

        tmp->data =d;
        tmp->next = head->next;
        head->next = tmp;
        return tmp;

}



/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertLast( int d )
{

    /***** ADD YOUR CODE HERE *****/
    List *tmp = (List *)malloc(sizeof(List));
    if(tmp==NULL){
        prtError(error_message1);
        return NULL;
    }
    tmp->data=d;
    tmp->next = NULL;
    if(head->next==NULL){
        head->next= tmp;
    } else{
        tail->next=tmp;
    }
    tail=tmp;
    return tmp;


}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* Return -1 if the list is empty, i.e., containing only the dummy node, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be remove. */

int removeFirst()
{

    /***** ADD YOUR CODE HERE *****/
    List *tmp = (List *)malloc(sizeof(List));
    if(tmp==NULL){
        prtError(error_message1);
        return NULL;
    }
    if(head->next==NULL){
        prtError(error_message2);
        return -1;
    }
    tmp = head->next;
    head->next = (head->next)->next;
    int answer = tmp->data;
    free(tmp);
    return answer;
}


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

List *search( int k )
{

    /***** ADD YOUR CODE HERE *****/
    List * tmp = (List *)malloc(sizeof(List));
    if(tmp==NULL){
        prtError(error_message1);
        return NULL;
    }
    tmp = head;
    while (tmp!=NULL)
    {

        if(tmp->data==k)
        {
            return tmp;
        }
        tmp=tmp->next;
    }

    return NULL;
}


/*************************** END OF FILE ***************************/
