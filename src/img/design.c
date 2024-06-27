#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "design.h"
#include "../functions/structs/structs.h"

// Función que imprime la hora actual en formato H:M:S
void imprimir_hora(time_t hora) {
    
    // Convertir la hora a tiempo local
    struct tm* tiempo_local = localtime(&hora);
    
    // Verificar si se pudo convertir la hora
    if (tiempo_local == NULL) {
        perror("Error al convertir la hora a tiempo local");
        return;
    }

    // Formatear la hora en formato H:M:S en una cadena de caracteres
    char hora_formateada[9]; // HH:MM:SS + '\0'
    if (strftime(hora_formateada, sizeof(hora_formateada), "%H:%M:%S", tiempo_local) == 0) {
        perror("Error al formatear la hora local");
        return;
    }

    // Mostrar la hora formateada
    printf("Hora local: %s\n", hora_formateada);
}

// Muestra superior de la cabeza normal
void cabeza_normalSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█          █\n");
  printf("█  █    █  █\n");
  return;
}

// Muestra superior de la cabeza cansada
void cabeza_cansadaSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█ ▄██  ██▄ █\n");
  printf("█  █    █  █\n");
  return;
}

// Muestra superior de la cabeza agotada
void cabeza_agotadaSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█  ▄▄  ▄▄  █\n");
  printf("█ ▀▀    ▀▀ █\n");
  return;
}

// Muestra inferior de la cabeza normal
void cabeza_normalInferior(){
  printf("█   ▄  ▄   █\n");
  printf(" █   ▀▀   █\n");
  printf("  ████████\n");
  return;
}

// Muestra inferior de la cabeza seria
void cabeza_seriaInferior(){
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");
  return;
}

// Muestra inferior de la cabeza triste
void cabeza_tristeInferior(){
  printf("█    ▄▄    █\n");
  printf(" █  ▀  ▀  █\n");
  printf("  ████████\n");
  return;
}

// Muestra el cuerpo normal
void cuerpo_normal(){
  printf(" █ █    █ █\n");
  printf(" ██      ██\n");
  printf("  ████████ \n");
  printf("   ██  ██  \n");
}

// Muestra el cuerpo hambriento
void cuerpo_hambre(){
  printf(" █ ██  ██ █\n");
  printf(" ██ █  █ ██\n");
  printf("    ████   \n");
  printf("    █  █   \n");
  return;
}

// Muestra el cuerpo desnutrido
void cuerpo_desnutrido(){
  printf(" █  █  █  █\n");
  printf(" █   ██   █\n");
  printf("    ████    \n");
  printf("    █  █   \n");  
  return;
}





void muertePor_tristeza(){
  printf("     ██      \n");
  printf("     ██      \n");
  printf("  ██ ██ ██   \n");
  printf(" █  ████  █  \n");
  printf(" █        █  \n");
  printf("█          █ \n");
  printf("█ ▀▄▀  ▀▄▀ █ \n");
  printf("█ ▀ ▀  ▀ ▀ █ \n");
  printf("█    ▄▄    █ \n");
  printf(" █  ▀  ▀  █  \n");
  printf("  ████████   \n");
  printf(" █ █    █ █  \n");
  printf(" ██      ██  \n");
  printf("  ████████   \n");
  printf("   ██  ██    \n");
  printf("             \n");
  printf("             \n");
  printf("             \n");
  printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");  
  return;
}

void muertePor_agotamiento(){
  printf("    ▄                \n");
  printf("       ▄▀            \n"),
  printf("      ▄       ▀      \n");
  printf("    ▄▀ ▀▄    ▄       \n");
  printf("  ▄▀     ▀▄▄▀ ▀▄     \n");
  printf(" █     ▄▄▄▄     █    \n");
  printf("█   ▄▀▀████▀▀▄   ▀▄  \n");
  printf("▀▄  █▄▄████▄▄█    █  \n");
  printf(" █   ██▀██▀██    ▄▀  \n");
  printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
  printf("     ▄▄▄▄▄▄▄▄        \n");
  printf("    █ █    █ █       \n");
  printf("    ██      ██       \n");
  printf("     ████████        \n");
  printf("      ██  ██         \n");
  return;
}

