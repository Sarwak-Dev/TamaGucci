#ifndef TIENDA_H
#define TIENDA_H
#include "../structs/structs.h"
#include "../TDAs/list.h"

Item* list_get(List *list, int index);

List menuTienda (List * lista);

#endif // TIENDA_H
