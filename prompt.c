#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"
#include "user.h"

#define CORRECT_EXIT 0
#define INCORRECT_EXIT 1

/* 
    we will have 4 states for the prompt
    0 initial state
    1 login state
    2 signup state
    3 leave state
*/

#define INITIAL_STATE 0
#define LOGIN_STATE 1
#define SIGNUP_STATE 2
#define LEAVE_STATE 3

#define LOGIN "login\n"
#define SIGNUP "signup\n"
#define LEAVE "leave\n"





int define_state(int state , char *input) {
    if (strcmp(input, LOGIN) == 0) {
        state = LOGIN_STATE;
    } else if (strcmp(input, SIGNUP) == 0) {
        state = SIGNUP_STATE;
    } else if (strcmp(input, LEAVE) == 0) {
        state = LEAVE_STATE;
    } /* else {
        state = INITIAL_STATE;
    } /*/
    return state;
}

/* 
    Funcion para "Limpiar" el buffer al utilizar fgets
    Ya que si el usuario ingresa mas caracteres de los 
    que se pueden almacenar el loop hace "skips"
    
*/
void clearfGetsBuffer(char *str) {
     char *p;
        if(p=strchr(str, '\n')){//check exist newline
            *p = 0;
        } else {
            scanf("%*[^\n]");scanf("%*c");//clear upto newline
        }
}

int main (int argc, char *argv[]) {

    int state = INITIAL_STATE;
    char state_input[10];

    /* Creamos la tabla de hash inicial*/

    HashTable *table = createHashTable(HASH_TABLE_SIZE);

    while (state != LEAVE_STATE) {
        
        char tempUsername[31];
        char tempPassword[13];

        switch (state)
        {
        case INITIAL_STATE:
            printf("Welcome to the prompt\n");
            printf("DON’T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
            fgets(state_input, 8, stdin);
            printf("You entered: %s", state_input);
            printf("Are they equal ? %d \n",strcmp(state_input, LOGIN));
            state = define_state(state, state_input);
            break;
        case LOGIN_STATE:
            printf("Login\n");
           
            
            printf("Enter your username: \n");

            fgets(tempUsername, 30 , stdin );

            clearfGetsBuffer(tempUsername);
           
           
            printf("Enter your password: \n");
            
            fgets(tempPassword, 12 , stdin);
            clearfGetsBuffer(tempPassword);

            
            User *userFound = searchHashTable(table, tempUsername);

            if (userFound != NULL) {
                printf("FOUND USER Username : %s ,Password: %d,Profile: %s \n",
                userFound->username, userFound->password ,userFound->profile);

                int hashedPassword = hash(tempPassword);
                if(hashedPassword == userFound->password) {
                    printf("Password is correct lets print all tweets\n");
                    printf("WHAT’S HAPPENING? \n");
                } else {
                    printf("Password is incorrect\n");
                }

            } else {
                printf("User not found\n");
            }
            

            break;
        case SIGNUP_STATE:
            printf("Signup\n");
            User* newUser = (User *) malloc(sizeof(User));
            newUser->username = (char *) malloc(sizeof(char) * 30);
            newUser->password = (int) malloc(sizeof(int));
            newUser->profile = (char *) malloc(sizeof(char) * 50);
            printf("Enter your username: \n");
            /* 
                Todo backend tiene restricciones de infraestructura o de negocio
                en este caso, diremos que el backend solo acepta 30 caracteres de username,
                Se aceptaran 12 de password y 50 de profile.
            */
            
            char tempProfile[51];

            fgets(tempUsername, 30 , stdin );

           clearfGetsBuffer(tempUsername);
           
            printf("Enter your password: \n");
            
            fgets(tempPassword, 12 , stdin);
            clearfGetsBuffer(tempPassword);
            
            printf("Enter your profile: \n");
            fgets(tempProfile, 50 , stdin ); 
            clearfGetsBuffer(tempProfile);

            newUser->username = tempUsername;
            newUser->password = hash(tempPassword);
            newUser->profile = tempProfile;
                      
            /* Hacemos la insercion del nuevo usuario en la tabla hash*/
            /* 
                No tenemos definido si hay un valor definido a ser tomado 
                para que sea key del par (key,value)

                Tenemos dos opciones:

                - Tomar el username como key, lo cual tiene sentido
                porque no es posible que existan dos usuarios con el
                mismo username en una base de datos.

                - Tomar un valor autoincremental como key

                de momento tomaremos el username como key 
            
            */

            insertHashTable(table, newUser->username, newUser);

           

            state = INITIAL_STATE;
            break;

        default:
            break;
        }
    }

    
    return 0;
}

