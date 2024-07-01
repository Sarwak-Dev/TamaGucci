#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>



#include "design.h"
#include "../functions/structs/structs.h"


void eliminar_archivo_guardado(const char *nombreArchivo, const char *rutaDirectorio);



void limpiarPantalla3() { system("cls"); }

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
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █\n");
  printf("  █          █\n");
  printf("  █          █\n");
  printf("  █  █    █  █\n");
  return;
}

// Muestra superior de la cabeza cansada
void cabeza_cansadaSuperior(){
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █\n");
  printf("  █          █\n");
  printf("  █ ▄██  ██▄ █\n");
  printf("  █  █    █  █\n");
  return;
}

// Muestra superior de la cabeza agotada
void cabeza_agotadaSuperior(){
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █\n");
  printf("  █          █\n");
  printf("  █  ▄▄  ▄▄  █\n");
  printf("  █ ▀▀    ▀▀ █\n");
  return;
}

// Muestra inferior de la cabeza normal
void cabeza_normalInferior(){
  printf("  █   ▄  ▄   █\n");
  printf("   █   ▀▀   █\n");
  printf("    ████████\n");
  return;
}

// Muestra inferior de la cabeza seria
void cabeza_seriaInferior(){
  printf("  █   ▄▄▄▄   █\n");
  printf("   █        █\n");
  printf("    ████████\n");
  return;
}

// Muestra inferior de la cabeza triste
void cabeza_tristeInferior(){
  printf("  █    ▄▄    █\n");
  printf("   █  ▀  ▀  █\n");
  printf("    ████████\n");
  return;
}

// Muestra el cuerpo normal
void cuerpo_normal(){
  printf("   █ █    █ █\n");
  printf("   ██      ██\n");
  printf("    ████████ \n");
  printf("     ██  ██  \n");
}

// Muestra el cuerpo hambriento
void cuerpo_hambre(){
  printf("   █ ██  ██ █\n");
  printf("   ██ █  █ ██\n");
  printf("      ████   \n");
  printf("      █  █   \n");
  return;
}

// Muestra el cuerpo desnutrido
void cuerpo_desnutrido(){
  printf("   █  █  █  █\n");
  printf("   █   ██   █\n");
  printf("      ████    \n");
  printf("      █  █   \n");  
  return;
}





