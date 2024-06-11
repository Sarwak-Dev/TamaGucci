#include "items.h"

// Definir acciones para los items
void aplicarEfecto(struct Item *item, struct Tamagotchi *mascota) {
    // Verificar el nombre del item y aplicar el efecto correspondiente
    if (strcmp(item->nombre, "Manzana") == 0) {
        // Si es una manzana, aumenta la vida del Tamagotchi
        mascota->vida += 10;
    } else {
        // Otros efectos para otros items
    }
}