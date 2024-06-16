#include <string.h>
#include <stdbool.h>
#include "../structs/structs.h"
#include "../TDAs/hashmap.h"
#include "effect.h"

// Incializa mapa de acciones y efectos en estadísticas
HashMap inicializar_mapa_acciones(HashMap mapa_acciones) {

    // Inicializar acción jugar y añadirla al mapa
    Efecto efecto_jugar = {0, -10, 20};
    insert_pair("Jugar", &efecto_jugar);

    // Inicializar acción acariciar y añadirla al mapa
    Efecto efecto_acariciar = {0, 0, 15};
    insert_pair("Acariciar", &efecto_acariciar);

    // Inicializar acción comer pescado y añadirla al mapa
    Efecto efecto_pescado = {30, -10, 10};
    insert_pair("Pescado", &efecto_pescado);

    // Inicializar acción comere hamburguesa y añadirla al mapa
    Efecto efecto_hamburguesa = {30, -20, 20};
    insert_pair("Hamburguesa", &efecto_hamburguesa);


    // Retornamos mapa con sus pares acción-efecto inicializadas
    return mapa_acciones;
}
/* Estos son solo ejemplos de objetos y acciones que se pueden introducir. Podemos optar 
por inicializar los objetos en el mismo código como hago aquí, o bien agregar y editar 
los efectos de los objetos en un .txt que esta función se encargue de leer para 
// poblar el mapa con esos datos*/



// Definir acciones para los items
bool aplicar_efecto(char * nombre_accion, struct Tamagotchi *mascota, HashMap *mapa_acciones) {

    // Buscamos par acción-efecto por nombre en el mapa de acciones
    Pair * par_accion = search_map(mapa_acciones, nombre_accion);
    if (par_accion == NULL) return false; // Indicar que no se pudo aplicar

    // Aplicar variación de estadísticas por el efecto
    mascota->comida     +=  par_accion->value->alteracion_comida;
    mascota->descanso   +=  par_accion->value->alteracion_descanso;
    mascota->animo      +=  par_accion->value->alteracion_animo;

    // Confirmar que el efecto pudo aplicarse
    return true;
}