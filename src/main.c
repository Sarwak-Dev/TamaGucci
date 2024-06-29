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
#include "interaction/games/games.h"
#include "interaction/shop/shop.h"

void menuPrincipal(HashMap * mapa_accion_efecto, Juego * juego);
void menuInferior();
void menuInventario();
void menuInteracciones();
void menuIluminacion();
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
    system("chcp 65001");
    limpiarPantalla();

    //Declara la variable mapa_accion_efecto con tipo HashMap
    HashMap *mapa_accion_efecto = create_map(20); // Revisar functions.effect para mas informacion.
    Item lista_objetos[7];

    strcpy(lista_objetos[0].nombre, "Pescado");
    lista_objetos[0].coste = 20;
    lista_objetos[0].restantes = 5;

    strcpy(lista_objetos[1].nombre, "Hamburguesa");
    lista_objetos[1].coste = 30;
    lista_objetos[1].restantes = 1;

    strcpy(lista_objetos[2].nombre, "Sushi");
    lista_objetos[2].coste = 40;
    lista_objetos[2].restantes = 1;

    strcpy(lista_objetos[3].nombre, "Caja de Arena");
    lista_objetos[3].coste = 20;
    lista_objetos[3].restantes = 0;

    strcpy(lista_objetos[4].nombre, "Proteina");
    lista_objetos[4].coste = 35;
    lista_objetos[4].restantes = 0;

    strcpy(lista_objetos[5].nombre, "Redbull");
    lista_objetos[5].coste = 35;
    lista_objetos[5].restantes = 0;

    strcpy(lista_objetos[6].nombre, "Gata a domicilio");
    lista_objetos[6].coste = 35;
    lista_objetos[6].restantes = 0;

    inicializar_mapa_acciones(mapa_accion_efecto);
    //inicializar_lista_objetos(lista_objetos[7]);
    printf("Mapa inicializado\n"); // Debug print

    //menuTienda(lista_objetos);

    const char* filename = "cache/save.txt";

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

    /* */cargar_estado(juego, filename);
    printf("Carga finalizada\n"); // Debug print

    actualizar_estado(juego);
    printf("Actualización realizada\n"); // Debug print

    guardar_estado(juego, filename);
    printf("Guardado realizado\n"); // Debug print

    printf("\033[0;97;30m");
    setConsoleColor("F0");
    printf("\033[H\033[J");

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
                    menuInteracciones(mapa_accion_efecto, juego);
                    break;
                case 2:
                    //Inventario
                    limpiarPantalla();
                    menuInventario2(lista_objetos);
                    break;
                case 3:
                    //Tienda
                    limpiarPantalla();
                    menuTienda(lista_objetos);
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
            }/**/ 
        /**/actualizar_estado(juego);
        guardar_estado(juego, filename);/**/
    }

    return 0;
}

void menuPrincipal(HashMap * mapa_accion_efecto, Juego * juego) {
    Tamagotchi * mascota;

    printf("\n  Estado actual del Tamagotchi:\n\n");

    printf("    Comida: ");
    printf(" %f    ", juego->mascota.comida);

    printf("    Descanso: ");
    printf(" %f    ", juego->mascota.descanso);

    printf("    Animo: ");
    printf(" %f    \n \n \n", juego->mascota.animo);

    printf("    dinero: ");
    printf(" %f    \n \n \n", juego->dinero);

//Gato
    mostrar_mascota(mascota);
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

void menuInteracciones(HashMap * mapa_accion_efecto, Juego * juego) {
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
            acaricia();
            aplicar_efecto("Acariciar", &juego->mascota, mapa_accion_efecto);
            esperarInput();
            break;
        case 3:
            // Palmaditas
            limpiarPantalla();
            printf("\n    Le has dado palmaditas a tu mascota\n");
            aplicar_efecto("Palmadita", &juego->mascota, mapa_accion_efecto);
            palmada;
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
