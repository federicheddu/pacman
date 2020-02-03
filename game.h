#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "pacman.h"
#include "ghost.h"

//stampa del menu
int mainMenu();
void printNewGame();
void printExit();
void printSUGA();

//stampa del gioco
void printEntity(Pos entita, pthread_mutex_t *mutex);
void clearEntity(Pos entita, pthread_mutex_t *mutex, int num, int pallini[][num]);
void printCampo(int level);
void printStats(int livello, int score);
void printDot(int num, int pallini[][num]);

//inizializzazione dati
void startBullet(int num, Pos proiettili[][num]);
void startCharacter(Par personaggi[]);
void startGhost(int num, int pallini[][num], Pos fantasmi[]);

//controlli di gioco
_Bool canShoot(Pos proiettili[][MAX_PROIETTILI], Entity entita);
int checkScore(int x, int y, int num, int pallini[][num]);

//gioco
void gameController(int livello, Buffer *dati, Buffer *collisioni);

#endif
