#ifndef EFFECT_H
#define EFFECT_H

// Estructura para indicar cómo un efecto alterará las estadísticas
typedef struct Efecto {
    int alteracion_comida;
    int alteracion_descanso;
    int alteracion_animo;
} Efecto;

// Incializa mapa de acciones y efectos en estadísticas
HashMap inicializar_mapa_acciones(HashMap mapa_acciones);

// Definir acciones para los items
bool aplicar_efecto(char * accion, struct Tamagotchi *mascota, HashMap *mapa_acciones);

#endif