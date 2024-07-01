#ifndef TIENDA_H
#define TIENDA_H
#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/list.h"
#include "../../functions/effect/effect.h"

#define ARR_SIZE 7

void menuTienda(Item arreglo[ARR_SIZE], Juego * juego);
void menuInventario(Item arreglo[ARR_SIZE], Juego * juego, HashMap * mapa_acciones, Tamagotchi * mascota);

// Función que actualiza el arreglo de objetos con las cantidades restantes
void actualizar_arreglo_objetos(Item arreglo_objetos[ARR_SIZE], int almacenamiento[ARR_SIZE]);

#endif // TIENDA_H
