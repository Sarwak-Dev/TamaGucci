#include <unistd.h>

// Librerias creadas
#include "functions/TDAs/list.h"
#include "functions/structs/structs.h"
#include "functions/TDAs/hashmap.h"
#include "functions/effect/effect.h"


void menuPrincipal(HashMap mapa_principal);// mapa_principal == mapa acciones. Revisar functions.effect para mas informacion.
void menuInferior();
void menuInventario();
void menuAcciones();
void menuIluminacion();
void menuTienda();
void esperarInput();
void limpiarPantalla();
void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota, HashMap mapa_principal);

void setConsoleColor(const char* color) {
    char command[10];
    snprintf(command, sizeof(command), "color %s", color);
    system(command);
}

int main() {
    //Comandos de inicio de la consola
    printf("\033[0;97;30m");
    setConsoleColor("F0");
    printf("\033[H\033[J");
    system("chcp 65001");

    //Declara la variable mapa_principal con tipo HashMap
    HashMap *mapa_principal = create_map(20);
    inicializar_mapa_acciones(*mapa_principal);

    int opcion;

    while (true) {
        
        limpiarPantalla();
        menuPrincipal(*mapa_principal);
        menuInferior();
        printf("\n  Selecciona una opcion: \n");
        
        scanf("%d", &opcion);
        while (getchar() != '\n');

            switch(opcion) {
                case 1:
                    //Acciones
                    limpiarPantalla();
                    menuAcciones();
                    printf("\n  Selecciona una opcion: \n");

                    scanf("%d", &opcion);
                    while (getchar() != '\n');

                    switch(opcion) {
                        case 1:
                            //Jugar
                            limpiarPantalla();
                            printf("    Has ganado el piedra-papel o tijeras\n");
                            esperarInput();
                            break;
                        case 2:
                            //Acariciar
                            limpiarPantalla();
                            printf("    Has acariciado a tu mascota\n");
                            esperarInput();
                            break;
                        case 3:
                            //Palmaditas
                            limpiarPantalla();
                            printf("    Le has dado palmaditas a tu mascota\n");
                            esperarInput();
                            break;
                        case 4:
                            limpiarPantalla();
                            menuIluminacion();

                            scanf("%d", &opcion);
                            while (getchar() != '\n');

                            switch(opcion) {
                                case 1:
                                    //Oscuro
                                    printf("\033[0;40;37m");
                                    setConsoleColor("0F");
                                    break;
                                case 2:
                                    //Claro
                                    printf("\033[0;97;30m");
                                    setConsoleColor("F0");
                                    break;
                                default:
                                    // Opción no válida
                                    printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
                        }
                            break;
                        case 5:
                            //Salir
                            break;
                        default:
                            // Opción no válida
                            printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
                        }
                    break;
                case 2:
                    //Inventario
                    limpiarPantalla();
                    menuInventario();
                    printf("\n  Selecciona una opcion: \n");
                    scanf("%d", &opcion);
                    while (getchar() != '\n');

                    switch(opcion) {
                        case 1:
                            //Manzana
                            break;
                        case 2:
                            //Agua
                            break;
                        case 3:
                            //Super8
                            break;
                            
                        case 4:
                            //Coca-Cola
                            break;
                        case 5:
                            //Salir
                            break;
                        default:
                            // Opción no válida
                            printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
                        }
                    break;
                case 3:
                    //Tienda
                    limpiarPantalla();
                    menuTienda();

                    printf("\n  Selecciona una opcion: \n");
                    scanf("%d", &opcion);
                    while (getchar() != '\n');

                    switch(opcion) {
                        case 1:
                            //Manzana
                            limpiarPantalla();
                            printf("Has comprado una Manzana");
                            esperarInput();
                            break;
                        case 2:
                            //Agua
                            limpiarPantalla();
                            printf("Has comprado un Agua");
                            esperarInput();
                            break;
                        case 3:
                            //Super8
                            limpiarPantalla();
                            printf("Has comprado un Super 8");
                            esperarInput();
                            break;
                            
                        case 4:
                            //Coca-Cola
                            limpiarPantalla();
                            printf("Has comprado una Coca-Cola");
                            esperarInput();
                            break;
                        case 5:
                            //Salir
                            break;
                                default:
                                    // Opción no válida
                                    printf("\n  Opcion no valida. Por favor, selecciona una opcion valida.\n");
                        }
                        
                    break;
                case 4:
                    // Salir
                    printf("\nEmpezando a dormir en ");
                    for (int i = 3; i > 0; i--) {
                        printf("%d ", i);
                        fflush(stdout); // Limpiar el buffer de salida para asegurarse de que se imprima de inmediato
                        sleep(1); // Esperar un segundo
                    }
                    printf("\n");
                    exit(0);
                    break;
                default:
                    // Opción no válida
                    printf("\nOpcion no valida. Por favor, selecciona una opcion valida.\n");
            }
    }

    return 0;
}

