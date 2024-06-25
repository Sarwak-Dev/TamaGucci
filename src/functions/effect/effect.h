#ifndef EFFECT_H
#define EFFECT_H

#include "../structs/structs.h"
#include "../TDAs/hashmap.h"

struct HashMap;

// Incializa mapa de acciones y efectos en estadísticas
HashMap inicializar_mapa_acciones(HashMap mapa_acciones);

// Definir acciones para los items
bool aplicar_efecto(char * accion, struct Tamagotchi *mascota, HashMap *mapa_acciones);

#endif