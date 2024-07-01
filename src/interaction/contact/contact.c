#include <stdio.h>
#include <time.h>

#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/hashmap.h"
#include "../../functions/effect/effect.h"
#include "contact.h"

// Función para efectuar caricia en el tamagotchi
void acariciar(Juego * juego, HashMap * mapa_accion_efecto) {
    time_t ahora = time(NULL); // Hora actual
    time_t* caricia_tiempo;
    
    // Eliminar caricias que ocurrieron hace más de una hora
    while (juego->caricias_ultima_hora->size > 0) {
        caricia_tiempo = (time_t*)list_first(juego->caricias_ultima_hora);
        double diferencia = difftime(ahora, *caricia_tiempo);
        
        if (diferencia > 3600) { // Si la diferencia es mayor a una hora
            free(list_popFront(juego->caricias_ultima_hora)); // Eliminar la caricia
        } else {
            break; // Terminar el bucle si se encuentra una caricia dentro de la hora
        }
    }

    // Verificar si la lista tiene menos de 5 elementos
    if (juego->caricias_ultima_hora->size < 5) {

        // Indicar que caricia tuvo efecto
        printf("\n\n  Has acariciado a tu mascota\n\n");

        // Aplicar el efecto de la caricia
        aplicar_efecto("Acariciar", &juego->mascota, mapa_accion_efecto);

        // Añadir la caricia actual a la lista
        time_t* nueva_caricia = (time_t*)malloc(sizeof(time_t));
        *nueva_caricia = ahora;
        list_pushBack(juego->caricias_ultima_hora, nueva_caricia);
    } else {
        // Indicar que caricia no hizo efecto
        printf("\n\n  Has alcanzado el límite de caricias por hora. Caricia sin efecto\n\n");
    }
}

// Función para dar palmaditas al gato
void dar_palmaditas(Juego* juego, HashMap* mapa_accion_efecto) {
    time_t ahora = time(NULL); // Hora actual
    double diferencia = difftime(ahora, juego->ultima_palmadita); // Diferencia de tiempo en segundos

    if (diferencia > 3600) { // Si la diferencia es menor a una hora
        aplicar_efecto("Palmaditas", &juego->mascota, mapa_accion_efecto);
        printf("\n\n  Le has dado palmaditas a tu mascota\n\n");
    } else {
        aplicar_efecto("Palmaditas Innecesarias", &juego->mascota, mapa_accion_efecto);
        printf("\n\n  Palmaditas innecesarias. Tu mascota no necesitaba más palmaditas.\n\n");
    }

    // Actualizar la hora de la última palmadita
    juego->ultima_palmadita = ahora;
}