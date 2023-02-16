#ifndef TWEET_H
#define TWEET_H

#include <time.h>
#include "user.h"

/* 
    Estructura de un tweet.
    consiste en el usuario
    un timestamp que seria la fecha de su creacion
    y el texto.
*/

typedef struct tweet {
   struct user *user;
    time_t date;
    char *text;
} Tweet ;


#endif

