#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "games.h"

void limpiarPantalla2();

// Función para obtener la elección de la computadora
int obtenerEleccionComputadora() {
    return rand() % 3 + 1;
}

// Función para mostrar el resultado
void mostrarResultado(int jugador, int computadora) {
    const char *opciones[] = {"Tijeras", "Piedra", "Papel"};

    printf("\n   Tú elegiste: %s\n", opciones[jugador - 1]);
    printf("   El gato eligió: %s\n\n", opciones[computadora - 1]);

    if (jugador == computadora) {
        printf("   Es un empate!\n");
    } else if ((jugador == 1 && computadora == 3) || 
               (jugador == 2 && computadora == 1) || 
               (jugador == 3 && computadora == 2)) {
        printf("   ¡Ganaste esta ronda!\n");
    } else {
        printf("   ¡Perdiste esta ronda!\n");
    }
}

// Función para determinar el ganador de una ronda
int determinarGanador(int jugador, int computadora) {
    if (jugador == computadora) {
        return 0; // Empate
    } else if ((jugador == 1 && computadora == 3) || 
               (jugador == 2 && computadora == 1) || 
               (jugador == 3 && computadora == 2)) {
        return 1; // Jugador gana
    } else {
        return 2; // Computadora gana
    }
}

// Función para jugar una ronda y acumular los resultados
void jugarRonda() {
    int eleccionJugador;
    int puntosJugador = 0;
    int puntosComputadora = 0;

    srand(time(0));  // Inicializar la semilla del generador de números aleatorios

    while (puntosJugador < 2 && puntosComputadora < 2) {
        printf("\n   Bienvenido al juego de Piedra, Papel o Tijeras\n\n");
        printf("\n");     
        printf("   █    █          ▄▄▄           ██████ \n");
        printf("    █  █         ▄▀   ▀▄         ██████ \n");
        printf("    ▄██▄        █       █        ██████ \n");
        printf("   ▀▄▀▀▄▀       ▀▄▄▄▄▄▄▄▀        ██████ \n");
        printf("\n\n");
        printf("   1) Tijeras   ");
        printf("   2) Piedra    ");
        printf("   3) Papel\n\n");
        printf("   Elige una opción: ");
        scanf("%d", &eleccionJugador);
        limpiarPantalla2();
        printf("   Opción: %d", eleccionJugador);

        if (eleccionJugador < 1 || eleccionJugador > 3) {
            printf("Opción no válida. Inténtalo de nuevo.\n");
            continue;
        }

        int eleccionComputadora = obtenerEleccionComputadora();
        mostrarResultado(eleccionJugador, eleccionComputadora);

        int resultado = determinarGanador(eleccionJugador, eleccionComputadora);
        if (resultado == 1) {
            puntosJugador++;
        } else if (resultado == 2) {
            puntosComputadora++;
        }

        printf("   Puntuación: Jugador %d - %d Gato\n\n", puntosJugador, puntosComputadora);
    }

    if (puntosJugador == 2) {
        printf("   ¡Felicidades! Ganaste el juego.\n");
        scanf(" ");
    } else {
        printf("   ¡Lo siento! El Gato ganó el juego.\n");
        scanf(" ");
    }
}

void limpiarPantalla2() { system("cls"); }
