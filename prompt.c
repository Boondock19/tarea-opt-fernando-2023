#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashTable.h"
#include "linkedList.h"
#include "user.h"
#include "tweet.h"

#define CORRECT_EXIT 0
#define INCORRECT_EXIT 1

/* 
    we will have 4 states for the prompt
    0 initial state
    1 login state
    2 signup state
    3 leave state
*/
/* 
    Las siguiente definiciones de valor
    son utilizados como flags para los estados
    del programa iterativo, cada nombre es explicativo
*/

#define INITIAL_STATE 0
#define LOGIN_STATE 1
#define SIGNUP_STATE 2
#define LEAVE_STATE 3

#define LOGIN "login\n"
#define SIGNUP "signup\n"
#define LEAVE "leave\n"

#define NEW_TWEET_STATE 4
#define GET_PROFILE_STATE 1
#define FOLLOW_STATE 2
#define LOGOUT_STATE 3

#define NEW_TWEET "+\n"
#define GET_PROFILE "@\n"
#define FOLLOW "follow"
#define LOGOUT "logout"

/* 
    Funcion para definir el estado del programa
    segun input del usuario antes de hacer login
*/

int defineState(int state , char *input) {
      if (strcmp(input, LOGIN) == 0) {
        state = LOGIN_STATE;
    } else if (strcmp(input, SIGNUP) == 0) {
        state = SIGNUP_STATE;
    } else if (strcmp(input, LEAVE) == 0) {
        state = LEAVE_STATE;
    } 
    return state;
}

/* 
    Funcion para definir el estado del programa
    segun input del usuario despues de hacer login
*/

int defineLoginInput(int loginState,char *input) {

    if (strcmp(input, NEW_TWEET) == 0) {
        loginState = NEW_TWEET_STATE;
    } else if (strcmp(input, GET_PROFILE) == 0) {
        loginState = GET_PROFILE_STATE;
    } else if (strcmp(input, FOLLOW) == 0) {
        loginState = FOLLOW_STATE;
    } else if (strcmp(input, LOGOUT) == 0) {
        loginState = LOGOUT_STATE;
    } else {
        return 0;
    }
    return loginState;
      
}



/* 
    Funcion para "Limpiar" el buffer al utilizar fgets
    Ya que si el usuario ingresa mas caracteres de los 
    que se pueden almacenar el loop hace "skips"
    
*/
void clearfGetsBuffer(char *str) {
     char *p;
        if(p=strchr(str, '\n')){
            *p = 0;
        } else {
            scanf("%*[^\n]");scanf("%*c");
        }
}

