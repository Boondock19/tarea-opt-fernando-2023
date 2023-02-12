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

int main (int argc, char *argv[]) {

    int state = INITIAL_STATE;
    char state_input[10];

    while (state != LEAVE_STATE) {
        
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
            fgets(state_input, 8, stdin);
            printf("You entered: %s", state_input);
            printf("Are they equal ? %d \n",strcmp(state_input, SIGNUP));
            state = define_state(state, state_input);
            break;
        case SIGNUP_STATE:
            printf("Signup\n");
            fgets(state_input, 8, stdin);
            printf("You entered: %s", state_input);
            printf("Are they equal ? %d \n",strcmp(state_input, LEAVE));
            state = define_state(state, state_input);
            User* newUser = (User *) malloc(sizeof(User));
            newUser->username = "BoondockTACE";
            
            
            newUser->password = hash("jm2839365");

           
            printf("Username : %s ,Password: %d,Profile: %s \n", 
            newUser->username, newUser->password ,newUser->profile);
            
            break;

        default:
            break;
        }
    }

    
    return 0;
}