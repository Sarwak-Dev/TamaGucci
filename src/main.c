#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


// librerias creadas
#include "items/items.h"

struct Tamagotchi {
    int hambre;
    int cansancio;
    int aburrimiento;
};

int main() {
    // Crear un Tamagotchi
    struct Tamagotchi mascota;
    mascota.hambre = 100;
    mascota.cansancio = 100;
    mascota.aburrimiento = 100;

    // Crear un item
    struct Item manzana;
    strcpy(manzana.nombre, "Manzana");

    struct Item agua;
    strcpy(agua.nombre, "Agua");

    // Aplicar efecto del item a la mascota
    aplicarEfecto(&manzana, &mascota);
    aplicarEfecto(&agua, &mascota);

    // Mostrar el estado del Tamagotchi después de la interacción
    printf("Estado del Tamagotchi:\n");
    printf("hambre: %d\n", mascota.hambre);
    printf("cansancio: %d\n", mascota.cansancio);
    printf("aburrimiento: %d\n", mascota.aburrimiento);

    return 0;
}