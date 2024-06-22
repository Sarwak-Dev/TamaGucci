#ifndef STRUCTS_H
#define STRUCTS_H

// Constantes de cambio de nivel de estado
#define LVL2 60
#define LVL3 30

// Estructura para representar el Tamagotchi
typedef struct Tamagotchi {
    int comida;
    int descanso;
    int animo;
} Tamagotchi;

// Estructura para representar los items almacenados
typedef struct Item {
    char nombre[20];
    int restantes;
} Item;

// Estructura para definir los efectos que tendrán las acciones en las estadísticas
typedef struct Efecto {
    int alteracion_comida;
    int alteracion_descanso;
    int alteracion_animo;
} Efecto;

typedef struct Juego {
    Tamagotchi mascota;
    /*List mochila;
    time_t ultima_actualización;
    time_t ultima_caricia;*/
    bool dormido;
    bool vivo;
} Juego;

#endif