#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H


/* 
    Debemos usar las listas enlazadas para
    guardar a la lista de siguiendos de un user
    y adicionalmente para guardar los tweets dentro 
    de un user. Eso quiere decir que tendremos dos tipos
    de listas ya que C nos obliga a especificar el tipo
    de dato al generar el struct de la lista enlazada.

    Al investigar consegui que se puede utilizar el tipo void
    para almacenar cualquier tipo de dato en la lista, pero
    al momento de guardar vamos a tener que hacer un casteo 
    al tipo que en realidad queremos, es decir, (User *) para
    guardar un usuario y (Tweet *) para guardar un tweet.

*/

typedef struct linkedList {
    void *data;
    struct LinkedList *next;

} LinkedList;


/* 
    Definicion de la estructura de nodo para una lista enlazada
    Basicamente es un apuntador a la lista enlazada
*/

typedef struct linkedList *node;

node createNode();

node insertNode(node head,void *data);

void printList(node head);

#endif