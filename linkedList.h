#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H

#include "tweet.h"


/* 
    Debemos usar las listas enlazadas para
    guardar a la lista de siguiendos de un user
    y adicionalmente para guardar los tweets dentro 
    de un user.

    Al investigar consegui que se puede utilizar el tipo void
    para almacenar cualquier tipo de dato en la lista, pero
    al momento de guardar vamos a tener que hacer un casteo 
    al tipo que en realidad queremos, es decir, (User *) para
    guardar un usuario y (Tweet *) para guardar un tweet.

*/

typedef struct node {
    void *data;
    struct node *next;

} Node;

void printLinkedList(Node *head,int type);

void insertNode(Node **head, void *data);

int countNodes(Node *head);

#endif