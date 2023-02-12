

/* 
    Estructura general de un Usuario
    username: nombre de usuario
    password: contraseña guardada con el hash
    profile: Pequeña descripción del usuario

    Los 3 valores son strings pero guardados en apuntadores
 */

typedef struct user{
    char *username;
    int password;
    char *profile;
} User;