void muertePor_hambre(){
  printf("              \n");
  printf("              \n");
  printf("   ██   ██    \n");
  printf("  █  ███  █   \n");
  printf("  █       █   \n");
  printf(" █         █  \n");
  printf("█ ▀▄▀   ▀▄▀ █ \n");
  printf("█ ▀ ▀   ▀ ▀ █ \n");
  printf(" █  ▄▀▀▀▄  █  \n");
  printf("  █ ▀▄▄▄▀ █   \n");
  printf("   ███████    \n");
  printf("  █   █   █   \n");
  printf("  █   █   █   \n");
  printf("     ███      \n");
  printf("    █   █     \n");
return;
}



void cariño(){
  for(int i=0; i<3; i++){
    printf("                                 \n");
    printf("              ▄▄▄                 \n");
    printf("         ▄▄▄▀▀   ▀▄                \n");
    printf("  ▄▄▄▀▀▀▀         █                \n");
    printf("  ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
    printf(" █▀▀▄▄▄▄▀▀█▄▀                       \n");
    printf(" █        █                       \n");
    printf("█          █                      \n");
    printf("█          █                      \n");
    printf("█▀▄▄▀  ▀▄▄▀█                      \n");
    printf("█   ▄  ▄   █\n");
    printf(" █   ▀▀   █\n");
    printf("  ████████\n");


    sleep(1);
    limpiarPantalla();


    printf("                                  \n");
    printf("               ▄▄▄                 \n");
    printf("          ▄▄▄▀▀   ▀▄                \n");
    printf("   ▄▄▄▀▀▀▀         █                \n");
    printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
    printf(" █▀▀▄▄▄▄▀▀█▀▄▀                       \n");
    printf(" █        █                       \n");
    printf("█          █                      \n");
    printf("█          █                      \n");
    printf("█▀▄▄▀  ▀▄▄▀█                      \n");
    printf("█   ▄  ▄   █\n");
    printf(" █   ▀▀   █\n");
    printf("  ████████\n");

    sleep(1);
    limpiarPantalla();
  }

  printf("                                 \n");
  printf("              ▄▄▄                 \n");
  printf("         ▄▄▄▀▀   ▀▄                \n");
  printf("  ▄▄▄▀▀▀▀         █                \n");
  printf("  ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf(" █▀▀▄▄▄▄▀▀█▄▀                    \n");
  printf(" █        █                   \n");
  printf("█          █                       \n");
  printf("█          █ ▄                      \n");
  printf("█▀▄▄▀  ▀▄▄▀█                      \n");
  printf("█   ▄  ▄   █\n");
  printf(" █   ▀▀   █\n");
  printf("  ████████\n");

  usleep(300000);
  limpiarPantalla();
  
  printf("                                 \n");
  printf("              ▄▄▄                 \n");
  printf("         ▄▄▄▀▀   ▀▄                \n");
  printf("  ▄▄▄▀▀▀▀         █                \n");
  printf("  ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf(" █▀▀▄▄▄▄▀▀█▄▀                    \n");
  printf(" █        █                   \n");
  printf("█          █                       \n");
  printf("█          █ ▄▀                      \n");
  printf("█▀▄▄▀  ▀▄▄▀█                      \n");
  printf("█   ▄  ▄   █\n");
  printf(" █   ▀▀   █\n");
  printf("  ████████\n");

  usleep(300000);
  limpiarPantalla();
  
  printf("                                 \n");
  printf("              ▄▄▄                 \n");
  printf("         ▄▄▄▀▀   ▀▄                \n");
  printf("  ▄▄▄▀▀▀▀         █                \n");
  printf("  ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf(" █▀▀▄▄▄▄▀▀█▄▀    ▄ ▄                 \n");
  printf(" █        █     █ ▀ █              \n");
  printf("█          █     ▀▄▀                  \n");
  printf("█          █ ▄▀                      \n");
  printf("█▀▄▄▀  ▀▄▄▀█                      \n");
  printf("█   ▄  ▄   █\n");
  printf(" █   ▀▀   █\n");
  printf("  ████████\n");
  
  sleep(1);
  limpiarPantalla();
  
  return;
}

void palmada(){
  for(int i=0; i<7; i++){

    printf("               ▄▄▄                 \n");
    printf("          ▄▄▄▀▀   ▀▄                \n");
    printf("   ▄▄▄▀▀▀▀         █                \n");
    printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
    printf("           ▀▄▀                       \n");
    printf("                                  \n");
    printf("                                  \n");
    printf("  ██    ██\n");
    printf(" █  ████  █\n");
    printf(" █        █\n");
    printf("█          █\n");
    printf("█ ███  ███ █\n");
    printf("█  █    █  █\n");
    printf("█   ▄▄▄▄   █\n");
    printf(" █        █\n");
    printf("  ████████\n");


    usleep(300000);
    limpiarPantalla();

    printf("                                  \n");
    printf("                                  \n");
    printf("                                  \n");
    printf("                                  \n");
    printf("               ▄▄▄                 \n");
    printf("          ▄▄▄▀▀   ▀▄                \n");
    printf("   ▄▄▄▀▀▀▀         █                \n");
    printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
    printf(" █▀▀▄▄▄▄▀▀█▀▄▀                       \n");
    printf(" █        █                       \n");
    printf("█          █                      \n");
    printf("█ ███  ███ █\n");
    printf("█  █    █  █\n");
    printf("█   ▄▄▄▄   █\n");
    printf(" █        █\n");
    printf("  ████████\n");

    usleep(300000);
    limpiarPantalla();
  }
  
  printf("               ▄▄▄                 \n");
  printf("          ▄▄▄▀▀   ▀▄                \n");
  printf("   ▄▄▄▀▀▀▀         █                \n");
  printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("           ▀▄▀                       \n");
  printf("                                  \n");
  printf("                                  \n");
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█ ███  ███ █\n");
  printf("█  █    █  █\n");
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");
  
  usleep(700000);
  limpiarPantalla();
  
  printf("               ▄▄▄                 \n");
  printf("          ▄▄▄▀▀   ▀▄                \n");
  printf("   ▄▄▄▀▀▀▀         █                \n");
  printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("           ▀▄▀                       \n");
  printf("                                  \n");
  printf("                                  \n");
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █  █\n");
  printf("█          █\n");
  printf("█ ███  ███ █\n");
  printf("█  █    █  █ \n");
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");


  usleep(1000000);
  limpiarPantalla();
  
  printf("               ▄▄▄                 \n");
  printf("          ▄▄▄▀▀   ▀▄                \n");
  printf("   ▄▄▄▀▀▀▀         █                \n");
  printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("           ▀▄▀                       \n");
  printf("                                  \n");
  printf("                                  \n");
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █  █ █\n");
  printf("█          █\n");
  printf("█ ███  ███ █\n");
  printf("█  █    █  █ \n");
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");

  usleep(1000000);
  limpiarPantalla();
  
  printf("               ▄▄▄                 \n");
  printf("          ▄▄▄▀▀   ▀▄                \n");
  printf("   ▄▄▄▀▀▀▀         █                \n");
  printf("   ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("           ▀▄▀                       \n");
  printf("                                  \n");
  printf("                                  \n");
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █  █ █ █\n");
  printf("█          █\n");
  printf("█ ███  ███ █\n");
  printf("█  █    █  █ \n");
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");

  sleep(1);
  limpiarPantalla();
}


// Función para mostrar el gato en función del estado de sus estadísticas
void mostrar_mascota(Tamagotchi * mascota){

  // Mostrar zona superior de la cabeza
  if (mascota->descanso < LIMIT_LVL3) cabeza_agotadaSuperior();
  else if (mascota->descanso < LIMIT_LVL2) cabeza_cansadaSuperior();
  else cabeza_normalSuperior();

  // Mostrar zona inferior de la cabeza
  if (mascota->animo < LIMIT_LVL3) cabeza_tristeInferior();
  else if (mascota->animo < LIMIT_LVL2) cabeza_seriaInferior();
  else cabeza_normalInferior();

  // Mostrar cuerpo
  if (mascota->comida < LIMIT_LVL3) cuerpo_desnutrido();
  else if (mascota->comida < LIMIT_LVL2) cuerpo_hambre();
  else cuerpo_normal();
}