void menuPrincipal(HashMap mapa_principal) {
    printf("\n  Estado actual del Tamagotchi:\n\n");

    printf("    Comida: ");
    printf("███████");

    printf("    Descanso: ");
    printf("███████████");

    printf("    Animo: ");
    printf("████\n\n\n");

    //char * clave_buscar = "Jugar"; // Por ejemplo, buscar el efecto de la acción "Jugar"

// Buscar el par clave-valor en el mapa
    //Pair * par = search_map(&mapa_principal, clave_buscar);
    //if (par != NULL) {
     //Acceder al valor (que es un puntero a Efecto)
    //Efecto * efecto = par->value;
    
     //Acceder al campo alteracion_animo
    //int alteracion_animo = efecto->alteracion_animo;
    
     //Imprimir el valor de alteracion_animo
    //printf("Alteracion de animo para %s: %d\n", clave_buscar, alteracion_animo);
    //}   else {
    //printf("No se encontró la acción %s en el mapa.\n", clave_buscar);
    //}

    printf("      ██    ██\n");
    printf("     █  ████  █\n");
    printf("     █        █\n");
    printf("    █          █\n");
    printf("    █          █\n");
    printf("    █  █    █  █\n");
    printf("    █   ▄  ▄   █\n");
    printf("     █   ▀▀   █\n");
    printf("      ████████\n");
    printf("     █ █    █ █\n");
    printf("     ██      ██\n");
    printf("      ████████ \n");
    printf("       ██  ██  \n\n");
}

void menuInferior() {
    printf("\n  ==================\n\n");
    printf("    1) Acciones\n");
    printf("    2) Abrir Inventario\n");
    printf("    3) Abrir Tienda\n");
    printf("    4) Dormir\n");
}

void menuInventario() {
    printf("    ==================\n");
    printf("        INVENTARIO:\n");
    printf("    ==================\n\n");
    printf("    1) Manzana x6\n");
    printf("    2) Agua x3\n");
    printf("    3) Super 8 x8\n");
    printf("    4) Coca-Cola x8\n");
    printf("    5) Salir\n");
}

void menuAcciones() {
    printf("    1) Jugar\n");
    printf("    2) Acariciar\n");
    printf("    3) Palmaditas\n");
    printf("    4) Iluminacion\n");
    printf("    5) Salir\n");
}

void menuIluminacion() {
    printf("    1) Oscuro\n");
    printf("    2) Claro\n");
}

void menuTienda() {
    printf("    ==================\n");
    printf("          Tienda:\n");
    printf("    ==================\n\n");
    printf("    1) Comprar Manzana | $50\n");
    printf("    2) comprar Agua | $50\n");
    printf("    3) Comprar Super 8 | $50\n");
    printf("    4) Comprar Coca-Cola | $50\n");
    printf("    5) Salir\n");
}

void esperarInput() {
    printf("\n  Presiona Enter para continuar...");
    while (getchar() != '\n'); // Esperar la entrada del usuario
}

void limpiarPantalla() { system("cls"); }


void printItem(char *item, int restantes, int comida, int descanso, int animo, struct Tamagotchi mascota, HashMap mapa_principal) {
    limpiarPantalla();
    printf("    Has comido una ");
    for (int i = 0; item[i] != '\0'; i++) {
        printf("%c", item[i]); // Imprime cada carácter de la cadena
    }
    printf(" (%d restantes)\n", restantes);
    printf("    %d Comida\n", comida);
    printf("    %d Descanso\n", descanso);
    printf("    %d Animo\n", animo);
    esperarInput();
    limpiarPantalla();
    menuPrincipal(mapa_principal);
    menuInferior();
}
//ME GUSTA EL PENEEEEEEEe