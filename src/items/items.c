#include <string.h>
#include "items.h"

// Definir acciones para los items
void aplicarEfecto(struct Item *item, struct Tamagotchi *mascota) {
    // Verificar el nombre del item y aplicar el efecto correspondiente
    if (strcmp(item->nombre, "Manzana") == 0) {
        // Si es una manzana, aumenta la vida del Tamagotchi
        mascota->hambre += 10;
    } 

    else if (strcmp(item->nombre, "Agua") == 0) {
        // Si es un agua, aumenta la vida del Tamagotchi
        mascota->hambre += 8;
    } 
    
    else {
        // Otros efectos para otros items
    }
}