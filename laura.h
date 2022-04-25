#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>



int request_menu_input()
{
    // declaramos la variable
    int input_;

    // solicitamos al usuario que ingrese el menu input
    printf("Please enter your choice: ");
    scanf("%d", &input_);

    // retornamos el valor ingresado
    return input_;
}


int menu()
{
    printf("\n");
    printf("1. Add new book\n");
    printf("2. Sedes\n");
    printf("3. Delete book\n");
    printf("4. Search book\n");
    printf("5. Print all books\n");
    printf("6. Edit book\n");
    printf("7. Exit\n");
    printf("\n");
    return request_menu_input();
}

int sub_menu()
{
    printf("\n");
    printf("1. Print all sedes\n");
    printf("2. Back\n");
    printf("\n");

    return request_menu_input();
}


int get_last_element_of_each_line(char *filename) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    char *last_element;
    int iterator = 0;

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file\nThe file should be located in the folder above the folder where the program is located\n");
        return 0;
    } else {
        printf("File opened\n");
    }

    while ((read = getline(&line, &len, file)) != -1) {
        // conseguimos el ultimo elemento de cada linea
        token = strtok(line, ",");
        while (token != NULL) {
            last_element = token;
            token = strtok(NULL, ",");
        }
        printf("%s", last_element);
        iterator++;
    }
    // printeamos el numero de sedes
    printf("\nSedes found: %d\n\n", iterator);

    fclose(file);

    printf("\nRedirecting to main menu...\n");
    Sleep(2000);

    return 1;
}
