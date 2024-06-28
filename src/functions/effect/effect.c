#include "effect.h"
// Comida Descanso Animo Precio Tipo

// Incializa mapa de acciones y efectos en estadísticas
HashMap * inicializar_mapa_acciones(HashMap * mapa_acciones) {

    // Inicializar acción jugar y añadirla al mapa
    Efecto efecto_jugar = {0, -20, 35, 0, "Interaccion"};
    insert_map(mapa_acciones, "Jugar", &efecto_jugar);

    // Inicializar acción acariciar y añadirla al mapa
    Efecto efecto_acariciar = {0, 0, 15, 0, "Interaccion"};
    insert_map(mapa_acciones, "Acariciar", &efecto_acariciar);

    // Inicializar acción palmaditas y añadirla al mapa
    Efecto efecto_palmaditas = {0, 10, -5, 0, "Interaccion"};
    insert_map(mapa_acciones, "Palmadita", &efecto_palmaditas);

    // Inicializar acción comer pescado y añadirla al mapa
    Efecto efecto_pescado = {20, -5, 10, 20, "Objeto"};
    insert_map(mapa_acciones, "Pescado", &efecto_pescado);

    // Inicializar acción comere hamburguesa y añadirla al mapa
    Efecto efecto_hamburguesa = {20, -10, 15, 20, "Objeto"};
    insert_map(mapa_acciones, "Hamburguesa", &efecto_hamburguesa);

    // Inicializar acción comere sushi y añadirla al mapa
    Efecto efecto_sushi = {30, 0, 20, 60, "Objeto"};
    insert_map(mapa_acciones, "Sushi", &efecto_sushi);

    // Inicializar acción cajaArena y añadirla al mapa
    Efecto efecto_cajaArena = {-10, -20, -30, 25, "Objeto"};
    insert_map(mapa_acciones, "Caja de Arena", &efecto_cajaArena);

    // Inicializar acción proteina y añadirla al mapa
    Efecto efecto_proteina = {35, -10, -10, 40, "Objeto"};
    insert_map(mapa_acciones, "Proteina", &efecto_proteina);

    // Inicializar acción redbull y añadirla al mapa
    Efecto efecto_redbull = {-10, 35, -10, 40, "Objeto"};
    insert_map(mapa_acciones, "Redbull", &efecto_redbull);

    // Inicializar acción gata y añadirla al mapa
    Efecto efecto_gata = {-10, -10, 35, 40, "Objeto"};
    insert_map(mapa_acciones, "Gata a domicilio", &efecto_gata);

    // Retornamos mapa con sus pares acción-efecto inicializadas
    return mapa_acciones;
}

List inicializar_lista_objetos(List *lista_objetos){
    Item * pescado;
    strcpy(pescado->nombre, "Pescado");
    pescado->restantes = 5;
    list_pushBack(lista_objetos, pescado);

    Item * hamburguesa;
    strcpy(hamburguesa->nombre, "Hamburguesa");
    hamburguesa->restantes = 1;
    list_pushBack(lista_objetos, hamburguesa);

    Item * sushi;
    strcpy(sushi->nombre, "Sushi");
    sushi->restantes = 1;
    list_pushBack(lista_objetos, sushi);

    Item * cajaArena;
    strcpy(cajaArena->nombre, "Caja de Arena");
    cajaArena->restantes = 0;
    list_pushBack(lista_objetos, cajaArena);

    Item * proteina;
    strcpy(proteina->nombre, "Proteina");
    proteina->restantes = 0;
    list_pushBack(lista_objetos, proteina);

    Item * redbull;
    strcpy(redbull->nombre, "Redbull");
    redbull->restantes = 0;
    list_pushBack(lista_objetos, redbull);

    Item * gata;
    strcpy(gata->nombre, "Gata a domicilio");
    gata->restantes = 0;
    list_pushBack(lista_objetos, gata);

    return *lista_objetos;
}


// Definir acciones para los items
bool aplicar_efecto(char * nombre_accion, struct Tamagotchi *mascota, HashMap *mapa_acciones) {
    
    // Buscamos par acción-efecto por nombre en el mapa de acciones
    Pair * par_accion = search_map(mapa_acciones, nombre_accion);
    if (par_accion == NULL) return false; // Indicar que no se pudo aplicar

    // Aplicar variación de estadísticas por el efecto
    printf("\n\n\n\n         FUNCIONO WEONNNNN\n\n\n");
    mascota->comida     +=  par_accion->value->alteracion_comida;
    mascota->descanso   +=  par_accion->value->alteracion_descanso;
    mascota->animo      +=  par_accion->value->alteracion_animo;

    // Confirmar que el efecto pudo aplicarse
    return true;
}