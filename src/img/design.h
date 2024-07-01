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

// Animación de la muerte por depresión
void muertePor_tristeza();

// Animación de la muerte por burnout
void muertePor_agotamiento();

// Animación de la muerte por inanición
void muertePor_hambre();

// Animación de caricia
void animacion_acariciar(Juego * juego);

// Animación de palmaditas
void animacion_palmaditas(Juego * juego);

// Animación para imprimir el cuerpo actual del gato
void mostrar_cuerpo(Juego * juego);

// Función para mostrar el gato en función del estado de sus estadísticas
void mostrar_mascota(Juego * juego);

// Función para eliminar archivo de guardado
void eliminar_archivo_guardado(const char *nombreArchivo, const char *rutaDirectorio);

#endif