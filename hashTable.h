#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "user.h"



#define HASH_TABLE_SIZE 1000

 /* 
    Estructura de un item de la tabla hash
    Debe ser un par de la forma (key, value)
    donde value es un tipo de dato de tipo
    User.	
 */

typedef struct hashTableItem {
    char *key;
    User *value;
} HashItem;


/* 
    Definimos a la tabla hash
    donde items es un arreglo de apuntadores a items de la tabla
    size es el tamaño de la tabla
    count es el numero de elementos en la tabla
*/

typedef struct hashTable {
    HashItem** items;
    int size;
    int count;
} HashTable;


/*   
    Funcion de hash
    Recibe un string y toma el valor ASCII de cada caracter
    y lo suma para obtener un valor unico para cada string
    que se ingrese aplicando el modulo del tamaño de la tabla

 */

 long hash(char *str) {}


 /* 
    Funcion para crear un item de la tabla hash
    es decir para crear un par (key, value) con
    value de tipo User.
*/

HashItem* createHashItem(char* key,User* value) {}


/*
    Funcion para crear una tabla de hash
    toma como parametro el tamaño de la tabla.

    Inicializa la tabla con el tamaño dado con
    valores NULL y el numero de elementos en 0.

*/

HashTable* createHashTable(int size) {}

/* 
    Funcion para poder debbugear la tabla de hash
    Imprime el valor de cada item de la tabla
*/

void printHashTable(HashTable* table) {}


void insertHashTable(HashTable* table, char* key, User* value) {}

  /* 
        Funcion que retorna a un usuario dada una key de
        la tabla de hash.
    */

 User* searchHashTable (HashTable* hashTable, char* key) {}

#endif