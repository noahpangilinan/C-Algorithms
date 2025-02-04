/****************************************************************************
 The purpose of this example is to exercise, using pointers
 
 student version 
 
 gcc -O1 -Wall -std=c99 -pedantic -g  lab_c.c -o lab_c
 valgrind --tool=memcheck --leak-check=yes --track-origins=yes --error-exitcode=99 ./lab_c
 
 09/09/2019 R. Repka    Minor formatting changes
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---------------------------------------------------------------------------
  These data structures are used to simulated a very simple linked list
---------------------------------------------------------------------------*/
// Data type for each node in our linked list
typedef struct Node{
    int index;             // The node number
    struct Node *next;     // Pointer to the next node or NULL if last
    char string[40];       // The data payload
} Node;


// This is the master linked list starting point
typedef struct {
    int nterms;            // The total number of active nodes
    Node *front;           // Pointer to the first node
} Wrapper;



// Function prototypes
void printList(Wrapper *wrapper_p);

int main(int argc, char *argv[]) {
   Wrapper *wrapper_p;
   Node *node_p = NULL;
   Node *temp_p = NULL;
   
   // Wire the first node in
   node_p = (Node *)malloc(sizeof(Node));
   node_p->index = 1;
   strncpy(node_p->string, "one", sizeof(node_p->string)-1);
   wrapper_p = (Wrapper *)malloc(sizeof(Wrapper));
   wrapper_p->nterms = 1;
   wrapper_p->front = node_p;
    printf("Printing 1 node linked list: \n");
   printList(wrapper_p);

   // Wire the second node in
    temp_p = (Node *)malloc(sizeof(Node));
    temp_p->index = 2;
    printf("\nPrinting 2 node linked list: \n");

    strncpy(temp_p->string, "two", sizeof(temp_p->string)-1);
    wrapper_p->nterms = 2;
    wrapper_p->front->next = temp_p;
    printList(wrapper_p);
   // Clean up memory
   free(node_p);
   free(wrapper_p);
   free(temp_p);
   node_p = NULL;
   temp_p = NULL;
   wrapper_p = NULL;
   return 0;
}

// Walk the linked list and print the contents 
void printList(Wrapper *wrapper_p) {
    Node *curnode;
    curnode = wrapper_p->front;
    for (int i = 0; i < wrapper_p->nterms; i++) {
      printf("node %d contains string '%s' \n", curnode->index, curnode->string);
      curnode = curnode->next;
    }
}