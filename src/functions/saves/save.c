#include "save.h"

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

    // Guardar la hora de la última actualización
    fprintf(file, "%ld\n", juego->ultima_actualizacion);

    // Guardar la hora de la última palmadita
    fprintf(file, "%ld\n", juego->ultima_palmadita);

    // Guardar la hora del último pago
    fprintf(file, "%ld\n", juego->ultimo_pago);

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

    // Se abre archivo con el nombre indicado en modo lectura
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        // El archivo no existe, se puede crear
        printf("El archivo no existe. Creando %s...\n", filename);
        
        // Abrir el archivo en modo escritura para crearlo
        file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Error al crear el archivo %s.\n", filename);
            return;
        }
        
        // Escribir el texto inicial con el número de comida en la mascota
        fprintf(file, "%.2f %.2f %.2f %d %d\n",
            juego->mascota.comida,
            juego->mascota.descanso,
            juego->mascota.animo,
            juego->mascota.dormido,
            juego->mascota.vivo);

        // Cerrar el archivo después de escribir
        fclose(file);
    } else {
        // El archivo ya existe, no hacemos nada
        printf("El archivo %s ya existe. No se crea otro.\n", filename);

        // Cerrar el archivo que se intentó abrir en modo lectura
        fclose(file);
    }
}

// Función para actualizar estadísticas del Tamagotchu en función del tiempo
// Transcurrido desde la última actualización
void actualizar_estado(Juego* juego) {

    time_t ahora = time(NULL); // Definir la hora actual
    // Calcular diferencia en segundos desde últimas actualizaciones y la hora actual
    double segundos_transcurridos = difftime(ahora, juego->ultima_actualizacion);
    double segundos_ultimo_pago = difftime(ahora, juego->ultimo_pago);

    // Calcular las variaciones por segundo en función de los máximos de horas
    float comida_por_segundo = 100.0f / (MAX_HORAS_COMIDA * 3600.0f);
    float descanso_por_segundo = 100.0f / (MAX_HORAS_DESCANSO * 3600.0f);
    float animo_por_segundo = 100.0f / (MAX_HORAS_ANIMO * 3600.0f);

    // Actualizar las estadísticas en función de su variación por segundo
    juego->mascota.comida -= segundos_transcurridos * comida_por_segundo;
    juego->mascota.animo -= segundos_transcurridos * animo_por_segundo;

    if (juego->mascota.dormido) {   // Si está dormido, aumenta descanso
        juego->mascota.descanso += segundos_transcurridos * descanso_por_segundo;
    } else {                        // Si no lo está, disminuye descanso
        juego->mascota.descanso -= segundos_transcurridos * descanso_por_segundo;
    }

    // Dar pagos correspondientes cada 12 horas
    int pagos_realizados = (int)(segundos_ultimo_pago / (12 * 3600));
    juego->dinero += DINERO_12_HORAS * pagos_realizados;

    // Asegurar que las estadísticas no caigan por debajo de 0 o superen 100
    if (juego->mascota.comida < 0.0f) juego->mascota.comida = 0.0f;
    if (juego->mascota.descanso < 0.0f) juego->mascota.descanso = 0.0f;
    if (juego->mascota.descanso > 100.0f) juego->mascota.descanso = 100.0f;
    if (juego->mascota.animo < 0.0f) juego->mascota.animo = 0.0f;

    // Actualizar la última hora de actualización
    juego->ultima_actualizacion = ahora;
    if (pagos_realizados > 0) juego->ultimo_pago = ahora;
}