#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "utility.h"

//stampa del menu
int mainMenu();
void printNewGame();
void printExit();
void printSUGA();

//stampa del gioco
void printPacman(Pos pacman); //todo
void printGhost(Pos ghost, GhostType type); //todo
void printCampo(int level);
void printDati();

//gioco
void areaGioco(Pos *pos_pacman, int num_vite);

#endif