#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>


// librerias creadas
#include "items/items.h"


void menuPrincipal(struct Tamagotchi mascota);
void menuInferior();
void menuInventario();
void esperarInput();
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

    while (true) {
        limpiarPantalla();
        menuPrincipal(mascota);
        menuInferior();
        
        printf("\nSelecciona una opcion: \n");
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch(opcion) {
                case 1:
                    //Inventario
                    limpiarPantalla();
                    menuInventario();
                    printf("\nSelecciona una opcion: \n");
                    scanf("%d", &opcion);
                    while (getchar() != '\n');

                    switch(opcion) {
                        case 1:
                            //Manzana
                            limpiarPantalla();
                            printf("Has comido una manzana (5 restantes)\n");
                            printf("+20 Comida\n");
                            printf("-5 Cansancio\n");
                            printf("+10 Aburrimiento\n");
                            esperarInput();
                            limpiarPantalla();
                            menuPrincipal(mascota);
                            menuInferior();
                            break;
                        case 2:
                            //Agua
                            limpiarPantalla();
                            printf("Has tomado un agua (2 restantes)");
                            printf("+7 Comida\n");
                            printf("-3 Cansancio\n");
                            printf("+8 Aburrimiento\n");
                            esperarInput();
                            limpiarPantalla();
                            menuPrincipal(mascota);
                            menuInferior();
                            break;
                        case 3:
                            //Super8
                            limpiarPantalla();
                            printf("Has comido un Super8 (7 restantes)\n");
                            printf("+60 Comida\n");
                            printf("+40 Cansancio\n");
                            printf("+50 Aburrimiento\n");
                            esperarInput();
                            limpiarPantalla();
                            menuPrincipal(mascota);
                            menuInferior();
                            break;
                            
                        case 4:
                            //Coca-Cola
                            limpiarPantalla();
                            printf("Has tomado una Coca-Cola (7 restantes)\n");
                            printf("-10 Comida\n");
                            printf("+80 Cansancio\n");
                            printf("+20 Aburrimiento\n");
                            esperarInput();
                            limpiarPantalla();
                            menuPrincipal(mascota);
                            menuInferior();
                            break;
                        case 5:
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
                    printf("    El gato\n\n");
                    printf("    |X|O|O|\n");
                    printf("    |O|X|X|\n");
                    printf("    |O|X|X|\n");
                    printf("\n\nNota: Si ganas en este juego puedes obtener mas puntos de energia.\n");
                    esperarInput();
                    break;
                case 3:
                    // Salir
                    printf("\nEmpezando a dormir en ");
                    for (int i = 3; i > 0; i--) {
                        printf("%d ", i);
                        fflush(stdout); // Limpiar el buffer de salida para asegurarse de que se imprima de inmediato
                        sleep(1); // Esperar un segundo
                    }
                    printf("\n");
                    exit(0);
                    break;
                default:
                    // Opción no válida
                    printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
            }
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
    printf("1) Manzana x6\n");
    printf("2) Agua x3\n");
    printf("3) Super 8 x8\n");
    printf("4) Coca-Cola x8\n");
    printf("5) Salir\n");
}

void esperarInput() {
    printf("\nPresiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

void limpiarPantalla() { system("cls"); }
