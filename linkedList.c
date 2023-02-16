
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"




/* 
    Funcion para agregar un nodo a la lista enlazada.
    requiere de un nodo que seria head, y el valor que sera
    almacenado en el nodo.
*/



void insertNode(Node **headRef, Tweet *data) {
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



void printLinkedList(Node* node) {
    while (node != NULL) {
        printf("User:  %s, date: %s , text: %s", node->data->user->username,ctime(&node->data->date), node->data->text);
        node = node->next;
    }
};





