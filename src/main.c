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

#define GREEN printf("\033[0;32m");
#define WHITE printf("\033[0m");
#define CYAN printf("\033[0;36m");
#define REDC printf("\033[0;91m");
#define YELLOW printf("\033[0;93m");

void menuPrincipal(struct Tamagotchi mascota);
void menuInferior();
void menuInventario();
void esperarInput();
void limpiarPantalla();
void printItem(char *item, int restantes, int comida, int cansancio, int aburrimiento, struct Tamagotchi mascota);


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

    char item[20];
    int restantes;
    int comida;
    int cansancio;
    int aburrimiento;

    int opcion;

    while (true) {
        limpiarPantalla();
        menuPrincipal(mascota);
        menuInferior();
        YELLOW
        printf("\nSelecciona una opcion: \n");
        WHITE
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch(opcion) {
                case 1:
                    //Inventario
                    limpiarPantalla();
                    menuInventario();
                    YELLOW
                    printf("\nSelecciona una opcion: \n");
                    WHITE
                    scanf("%d", &opcion);
                    while (getchar() != '\n');

                    switch(opcion) {
                        case 1:
                            //Manzana
                            strcpy(item, "Manzana");
                            restantes = 5;
                            comida = 20;
                            cansancio = -10;
                            aburrimiento = 10;

                            printItem(item, restantes, comida, cansancio, aburrimiento, mascota);
                            break;
                        case 2:
                            //Agua
                            strcpy(item, "Agua");
                            restantes = 2;
                            comida = 7;
                            cansancio = -3;
                            aburrimiento = 8;

                            printItem(item, restantes, comida, cansancio, aburrimiento, mascota);
                            break;
                        case 3:
                            //Super8
                            strcpy(item, "Super 8");
                            restantes = 7;
                            comida = 60;
                            cansancio = 40;
                            aburrimiento = 50;

                            printItem(item, restantes, comida, cansancio, aburrimiento, mascota);
                            break;
                            
                        case 4:
                            //Coca-Cola
                            strcpy(item, "Coca-Cola");
                            restantes = 7;
                            comida = -10;
                            cansancio = 80;
                            aburrimiento = 20;

                            printItem(item, restantes, comida, cansancio, aburrimiento, mascota);
                            break;
                        case 5:
                            //Salir
                            break;
                        default:
                            // Opción no válida
                            REDC
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
                    REDC
                    printf("\n\nNota: Si ganas en este juego puedes obtener mas puntos de energia.\n");
                    WHITE
                    esperarInput();
                    break;
                case 3:
                    // Salir
                    REDC
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
                    REDC
                    printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
                    WHITE
            }
    }

    return 0;
}

void menuPrincipal(struct Tamagotchi mascota) {
    YELLOW
    printf("\nEstado actual del Tamagotchi:\n\n");
    CYAN
    printf(" /\\_/\\   \n");
    printf("( o o )  \n");
    printf(" > ^ <   \n\n");
    WHITE

    printf("Hambre: ");
    GREEN
    printf("%d\n", mascota.hambre);
    WHITE

    printf("Cansancio: ");
    GREEN
    printf("%d\n", mascota.cansancio);
    WHITE

    printf("Aburrimiento: ");
    GREEN
    printf("%d\n", mascota.aburrimiento);
    WHITE
}

void menuInferior() {
    CYAN
    printf("\n\n1) Abrir Inventario\n");
    printf("2) Jugar\n");
    printf("3) Dormir\n");
    WHITE
}

void menuInventario() {
    REDC
    printf("==================\n");
    printf("    INVENTARIO:\n");
    printf("==================\n\n");
    CYAN
    printf("1) Manzana x6\n");
    printf("2) Agua x3\n");
    printf("3) Super 8 x8\n");
    printf("4) Coca-Cola x8\n");
    printf("5) Salir\n");
    WHITE
}

void esperarInput() {
    YELLOW
    printf("\nPresiona Enter para continuar...");
    WHITE
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

void limpiarPantalla() { system("cls"); }

void printItem(char *item, int restantes, int comida, int cansancio, int aburrimiento, struct Tamagotchi mascota) {
    limpiarPantalla();
    YELLOW
    printf("Has comido una ");
    for (int i = 0; item[i] != '\0'; i++) {
        printf("%c", item[i]); // Imprime cada carácter de la cadena
    }
    REDC
    printf(" (%d restantes)\n", restantes);
    GREEN
    printf("    %d Comida\n", comida);
    printf("    %d Cansancio\n", cansancio);
    printf("    %d Aburrimiento\n", aburrimiento);
    WHITE
    esperarInput();
    limpiarPantalla();
    menuPrincipal(mascota);
    menuInferior();
}