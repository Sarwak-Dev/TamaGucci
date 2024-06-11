#ifndef ITEMS_H
#define ITEMS_H

// Estructura para representar los items disponibles
struct Item {
    char nombre[20];
    // Otras propiedades relevantes
};

// Estructura para representar el Tamagotchi
struct Tamagotchi {
    int vida;
    int hambre;
    int sed;
    bool feliz;
};

// Definir acciones para los items
void aplicarEfecto(struct Item *item, struct Tamagotchi *mascota);

#endif