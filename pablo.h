#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


int search_book_repetido(char *filename, char *book_name)
{
    // declare variables
    FILE *file = fopen(filename, "rb");
    char *buffer;
    long length;
    int found = 0;
    int iterator = 0;
    ssize_t read;
    char *line = NULL;
    size_t len = 0;
    char *token;
    char *last_element;

    if (file == NULL)
    {
        return 0;
    }
    // leemos el archivo linea por linea
    while ((read = getline(&line, &len, file)) != -1)
    {
        iterator++;
        // conseguimos el primer elemento de cada linea
        token = strtok(line, ",");
        while (token != NULL) {
            if  (strcmp(token, book_name) == 0) {
                found = 1;
                token = strtok(NULL, ",");

                token = strtok(NULL, ",");

                token = strtok(NULL, ",");

                token = strtok(NULL, ",");

                token = strtok(NULL, ",");

                token = strtok(NULL, ",");

                token = strtok(NULL, ",");


                // cerramos el archivo
                fclose(file);

                Sleep(2000);

                // retornamos el archivo encontrado
                return found;
            } else {
                // condicional en caso de que no se encuentre el libro
                found = 0;
                // actualizamos el token
                token = strtok(NULL, ",");
            }
        }
    }
    return found;

}
