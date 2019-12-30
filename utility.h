#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

//macro tasti, movimento e azioni
#define SU 65 						/* Freccia su */
#define GIU 66 						/* Freccia giu */
#define SINISTRA 68					/* Freccia sinsitra */
#define DESTRA 67					/* Freccia destra */
#define SPARO ' '                   /* Barra spaziatrice */
#define FERMO 0                     /* Entità si ferma */

//macro menu
#define NEWGAME 0
#define EXIT 1
#define SUGA 2

//macro gioco
#define PASSO 1 					/* Spostamento entita */

typedef enum {
    BULLET, PACMAN, BLINKY, PINKY, SPUNKY, CLYDE, INKY, SUE, FUNKY, GLITCHY
} Entity;

//definisce la posizione e il tipo di entita
typedef struct {
    int x;
    int y;
    int dir;
    _Bool sparo;
    Entity entita;
} Pos;

//definisce i parametri della pos
typedef struct {
    Pos posizione;
    int numVite;
    int numColpiSubiti;
} Par;

//elemento della lista che andrà a comporre il buffer
typedef struct bufferElement {
    Pos posizione;
    struct bufferElement *next;
} BufferElement;

//definisce primo e ultimo elemento del buffer, tutte le operazioni in O(1)
typedef struct {
    BufferElement *first;
    BufferElement *last;
} Buffer;

//utility
int randRange(int min, int max);

//gestione del buffer
void insertBuffer(Buffer *buffer, pthread_mutex_t *mutex, Pos new);
BufferElement* removeBuffer(Buffer *buffer);

//mutex
static pthread_mutex_t mutexDatiAux = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t *mutexDati = &mutexDatiAux;
static pthread_mutex_t mutexTeminaleAux = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t *mutexTerminale = &mutexTeminaleAux;

#endif