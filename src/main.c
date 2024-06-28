#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Librerias creadas
#include "functions/TDAs/list.h"
#include "functions/structs/structs.h"
#include "functions/TDAs/hashmap.h"
#include "functions/effect/effect.h"
#include "functions/saves/save.h"
#include "img/design.h"
#include "interaction/games.h"

void menuPrincipal(HashMap * mapa_accion_efecto, Juego * juego);
void menuInferior();
void menuInventario();
void menuInteracciones();
void menuIluminacion();
void menuTienda();
void dejarDormir();
void esperarInput();
void limpiarPantalla();
void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota, HashMap mapa_accion_efecto);

void setConsoleColor(const char* color) {
    char command[10];
    snprintf(command, sizeof(command), "color %s", color);
    system(command);
}

int main() {
    //Comandos de inicio de la consola
    printf("\033[0;97;30m");
    setConsoleColor("F0");
    printf("\033[H\033[J");
    system("chcp 65001");

    //Declara la variable mapa_accion_efecto con tipo HashMap
    HashMap *mapa_accion_efecto = create_map(20); // Revisar functions.effect para mas informacion.
    inicializar_mapa_acciones(mapa_accion_efecto);
    printf("Mapa inicializado\n"); // Debug print

    const char* filename = "save.txt";

    // Inicializar juego y mascota
    Juego* juego = (Juego*)malloc(sizeof(Juego));
    if (juego == NULL) {
        perror("Error al asignar memoria para el juego");
        return 1;
    }
    printf("Juego inicializado\n"); // Debug print

    Tamagotchi* mascota = (Tamagotchi*)malloc(sizeof(Tamagotchi));
    if (mascota == NULL) {
        perror("Error al asignar memoria para la mascota");
        free(juego);
        return 1;
    }
    printf("Mascota inicializada\n"); // Debug print

    cargar_estado(juego, filename);
    printf("Carga finalizada\n"); // Debug print

    actualizar_estado(juego);
    printf("Actualización realizada\n"); // Debug print

    guardar_estado(juego, filename);
    printf("Guardado realizado\n"); // Debug print

    int opcion;

    while (true) {
        
        limpiarPantalla();
        menuPrincipal(mapa_accion_efecto, juego);
        menuInferior();
        printf("\n  Selecciona una opcion: \n");
        
        scanf("%d", &opcion);
        while (getchar() != '\n');

            switch(opcion) {
                case 1:
                    // Interacciones
                    limpiarPantalla();
                    menuInteracciones();
                    break;
                case 2:
                    //Inventario
                    limpiarPantalla();
                    menuInventario();
                    break;
                case 3:
                    //Tienda
                    limpiarPantalla();
                    menuTienda();
                    break;
                case 4:
                    // Salir
                    dejarDormir();
                    free(juego); // Liberar la memoria asignada
                    free(mascota); // Liberar la memoria asignada
                    exit(0);
                    break;
                default:
                    // Opción no válida
                    printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
            }
        actualizar_estado(juego);
        guardar_estado(juego, filename);
    }

    return 0;
}

void menuPrincipal(HashMap * mapa_accion_efecto, Juego * juego) {
    printf("\n  Estado actual del Tamagotchi:\n\n");

    printf("    Comida: ");
    printf(" %f    ", juego->mascota.comida);

    printf("    Descanso: ");
    printf(" %f    ", juego->mascota.descanso);

    printf("    Animo: ");
    printf(" %f    \n \n \n ", juego->mascota.animo);

    //char * clave_buscar = "Jugar"; // Por ejemplo, buscar el efecto de la acción "Jugar"

 //Buscar el par clave-valor en el mapa
    //Pair * par = search_map(mapa_accion_efecto, clave_buscar);
     //Acceder al valor (que es un puntero a Efecto)
    //Juego * juego;
    
     //Imprimir el valor de alteracion_animo
    //printf("animo: %f\n", juego->mascota.animo);

    //mostrar_mascota(&juego->mascota);

    printf("      ██    ██\n");
    printf("     █  ████  █\n");
    printf("     █        █\n");
    printf("    █          █\n");
    printf("    █          █\n");
    printf("    █  █    █  █\n");
    printf("    █   ▄  ▄   █\n");
    printf("     █   ▀▀   █\n");
    printf("      ████████\n");
    printf("     █ █    █ █\n");
    printf("     ██      ██\n");
    printf("      ████████ \n");
    printf("       ██  ██  \n\n");
}

