#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <time.h>

//macro sacra
#define DEBUG 1

//macro tasti, movimento e azioni
#define SU 65 						/* Freccia su */
#define GIU 66 						/* Freccia giu */
#define SINISTRA 68					/* Freccia sinsitra */
#define DESTRA 67					/* Freccia destra */
#define SPARO ' '                   /* Barra spaziatrice */
#define FERMO 0                     /* Entità si ferma */
#define SHIFT_MOVIMENTO 65

//macro menu
#define NEWGAME 0
#define EXIT 1
#define SUGA 2

//macro gioco
#define PASSO 1 					/* Spostamento entita */
#define NUM_PERSONAGGI 7              /* Pacman + fantasmi */
#define MAX_PROIETTILI 4            /* Numero massimo di proiettili in contemporanea per entità*/
#define NUM_PALLINI 210

typedef enum {
    PACMAN, BLINKY, PINKY, CLYDE, INKY, FUNKY, GLITCHY, BULLET
} Entity;

const static char EntityName[8][10] = {"PACMAN   ", "BINKY    ", "PINKY    ", "CLYDE    ", "INKY     ", "FUNKY    ", "GLITCHY  ", "BULLET   "};

//definisce la posizione e il tipo di entita
typedef struct {
    int x;          //coordinata sul terminale
    int y;          //coordinata sul terminale
    int dir;        //direzione di movimento
    _Bool sparo;    //personaggio: se ha sparato || proiettile: se è attivo
    Entity entita;  //tipo di entità
    pthread_t id;   //id del thread
} Pos;


//definisce i parametri della pos
typedef struct {
    Pos posizione;
    int vite;           //numero di vite
    int colpiSubiti;    //numero di colpi di proiettile subiti
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

//parametri di partenza per proiettili e fantasmi
typedef struct {
    Pos posizione;
    Buffer *buffer;
} PosStart;

//utility
int randRange(int min, int max);
_Bool entityMv(int x, int y, char dir);

//gestione del buffer
void insertBuffer(Buffer *buffer, pthread_mutex_t *mutex, Pos new);
BufferElement* removeBuffer(Buffer *buffer);

//mutex
static pthread_mutex_t mutexDatiAux = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t *mutexDati = &mutexDatiAux;
static pthread_mutex_t mutexTeminaleAux = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t *mutexTerminale = &mutexTeminaleAux;

//campo


#endif