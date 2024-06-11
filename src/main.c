#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


// librerias creadas
#include "items/items.h"


void menuPrincipal(struct Tamagotchi mascota);
void menuInferior();
void menuInventario();
void limpiarPantalla();


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

    menuPrincipal(mascota);
    menuInferior();
    
    printf("\nSelecciona una opcion: \n");
    scanf("%d", &opcion);
    switch(opcion) {
            case 1:
                //Inventario
                limpiarPantalla();
                menuInventario();
                printf("\nSelecciona una opcion: \n");
                scanf("%d", &opcion);
                switch(opcion) {
                    case 1:
                        //Manzana
                        printf("\nHas comido una manzana te quedan 5");
                        scanf("%d", &opcion);
                        break;
                    case 2:
                        //Agua
                        printf("\nHas tomado un Agua te quedan 5");
                        getchar();
                        break;
                    case 3:
                        //Coca-Cola
                        printf("\nHas tomado una Coca-Cola te quedan 5");
                        getchar();
                    case 4:
                        //Salir
                        break;
                    default:
                        // Opción no válida
                        printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
                    }
                break;
            case 2:
                //Jugar
                limpiarPantalla();
                printf("Proximamente...");
                break;
            case 3:
                //Salir
                printf("\nSaliendo del programa...\n");
            default:
                // Opción no válida
                printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
        }

    return 0;
}

void menuPrincipal(struct Tamagotchi mascota) {
    printf("\nEstado actual del Tamagotchi:\n");
    printf(" /\\_/\\   \n");
    printf("( o o )  \n");
    printf(" > ^ <   \n\n");
    printf("Hambre: %d\n", mascota.hambre);
    printf("Cansancio: %d\n", mascota.cansancio);
    printf("Aburrimiento: %d\n", mascota.aburrimiento);
}

void menuInferior() {
    printf("\n\nSelecciona una opcion:\n\n");
    printf("1) Abrir Inventario\n");
    printf("2) Jugar\n");
    printf("3) Dormir\n");
}

void menuInventario() {
    printf("\n\nSelecciona una opcion:\n\n");
    printf("1) Manzana x5\n");
    printf("2) Agua x2\n");
    printf("3) Coca-Cola x6\n");
    printf("4) Salir\n");
}

void limpiarPantalla() { system("cls"); }