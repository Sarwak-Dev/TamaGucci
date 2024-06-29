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
void imprimir_barras(float valor);
void menuInferior();
void menuInteracciones(HashMap * mapa_accion_efecto, Juego * juego, Tamagotchi * mascota);
void menuIluminacion();
void dejarDormir();
void esperarInput();
void limpiarPantalla();
void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota, HashMap mapa_accion_efecto);

bool ilum = true;

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

    inicializar_mapa_acciones(mapa_accion_efecto);
    inicializar_lista_objetos(lista_objetos);
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
    juego->mochila = list_create();
    juego->caricias_ultima_hora = list_create();
    printf("Listas inicializadas\n");

    Tamagotchi* mascota = (Tamagotchi*)malloc(sizeof(Tamagotchi));
    if (mascota == NULL) {
        perror("Error al asignar memoria para la mascota");
        free(juego);
        return 1;
    }
    printf("Mascota inicializada\n"); // Debug print

    /* */cargar_estado(juego, filename);
    printf("Carga finalizada\n"); // Debug print

    printf("%f %f %f\n", juego->mascota.comida, juego->mascota.descanso, juego->mascota.animo);
    if (juego->mochila->head == NULL) printf("Lista mochila vacía");

    actualizar_estado(juego);
    printf("Actualización realizada\n"); // Debug print

    printf("%f %f %f\n", juego->mascota.comida, juego->mascota.descanso, juego->mascota.animo);
    if (juego->mochila->head == NULL) printf("Lista mochila vacía");

    guardar_estado(juego, filename);
    printf("Guardado realizado\n"); // Debug print

    //printf("\033[0;97;107m");
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
                    menuInteracciones(mapa_accion_efecto, juego, mascota);
                    break;
                case 2:
                    //Inventario
                    limpiarPantalla();
                    menuInventario(lista_objetos, juego);
                    break;
                case 3:
                    //Tienda
                    limpiarPantalla();
                    menuTienda(lista_objetos, juego);
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
    Tamagotchi * mascota;

    printf("\n  Estado actual del Tamagotchi:\n\n");

    printf("    Comida:");
    imprimir_barras(juego->mascota.comida);
    //printf(" %.0f%%    ", juego->mascota.comida);
    
    printf("    Descanso: ");
    imprimir_barras(juego->mascota.descanso);
    //printf(" %.0f%%    ", juego->mascota.descanso);

    printf("    Animo:");
    imprimir_barras(juego->mascota.animo);
    //printf(" %.0f%%    \n \n \n", juego->mascota.animo);

    printf("    Dinero: ");
    printf("%d$\n\n\n", juego->dinero);
    printf("   ━━━∙ʚ●ɞ∙━━━\n\n\n");

    //printf("\033[0;40;37m");

//Gato
    mostrar_mascota(mascota, juego);
}

void imprimir_barras(float valor) {
    int num_barras = valor / 10; // Número de barras completas
    float resto = valor - num_barras * 10; // Resto para determinar la barra más delgada
    
    if (ilum == true) {
        if (valor <= 0) {
            printf(" ");
        } else if (valor < 10) {
            printf("\033[0;31;107m▌"); // Rojo con fondo blanco
        } else {
            // Imprimir barras completas
            for (int i = 0; i < num_barras; ++i) {
                if (i == 0 && resto > 0 && resto < 10) {
                    if (valor > 60) {
                        printf("\033[0;32;107m▐"); // Verde con fondo blanco, primera barra más delgada
                    } else if (valor > 30) {
                        printf("\033[0;33;107m▐"); // Amarillo con fondo blanco, primera barra más delgada
                    } else {
                        printf("\033[0;31;107m▐"); // Rojo con fondo blanco, primera barra más delgada
                    }
                } else if (i == 0 && resto >= 10) {
                    if (valor > 60) {
                        printf("\033[0;32;107m█"); // Verde con fondo blanco, primera barra completa
                    } else if (valor > 30) {
                        printf("\033[0;33;107m█"); // Amarillo con fondo blanco, primera barra completa
                    } else {
                        printf("\033[0;31;107m█"); // Rojo con fondo blanco, primera barra completa
                    }
                } else {
                    if (valor > 60) {
                        printf("\033[0;32;107m█"); // Verde con fondo blanco, barras completas
                    } else if (valor > 30) {
                        printf("\033[0;33;107m█"); // Amarillo con fondo blanco, barras completas
                    } else {
                        printf("\033[0;31;107m█"); // Rojo con fondo blanco, barras completas
                    }
                }
            }
        }
        printf("\033[0;30;107m"); // Restaurar colores por defecto al final
    } else {
        if (valor <= 0) {
            printf(" ");
        } else if (valor < 10) {
            printf("\033[0;31;40m▌"); // Rojo con fondo negro
        } else {
            // Imprimir barras completas
            for (int i = 0; i < num_barras; ++i) {
                if (i == 0 && resto > 0 && resto < 10) {
                    if (valor > 60) {
                        printf("\033[0;32;40m▐"); // Verde con fondo negro, primera barra más delgada
                    } else if (valor > 30) {
                        printf("\033[0;33;40m▐"); // Amarillo con fondo negro, primera barra más delgada
                    } else {
                        printf("\033[0;31;40m▐"); // Rojo con fondo negro, primera barra más delgada
                    }
                } else if (i == 0 && resto >= 10) {
                    if (valor > 60) {
                        printf("\033[0;32;40m█"); // Verde con fondo negro, primera barra completa
                    } else if (valor > 30) {
                        printf("\033[0;33;40m█"); // Amarillo con fondo negro, primera barra completa
                    } else {
                        printf("\033[0;31;40m█"); // Rojo con fondo negro, primera barra completa
                    }
                } else {
                    if (valor > 60) {
                        printf("\033[0;32;40m█"); // Verde con fondo negro, barras completas
                    } else if (valor > 30) {
                        printf("\033[0;33;40m█"); // Amarillo con fondo negro, barras completas
                    } else {
                        printf("\033[0;31;40m█"); // Rojo con fondo negro, barras completas
                    }
                }
            }
        }
        printf("\033[0;97;40m"); // Restaurar colores por defecto al final
    }
}

void menuInferior() {
    printf("\n   ━━━∙ʚ●ɞ∙━━━\n\n");
    printf("    1) Acciones\n");
    printf("    2) Abrir Inventario\n");
    printf("    3) Abrir Tienda\n");
    printf("    4) Dormir\n");
}

void menuInteracciones(HashMap * mapa_accion_efecto, Juego * juego, Tamagotchi * mascota) {
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
            acaricia(mascota, juego);
            aplicar_efecto("Acariciar", &juego->mascota, mapa_accion_efecto);
            printf("\n\n  Has acariciado a tu mascota\n\n");
            esperarInput();
            break;
        case 3:
            // Palmaditas
            limpiarPantalla();
            palmada(mascota, juego);
            aplicar_efecto("Palmadita", &juego->mascota, mapa_accion_efecto);
            printf("\n\n  Le has dado palmaditas a tu mascota\n\n");
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
            setConsoleColor("0F");
            ilum = false;
            break;
        case 2:
            //Claro
            setConsoleColor("F0");
            ilum = true;
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