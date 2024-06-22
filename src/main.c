#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// Librerias creadas
#include "functions/TDAs/hashmap.h"
#include "functions/effect/effect.h"
#include "functions/structs/structs.h"

// Definición de Colores
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
void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota);


int main() {
    // Crear un Tamagotchi
    struct Tamagotchi mascota;
    mascota.comida = 100;
    mascota.descanso = 100;
    mascota.animo = 100;

    // Crear un item
    struct Item manzana;
    strcpy(manzana.nombre, "Manzana");

    struct Item agua;
    strcpy(agua.nombre, "Agua");

    char item[20];
    int restantes;
    int comida;
    int descanso;
    int animo;

    int opcion;

    while (true) {
        limpiarPantalla();
        menuPrincipal(mascota);
        menuInferior();
        YELLOW
        printf("\nSelecciona una opcion: \n");
        WHITE
        
        // Prueba para conocer si TamaGucci.exe ejecuta el .exe actualizado (No lo hace)
        //printf("\nActualizado\n");
        
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
                            descanso = -10;
                            animo = 10;

                            printItem(item, restantes, comida, descanso, animo, mascota);
                            break;
                        case 2:
                            //Agua
                            strcpy(item, "Agua");
                            restantes = 2;
                            comida = 7;
                            descanso = -3;
                            animo = 8;

                            printItem(item, restantes, comida, descanso, animo, mascota);
                            break;
                        case 3:
                            //Super8
                            strcpy(item, "Super 8");
                            restantes = 7;
                            comida = 60;
                            descanso = 40;
                            animo = 50;

                            printItem(item, restantes, comida, descanso, animo, mascota);
                            break;
                            
                        case 4:
                            //Coca-Cola
                            strcpy(item, "Coca-Cola");
                            restantes = 7;
                            comida = -10;
                            descanso = 80;
                            animo = 20;

                            printItem(item, restantes, comida, descanso, animo, mascota);
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

    printf("Comida: ");
    GREEN
    printf("%d\n", mascota.comida);
    WHITE

    printf("Descanso: ");
    GREEN
    printf("%d\n", mascota.descanso);
    WHITE

    printf("Animo: ");
    GREEN
    printf("%d\n", mascota.animo);
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

void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota) {
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
    printf("    %d Descanso\n", descanso);
    printf("    %d Animo\n", animo);
    WHITE
    esperarInput();
    limpiarPantalla();
    menuPrincipal(mascota);
    menuInferior();
}
//ME GUSTA EL PENEEEEEEE