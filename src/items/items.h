#ifndef ITEMS_H
#define ITEMS_H

// Estructura para representar los items disponibles
struct Item {
    char nombre[20];
    // Otras propiedades relevantes
};

// Estructura para representar el Tamagotchi
struct Tamagotchi {
    int hambre;
    int cansancio;
    int aburrimiento;
};
// Definir acciones para los items
void aplicarEfecto(struct Item *item, struct Tamagotchi *mascota);

#endif