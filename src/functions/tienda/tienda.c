#include <stdio.h>
#include <stdlib.h>
#include "tienda.h"

Item* list_get(List *list, int index) {
    if (list == NULL || index < 0 || index >= list->size) {
        return NULL; // Índice fuera de rango o lista no inicializada
    }

    Item *current = list_first(list);
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        current = list_next(list);
        count++;
    }

}

List menuTienda(List *lista) {
    int opcion;
    printf("   ===================================================\n");
    printf("   ¡ Bienvenido a la tienda !\n");
    printf("   Objetos a disposición:\n\n");
    
    Item *current = list_first(lista);
    int i = 1;

    while (current != NULL) {
        printf("   %d) Nombre: %s, Precio: 0\n", i, current->nombre);
        i++;
        current = list_next(lista);
    }
    printf("   %d) Salir\n", i);
    
    printf("   Selecciona una opción: \n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    Item *item = NULL;

switch(opcion) {
    case 1:
        item = list_first(lista); // Obtener el primer elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido un Pescado\n");
        break;

    case 2:
        item = (Item*)list_get(lista, 1); // Obtener el segundo elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido una Hamburguesa\n");
        break;

    case 3:
        item = (Item*)list_get(lista, 2); // Obtener el tercer elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido un Sushi\n");
        break;

    case 4:
        item = (Item*)list_get(lista, 3); // Obtener el cuarto elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido una Caja de Arena\n");
        break;

    case 5:
        item = (Item*)list_get(lista, 4); // Obtener el quinto elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido una Proteína\n");
        break;

    case 6:
        item = (Item*)list_get(lista, 5); // Obtener el sexto elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido un Redbull\n");
        break;

    case 7:
        item = (Item*)list_get(lista, 6); // Obtener el séptimo elemento de la lista
        item->restantes += 1;
        printf("\n   Has adquirido una Gata a Domicilio\n");
        break;

    case 8:
        break;

    default:
        // Opción no válida
        printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
    }
    return *lista;
}




void limpiarPantalla4() { system("cls"); }



