#include <string.h>
#include <stdbool.h>
#include "design.h"

void limpiarPantalla() { system("clear"); }

void cabeza_normalSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█          █\n");
  printf("█  █    █  █\n");
  return;
}

void cabeza_cansadaSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█ ███  ███ █\n");
  printf("█  █    █  █\n");
  return;
}

void cabeza_agotadaSuperior(){
  printf("  ██    ██\n");
  printf(" █  ████  █\n");
  printf(" █        █\n");
  printf("█          █\n");
  printf("█  ▄▄  ▄▄  █\n");
  printf("█ ▀▀    ▀▀ █\n");
  return;
}

void cabeza_normalInferior(){
  printf("█   ▄  ▄   █\n");
  printf(" █   ▀▀   █\n");
  printf("  ████████\n");
  return;
}

void cabeza_seriaInferior(){
  printf("█   ▄▄▄▄   █\n");
  printf(" █        █\n");
  printf("  ████████\n");
  return;
}

void cabeza_tristeInferior(){
  printf("█    ▄▄    █\n");
  printf(" █  ▀  ▀  █\n");
  printf("  ████████\n");
  return;
}

void cuerpo_normal(){
  printf(" █ █    █ █\n");
  printf(" ██      ██\n");
  printf("  ████████ \n");
  printf("   ██  ██  \n");
}

void cuerpo_hambre(){
  printf(" █ ██  ██ █\n");
  printf(" ██ █  █ ██\n");
  printf("    ████   \n");
  printf("    █  █   \n");
  return;
}

void cuerpo_desnutrido(){
  printf(" █   ██   █\n");
  printf(" █   ██   █\n");
  printf("    ████   \n");
  printf("    █  █   \n");
  return;
}