int main (int argc, char *argv[]) {

    int state = INITIAL_STATE;
    int loginInputState;
    char stateInput[10];
    char loginInput[7];
    char profileInput[10];

    /* Creamos la tabla de hash inicial*/

    HashTable *table = createHashTable(HASH_TABLE_SIZE);

    /* 
        Inicio del programa iterativo
    */

    while (state != LEAVE_STATE) {
        
        char *tempUsername = (char *) malloc(sizeof(char) * 31);
        char *tempPassword = (char *) malloc(sizeof(char) * 13);
        

        switch (state)
        {
            /* 
                Estado inicial del programa
                El usuario puede elegir entre login, signup o leave
            */
        case INITIAL_STATE:
            printf("DON’T MISS WHAT’S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
            fgets(stateInput, 8, stdin);
            state = defineState(state, stateInput);
            break;
        case LOGIN_STATE:
           
            /* 
                El usuario debe hacer login
            */ 
            printf("USERNAME: \n");

            fgets(tempUsername, 30 , stdin );

            clearfGetsBuffer(tempUsername);
           
           
            printf("PASSWORD: \n");
            
            fgets(tempPassword, 12 , stdin);
            clearfGetsBuffer(tempPassword);

            
            User *userFound = searchHashTable(table, tempUsername);

            if (userFound != NULL) {
                printf("User found \n");
              

                Node *head = userFound->tweets;

                int hashedPassword = hash(tempPassword);
                if(hashedPassword == userFound->password) {
                    timeline:
                    printf("Profile : %s \n", userFound->profile);
                    printLinkedList(head,1);
                    printf("WHAT’S HAPPENING? \n");
                    fgets(loginInput,sizeof(loginInput),stdin);
                    /* Definimos que accion quiere tomar el usuario .*/
                    loginInputState = defineLoginInput(loginInputState, loginInput);
                    

                    switch (loginInputState)
                    {
                    case (NEW_TWEET_STATE):
                        printf("Write your tweet: \n");
                        /* Creamos espacio para el tweet y el texto */
                        Tweet *newTweet = (Tweet *) malloc(sizeof(Tweet)); 
                        
                        char *text = (char *) malloc(sizeof(char) * 280);
                       
                        fgets(text, sizeof(char) * 280, stdin);
                        
                     
                       
                       
                        newTweet->user = userFound;
                        newTweet->date = time(NULL);
                        newTweet->text = text;
                        
                        
        

                        
                        printLinkedList(head,1);
                        
                        /* Lo agregamos a la lista de tweets */
                        
                        insertNode(&head, newTweet);
                        userFound->tweets = head;
                        
                        printLinkedList(head,1);
                        
                        
                        goto timeline;
                        break;
                    
                    case (GET_PROFILE_STATE): 
                       
                        printf("Write the username of the person you are looking for\n");

                        char *profileUsername = (char *) malloc(sizeof(char) * 31);
                        

                        fgets(profileUsername, 30 , stdin );
                        clearfGetsBuffer(profileUsername);
                        User *userProfile = searchHashTable(table, profileUsername);

                        if (userProfile == NULL) {
                            printf("User not found\n");
                            goto timeline;
                        }
                        /* Show profile of user found */
                    
                        /* Se imprime la lista de tweets del perfil del usuario */
                        printf("Profile of : %s found\n", userProfile->username);
                        printf("Profile : %s \n", userProfile->profile);
                        Node* headTweets = userProfile->tweets;
                        
                        printLinkedList(headTweets, 1);
                        fgets(profileInput,sizeof(loginInput),stdin);
                        clearfGetsBuffer(profileInput);
                        if (strcmp(profileInput, FOLLOW) == 0) {
                           
                            /* Insertamos al usuario en la lista de following de userFound */
                            Node *headFolliwing = userFound->following;
                    
                            insertNode(&headFolliwing, userProfile);
                            userFound->following = headFolliwing;
                            
                            
                        }
                        goto timeline;
                        break;
                    
                    case (LOGOUT_STATE):
                        state = INITIAL_STATE;
                        break;
                    
                    default:
                        printf("Invalid input\n");
                        goto timeline;
                        break;
                    }
                } else {
                    printf("Password is incorrect\n");
                    state = INITIAL_STATE;
                }

            } else {
                printf("User not found\n");
            }
            
            break;
        case SIGNUP_STATE: ;
            User* newUser = (User *) calloc(1,sizeof(User));
            newUser->username = (char *) malloc(sizeof(char) * 30);
            newUser->password = (int) malloc(sizeof(int) * 12);
            newUser->profile = (char *) malloc(sizeof(char) * 50);
            newUser->tweets = (Node *) malloc(sizeof(Node));
            newUser->following = (Node *) malloc(sizeof(Node));
            printf("USERNAME: \n");
            /* 
                Todo backend tiene restricciones de infraestructura o de negocio
                en este caso, diremos que el backend solo acepta 30 caracteres de username,
                Se aceptaran 12 de password y 50 de profile.
            */
            
            char *tempProfile = (char *) malloc(sizeof(char) * 51);

            fgets(tempUsername, 30 , stdin );

           clearfGetsBuffer(tempUsername);
           
            printf("PASSWORD: \n");
            
            fgets(tempPassword, 12 , stdin);
            clearfGetsBuffer(tempPassword);
            
            printf("PROFILE: \n");
            fgets(tempProfile, 50 , stdin ); 
            clearfGetsBuffer(tempProfile);

            newUser->username = tempUsername;
            newUser->password = hash(tempPassword);
            newUser->profile = tempProfile;
            newUser->tweets = NULL;
            newUser->following = NULL;

                      
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

