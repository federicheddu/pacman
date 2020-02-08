#include "pacman.h"

void * pacman(void * param) {
  // parsing dei buffer
  PosStart *pacStart = (PosStart*) param; 
  Buffer *dati = pacStart->dati;
  _Bool *collisioni = pacStart->collisioni;
  int lv = pacStart->lv;
  // info direzione e sparo
  char c, dir, dirOld;
  int hoSparato = 0;
  //Stato iniziale di pacman
  Pos posPacman;
  posPacman.x = pacStart->posizione.x;
  posPacman.y = pacStart->posizione.y;
  posPacman.dir = FERMO;
  posPacman.sparo = false;
  posPacman.entita = PACMAN;
  posPacman.id = pthread_self();

  //Segnalazione della posizione iniziale
  insertBuffer(dati, mutexDati, posPacman);
  nodelay(stdscr, TRUE);

  while(true) {

    //direzione -> controllo se può continuare senza input
    if(!entityMv(posPacman.x, posPacman.y, posPacman.dir, lv))
      posPacman.dir = FERMO;

    //piglia input (non bloccante)
    c=getch();
    if(c != ERR)
      dir = c;

    //modifica della posizione
    switch(dir) {
      case SU:
        if(entityMv(posPacman.x, posPacman.y, SU, lv)) {
          posPacman.y-=1;
          posPacman.dir = SU;
        } else posPacman.dir = FERMO;
        hoSparato = 0;
        break;

      case GIU:
        if(entityMv(posPacman.x, posPacman.y, GIU, lv)) {
          posPacman.y+=1;
          posPacman.dir = GIU;
        } else posPacman.dir = FERMO;
        hoSparato = 0;
        break;

      case DESTRA:
        if(entityMv(posPacman.x, posPacman.y, DESTRA, lv)) {
          posPacman.x+=1;
          posPacman.dir = DESTRA;
        } else posPacman.dir = FERMO;
        hoSparato = 0;

        //effetto pacman
        if(posPacman.x+2 == 110)
          posPacman.x= 40;
        break;

      case SINISTRA:
        if(entityMv(posPacman.x, posPacman.y, SINISTRA, lv)) {
          posPacman.x-=1;
          posPacman.dir = SINISTRA;
        } else posPacman.dir = FERMO;
        hoSparato = 0;

        //effetto pacman
        if(posPacman.x == 40)
          posPacman.x = 108;
        break;

      case SPARO:
      
        if(hoSparato == 0)
          posPacman.sparo = true;
        else
          posPacman.sparo = false;

        hoSparato++;
        break;

      default:
        hoSparato = 0;
        break;
    }

    //aggiornamento della posizione nel buffer e pausa
    insertBuffer(dati, mutexDati, posPacman);
    usleep(100000);
  }
}