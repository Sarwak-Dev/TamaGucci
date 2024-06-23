#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "save.h"
#include "../TDAs/list.h"
#include "../structs/structs.h"

// Función para escribir los elementos de un alista en un archivo separados por comas
void guardar_lista_en_archivo(FILE* file, List* lista, const char* tipo) {

    // Se recorre cada nodo e la lista
    for (Node* node = lista->head; node != NULL; node = node->next) {

        // Si la lista es de tiempo, se escribe en el formato indicado
        if (strcmp(tipo, "time_t") == 0) {
            fprintf(file, "%ld", *(time_t*)node->data);

        // Si la lista es de cadenas, se escribe en el formato indicado
        } else if (strcmp(tipo, "string") == 0) {
            fprintf(file, "%s", (char*)node->data);
        }

        // Si existen más elementos, se imprime una coma
        if (node->next != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "\n"); // Se imprime un salto de línea acabando la lista
}

// Función que guarda el estado actual del juego en un archivo
void guardar_estado(Juego* juego, const char* filename) {

    // Se abre archivo con el nombre indicado
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo para guardar");
        return;
    }

    // Guardar las estadísticas del Tamagotchi y sus estados
    fprintf(file, "%.2f %.2f %.2f %d %d\n",
            juego->mascota.comida,
            juego->mascota.descanso,
            juego->mascota.animo,
            juego->mascota.dormido,
            juego->mascota.vivo);

    // Guardar el dinero del juego
    fprintf(file, "%d\n", juego->dinero);

    // Guardar los ítems en la mochila
    guardar_lista_en_archivo(file, &juego->mochila, "string");

    // Guardar la última actualización
    fprintf(file, "%ld\n", juego->ultima_actualizacion);

    // Guardar la última palmadita
    fprintf(file, "%ld\n", juego->ultima_palmadita);

    // Guardar las horas de las últimas caricias
    guardar_lista_en_archivo(file, &juego->caricias_ultima_hora, "time_t");

    fclose(file); // Cerramos el archivo
}

// Función para leer la lista de archivos
void leer_lista_de_archivo(FILE* file, List* lista, const char* tipo) {

    // Se crea cadena para línea a leer
    char line[1024];

    // Se lee línea del archivo y se almacena en cadena
    if (fgets(line, sizeof(line), file)) {

        // Se inicializa token separado por la coma
        char* token = strtok(line, ", ");

        // Mientras el toquen no sea nulo
        while (token != NULL) {

            // Si la lista es de tiempo, se inicializa en el formato indicado
            if (strcmp(tipo, "time_t") == 0) {
                // Se agrega elemento a la lista
                time_t* time = (time_t*)malloc(sizeof(time_t));
                sscanf(token, "%ld", time);
                list_pushBack(lista, time);
            
            // Si la lista es de cadenas, se inicializa en el formato indicado
            } else if (strcmp(tipo, "string") == 0) {
                // Se agrega elemento a la lista
                char* item = strdup(token);
                list_pushBack(lista, item);
            }
            // Se toma siguiente parte de la línea hasta la coma
            token = strtok(NULL, ", ");
        }
    }
}

// Función para cargar el estado desde un archivo para actualizar estadísticas
void cargar_estado(Juego* juego, const char* filename) {

    // Se abre archivo con el nombre indicado
    FILE* file = fopen(filename, "r");

    // De no existir el archivo de guardado, se crea un nuevo gato
    if (file == NULL) {
        // Estado inicial de la mascota
        juego->mascota.comida = 100.0f;
        juego->mascota.descanso = 100.0f;
        juego->mascota.animo = 100.0f;
        juego->mascota.dormido = false;
        juego->mascota.vivo = true;
        juego->dinero = 0;
        juego->ultima_actualizacion = time(NULL);
        juego->ultima_palmadita = time(NULL);

        // Inicializamos las listas vacías
        juego->mochila = *list_create();
        juego->caricias_ultima_hora = *list_create();
        return;
    }

    // Leer las estadísticas del Tamagotchi y sus estados
    fscanf(file, "%f %f %f %d %d\n",
           &juego->mascota.comida,
           &juego->mascota.descanso,
           &juego->mascota.animo,
           (int*)&juego->mascota.dormido,
           (int*)&juego->mascota.vivo);

    // Leer el dinero del juego
    fscanf(file, "%d\n", &juego->dinero);

    // Leer los ítems de la mochila
    leer_lista_de_archivo(file, &juego->mochila, "string");

    // Leer la última actualización
    fscanf(file, "%ld\n", &juego->ultima_actualizacion);

    // Leer la última palmadita
    fscanf(file, "%ld\n", &juego->ultima_palmadita);

    // Leer las horas de las últimas caricias
    leer_lista_de_archivo(file, &juego->caricias_ultima_hora, "time_t");

    fclose(file); // Se cierra el archivo
}