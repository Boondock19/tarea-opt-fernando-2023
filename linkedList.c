
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


/* 
    Metodo para crear un espacio de memoria para un apuntador
    a lista enlazada/nodo.
*/

node createNode() {
    node temp;
    temp = (node)malloc(sizeof(LinkedList));
    temp->next = NULL; 
    return temp;
}

/* 
    Funcion para agregar un nodo a la lista enlazada.
    requiere de un nodo que seria head, y el valor que sera
    almacenado en el nodo.
*/

node insertNode(node head,void *data) {
    node temp,p;
    temp = createNode();
    temp->data = data;
    /* Si la lista esta vacia entonces lo agregamos directamente */
    if(head == NULL) {
        head = temp;
    } else {
        /* Recorremos la lista hasta el final para poder 
        agregar el nuevo nodo al final de la lista.
        */
        p = head;
        while(p->next != NULL ) {
            p = p->next;
         }
        p->next = temp;
    }

    return head;
}


void printList(node head) {
    node p;
    p = head;
    while(p != NULL) {
        printf("%s", (char *)p->data);
        p = p->next;
    }
}



