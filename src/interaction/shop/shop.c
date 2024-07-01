#include <stdio.h>
#include <stdlib.h>
#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/hashmap.h"
#include "../../functions/TDAs/list.h"
#include "shop.h"

void esperarInput2() {
    printf("\n  Presiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

void menuTienda(Item arreglo[ARR_SIZE], Juego * juego) {
    // Mostrar el encabezado y la lista de productos disponibles
    printf("\n   ╔════════════════════════════════════════╗\n");
    printf("   ║                TIENDA                  ║\n");
    printf("   ║════════════════════════════════════════║\n");
    printf("   ║                                        ║\n");
    
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("   ║ %2d) %-30s $%d  ║\n", i + 1, arreglo[i].nombre, arreglo[i].coste);
    }
    printf("   ║ %2d) %-30s     ║\n", ARR_SIZE + 1, "Salir");
    printf("   ╚════════════════════════════════════════╝\n");

    int opcion; // Variable para almacenar opción del usuario

    printf("\n   Selecciona una opción: ");

    // De entregar una opción no válida, se sale de la tienda
    if (scanf("%d", &opcion) != 1) {
        printf("\n   Error: entrada no válida. Saliendo de la tienda.\n");
        esperarInput2();
        return;
    }

    while (getchar() != '\n'); // Limpiar el buffer de entrada

    // Procesar la opción seleccionada
    if (opcion >= 1 && opcion <= ARR_SIZE) {
        // Comprobar si el jugador tiene suficiente dinero
        if (arreglo[opcion - 1].coste <= juego->dinero) {

            // Aumentar cantidad restante del objeto
            arreglo[opcion - 1].restantes += 1; // En arreglo de objetos
            juego->almacenamiento[opcion - 1] += 1; // En arreglo de almacenamiento dentro del struct Juego

            // Disminuir dinero en relación al coste del objeto comprado
            juego->dinero -= arreglo[opcion - 1].coste;

            // Indicar al usuario que la compra se ha efectuado
            printf("\n   Has adquirido un(a) %s.\n", arreglo[opcion - 1].nombre);
        } else {
            // Indicar al usuario que la compra no pudo realizarse por falta de dinero
            printf("\n   No tienes suficiente dinero para comprar %s.\n", arreglo[opcion - 1].nombre);
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

void menuInventario(Item arreglo[ARR_SIZE], Juego * juego, HashMap * mapa_acciones, Tamagotchi * mascota) {
    // Mostrar el encabezado y el arreglo de objetos en el inventario
    printf("\n   ╔════════════════════════════════════════════════╗\n");
    printf("   ║                   INVENTARIO                   ║\n");
    printf("   ║════════════════════════════════════════════════║\n");
    printf("   ║                                                ║\n");
    printf("   ║ Dinero: $%-8d                              ║\n", juego->dinero);
    printf("   ║                                                ║\n");

    // Crear un arreglo temporal de objetos con restantes > 0
    Item arregloTemp[ARR_SIZE];
    int numObjetos = 0;

    // Recorre arreglo de objetos para corroborar cuáles tienen restantes
    for (int i = 0; i < ARR_SIZE; i++) {
        if (arreglo[i].restantes > 0) {

            // Le damos al objeto de el arreglo temporal los valores correspondientes
            strcpy(arregloTemp[numObjetos].nombre, arreglo[i].nombre); // Copiamos nombre
            arregloTemp[numObjetos].coste = arreglo[i].coste; // Asignamos coste
            arregloTemp[numObjetos].restantes = arreglo[i].restantes; // Asignamos cantidad restante
            numObjetos++;
        }
    }

    // Mostrar los objetos disponibles en el inventario
    for (int i = 0; i < numObjetos; i++) {
        printf("   ║ %2d) %-37s x%-4d║\n", i + 1, arregloTemp[i].nombre, arregloTemp[i].restantes);
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

        // Se disminuye valor de restantes del objeto seleccionado
        arregloTemp[opcion - 1].restantes -= 1; // En arreglo temporal
        printf("\n   Has consumido un(a) %s.\n", arregloTemp[opcion - 1].nombre);
        aplicar_efecto(arregloTemp[opcion - 1].nombre, &juego->mascota, mapa_acciones);
        esperarInput2();

        // Se recorre inventario original para encontrar objeto original
        for (int i = 0; i < ARR_SIZE; i++) {

            // De tener el mismo nombre de objeto, se disminuye restantes
            if (strcmp(arreglo[i].nombre, arregloTemp[opcion - 1].nombre) == 0) {
                arreglo[i].restantes -= 1; //
                juego->almacenamiento[i] -= 1;
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

// Función que actualiza el arreglo de objetos con las cantidades restantes
void actualizar_arreglo_objetos(Item arreglo_objetos[7], int almacenamiento[7]) {
    for (int i = 0; i < 7; i++) {
        arreglo_objetos[i].restantes = almacenamiento[i];
    }
}

void limpiarPantalla4() { system("cls"); }



