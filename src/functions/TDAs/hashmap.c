#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../effect/effect.h"
#include "hashmap.h"
#include <stdbool.h>
#include <assert.h>

// Crear par clave-valor
Pair * create_pair( char * key,  Efecto * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

// Función Hash para elegir posisicón del par en el mapa
long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

// Función que compara si dos cadenas son idénticas
int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

// Función que corrobora si un espacio de la tabla está disponible
bool aviable(Pair **buckets, long pos) {
  if (buckets[pos] == NULL || buckets[pos]->key == NULL) return true;
  return false;
}

// Función que recibe un par y una posición específica para insertarse
void insert_pair(Pair **buckets, char * key, Efecto * value, long pos) {
  if (buckets[pos] == NULL) buckets[pos] = createPair(key, value);
  buckets[pos]->key = key;
  buckets[pos]->value = value;
}

// Función que busca una posición para un par y lo agrega en el mapa
void insert_map(HashMap * map, char * key, Efecto * value) {
    if(map==NULL || key==NULL) return;
    if(map->size > 0.7 * map->capacity) enlarge(map);
  
    long hashkey = hash(key, map->capacity);
    long i = hashkey;
  
    do {
      if (aviable(map->buckets, i)) {
        insertPair(map->buckets, key, value, i);
        map->size++;
        map->current = i;
        return;
      } i = (i + 1) % map->capacity;
    } while (i != hashkey);
}

// Función que redimensiona el tamaño del mapa
void enlarge(HashMap * map) {
  
  long old_capacity = map->capacity;
  map->capacity *= 2;
  
  Pair ** old_buckets = map->buckets;
  Pair ** new_buckets = (Pair **) calloc (map->capacity, sizeof(Pair *));
  assert(new_buckets != NULL);
  map->buckets = new_buckets;
  
  for (long i = 0 ; i < old_capacity ; i++) {
    if (old_buckets[i] != NULL) insertMap(map, old_buckets[i]->key, old_buckets[i]->value);
  }
  free(old_buckets);
}

// Función que crea un mapa
HashMap * create_map(long capacity) {
    HashMap * map = (HashMap *)malloc(sizeof(HashMap));
    assert(map != NULL);
    map->buckets = (Pair **)calloc(capacity, sizeof(Pair *));
    assert(map->buckets != NULL);
    map->size = 0;
    map->capacity = capacity;
    map->current = -1;
    return map;
}

// Función que elimina un par del mapa
void erase_map(HashMap * map,  char * key) {    
  Pair *deleted = searchMap(map, key);
  if (deleted != NULL) {
    deleted->key = NULL;
    map->size -= 1;
  }
}

// Función para buscar un par por su clave dentro del mapa
Pair * search_map(HashMap * map,  char * key) {   
  long hashkey = hash(key, map->capacity);
  while (map->buckets[hashkey] != NULL) {
    if (is_equal(map->buckets[hashkey]->key, key)) {
      map->current = hashkey;
      return map->buckets[hashkey];
    } hashkey = (hashkey + 1) % map->capacity;
  } return NULL;
}

// Función para retornar el primer par de un mapa
Pair * first_map(HashMap * map) {
  for (long i = 0; i < map->capacity; i++) {
    if (map->buckets[i] != NULL && map->buckets[i]->key) {
      map->current = i;
      return map->buckets[i];
    }
  } return NULL;
}

// Función para recorrer el siguiente elemento del mapa
Pair * next_map(HashMap * map) {
  for (long i = map->current + 1; i < map->capacity; i++) {
    if (map->buckets[i] != NULL && map->buckets[i]->key != NULL) {
      map->current = i;
      return map->buckets[i];
    }
  } return NULL;
}
