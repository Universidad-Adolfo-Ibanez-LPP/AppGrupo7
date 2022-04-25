#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


char *read_file(char *filename)
{
    // declaramos las funciones
    FILE *file;
    char *buffer;
    long length;

    // abrimos el archivo
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file\nThe file should be located in the folder above the folder where the program is located\n");
        return NULL;
    } else {
        printf("File opened\n");
    }


    // encontramos el final del archivo
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // alocamos memoria para el buffer
    buffer = (char *)malloc(length + 1);
    if (buffer == NULL)
    {
        printf("Error allocating memory for file %s\n", filename);
        return NULL;
    }

    // leemos el archivo
    fread(buffer, 1, length, file);
    buffer[length] = 0;

    // cerrar el archivo
    fclose(file);

    // retornamos el resultado
    return buffer;
}