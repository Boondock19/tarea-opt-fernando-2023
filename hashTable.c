#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"
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


void insertHashTable(HashTable* table, char* key, User* value) {
    HashItem* item = createHashItem(key,value);
    int index = hash(item->key);

    /* Verificamos que el index obtenido este vacio */

    HashItem* tableBlock = table->items[index];

    if (tableBlock == NULL) {

        /* Verificamos que no este llena la tabla*/
        if (table->count == table->size) {
            printf("Tabla llena \n");
            return;
        }

        /* Si esta vacio entonces insertamos */
        table->items[index] = item;
        table->count++;
        /* TODO: HACER UPDATE DE UN USUARIO ? */
        /* TODO : MANEJAR EL LAS COLISIONES????? */
    }
 
}

  /* 
        Funcion que retorna a un usuario dada una key de
        la tabla de hash.
    */

    User* searchHashTable (HashTable* hashTable, char* key) {
        int index = hash(key);
        HashItem* item = hashTable->items[index];

        /* Si no se encuentra a un item, entonces retornamos NULL*/
        if (item == NULL) {
            return NULL;
        }

        return item->value;
}

