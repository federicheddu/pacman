#include "pacman.h"

void * pacman(void * param) {
  // parsing dei buffer
  PosStart *pacStart = (PosStart*) param; 
  Buffer *dati = pacStart->dati;
  Buffer *collisioni = pacStart->collisioni;
  // info direzione e sparo
  char c, dir, dirOld;
  int hoSparato = 0;
  //Stato iniziale di pacman
  Pos posPacman;
  posPacman.x = 45;
  posPacman.y = 29;
  posPacman.dir = FERMO;
  posPacman.sparo = false;
  posPacman.entita = PACMAN;
  posPacman.id = pthread_self();
  pacStart->posizione = posPacman;

  //Segnalazione della posizione iniziale
  insertBuffer(dati, mutexDati, posPacman);
  nodelay(stdscr, TRUE);

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
        hoSparato = 0;
        break;

      case GIU:
        if(entityMv(posPacman.x, posPacman.y, GIU)) {
          posPacman.y+=1;
          posPacman.dir = GIU;
        } else posPacman.dir = FERMO;
        hoSparato = 0;
        break;

      case DESTRA:
        if(entityMv(posPacman.x, posPacman.y, DESTRA)) {
          posPacman.x+=1;
          posPacman.dir = DESTRA;
        } else posPacman.dir = FERMO;
        hoSparato = 0;

        //effetto pacman
        if(posPacman.x+3 == 112)
          posPacman.x= 40;
        break;

      case SINISTRA:
        if(entityMv(posPacman.x, posPacman.y, SINISTRA)) {
          posPacman.x-=1;
          posPacman.dir = SINISTRA;
        } else posPacman.dir = FERMO;
        hoSparato = 0;

        //effetto pacman
        if(posPacman.x-1 == 38)
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