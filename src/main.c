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
void imprimir_barra(float valor);
void menuInferior();
void menuAcciones(HashMap * mapa_accion_efecto, Juego * juego, Tamagotchi * mascota);
void menuIluminacion();
void dejarDormir();
void esperarInput();
void limpiarPantalla();


bool ilum = true;

void setConsoleColor(const char* color) {
    char command[10];
    snprintf(command, sizeof(command), "color %s", color);
    system(command);
}

// Función principal
int main() {

    //Comandos de inicio de la consola
    system("chcp 65001");
    limpiarPantalla();

    // Declaración e inicialización del contenido del mapa acción-efecto
    HashMap *mapa_accion_efecto = create_map(20);
    inicializar_mapa_acciones(mapa_accion_efecto);
    printf("Mapa acción-efecto inicalizado\n");

    // Declaración e inicialización del contenido del arreglo de objetos
    Item arreglo_objetos[ARR_SIZE];
    inicializar_arreglo_objetos(arreglo_objetos);
    printf("Arreglo de objetos inicalizado\n");

    // Declaración del nombre del archivo de guardado
    const char* filename = "cache/save.txt";

    // Inicialización del Juego
    Juego* juego = (Juego*)malloc(sizeof(Juego));
    if (juego == NULL) {
        perror("Error al asignar memoria para el juego");
        return 1;
    }
    printf("Juego inicializado\n"); // Debug print

    juego->caricias_ultima_hora = list_create(); // Inicialización cola de caricias
    printf("Lista inicializadas\n");

    // Inicialización de la mascota Tamagotchi
    Tamagotchi* mascota = (Tamagotchi*)malloc(sizeof(Tamagotchi));
    if (mascota == NULL) {
        perror("Error al asignar memoria para la mascota");
        free(juego);
        return 1;
    }
    printf("Mascota inicializada\n"); // Debug print

    // Carga, actualización y guardado del juego
    /* */cargar_estado(juego, filename);
    printf("Carga finalizada\n"); // Debug print

    /*printf("%f %f %f\n", juego->mascota.comida, juego->mascota.descanso, juego->mascota.animo);
    if (juego->mochila->head == NULL) printf("Lista mochila vacía");*/

    actualizar_estado(juego);
    printf("Actualización realizada\n"); // Debug print

    actualizar_arreglo_objetos(arreglo_objetos, juego->almacenamiento);

    /*printf("%f %f %f\n", juego->mascota.comida, juego->mascota.descanso, juego->mascota.animo);
    if (juego->mochila->head == NULL) printf("Lista mochila vacía");*/

    guardar_estado(juego, filename);
    printf("Guardado realizado\n"); // Debug print

    // Se declara colores de pantalla y texto predeterminados
    //printf("\033[0;97;107m");
    setConsoleColor("F0");
    printf("\033[H\033[J");

    // Declaración de variable para la opción elegida por el usuario
    int opcion;

    // Bucle principal del programa
    while (true) {

        limpiarPantalla(); // Limpieza de impresiones de depurado
        menuPrincipal(mapa_accion_efecto, juego); // Se muestra menú principal del juego
        menuInferior(); // Se muestra menú inferior del juego

        // Se le solicita una opción al usuario
        printf("\n  Selecciona una opcion: \n");
        
        // Bucle de submenús
        scanf("%d", &opcion); // Se lee opción del usuario
        while (getchar() != '\n'); // Se espera tecla Enter para continuar

        switch(opcion) {
            case 1: 
                // Submenú de acciones
                limpiarPantalla(); // Limpieza de pantalla
                menuAcciones(mapa_accion_efecto, juego, mascota); // Se muestra submenú
                break; // Acabamos ejecución del Switch
            case 2:
                //Inventario
                limpiarPantalla(); // Limpieza de pantalla
                menuInventario(arreglo_objetos, juego, mapa_accion_efecto, mascota);
                break; // Acabamos ejecución del Switch
            case 3:
                //Tienda
                limpiarPantalla(); // Limpieza de pantalla
                menuTienda(arreglo_objetos, juego);
                break; // Acabamos ejecución del Switch
            case 4:
                // Salir
                dejarDormir();
                free(juego); // Liberar la memoria asignada
                free(mascota); // Liberar la memoria asignada
                exit(0); // Finalización del programa
                break; // Acabamos ejecución del Switch
            default:
                // Opción no válida
                printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
        }
        // Se actualiza y guarda el estado del juego
        actualizar_estado(juego); // Actualización según tiempo transcurrido
        guardar_estado(juego, filename); // Guardado en archivo
    }
    return 0; // Finalización secundaria del programa
}

// Función para el menú principal
void menuPrincipal(HashMap * mapa_accion_efecto, Juego * juego) {

    printf("\n  Estado actual del Tamagotchi:\n\n");

    printf("    Comida:");
    imprimir_barra(juego->mascota.comida);
    //printf(" %.0f%%    ", juego->mascota.comida);
    
    printf("    Descanso: ");
    imprimir_barra(juego->mascota.descanso);
    //printf(" %.0f%%    ", juego->mascota.descanso);

    printf("    Animo:");
    imprimir_barra(juego->mascota.animo);
    //printf(" %.0f%%    \n \n \n", juego->mascota.animo);

    printf("    Dinero: ");
    printf("%d$\n\n\n", juego->dinero);
    printf("   ━━━∙ʚ●ɞ∙━━━\n\n\n");

    //Gato
    mostrar_mascota(juego);
}

