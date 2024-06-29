#include "save.h"

// Función para escribir los elementos de una lista en un archivo separados por comas
void guardar_lista_en_archivo(FILE* file, List* lista, const char* tipo) {
    printf("Comenzamos el guardado\n");
    
    // Se maneja excepción si lista está vacía
    if (lista->head == NULL || lista->tail == NULL) {
        fprintf(file, ";\n");
        printf("Se imprime lista vacía en save.txt\n");
        return;
    }
    printf("Se imprimira la lista completa en save.txt\n");
    // Se recorre cada nodo de la lista
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
    fprintf(file, ";\n"); // Se imprime un punto y coma acabando la lista
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
    printf("Gato guardado con éxito\n");

    // Guardar el dinero del juego
    fprintf(file, "%d\n", juego->dinero);

    // Guardar los ítems en la mochila
    guardar_lista_en_archivo(file, juego->mochila, "string");

    // Guardar la hora de la última actualización
    fprintf(file, "%ld\n", juego->ultima_actualizacion);

    // Guardar la hora de la última palmadita
    fprintf(file, "%ld\n", juego->ultima_palmadita);

    // Guardar la hora del último pago
    fprintf(file, "%ld\n", juego->ultimo_pago);

    // Guardar las horas de las últimas caricias
    guardar_lista_en_archivo(file, juego->caricias_ultima_hora, "time_t");

    fclose(file); // Cerramos el archivo
}

// Función para leer la lista de archivos
void leer_lista_de_archivo(FILE* file, List* lista, const char* tipo) {
    char line[1024];
    printf("Intentando leer línea\n");

    // Se lee línea del archivo y se almacena en cadena
    if (fgets(line, sizeof(line), file)) {
        // Verificar si la línea solo contiene un punto y coma
        if (strcmp(line, ";\n") == 0 || strcmp(line, ";\r\n") == 0) {
            printf("Línea vacía <solo punto y coma>\n");
            return;
        }

        printf("Línea leída con éxito\n");
        char* token = strtok(line, ",;");
        printf("Tokens separados\n");

        // Mientras el token no sea nulo
        while (token != NULL) {
            if (strcmp(tipo, "time_t") == 0) {
                printf("Procesando tipo tiempo\n");
                time_t* time = (time_t*)malloc(sizeof(time_t));
                if (time == NULL) {
                    perror("Error de memoria al asignar time_t");
                    return;
                }
                sscanf(token, "%ld", time);
                list_pushBack(lista, time);
            } else if (strcmp(tipo, "string") == 0) {
                printf("Procesando tipo string\n");
                char* item = strdup(token);
                if (item == NULL) {
                    perror("Error de memoria al duplicar cadena");
                    return;
                }
                list_pushBack(lista, item);
            }
            token = strtok(NULL, ",;");
            printf("Siguiente token procesado\n");
        }
    }
}

// Función para cargar el estado desde un archivo para actualizar estadísticas
void cargar_estado(Juego* juego, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // El archivo no existe, inicializamos el estado inicial
        printf("Inicializando variables de Juego\n"); // Debug print

        juego->mascota.comida = 100.0f;
        juego->mascota.descanso = 100.0f;
        juego->mascota.animo = 100.0f;
        juego->mascota.dormido = false;
        juego->mascota.vivo = true;
        juego->dinero = 0;
        juego->ultima_actualizacion = time(NULL);
        juego->ultima_palmadita = time(NULL);
        juego->ultimo_pago = time(NULL);
        // Inicializamos las listas vacías
        juego->mochila = list_create();
        juego->caricias_ultima_hora = list_create();
        return;
    }

    // Leer las estadísticas del Tamagotchi y sus estados
    printf("Leyendo datos del save.txt\n"); // Debug print

    /*fscanf(file, "%f %f %f %d %d\n",
           &juego->mascota.comida,
           &juego->mascota.descanso,
           &juego->mascota.animo,
           (int*)&juego->mascota.dormido,
           (int*)&juego->mascota.vivo);*/

    fscanf(file, "%f ", &juego->mascota.comida);
    printf("Se ha leído comida con éxito\n");
    fscanf(file, "%f ", &juego->mascota.descanso);
    printf("Se ha leído descanso con éxito\n");
    fscanf(file, "%f", &juego->mascota.animo);
    printf("Se ha leído animo con éxito\n");
    fscanf(file, "%d " ,(int*)&juego->mascota.dormido);
    printf("Se ha leído dormido con éxito\n");
    fscanf(file, "%d\n" ,(int*)&juego->mascota.vivo);
    printf("Se ha leído vivo con éxito\n");


    // Leer el dinero del juego
    if (fscanf(file, "%d\n", &juego->dinero) != 1) {
        perror("Error al leer el dinero del juego");
        fclose(file);
        return;
    }
    printf("Se ha leído dinero con éxito\n");

    // Leer los ítems de la mochila
    leer_lista_de_archivo(file, juego->mochila, "string");

    // Leer la última actualización
    if (fscanf(file, "%ld\n", &juego->ultima_actualizacion) != 1) {
        perror("Error al leer la última actualización");
        fclose(file);
        return;
    }
    printf("Se ha leído ultima actualizacion con éxito\n");

    // Leer la última palmadita
    if (fscanf(file, "%ld\n", &juego->ultima_palmadita) != 1) {
        perror("Error al leer la última palmadita");
        fclose(file);
        return;
    }
    printf("Se ha leído ultima palmadita con éxito\n");

    // Leer el último pago
    if (fscanf(file, "%ld\n", &juego->ultimo_pago) != 1) {
        perror("Error al leer el último pago");
        fclose(file);
        return;
    }
    printf("Se ha leído ultimo pago con éxito\n");

    // Leer las horas de las últimas caricias
    leer_lista_de_archivo(file, juego->caricias_ultima_hora, "time_t");

    fclose(file);
}


// Función para actualizar estadísticas del Tamagotchi en función del tiempo
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