#ifndef TIENDA_H
#define TIENDA_H
#include "../../functions/structs/structs.h"
#include "../../functions/TDAs/list.h"

Item* list_get(List *list, int index);

List menuTienda (List * lista);

#endif // TIENDA_H
