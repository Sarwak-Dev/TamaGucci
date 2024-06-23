#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include "../TDAs/list.h"
#include "../structs/structs.h"

// Función para escribir los elementos de un alista en un archivo separados por comas
void guardar_lista_en_archivo(FILE* file, List* lista, const char* tipo);

// Función que guarda el estado actual del juego en un archivo
void guardar_estado(Juego* juego, const char* filename);

// Función para leer la lista de archivos
void leer_lista_de_archivo(FILE* file, List* lista, const char* tipo);

// Función para cargar el estado desde un archivo para actualizar estadísticas
void cargar_estado(Juego* juego, const char* filename);

#endif