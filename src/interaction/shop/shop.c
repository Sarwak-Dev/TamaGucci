#include <stdio.h>
#include <stdlib.h>

#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/hashmap.h"
#include "../../functions/TDAs/list.h"
#include "shop.h"

// Función que crea un arreglo con todos los objetos presentes en el mapa acción-efecto
/*Item * inicializar_arreglo_objetos(HashMap * mapa_accion_efecto) {

    Item objetos[10]; // Creamos arreglo de objetos
    int i = 0; // Inicializamos índice
    Pair * current = first_map(mapa_accion_efecto); // Iteador para el mapa

    // Recorremos mapa acción-efecto para encontar los efectos asociados a objetos
    while (current != NULL) {

        // Si el par actual tiene un efecto del tipo efecto
        if (strcmp(current->value->tipo,"Objeto") == 0) {

            // Creamos un objeto con el nombre y el coste correspondiente al objeto
            Item objeto = {current->key, current->value->coste, 0};

            // Agregamos el objeto al arreglo y actualizamos el índice
            objetos[i] = objeto;
            i++;
        }
        current = next_map(mapa_accion_efecto); // Recorremos el siguiente par
    }
    // Retornamos el arreglo con todos los objetos del mapa
    return objetos;
}*/

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

List menuTienda(Item * objetos[10]) {
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



