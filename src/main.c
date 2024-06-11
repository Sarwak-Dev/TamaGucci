#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


// librerias creadas
#include "items.h"

struct Tamagotchi {
    int vida;
    int hambre;
    int sed;
    bool feliz;
};

int main() {
    // Crear un Tamagotchi
    struct Tamagotchi mascota;
    mascota.vida = 100;
    mascota.hambre = 0;
    mascota.sed = 0;
    mascota.feliz = true;

    // Crear un item
    struct Item manzana;
    strcpy(manzana.nombre, "Manzana");

    // Aplicar efecto del item a la mascota
    aplicarEfecto(&manzana, &mascota);

    // Mostrar el estado del Tamagotchi después de la interacción
    printf("Estado del Tamagotchi:\n");
    printf("Vida: %d\n", mascota.vida);
    printf("Hambre: %d\n", mascota.hambre);
    printf("Sed: %d\n", mascota.sed);
    printf("Feliz: %s\n", mascota.feliz ? "Sí" : "No");

    return 0;
}