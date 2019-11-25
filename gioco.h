//
// Created by Fabio Pili on 25/11/2019.
//

#ifndef PACMAN_GIOCO_H
#define PACMAN_GIOCO_H

#endif //PACMAN_GIOCO_H

#include <curses.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

//macro keypad
#define SU 65
#define GIU 66
#define DESTRA 67
#define SINISTRA 68
#define STOP 0 //non è del keypad ma fa parte del movimento
//macro menu
#define NEWGAME 0
#define EXIT 1
#define SUGA 2
//macro di gioco
#define LEVELS 1
#define SPAWN_LEVEL1_X 29
#define SPAWN_LEVEL1_Y 45

//gioco
int mainMenu();
int levelsMenu(); //TODO
void gameController(int pipe, int level);

//stampa del menu
void printNewGame();
void printExit();
void printSUGA();

//stampa del gioco
void printCampo(int level); //TODO poi da aggiornare con i prossimi livelli
void printDati();