void muertePor_tristeza(){
    while(true){
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
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄████ ▄██   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█  ▀▄▀  ▀▄▀█ \n");
        printf("█  ▀ ▀  ▀ ▀█ \n");
        printf("█     ▄▄   █ \n");
        printf(" █   ▀  ▀ █  \n");
        printf("  ████████   \n");
        printf("  █ █    ██  \n");
        printf("  ██     █  \n");
        printf("  ████████   \n");
        printf("    ██ ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█   ▀▄▀  ▀▄█ \n");
        printf("█   ▀ ▀  ▀ █ \n");
        printf("█      ▄▄  █ \n");
        printf(" █    ▀  ▀█  \n");
        printf("  ████████   \n");
        printf("  █  █   █  \n");
        printf("  ███    █  \n");
        printf("  ████████   \n");
        printf("     ████    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█    ▀▄▀  ▀█ \n");
        printf("█    ▀ ▀  ▀█ \n");
        printf("█      ▄▄  █ \n");
        printf(" █    ▀  ▀█  \n");
        printf("  ████████   \n");
        printf("  █ █ █  █  \n");
        printf("  █ ██   █  \n");
        printf("  ████████   \n");
        printf("      ███    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█     ▀▄▀  █ \n");
        printf("█     ▀ ▀  █ \n");
        printf("█       ▄▄ █ \n");
        printf(" █     ▀  █  \n");
        printf("  ████████   \n");
        printf("  █  █ █ █  \n");
        printf("  █  ██  █  \n");
        printf("  ████████   \n");
        printf("       ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█     ▀▄▀  █ \n");
        printf("█     ▀ ▀  █ \n");
        printf("█       ▄▄ █ \n");
        printf(" █     ▀  █  \n");
        printf("  ████████   \n");
        printf("  █   █ ██   \n");
        printf("  █   ██ █   \n");
        printf("  ████████   \n");
        printf("       ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█      ▀▄▀ █ \n");
        printf("█      ▀ ▀ █ \n");
        printf("█        ▄▄█ \n");
        printf(" █      ▀ █  \n");
        printf("  ████████   \n");
        printf("  █    █ █ \n");
        printf("  █    ███   \n");
        printf("  ████████   \n");
        printf("       ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█       ▀▄▀█ \n");
        printf("█       ▀ ▀█ \n");
        printf("█         ▄█ \n");
        printf(" █       ▀█  \n");
        printf("  ████████   \n");
        printf("  █     █ █  \n");
        printf("  █     ███  \n");
        printf("  ████████   \n");
        printf("      ███    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄▄███ ▄▄█   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█        ▀▄█ \n");
        printf("█        ▀ █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      ██  \n");
        printf("  █      ██  \n");
        printf("  ████████   \n");
        printf("      ███    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄████ ▄██   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█         ▀█ \n");
        printf("█         ▀█ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("      ███    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄█▄██ ▄█▄   \n");
        printf(" █  █████ █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("     ████    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ▄█ ██ ██▄   \n");
        printf(" █  ████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("    ██ ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf("  ██ ██ ██   \n");
        printf(" █  ████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("   ██  ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" ▄██ ██ █▄   \n");
        printf(" █  ████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("   ██ ██    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" ▄█▄ ██▄█▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("   ████    \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" ██▄ ████▄    \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▀         █ \n");
        printf("█▀         █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf("  █      █  \n");
        printf("  █      █  \n");
        printf("  ████████   \n");
        printf("   ███       \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▀▄        █ \n");
        printf("█▀         █ \n");
        printf("█          █ \n");
        printf(" █        █  \n");
        printf("  ████████   \n");
        printf(" ██      █  \n");
        printf(" ██      █  \n");
        printf("  ████████   \n");
        printf("   ███        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▀▄▀       █ \n");
        printf("█▀ ▀       █ \n");
        printf("█▄         █ \n");
        printf(" █▀       █  \n");
        printf("  ████████   \n");
        printf(" █ █     █  \n");
        printf(" ███     █  \n");
        printf("  ████████   \n");
        printf("   ███        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█ ▀▄▀      █ \n");
        printf("█ ▀ ▀      █ \n");
        printf("█▄▄        █ \n");
        printf(" █ ▀      █  \n");
        printf("  ████████   \n");
        printf("  █ █    █  \n");
        printf("  ███    █  \n");
        printf("  ████████   \n");
        printf("   ██        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█  ▀▄▀     █ \n");
        printf("█  ▀ ▀     █ \n");
        printf("█ ▄▄       █ \n");
        printf(" █  ▀     █  \n");
        printf("  ████████   \n");
        printf("  ██ █   █  \n");
        printf("  █ ██   █  \n");
        printf("  ████████   \n");
        printf("   ██        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█  ▀▄▀     █ \n");
        printf("█  ▀ ▀     █ \n");
        printf("█ ▄▄       █ \n");
        printf(" █  ▀     █  \n");
        printf("  ████████   \n");
        printf("  █ █ █  █  \n");
        printf("  █  ██  █  \n");
        printf("  ████████   \n");
        printf("   ██        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▀  ▀▄▀    █ \n");
        printf("█▀  ▀ ▀    █ \n");
        printf("█  ▄▄      █ \n");
        printf(" █▀  ▀    █  \n");
        printf("  ████████   \n");
        printf("  █  █ █ █  \n");
        printf("  █   ██ █  \n");
        printf("  ████████   \n");
        printf("   ███        \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" █▄▄ ███▄▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▄▀  ▀▄▀   █ \n");
        printf("█ ▀  ▀ ▀   █ \n");
        printf("█  ▄▄      █ \n");
        printf(" █▀  ▀    █  \n");
        printf("  ████████   \n");
        printf("  █   █  █  \n");
        printf("  █    ███  \n");
        printf("  ████████   \n");
        printf("   ████       \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
        printf("     ██      \n");
        printf("     ██      \n");
        printf(" ██▄ ████▄   \n");
        printf(" █ █████  █  \n");
        printf(" █        █  \n");
        printf("█          █ \n");
        printf("█▀▄▀  ▀▄▀  █ \n");
        printf("█▀ ▀  ▀ ▀  █ \n");
        printf("█   ▄▄     █ \n");
        printf(" █ ▀  ▀   █  \n");
        printf("  ████████   \n");
        printf(" ██    █ █  \n");
        printf("  █     ██  \n");
        printf("  ████████   \n");
        printf("   ██ ██      \n");
        printf("             \n");
        printf("             \n");
        printf("             \n");
        printf("▄▄▄▄▄▄▄▄▄▄▄▄ \n");
        Sleep(250);
          if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        limpiarPantalla3();
    }
}

void muertePor_agotamiento(){
  while(true){
    printf("                   \n");
    printf("                   \n"),
    printf("      ▄              \n");
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
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("                   \n");
    printf("                   \n"),
    printf("     ▀▄              \n");
    printf("    ▄▀ ▀▄    ▄       \n");
    printf("  ▄▀     ▀▄▄▀ ▀▄     \n");
    printf(" █     ▄▄▄▄     █    \n");
    printf("█   ▄▀▀████▀▀▄   ▄  \n");
    printf("▀▄  █▄▄████▄▄█   █  \n");
    printf(" █   ██▀██▀██    ▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("                   \n");
    printf("     ▄              \n"),
    printf("      ▄              \n");
    printf("     █ ▀▄    ▄▀       \n");
    printf("  ▄ ▀    ▀▄▄▀ ▀▄     \n");
    printf(" █     ▄▄▄▄     █    \n");
    printf("█   ▄▀▀████▀▀▄   ▄  \n");
    printf("▀▄  █▄▄████▄▄█    █  \n");
    printf(" █   ██▀██▀██    ▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("                   \n");
    printf("     ▀              \n"),
    printf("      ▄▀      ▄        \n");
    printf("     █ ▀▄    ▄       \n");
    printf("   ▀     ▀▄▄▀ ▀▄     \n");
    printf("  █    ▄▄▄▄     █    \n");
    printf(" █  ▄▀▀████▀▀▄   ▀▄  \n");
    printf(" ▄  █▄▄████▄▄█    █  \n");
    printf(" █   ██▀██▀██    ▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("    ▄               \n");
    printf("       ▄      ▄      \n"),
    printf("      ▄              \n");
    printf("    ▄▀ ▀▄    ▄       \n");
    printf("   ▀     ▀▄▄▀ █     \n");
    printf("  █    ▄▄▄▄     █    \n");
    printf("█   ▄▀▀████▀▀▄   ▀▄  \n");
    printf("▄   █▄▄████▄▄█    █  \n");
    printf(" █   ██▀██▀██    ▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("    ▀        ▄       \n");
    printf("       ▀            \n"),
    printf("      ▄              \n");
    printf("    ▄▀ ▀▄    █      \n");
    printf("   ▀     ▀▄▄▀ ▀      \n");
    printf("  █    ▄▄▄▄    ▀▄    \n");
    printf("█   ▄▀▀████▀▀▄   ▀  \n");
    printf("▀▄  █▄▄████▄▄█   █  \n");
    printf(" █   ██▀██▀██    ▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("       ▀             \n");
    printf("                   \n"),
    printf("      ▄              \n");
    printf("    ▄▀ ▀▄    ▄▄       \n");
    printf("   ▄     ▀▄▄▀  █     \n");
    printf("  █    ▄▄▄▄     ▄    \n");
    printf("█   ▄▀▀████▀▀▄   ▀  \n");
    printf("▀▄  █▄▄████▄▄█    █  \n");
    printf(" █   ██▀██▀██    ▄ \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    printf("                   \n");
    printf("                   \n");
    printf("      ▄              \n");
    printf("    ▄▀ ▀▄    ▄       \n");
    printf("   ▀     ▀▄▄▀ ▀█     \n");
    printf(" █     ▄▄▄▄         \n");
    printf("█   ▄▀▀████▀▀▄   ▀▄  \n");
    printf("▀▄  █▄▄████▄▄█    █  \n");
    printf(" █   ██▀██▀██    ▄▀  \n");
    printf("  ▀▄   ▄▄▄▄    ▄▀    \n");
    printf("     ▄▄▄▄▄▄▄▄        \n");
    printf("    █ █    █ █       \n");
    printf("    ██      ██       \n");
    printf("     ████████        \n");
    printf("      ██  ██         \n");
    Sleep(250);
    limpiarPantalla3();
    if (_kbhit()) {

      _getch(); // Captura la tecla presionada
      break;
      }
    }
    
}

void muertePor_hambre(){
  while(true){
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
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
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
        printf("  █       █   \n");
        printf("     ███      \n");
        printf("    █   █     \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
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
        printf("  █       █   \n");
        printf("  █       █   \n");
        printf("     █ █     \n");
        printf("    █   █     \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("   ██   ██    \n");
        printf("  █  ███  █   \n");
        printf("  █       █   \n");
        printf(" █         █  \n");
        printf("█ ▀▄▀   ▀▄▀ █ \n");
        printf("█ ▀ ▀   ▀ ▀ █ \n");
        printf(" █  ▄▀▀▀▄  █  \n");
        printf("   █▀▄▄▄▀█   \n");
        printf("    █████    \n");
        printf("  █       █   \n");
        printf("  █       █   \n");
        printf("             \n");
        printf("    █   █     \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("   ██   ██    \n");
        printf("   █ ███ █   \n");
        printf("  █       █   \n");
        printf(" █         █  \n");
        printf("█ ▀▄▀   ▀▄▀ █ \n");
        printf(" █▀ ▀   ▀ ▀█ \n");
        printf("  █ ▄▀▀▀▄ █  \n");
        printf("   █▀▄▄▄▀█   \n");
        printf("    █████    \n");
        printf("  █       █   \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("    █   █  \n");
        printf("   █ ███ █   \n");
        printf("  █       █  \n");
        printf(" █▀▄▀   ▀▄▀█ \n");
        printf(" █▀ ▀   ▀ ▀█ \n");
        printf("  █ ▄▀▀▀▄ █  \n");
        printf("   █▀▄▄▄▀█   \n");
        printf("    █████    \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("    █   █  \n");
        printf("   █ ███ █   \n");
        printf("  █       █  \n");
        printf(" █▀▄▀   ▀▄▀█ \n");
        printf("  █ ▀   ▀ █ \n");
        printf("   █▄▀▀▀▄█  \n");
        printf("    █▄▄▄█   \n");
        printf("     ▀▀▀   \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("    █ █ █    \n");
        printf("   █     █  \n");
        printf("  █▄▀   ▀▄█ \n");
        printf("  █ ▀   ▀ █ \n");
        printf("   █▄▀▀▀▄█  \n");
        printf("    █▄▄▄█   \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("     █ █    \n");
        printf("    █   █  \n");
        printf("   █▀   ▀█ \n");
        printf("   █▀   ▀█ \n");
        printf("    █▀▀▀█  \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("     █ █     \n");
        printf("   █▀   ▀█ \n");
        printf("   █▀   ▀█ \n");
        printf("     ▀▀▀  \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("    █▀  ▀█ \n");
        printf("    █▀  ▀█ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("     █▀▀█ \n");
        printf("      ▀▀ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("      ▄▄ \n");
        printf("      ▀▀ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("      ▄▄ \n");
        printf("      ▀▀ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("      ▄▄ \n");
        printf("      ▀▀ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("             \n");
        printf("      <pop> \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("             \n");
        printf("      ▄ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("           \n");
        printf("     ▄        \n");
        printf("       ▄ \n");
        printf("         \n");
        printf("         \n");
        printf("         \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("  ▄       \n");
        printf("        ▄   \n");
        printf("     ▄        \n");
        printf("      ▄ \n");
        printf("     ▄   ▄ \n");
        printf("         \n");
        printf("    ▄     \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }
        printf("              \n");
        printf("              \n");
        printf("       \n");
        printf("       \n");
        printf("         \n");
        printf("          \n");
        printf("            \n");
        printf("       \n");
        printf("       WUSH!! \n");
        printf("         \n");
        printf("        \n");
        printf("           \n");
        printf("           \n");
        printf("             \n");
        printf("            \n");
        Sleep(250);
        limpiarPantalla3();
        if (_kbhit()) {

          _getch(); // Captura la tecla presionada
          break;
       }


    }
  
return;
}

void animacion_acariciar(Juego * juego){

  limpiarPantalla3();
  for(int i=0; i<3; i++){
    printf("                                   \n");
    printf("                ▄▄▄                 \n");
    printf("           ▄▄▄▀▀   ▀▄                \n");
    printf("    ▄▄▄▀▀▀▀         █                \n");
    printf("    ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
    printf("   █▀▀▄▄▄▄▀▀█▄▀                       \n");
    printf("   █        █                       \n");
    printf("  █          █                      \n");
    printf("  █          █                      \n");
    printf("  █▀▄▄▀  ▀▄▄▀█                      \n");
    printf("  █   ▄  ▄   █\n");
    printf("   █   ▀▀   █\n");
    printf("    ████████\n");
   mostrar_cuerpo(juego);


    sleep(1);
    limpiarPantalla3();


    printf("                                    \n");
    printf("                 ▄▄▄                 \n");
    printf("            ▄▄▄▀▀   ▀▄                \n");
    printf("     ▄▄▄▀▀▀▀         █                \n");
    printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
    printf("   █▀▀▄▄▄▄▀▀█▀▄▀                       \n");
    printf("   █        █                       \n");
    printf("  █          █                      \n");
    printf("  █          █                      \n");
    printf("  █▀▄▄▀  ▀▄▄▀█                      \n");
    printf("  █   ▄  ▄   █\n");
    printf("   █   ▀▀   █\n");
    printf("    ████████\n");
    mostrar_cuerpo(juego);

    sleep(1);
    limpiarPantalla3();
  }

  printf("                                   \n");
  printf("                ▄▄▄                 \n");
  printf("           ▄▄▄▀▀   ▀▄                \n");
  printf("    ▄▄▄▀▀▀▀         █                \n");
  printf("    ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf("   █▀▀▄▄▄▄▀▀█▄▀                    \n");
  printf("   █        █                   \n");
  printf("  █          █                       \n");
  printf("  █          █ ▄                      \n");
  printf("  █▀▄▄▀  ▀▄▄▀█                      \n");
  printf("  █   ▄  ▄   █\n");
  printf("   █   ▀▀   █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);
  Sleep(300);
  //sleep(1);
  limpiarPantalla3();
  
  printf("                                     \n");
  printf("                ▄▄▄                 \n");
  printf("           ▄▄▄▀▀   ▀▄                \n");
  printf("    ▄▄▄▀▀▀▀         █                \n");
  printf("    ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf("   █▀▀▄▄▄▄▀▀█▄▀                    \n");
  printf("   █        █                   \n");
  printf("  █          █                       \n");
  printf("  █          █ ▄▀                      \n");
  printf("  █▀▄▄▀  ▀▄▄▀█                      \n");
  printf("  █   ▄  ▄   █\n");
  printf("   █   ▀▀   █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);
  Sleep(300);
  //sleep(1);

  limpiarPantalla3();
  
  printf("                                   \n");
  printf("                ▄▄▄                 \n");
  printf("           ▄▄▄▀▀   ▀▄                \n");
  printf("    ▄▄▄▀▀▀▀         █                \n");
  printf("    ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                     \n");
  printf("   █▀▀▄▄▄▄▀▀█▄▀    ▄ ▄                 \n");
  printf("   █        █     █ ▀ █              \n");
  printf("  █          █     ▀▄▀                  \n");
  printf("  █          █ ▄▀                      \n");
  printf("  █▀▄▄▀  ▀▄▄▀█                      \n");
  printf("  █   ▄  ▄   █\n");
  printf("   █   ▀▀   █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);

  sleep(1);
  limpiarPantalla3();
  
  return;
}

void animacion_palmaditas(Juego * juego){
  limpiarPantalla3();
  for(int i=0; i<7; i++){

    printf("                 ▄▄▄                 \n");
    printf("            ▄▄▄▀▀   ▀▄                \n");
    printf("     ▄▄▄▀▀▀▀         █                \n");
    printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
    printf("             ▀▄▀                       \n");
    printf("                                    \n");
    printf("                                    \n");
    printf("    ██    ██\n");
    printf("   █  ████  █\n");
    printf("   █        █\n");
    printf("  █          █\n");
    printf("  █ ███  ███ █\n");
    printf("  █  █    █  █\n");
    printf("  █   ▄▄▄▄   █\n");
    printf("   █        █\n");
    printf("    ████████\n");
    mostrar_cuerpo(juego);

    Sleep(200);
    //sleep(1);
    limpiarPantalla3();

    printf("                                    \n");
    printf("                                    \n");
    printf("                                    \n");
    printf("                                    \n");
    printf("                 ▄▄▄                 \n");
    printf("            ▄▄▄▀▀   ▀▄                \n");
    printf("     ▄▄▄▀▀▀▀         █                \n");
    printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
    printf("   █▀▀▄▄▄▄▀▀█▀▄▀                       \n");
    printf("   █        █                       \n");
    printf("  █          █                      \n");
    printf("  █ ███  ███ █\n");
    printf("  █  █    █  █\n");
    printf("  █   ▄▄▄▄   █\n");
    printf("   █        █\n");
    printf("    ████████\n");
    mostrar_cuerpo(juego);
    Sleep(200);
    //sleep(1);
    limpiarPantalla3();
  }
  
  printf("                 ▄▄▄                 \n");
  printf("            ▄▄▄▀▀   ▀▄                \n");
  printf("     ▄▄▄▀▀▀▀         █                \n");
  printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("             ▀▄▀                       \n");
  printf("                                    \n");
  printf("                                    \n");
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █\n");
  printf("  █          █\n");
  printf("  █ ███  ███ █\n");
  printf("  █  █    █  █\n");
  printf("  █   ▄▄▄▄   █\n");
  printf("   █        █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);
  Sleep(700);
  //sleep(1);
  limpiarPantalla3();
  
  printf("                 ▄▄▄                 \n");
  printf("            ▄▄▄▀▀   ▀▄                \n");
  printf("     ▄▄▄▀▀▀▀         █                \n");
  printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("             ▀▄▀                       \n");
  printf("                                    \n");
  printf("                                    \n");
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █  █\n");
  printf("  █          █\n");
  printf("  █ ███  ███ █\n");
  printf("  █  █    █  █ \n");
  printf("  █   ▄▄▄▄   █\n");
  printf("   █        █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);

  //Sleep(1000000);
  sleep(1);
  limpiarPantalla3();
  
  printf("                 ▄▄▄                 \n");
  printf("            ▄▄▄▀▀   ▀▄                \n");
  printf("     ▄▄▄▀▀▀▀         █                \n");
  printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("             ▀▄▀                       \n");
  printf("                                    \n");
  printf("                                    \n");
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █  █ █\n");
  printf("  █          █\n");
  printf("  █ ███  ███ █\n");
  printf("  █  █    █  █ \n");
  printf("  █   ▄▄▄▄   █\n");
  printf("   █        █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);

  //usleep(1000000);
  sleep(1);
  limpiarPantalla3();
  
  printf("                 ▄▄▄                 \n");
  printf("            ▄▄▄▀▀   ▀▄                \n");
  printf("     ▄▄▄▀▀▀▀         █                \n");
  printf("     ▀▄▄▄▄▄▄▄▄  ▄▄▀▀▀                   \n");
  printf("             ▀▄▀                       \n");
  printf("                                   \n");
  printf("                                  \n");
  printf("    ██    ██\n");
  printf("   █  ████  █\n");
  printf("   █        █  █ █ █\n");
  printf("  █          █\n");
  printf("  █ ███  ███ █\n");
  printf("  █  █    █  █ \n");
  printf("  █   ▄▄▄▄   █\n");
  printf("   █        █\n");
  printf("    ████████\n");
  mostrar_cuerpo(juego);
  sleep(1);
  limpiarPantalla3();
}

// Mostrar cuerpo

void mostrar_cuerpo(Juego * juego){  
  if (juego->mascota.comida < LIMIT_LVL3 && juego->mascota.comida > 0) cuerpo_desnutrido();
  else if (juego->mascota.comida < LIMIT_LVL2) cuerpo_hambre();
  else cuerpo_normal();
}

// Función para mostrar el gato en función del estado de sus estadísticas
void mostrar_mascota(Juego * juego){

  
    // Nombre del archivo a eliminar
    const char *nombreArchivo = "save.txt";
    // Ruta del directorio donde se encuentra el archivo
    const char *rutaDirectorio = "cache";

  //revisa si alguna estadistica esta en 0
  if(juego->mascota.comida <= 0){
    muertePor_hambre();
    eliminar_archivo_guardado(nombreArchivo, rutaDirectorio);
    limpiarPantalla3();
    printf("  \n HAS MATADO A TU GATO DE HAMBRE!");
    sleep(1);
    exit(EXIT_SUCCESS);

    return;
} 
  if(juego->mascota.descanso <= 0){
    muertePor_agotamiento();
    eliminar_archivo_guardado(nombreArchivo, rutaDirectorio);
    limpiarPantalla3();
    printf("  \n HAS MATADO A TU GATO DE AGOTAMIENTO!");
    sleep(1);
    exit(EXIT_SUCCESS);

    return;
  } 

  if(juego->mascota.animo <= 0){
    muertePor_tristeza();
    eliminar_archivo_guardado(nombreArchivo, rutaDirectorio);
    limpiarPantalla3();
    printf("  \n HAS MATADO A TU GATO DE PENA!");
    sleep(1);
    exit(EXIT_SUCCESS);
    return;
  }

  // Mostrar zona superior de la cabeza
  else if (juego->mascota.descanso < LIMIT_LVL3 && juego->mascota.descanso > 0) cabeza_agotadaSuperior();
  else if (juego->mascota.descanso < LIMIT_LVL2) cabeza_cansadaSuperior();
  else cabeza_normalSuperior();

  // Mostrar zona inferior de la cabeza
  if (juego->mascota.animo < LIMIT_LVL3 && juego->mascota.animo > 0) cabeza_tristeInferior();
  else if (juego->mascota.animo < LIMIT_LVL2) cabeza_seriaInferior();
  else cabeza_normalInferior();

  // Mostrar cueroi del gato
  mostrar_cuerpo(juego);
}

// Función para eliminar archivo de guardado
void eliminar_archivo_guardado(const char *nombreArchivo, const char *rutaDirectorio) {
    char rutaCompleta[1024];

    // Crear la ruta completa al archivo
    snprintf(rutaCompleta, sizeof(rutaCompleta), "%s/%s", rutaDirectorio, nombreArchivo);

    // Intentar eliminar el archivo
    if (remove(rutaCompleta) == 0) {
        printf("El archivo '%s' ha sido eliminado.\n", rutaCompleta);
    } else {
        perror("Error al eliminar el archivo");
    }
}