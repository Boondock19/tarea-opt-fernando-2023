#ifndef USER_H
#define USER_H


#include "linkedList.h"
#include "tweet.h"


/* 
    Estructura general de un Usuario
    username: nombre de usuario
    password: contraseña guardada con el hash
    profile: Pequeña descripción del usuario
    following: Lista enlazada de usuarios a los que sigue
    tweets: Lista enlazada de tweets del usuario

    Los 3 valores son strings pero guardados en apuntadores
 */

typedef struct user{
    char *username;
    int  password;
    char *profile;
    struct node *following;
    struct node *tweets;
} User;

#endif