#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "pacman.h"
#include "ghost.h"

//stampa del menu
int mainMenu();
void printMenu(int j);

//stampa del gioco
void printEntity(Pos entita, pthread_mutex_t *mutex, _Bool flagPower);
void clearEntity(Pos entita, pthread_mutex_t *mutex, int lv, int num, int par, int pallini[][num][par]);
void printCampo(int level);
void printStats(int livello, int score, Par pacman, double deltaTime, int highscore[], int scoreTotale);
void printLevelComplete(_Bool flag);

//inizializzazione dati
void startBullet(int num, Pos proiettili[][num]);
void startCharacter(Par personaggi[]);
void startGhost(int lv, int num, int par, int pallini[][num][par], Pos fantasmi[]);

//controlli di gioco
_Bool canShoot(Pos proiettili[][MAX_PROIETTILI], Entity entita);
int checkScore(int x, int y, int lv, int num, int par, int pallini[][num][par]);
_Bool checkPower(int x, int y, int lv, int num, int par, int pallini[][num][par]);
_Bool bulletMv(int x, int y, char dir, int lv);

//entita generali
void * bullet(void * param);

//gioco
int gameController(int livello, Buffer *dati, _Bool *collisioni, int highscore[]);

#endif
