#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

/* 
    Definimos un tamaño maximo para la tabla de hash.
*/

#define HASH_TABLE_SIZE 1000

/* HashTable */

/*   
    Funcion de hash
    Recibe un string y toma el valor ASCII de cada caracter
    y lo suma para obtener un valor unico para cada string
    que se ingrese aplicando el modulo del tamaño de la tabla

 */

 long hash(char *str) {
    long i = 0;
    
    for (int j = 0; str[j]; j++ ) {
        i += str[j];
    }

    return i % HASH_TABLE_SIZE;
 }


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
    Funcion para crear un item de la tabla hash
    es decir para crear un par (key, value) con
    value de tipo User.
*/

HashItem* createHashItem(char* key,User* value) {
    HashItem* item = (HashItem*) malloc(sizeof(HashItem));
    item->key = (char*) malloc(strlen(key) + 1 );
    item->value = (User*) malloc(sizeof(User));
    strcpy(item->key, key);
    item->value = value;
    return item;
}


/*
    Funcion para crear una tabla de hash
    toma como parametro el tamaño de la tabla.

    Inicializa la tabla con el tamaño dado con
    valores NULL y el numero de elementos en 0.

*/

HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (HashItem**) calloc(table->size, sizeof(HashItem*));

    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }

    return table;
}

/* 
    Funcion para poder debbugear la tabla de hash
    Imprime el valor de cada item de la tabla
*/

void printHashTable(HashTable* table) {
    printf("Tabla Hash actual \n");

    for (int i = 0 ; i < table->size; i++) {
        if (table->items[i] != NULL) {
            printf("Key: %s, User: username :%s , password: %d, profile: %s" , table->items[i]->key,
            table->items[i]->value->username, table->items[i]->value->password, table->items[i]->value->profile);
        }
    }

    printf("Fin de la tabla hash \n");
}