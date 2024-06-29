#include "effect.h"
// Comida Descanso Animo Precio Tipo

// Incializa mapa de acciones y efectos en estadísticas
HashMap * inicializar_mapa_acciones(HashMap * mapa_acciones) {

    // Inicializar acción jugar y añadirla al mapa
    Efecto efecto_jugar = {0, -20, 35, "Interaccion"};
    insert_map(mapa_acciones, "Jugar", &efecto_jugar);

    // Inicializar acción acariciar y añadirla al mapa
    Efecto efecto_acariciar = {0, 0, 15, "Interaccion"};
    insert_map(mapa_acciones, "Acariciar", &efecto_acariciar);

    // Inicializar acción palmaditas y añadirla al mapa
    Efecto efecto_palmaditas = {0, 10, -5, "Interaccion"};
    insert_map(mapa_acciones, "Palmadita", &efecto_palmaditas);

    // Inicializar acción comer pescado y añadirla al mapa
    Efecto efecto_pescado = {20, -5, 10, "Objeto"};
    insert_map(mapa_acciones, "Pescado", &efecto_pescado);

    // Inicializar acción comere hamburguesa y añadirla al mapa
    Efecto efecto_hamburguesa = {20, -10, 15, "Objeto"};
    insert_map(mapa_acciones, "Hamburguesa", &efecto_hamburguesa);

    // Inicializar acción comere sushi y añadirla al mapa
    Efecto efecto_sushi = {30, 0, 20, "Objeto"};
    insert_map(mapa_acciones, "Sushi", &efecto_sushi);

    // Inicializar acción cajaArena y añadirla al mapa
    Efecto efecto_cajaArena = {-10, -20, -30, "Objeto"};
    insert_map(mapa_acciones, "Caja de Arena", &efecto_cajaArena);

    // Inicializar acción proteina y añadirla al mapa
    Efecto efecto_proteina = {35, -10, -10, "Objeto"};
    insert_map(mapa_acciones, "Proteina", &efecto_proteina);

    // Inicializar acción redbull y añadirla al mapa
    Efecto efecto_redbull = {-10, 35, -10, "Objeto"};
    insert_map(mapa_acciones, "Redbull", &efecto_redbull);

    // Inicializar acción gata y añadirla al mapa
    Efecto efecto_gata = {-10, -10, 35, "Objeto"};
    insert_map(mapa_acciones, "Gata a domicilio", &efecto_gata);

    // Retornamos mapa con sus pares acción-efecto inicializadas
    return mapa_acciones;
}

void inicializar_lista_objetos(Item lista_objetos[7]) {
    strcpy(lista_objetos[0].nombre, "Pescado");
    lista_objetos[0].restantes = 5;

    strcpy(lista_objetos[1].nombre, "Hamburguesa");
    lista_objetos[1].restantes = 1;

    strcpy(lista_objetos[2].nombre, "Sushi");
    lista_objetos[2].restantes = 1;

    strcpy(lista_objetos[3].nombre, "Caja de Arena");
    lista_objetos[3].restantes = 0;

    strcpy(lista_objetos[4].nombre, "Proteina");
    lista_objetos[4].restantes = 0;

    strcpy(lista_objetos[5].nombre, "Redbull");
    lista_objetos[5].restantes = 0;

    strcpy(lista_objetos[6].nombre, "Gata a domicilio");
    lista_objetos[6].restantes = 0;
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

    // Nivelar si estadísticas sobrepasan los límites
    if (mascota->comida > 100) mascota->comida = 100;
    if (mascota->comida < 0) mascota->comida = 0;

    if (mascota->descanso > 100) mascota->descanso = 100;
    if (mascota->descanso < 0) mascota->descanso = 0;

    if (mascota->animo > 100) mascota->animo = 100;
    if (mascota->animo < 0) mascota->animo = 0;


    // Confirmar que el efecto pudo aplicarse
    return true;
}