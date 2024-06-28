#ifndef DESIGN_H
#define DESIGN_H

#include <time.h>
#include "../functions/structs/structs.h"

// Función que imprime la hora actual en formato H:M:S
void imprimir_hora(time_t hora);

// Muestra superior de la cabeza agotada
void cabeza_agotadaSuperior();

// Muestra superior de la cabeza cansada
void cabeza_cansadaSuperior();

// Muestra superior de la cabeza normal
void cabeza_normalSuperior();

// Muestra inferior de la cabeza triste
void cabeza_tristeInferior();

// Muestra inferior de la cabeza seria
void cabeza_seriaInferior();

// Muestra inferior de la cabeza normal
void cabeza_normalInferior();

// Muestra el cuerpo desnutrido
void cuerpo_desnutrido();

// Muestra el cuerpo hambriento
void cuerpo_hambre();

// Muestra el cuerpo normal
void cuerpo_normal();

void muertePor_tristeza();

void muertePor_agotamiento();

void muertePor_hambre();


void acaricia();

void palmada();


// Función para mostrar el gato en función del estado de sus estadísticas
void mostrar_mascota(Tamagotchi * mascota);

#endif