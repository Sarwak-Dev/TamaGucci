#ifndef STRUCTS_H
#define STRUCTS_H

// Inclusión de bibliotecas para definiciones
#include <time.h>
#include <stdbool.h>

#include "../TDAs/list.h"

// Constantes de cambio de nivel de estado
#define LIMIT_LVL2 60
#define LIMIT_LVL3 30

// Constantes de horas para estadística máxima
#define MAX_HORAS_COMIDA 50
#define MAX_HORAS_ANIMO 70
#define MAX_HORAS_DESCANSO 8

// Constante de pago cada 12 horas
#define DINERO_12_HORAS 40


// Estructura para representar el Tamagotchi
typedef struct Tamagotchi {
    float comida;   // Nivel de alimentación actual
    float descanso; // Nivel de descanso actual
    float animo;    // Nivel de animo actual
    bool dormido;   // Indica si la mascota está dormida
    bool vivo;      // Indica si la mascota sigue con vida
} Tamagotchi;

// Estructura para representar los items almacenados
typedef struct Item {
    char nombre[30];
    int coste;
    int restantes;
} Item;

// Estructura para definir los efectos que tendrán las acciones en las estadísticas
typedef struct Efecto {
    int alteracion_comida;
    int alteracion_descanso;
    int alteracion_animo;
    char tipo[30]; // Tipo objeto / interacción
} Efecto;

// Estructura para almacenar variables de juego
typedef struct Juego {
    Tamagotchi mascota;         // Tamagotchi en juego
    int dinero;                 // Dinero de juego
    List mochila;               // Mochila de Items almacenados
    time_t ultima_actualizacion;// Hora de última actualización
    time_t ultima_palmadita;    // Hora de última palmadita
    time_t ultimo_pago;         // Hora del último pago de dinero
    List caricias_ultima_hora;  // Lista con las horas de las últimas caricias
} Juego;

#endif // Structs