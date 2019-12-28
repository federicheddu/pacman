#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "utility.h"

//stampa del menu
int mainMenu();
void printNewGame();
void printExit();
void printSUGA();

//stampa del gioco
void printEntity(Pos entita, pthread_mutex_t *mutex);
void clearEntity(Pos entita, pthread_mutex_t *mutex);
void printCampo(int level);
void printDati();

//gioco
void gameController(int livello, Buffer *buffer);

#endif