// Función para imprimir la barra de una estadística
void imprimir_barra(float valor) {
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
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;107m▐"); // Verde con fondo blanco, primera barra más delgada
                    } else if (valor > LIMIT_LVL3) {
                        printf("\033[0;33;107m▐"); // Amarillo con fondo blanco, primera barra más delgada
                    } else {
                        printf("\033[0;31;107m▐"); // Rojo con fondo blanco, primera barra más delgada
                    }
                } else if (i == 0 && resto >= 10) {
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;107m█"); // Verde con fondo blanco, primera barra completa
                    } else if (valor > LIMIT_LVL3) {
                        printf("\033[0;33;107m█"); // Amarillo con fondo blanco, primera barra completa
                    } else {
                        printf("\033[0;31;107m█"); // Rojo con fondo blanco, primera barra completa
                    }
                } else {
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;107m█"); // Verde con fondo blanco, barras completas
                    } else if (valor > LIMIT_LVL3) {
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
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;40m▐"); // Verde con fondo negro, primera barra más delgada
                    } else if (valor > LIMIT_LVL3) {
                        printf("\033[0;33;40m▐"); // Amarillo con fondo negro, primera barra más delgada
                    } else {
                        printf("\033[0;31;40m▐"); // Rojo con fondo negro, primera barra más delgada
                    }
                } else if (i == 0 && resto >= 10) {
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;40m█"); // Verde con fondo negro, primera barra completa
                    } else if (valor > LIMIT_LVL3) {
                        printf("\033[0;33;40m█"); // Amarillo con fondo negro, primera barra completa
                    } else {
                        printf("\033[0;31;40m█"); // Rojo con fondo negro, primera barra completa
                    }
                } else {
                    if (valor > LIMIT_LVL2) {
                        printf("\033[0;32;40m█"); // Verde con fondo negro, barras completas
                    } else if (valor > LIMIT_LVL3) {
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


// Función para mostrar menú infeiror de opciones
void menuInferior() {
    printf("\n   ━━━∙ʚ●ɞ∙━━━\n\n");
    printf("    1) Acciones\n");
    printf("    2) Abrir Inventario\n");
    printf("    3) Abrir Tienda\n");
    printf("    4) Dormir\n");
}

// Función para mostrar menú de interacciones
void menuAcciones(HashMap * mapa_accion_efecto, Juego * juego, Tamagotchi * mascota) {

    int opcion; // Declaración de variable para almacenar opción

    // Mostrar opciones de acción
    printf("\n   ━━━∙ʚ●ɞ∙━━━\n\n");
    printf("    1) Jugar\n");
    printf("    2) Acariciar\n");
    printf("    3) Palmaditas\n");
    printf("    4) Iluminacion\n");
    printf("    5) Salir\n");
    printf("\n   ━━━∙ʚ●ɞ∙━━━\n\n");

    // Solicitar opción al usuario
    printf("\n  Selecciona una opcion: \n");
    scanf("%d", &opcion); // Escanea opción del usaurio
    while (getchar() != '\n'); // Espera tecla Enter para continuar

    // Switch de opciones
    switch(opcion) {
        case 1:
            //Jugar
            limpiarPantalla(); // Limpiar pantalla
            jugarRonda();
            esperarInput();
            break;
        case 2:
            // Acariciar
            limpiarPantalla(); // Limpiar pantalla
            acaricia(juego);
            aplicar_efecto("Acariciar", &juego->mascota, mapa_accion_efecto);
            printf("\n\n  Has acariciado a tu mascota\n\n");
            esperarInput();
            break;
        case 3:
            // Palmaditas
            limpiarPantalla(); // Limpiar pantalla
            palmada(juego); // Muestra animación de palmadita
            aplicar_efecto("Palmaditas", &juego->mascota, mapa_accion_efecto); // Aplica efecto palmaditas
            printf("\n\n  Le has dado palmaditas a tu mascota\n\n");
            esperarInput();
            break;
        case 4:
            // Cambiar iluminación
            limpiarPantalla(); // Limpiar pantalla
            menuIluminacion(); // Mostrar menú de iluminación
            break;
        case 5:
            //Salir
            break;
        default:
            // Opción no válida
            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

// Función para el menú de iluminación
void menuIluminacion() {

    int opcion; // Declaración de variable para almacenar opción

    // Muestra opciones al usuario
    printf("    1) Oscuro\n");
    printf("    2) Claro\n");

    scanf("%d", &opcion); // Escanea opción del usuario
    while (getchar() != '\n'); // Espera tecla Enter para continuar

    // Switch de opciones
    switch(opcion) {
        case 1:
            //Oscuro
            setConsoleColor("0F"); // Coloca el fondo en negro
            ilum = false; // Cambia booleano de iluminación a no iluminado
            break;
        case 2:
            //Claro
            setConsoleColor("F0"); // Coloca el fondo en blanco 
            ilum = true; // Cambia booleano de iluminación a no iluminado
            break; 
        default:
            // Opción no válida
            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
}

// Función para imprimir indicacion de que se hace dormir al gato
void dejarDormir() {
    printf("\nEmpezando a dormir en ");
    for (int i = 3; i > 0; i--) {
        printf("%d ", i);
        fflush(stdout); // Limpiar el buffer de salida para asegurarse de que se imprima de inmediato
        sleep(1); // Esperar un segundo
    }
    printf("\n");
}

// Función para esperar un input del usuario
void esperarInput() {
    printf("\n  Presiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

// Función que se encarga de eliminar todo lo impreso en pantalla
void limpiarPantalla() { system("cls"); }