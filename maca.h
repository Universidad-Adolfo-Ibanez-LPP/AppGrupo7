#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


int add_new_book_to_csv(char *filename, char *book_name, char *author, char *anio, char *estante_numero, char *estante_seccion, char *piso, char *edificio, char *sede)
{
    // declaramos las variables
    FILE *file;
    char *buffer;
    long length;

    // abrimos el archivo
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file\nThe file should be located in the folder above the folder where the program is located\n");
        return 0;
    } else {
        printf("File opened\n");
    }

    // encontramos el final del archivo
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // aloca memoria para el buffer
    buffer = (char *)malloc(length + 1);
    if (buffer == NULL)
    {
        printf("Error allocating memory for file %s\n", filename);
        return 0;
    }

    // leemos el archivo
    fread(buffer, 1, length, file);
    buffer[length] = 0;

    // cerramos el archivo
    fclose(file);

    // abrimos el archivo
    file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error opening file\nThe file should be located in the folder above the folder where the program is located\n");
        return 0;
    } else {
        printf("File opened\n");
    }

    // escribimos el archivo
    fwrite(buffer, 1, length, file);
    fwrite("\n", 1, 1, file);
    fwrite(book_name, 1, strlen(book_name), file);
    fwrite(",", 1, 1, file);
    fwrite(author, 1, strlen(author), file);
    fwrite(",", 1, 1, file);
    fwrite(anio, 1, strlen(anio), file);
    fwrite(",", 1, 1, file);
    fwrite(estante_numero, 1, strlen(estante_numero), file);
    fwrite(",", 1, 1, file);
    fwrite(estante_seccion, 1, strlen(estante_seccion), file);
    fwrite(",", 1, 1, file);
    fwrite(piso, 1, strlen(piso), file);
    fwrite(",", 1, 1, file);
    fwrite(edificio, 1, strlen(edificio), file);
    fwrite(",", 1, 1, file);
    fwrite(sede, 1, strlen(sede), file);

    // cerramos el archivo
    fclose(file);

    printf("\nRedirecting to main menu...\n");
    Sleep(2000);

    return 1;
}