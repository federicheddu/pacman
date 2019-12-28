#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <time.h>

//macro tasti
#define SU 65 						/* Freccia su */
#define GIU 66 						/* Freccia giu */
#define SINISTRA 68					/* Freccia sinsitra */
#define DESTRA 67					/* Freccia destra */

//macro menu
#define NEWGAME 0
#define EXIT 1
#define SUGA 2

//macro spostamenti
#define PASSO 1 					/* Spostamento entita */

typedef enum {BLINKY, PINKY, SPUNKY, CLYDE, INKY, SUE, SUE, FUNKY, GLITCHY} GhostType;

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    Pos *posizione;
    int *num_vite;
    pthread_mutex_t *mutex;
} Par;

#endif