void menuInferior() {
    printf("\n  ==================\n\n");
    printf("    1) Acciones\n");
    printf("    2) Abrir Inventario\n");
    printf("    3) Abrir Tienda\n");
    printf("    4) Dormir\n");
}

void menuInventario() {
    int opcion;
    
    printf("    ==================\n");
    printf("        INVENTARIO:\n");
    printf("    ==================\n\n");
    printf("    1) Manzana x6\n");
    printf("    2) Agua x3\n");
    printf("    3) Super 8 x8\n");
    printf("    4) Coca-Cola x8\n");
    printf("    5) Salir\n");

    printf("\n  Selecciona una opcion: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    switch(opcion) {
        case 1:
            //Manzana
            break;
        case 2:
            //Agua
            break;
        case 3:
            //Super8
            break;
                            
        case 4:
            //Coca-Cola
            break;
        case 5:
            //Salir
            break;
        default:
            // Opción no válida
            printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

void menuInteracciones() {
    int opcion;

    printf("    1) Jugar\n");
    printf("    2) Acariciar\n");
    printf("    3) Palmaditas\n");
    printf("    4) Iluminacion\n");
    printf("    5) Salir\n");

    printf("\n  Selecciona una opcion: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    switch(opcion) {
        case 1:
            //Jugar
            limpiarPantalla();
            jugarRonda();
            esperarInput();
            break;
        case 2:
            // Acariciar
            limpiarPantalla();
            printf("\n    Has acariciado a tu mascota\n");
            //acaricia();
            //aplicar_efecto("Acariciar", mascota, mapa_accion_efecto);
            esperarInput();
            break;
        case 3:
            // Palmaditas
            limpiarPantalla();
            printf("    Le has dado palmaditas a tu mascota\n");
            esperarInput();
            break;
        case 4:
            // Cambiar iluminación
            limpiarPantalla();
            menuIluminacion();
            break;
        case 5:
            //Salir
            break;
        default:
            // Opción no válida
            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

void menuIluminacion() {
    int opcion;

    printf("    1) Oscuro\n");
    printf("    2) Claro\n");

    scanf("%d", &opcion);
    while (getchar() != '\n');

    switch(opcion) {
        case 1:
            //Oscuro
             printf("\033[0;40;37m");
            setConsoleColor("0F");
            break;
        case 2:
            //Claro
            printf("\033[0;97;30m");
            setConsoleColor("F0");
            break;
        default:
            // Opción no válida
            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

void menuTienda() {
    int opcion;

    printf("    ==================\n");
    printf("          Tienda:\n");
    printf("    ==================\n\n");
    printf("    1) Comprar Manzana | $50\n");
    printf("    2) comprar Agua | $50\n");
    printf("    3) Comprar Super 8 | $50\n");
    printf("    4) Comprar Coca-Cola | $50\n");
    printf("    5) Salir\n");

    printf("\n  Selecciona una opcion: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    switch(opcion) {
        case 1:
            //Manzana
            limpiarPantalla();
            printf("Has comprado una Manzana");
            esperarInput();
            break;
        case 2:
            //Agua
            limpiarPantalla();
            printf("Has comprado un Agua");
            esperarInput();
            break;
        case 3:
            //Super8
            limpiarPantalla();
            printf("Has comprado un Super 8");
            esperarInput();
            break;
                            
        case 4:
            //Coca-Cola
            limpiarPantalla();
            printf("Has comprado una Coca-Cola");
            esperarInput();
            break;
        case 5:
            //Salir
            break;
        default:
            // Opción no válida
            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

void dejarDormir() {
    printf("\nEmpezando a dormir en ");
    for (int i = 3; i > 0; i--) {
        printf("%d ", i);
        fflush(stdout); // Limpiar el buffer de salida para asegurarse de que se imprima de inmediato
        sleep(1); // Esperar un segundo
    }
    printf("\n");
}

void esperarInput() {
    printf("\n  Presiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

// Función que se encarga de eliminar todo lo impreso en pantalla
void limpiarPantalla() { system("cls"); }


/*void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota, HashMap mapa_accion_efecto) {
    limpiarPantalla();
    printf("    Has comido una ");
    for (int i = 0; item[i] != '\0'; i++) {
        printf("%c", item[i]); // Imprime cada carácter de la cadena
    }
    printf(" (%d restantes)\n", restantes);
    printf("    %d Comida\n", comida);
    printf("    %d Descanso\n", descanso);
    printf("    %d Animo\n", animo);
    esperarInput();
    limpiarPantalla();
    menuPrincipal(mapa_accion_efecto;
    menuInferior();
}*/
//soi wekito ola
