
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



void printLinkedList(Node* node,int type) {
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





