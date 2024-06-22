#ifndef HashMap_h
#define HashMap_h

#include "../structs/structs.h"

// Estructura para los pares clave-valor del mapa
typedef struct Pair {
     char * key;
     Efecto * value;
} Pair;

// Definición de tipo HashMap
typedef struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
} HashMap;

// Función para crear un nuevo par
Pair * create_pair(char * key,  Efecto * value);

// Función para crear e inicializar un mapa
HashMap * create_map(long capacity);

// Función para insertar un par clave-valor al mapa
void insert_map(HashMap * table, char * key, Efecto * value);

// Función para eliminar un par clave-valor del mapa
void erase_map(HashMap * table, char * key);

// Función para buscar un par por su clave dentro del mapa
Pair * search_map(HashMap * table, char * key);

// Función para retornar el primer par de un mapa
Pair * first_map(HashMap * table);

// Función para recorrer el siguiente elemento del mapa
Pair * next_map(HashMap * table);

// Función para redimensionar tamaño de una tabla
void enlarge(HashMap * map);

#endif /* HashMap_h */
