#ifndef DESIGN_H
#define DESIGN_H

#include <time.h>

// Función que se encarga de eliminar todo lo impreso en pantalla
void limpiarPantalla();

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

// Función para mostrar el gato en función del estado de sus estadísticas
void mostrar_mascota(Tamagotchi * mascota);

#endif