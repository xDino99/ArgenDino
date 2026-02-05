#ifndef GLBENGINE_H
#define GLBENGINE_H

#include "primec.h"

extern int colorAcento;
extern str playerName;
extern str playerGender;

void ConfigMenu();
void GameSelectionMenu();

void MenuCambiarNombre();
void MenuSeleccionarGenero();
void MenuSeleccionarColor();
void MenuSeleccionarEdad();

void RunClassicSnake();

#endif