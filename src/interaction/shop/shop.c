#include <stdio.h>
#include <stdlib.h>
#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/hashmap.h"
#include "../../functions/TDAs/list.h"
#include "shop.h"

#define ARR_SIZE 7

void esperarInput2() {
    printf("\n  Presiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

void menuTienda(Item lista[ARR_SIZE], Juego * juego) {
    // Mostrar el encabezado y la lista de productos disponibles
    printf("\n   ╔════════════════════════════════════════╗\n");
    printf("   ║                TIENDA                  ║\n");
    printf("   ║════════════════════════════════════════║\n");
    printf("   ║                                        ║\n");
    
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("   ║ %2d) %-30s $%d  ║\n", i + 1, lista[i].nombre, lista[i].coste);
    }
    printf("   ║ %2d) %-30s     ║\n", ARR_SIZE + 1, "Salir");
    printf("   ╚════════════════════════════════════════╝\n");

    // Leer la opción del usuario
    int opcion;
    printf("\n   Selecciona una opción: ");

    if (scanf("%d", &opcion) != 1) {
        printf("\n   Error: entrada no válida. Saliendo de la tienda.\n");
        esperarInput2();
        return;
    }

    while (getchar() != '\n'); // Limpiar el buffer de entrada

    // Procesar la opción seleccionada
    if (opcion >= 1 && opcion <= ARR_SIZE) {
        // Comprobar si el jugador tiene suficiente dinero
        if (lista[opcion - 1].coste <= juego->dinero) {
            lista[opcion - 1].restantes += 1;
            juego->dinero -= lista[opcion - 1].coste;
            printf("\n   Has adquirido un(a) %s.\n", lista[opcion - 1].nombre);
        } else {
            printf("\n   No tienes suficiente dinero para comprar %s.\n", lista[opcion - 1].nombre);
        }
        esperarInput2();
        
    } else if (opcion == ARR_SIZE + 1) {
        printf("\n   Saliendo de la tienda...\n");
    } else {
        printf("\n   Opción no válida. Por favor, selecciona una opción válida.\n");
        esperarInput2();
    }
    printf("\n");
}

void menuInventario(Item lista[ARR_SIZE], Juego * juego) {
    // Mostrar el encabezado y la lista de objetos en el inventario
    printf("\n   ╔════════════════════════════════════════════════╗\n");
    printf("   ║                   INVENTARIO                   ║\n");
    printf("   ║════════════════════════════════════════════════║\n");
    printf("   ║                                                ║\n");
    printf("   ║ Dinero: $%-8d                              ║\n", juego->dinero);
    printf("   ║                                                ║\n");

    // Crear una lista temporal de objetos con restantes > 0
    Item listaTemp[ARR_SIZE];
    int numObjetos = 0;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (lista[i].restantes > 0) {
            strcpy(listaTemp[numObjetos].nombre, lista[i].nombre);
            listaTemp[numObjetos].coste = lista[i].coste;
            listaTemp[numObjetos].restantes = lista[i].restantes;
            numObjetos++;
        }
    }

    // Mostrar los objetos disponibles en el inventario
    for (int i = 0; i < numObjetos; i++) {
        printf("   ║ %2d) %-37s x%-4d║\n", i + 1, listaTemp[i].nombre, listaTemp[i].restantes);
    }
    printf("   ║ %2d) %-30s             ║\n", numObjetos + 1, "Salir");
    printf("   ║                                                ║\n");
    printf("   ╚════════════════════════════════════════════════╝\n");

    // Leer la opción del usuario
    int opcion;
    printf("\n   Selecciona una opción: ");
    if (scanf("%d", &opcion) != 1) {
        printf("\n   Error: entrada no válida. Saliendo del inventario.\n");
        esperarInput2();
        return;
    }
    while (getchar() != '\n'); // Limpiar el buffer de entrada

    // Procesar la opción seleccionada
    if (opcion >= 1 && opcion <= numObjetos) {
        listaTemp[opcion - 1].restantes -= 1;
        printf("\n   Has consumido un(a) %s.\n", listaTemp[opcion - 1].nombre);
        esperarInput2();

        // Actualizar el inventario original
        for (int i = 0; i < ARR_SIZE; i++) {
            if (strcmp(lista[i].nombre, listaTemp[opcion - 1].nombre) == 0) {
                lista[i].restantes -= 1;
                break;
            }
        }
    } else if (opcion == numObjetos + 1) {
        printf("   Saliendo del inventario...\n");
    } else {
        printf("\n   Opción no válida. Por favor, selecciona una opción válida.\n");
        esperarInput2();
    }
    printf("\n");
}

void limpiarPantalla4() { system("cls"); }



