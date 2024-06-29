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

void menuTienda(Item lista[7]) {
    int opcion;
    printf("   ===================================================\n");
    printf("   ¡Bienvenido a la tienda!\n");
    printf("   Objetos a disposición:\n\n");
    
    for (int i = 0; i < 7; i++) {
        printf("   %d) Nombre: %s, Precio: %d\n", i + 1, lista[i].nombre, lista[i].coste);
    }
    printf("   8) Salir\n");

    printf("   Selecciona una opción: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion >= 1 && opcion <= 7) {
        lista[opcion - 1].restantes += 1;
        printf("\n   Has adquirido un(a) %s\n", lista[opcion - 1].nombre);
    } else if (opcion == 8) {
        printf("   Saliendo de la tienda...\n\n");
    } else {
        printf("\n   Opción no válida. Por favor, selecciona una opción válida.\n");
    }
    printf("\n");
}

void menuInventario2(Item lista[7]) {
    int opcion;
    printf("   ===================================================\n");
    printf("   ¡Bienvenido al inventario!\n");
    printf("   Objetos en colección:\n\n");
    
    Item lista2[7];
    int k = 0;

    // Copiar elementos de lista a lista2 solo si restantes > 0
    for (int i = 0; i < 7; i++) {
        if (lista[i].restantes > 0) {
            strcpy(lista2[k].nombre, lista[i].nombre);
            lista2[k].coste = lista[i].coste;
            lista2[k].restantes = lista[i].restantes;
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("   %d) Nombre: %s, Cantidad: %d\n", i + 1, lista2[i].nombre, lista2[i].restantes);
    }
    printf("   %d) Salir\n", k + 1);

    printf("   Selecciona una opción: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion >= 1 && opcion <= k) {
        lista2[opcion - 1].restantes -= 1;
        esperarInput2();
        printf("\n   Has consumido un(a) %s\n", lista2[opcion - 1].nombre);

        // Actualizar el elemento correspondiente en lista
        for (int i = 0; i < 7; i++) {
            if (strcmp(lista[i].nombre, lista2[opcion - 1].nombre) == 0) {
                lista[i].restantes -= 1;
                break;
            }
        }
    } else if (opcion == k + 1) {
        printf("   Saliendo del inventario...\n\n");
    } else {
        printf("\n   Opción no válida. Por favor, selecciona una opción válida.\n");
    }
    printf("\n");
}

void limpiarPantalla4() { system("cls"); }



