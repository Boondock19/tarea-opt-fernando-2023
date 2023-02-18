
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"




/* 
    Funcion para agregar un nodo a la lista enlazada.
    requiere de un nodo que seria head, y el valor que sera
    almacenado en el nodo.
*/



void insertNode(Node **headRef, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *last = *headRef;
    newNode->data = data;
    newNode->next = NULL;

   if (*headRef == NULL) {
    *headRef = newNode;
    return;
   }

   while (last->next != NULL) {
    last = last->next;
   }

    last->next = newNode;
    return;
}


/* 
    Funcion utilizada para imprimir una lista enlazada
    la variable type sirve para saber que tipo de dato
    es y poder imprimirlo correctamente.
*/

void printLinkedList(Node* node,int type) {
    if (node == NULL) {
        printf("List is empty \n");
        }
    while (node != NULL) {
        void *data = node->data;
        if (type == 1) {
            Tweet *tweet = (Tweet *)data;
            printf("User:  %s, date: %s , text: %s \n", tweet->user->username,ctime(&tweet->date), tweet->text);
        } else if (type == 2) {
            User *user = (User *)data;
            printf("User:  %s\n", user->username);
        }
        node = node->next;
    }
};

/*  
    Funcion para contar lo nodos de una lista enlazada
*/

int countNodes(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}





