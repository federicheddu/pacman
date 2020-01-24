#include "pacman.h"

void * pacman(void * param) {
  Buffer *buffer = (Buffer*) param; // parsing del buffer
  char c, dir, dirOld;

  nodelay(stdscr, true);

  Pos posPacman;
  posPacman.x = 45;
  posPacman.y = 29;
  posPacman.dir = FERMO;
  posPacman.sparo = false;
  posPacman.entita = PACMAN;
  posPacman.id = pthread_self();

  //Segnalazione della posizione iniziale
  insertBuffer(buffer, mutexDati, posPacman);

  while(true) {

    //direzione -> controllo se può continuare senza input
    if(!entityMv(posPacman.x, posPacman.y, posPacman.dir))
      posPacman.dir = FERMO;

    //piglia input (non bloccante)
    c=getch();
    if(c != ERR)
      dir = c;

    //modifica della posizione
    switch(dir) {
      case SU:
        if(entityMv(posPacman.x, posPacman.y, SU)) {
          posPacman.y-=1;
          posPacman.dir = SU;
        } else posPacman.dir = FERMO;
        posPacman.sparo = false;
        break;

      case GIU:
        if(entityMv(posPacman.x, posPacman.y, GIU)) {
          posPacman.y+=1;
          posPacman.dir = GIU;
        } else posPacman.dir = FERMO;
        posPacman.sparo = false;
        break;

      case DESTRA:
        if(entityMv(posPacman.x, posPacman.y, DESTRA)) {
          posPacman.x+=1;
          posPacman.dir = DESTRA;
        } else posPacman.dir = FERMO;
        posPacman.sparo = false;

        //effetto pacman
        if(posPacman.x+3 == 112)
          posPacman.x= 40;
        break;

      case SINISTRA:
        if(entityMv(posPacman.x, posPacman.y, SINISTRA)) {
          posPacman.x-=1;
          posPacman.dir = SINISTRA;
        } else posPacman.dir = FERMO;
        posPacman.sparo = false;

        //effetto pacman
        if(posPacman.x-1 == 38)
          posPacman.x = 108;
        break;

      case SPARO:
        if(!posPacman.sparo)
          posPacman.sparo = true;
        break;

      default:
        posPacman.sparo = false;
        break;
    }

    //aggiornamento della posizione nel buffer e pausa
    insertBuffer(buffer, mutexDati, posPacman);
    usleep(100000);
  }
}
