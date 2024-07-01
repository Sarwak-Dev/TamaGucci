#include "effect.h"
#include <unistd.h>

// Comida Descanso Animo Precio Tipo

// Inicializa mapa de acciones y efectos en estadísticas
HashMap * inicializar_mapa_acciones(HashMap * mapa_acciones) {

    // Inicializar acción jugar y añadirla al mapa
    Efecto *efecto_jugar = malloc(sizeof(Efecto));
    efecto_jugar->alteracion_comida = 0;
    efecto_jugar->alteracion_descanso = -10;
    efecto_jugar->alteracion_animo = 15;
    insert_map(mapa_acciones, "Jugar", efecto_jugar);

    // Inicializar acción acariciar y añadirla al mapa
    Efecto *efecto_acariciar = malloc(sizeof(Efecto));
    efecto_acariciar->alteracion_comida = 0;
    efecto_acariciar->alteracion_descanso = 0;
    efecto_acariciar->alteracion_animo = 10;
    insert_map(mapa_acciones, "Acariciar", efecto_acariciar);

    // Inicializar acción palmaditas efectivas y añadirla al mapa
    Efecto *efecto_palmaditas = malloc(sizeof(Efecto));
    efecto_palmaditas->alteracion_comida = 0;
    efecto_palmaditas->alteracion_descanso = 10;
    efecto_palmaditas->alteracion_animo = -5;
    insert_map(mapa_acciones, "Palmaditas", efecto_palmaditas);

    // Inicializar acción palmaditas innecesarias y añadirla al mapa
    Efecto *efecto_palmaditas_innecesarias = malloc(sizeof(Efecto));
    efecto_palmaditas_innecesarias->alteracion_comida = 0;
    efecto_palmaditas_innecesarias->alteracion_descanso = 0;
    efecto_palmaditas_innecesarias->alteracion_animo = -8;
    insert_map(mapa_acciones, "Palmaditas Innecesarias", efecto_palmaditas_innecesarias);

    // Inicializar acción comer pescado y añadirla al mapa
    Efecto *efecto_pescado = malloc(sizeof(Efecto));
    efecto_pescado->alteracion_comida = 10;
    efecto_pescado->alteracion_descanso = -5;
    efecto_pescado->alteracion_animo = 5;
    insert_map(mapa_acciones, "Pescado", efecto_pescado);

    // Inicializar acción comer hamburguesa y añadirla al mapa
    Efecto *efecto_hamburguesa = malloc(sizeof(Efecto));
    efecto_hamburguesa->alteracion_comida = 15;
    efecto_hamburguesa->alteracion_descanso = -10;
    efecto_hamburguesa->alteracion_animo = 10;
    insert_map(mapa_acciones, "Hamburguesa", efecto_hamburguesa);

    // Inicializar acción comer sushi y añadirla al mapa
    Efecto *efecto_sushi = malloc(sizeof(Efecto));
    efecto_sushi->alteracion_comida = 20;
    efecto_sushi->alteracion_descanso = 0;
    efecto_sushi->alteracion_animo = 10;
    insert_map(mapa_acciones, "Sushi", efecto_sushi);

    // Inicializar acción cajaArena y añadirla al mapa
    Efecto *efecto_cajaArena = malloc(sizeof(Efecto));
    efecto_cajaArena->alteracion_comida = -10;
    efecto_cajaArena->alteracion_descanso = -15;
    efecto_cajaArena->alteracion_animo = -25;
    insert_map(mapa_acciones, "Caja de Arena", efecto_cajaArena);

    // Inicializar acción proteina y añadirla al mapa
    Efecto *efecto_proteina = malloc(sizeof(Efecto));
    efecto_proteina->alteracion_comida = 35;
    efecto_proteina->alteracion_descanso = -10;
    efecto_proteina->alteracion_animo = -10;
    insert_map(mapa_acciones, "Proteina", efecto_proteina);

    // Inicializar acción redbull y añadirla al mapa
    Efecto *efecto_redbull = malloc(sizeof(Efecto));
    efecto_redbull->alteracion_comida = -10;
    efecto_redbull->alteracion_descanso = 35;
    efecto_redbull->alteracion_animo = -10;
    insert_map(mapa_acciones, "Redbull", efecto_redbull);

    // Inicializar acción gata y añadirla al mapa
    Efecto *efecto_gata = malloc(sizeof(Efecto));
    efecto_gata->alteracion_comida = -10;
    efecto_gata->alteracion_descanso = -10;
    efecto_gata->alteracion_animo = 35;
    insert_map(mapa_acciones, "Gata a domicilio", efecto_gata);

    // Retornamos mapa con sus pares acción-efecto inicializadas
    return mapa_acciones;
}

// Función que se encarga de inicializar 
void inicializar_arreglo_objetos(Item arreglo_objetos[7]) {
    // Inicializar el primer objeto
    strcpy(arreglo_objetos[0].nombre, "Pescado");
    arreglo_objetos[0].restantes = 5;
    arreglo_objetos[0].coste = 4;

    // Inicializar el segundo objeto
    strcpy(arreglo_objetos[1].nombre, "Hamburguesa");
    arreglo_objetos[1].restantes = 1;
    arreglo_objetos[1].coste = 2;

    // Inicializar el tercer objeto
    strcpy(arreglo_objetos[2].nombre, "Sushi");
    arreglo_objetos[2].restantes = 1;
    arreglo_objetos[2].coste = 3;

    // Inicializar el cuarto objeto
    strcpy(arreglo_objetos[3].nombre, "Caja de Arena");
    arreglo_objetos[3].restantes = 0;
    arreglo_objetos[3].coste = 7;

    // Inicializar el quinto objeto
    strcpy(arreglo_objetos[4].nombre, "Proteina");
    arreglo_objetos[4].restantes = 0;
    arreglo_objetos[4].coste = 8;

    // Inicializar el sexto objeto
    strcpy(arreglo_objetos[5].nombre, "Redbull");
    arreglo_objetos[5].restantes = 0;
    arreglo_objetos[5].coste = 8;

    // Inicializar el séptimo objeto
    strcpy(arreglo_objetos[6].nombre, "Gata a domicilio");
    arreglo_objetos[6].restantes = 0;
    arreglo_objetos[6].coste = 8;
}

// Definir acciones para los items
bool aplicar_efecto(char * nombre_accion, struct Tamagotchi *mascota, HashMap *mapa_acciones) {
    
    // Buscamos par acción-efecto por nombre en el mapa de acciones
    Pair * par_accion = search_map(mapa_acciones, nombre_accion);
    if (par_accion == NULL) return false; // Indicar que no se pudo aplicar

    // Aplicar variación de estadísticas por el efecto
    Efecto *efecto = (Efecto *) par_accion->value;
    mascota->comida     +=  efecto->alteracion_comida;
    mascota->descanso   +=  efecto->alteracion_descanso;
    mascota->animo      +=  efecto->alteracion_animo;

    printf("\n   %d\n", efecto->alteracion_comida);
    printf("\n   %d\n", efecto->alteracion_descanso);
    printf("\n   %d\n", efecto->alteracion_animo);
    sleep(2);

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
