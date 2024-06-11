#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


// librerias creadas
#include "items/items.h"

void mostrarMenu() {
    printf("\nMenu:\n");
    printf("1. Dar de comer pan al Tamagotchi\n");
    printf("2. Salir del programa\n");
}

int main() {
    // Crear un Tamagotchi
    struct Tamagotchi mascota;
    mascota.hambre = 100;
    mascota.cansancio = 100;
    mascota.aburrimiento = 100;

    // Crear un item
    struct Item manzana;
    strcpy(manzana.nombre, "Manzana");

    struct Item agua;
    strcpy(agua.nombre, "Agua");

    int opcion;

     do {
        // Mostrar el estado actual del Tamagotchi
        printf("\nEstado actual del Tamagotchi:\n");
        printf(" /\\_/\\   \n");
        printf("( o o )  \n");
        printf(" > ^ <   \n\n");
        printf("Hambre: %d\n", mascota.hambre);
        printf("Cansancio: %d\n", mascota.cansancio);
        printf("Aburrimiento: %d\n", mascota.aburrimiento);

        // Mostrar el menú
        mostrarMenu();
        
        // Leer la opción seleccionada por el usuario
        printf("\nSelecciona una opcion: ");
        scanf("%d", &opcion);

        // Realizar la acción correspondiente según la opción seleccionada
        switch(opcion) {
            case 1:
                // Aplicar efecto del pan a la mascota
                aplicarEfecto(&manzana, &mascota);
                printf("\nHas dado de comer una manzana al Tamagotchi. ¡Qué delicia!\n");
                break;
            case 2:
                // Salir del programa
                printf("\nSaliendo del programa...\n");
                break;
            default:
                // Opción no válida
                printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
        }
    } while(opcion != 2); // Continuar mostrando el menú hasta que el usuario seleccione la opción de salir

    return 0;
}