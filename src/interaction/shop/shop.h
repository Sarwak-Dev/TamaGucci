#ifndef TIENDA_H
#define TIENDA_H
#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/list.h"
#include "../../functions/effect/effect.h"

void menuTienda(Item lista[7], Juego * juego);
void menuInventario(Item lista[7], Juego * juego, HashMap * mapa_acciones, Tamagotchi * mascota);

#endif // TIENDA_H
