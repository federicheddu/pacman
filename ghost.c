#include "ghost.h"

void * ghost (void * param){
  PosStart *start = (PosStart*) param; //parsing del buffer
  Pos posIniziale = start->posizione;
  Buffer *dati = start->dati;
  _Bool *collisioni = start->collisioni;
  int dir, dirOpposta, dirNext = 0;
  _Bool bump = false;

  Pos posGhost;
  posGhost.x = posIniziale.x;
  posGhost.y = posIniziale.y;
  posGhost.dir = FERMO;
  posGhost.sparo = false;
  posGhost.entita = posIniziale.entita;
  posGhost.id = pthread_self();

  sleep(randRange(4,7));

  //Segnalazione della posizione iniziale
  insertBuffer(dati, mutexDati, posGhost);

  sleep(randRange(1,3));

  posGhost.dir = randRange(65,68);
  while(true){

    if(posGhost.dir % 2 == 0)
      dirOpposta = -1;
    else
      dirOpposta = 1;

    if(collisioni[posGhost.entita-1]) {
      posGhost.dir = posGhost.dir + dirOpposta;
      collisioni[posGhost.entita-1] = false;
    }

    /*BEST RICORDO DEL PROGETTO DI SO1 EVER*/
    //while(dir=randRange(65,68) == posGhost.dir + dirOpposta && !entityMv(posGhost.x, posGhost.y,dir)) {};

    //Genera una direzione che non sia l'opposta a quella attuale, e che sia fattibile nella mappa
    dirNext = randRange(0,3);
    dir = dirNext + SHIFT_MOVIMENTO;
    while (dir == posGhost.dir + dirOpposta || !entityMv(posGhost.x, posGhost.y,dir)) {
       dirNext++;
       dirNext %= 4;
       dir = dirNext + SHIFT_MOVIMENTO;
    }

    //Una volta che la direzione è ok allora può camminare
    switch(dir){

      case SU:
        posGhost.y-=1;
        posGhost.dir = SU;
        break;

      case GIU:
        posGhost.y+=1;
        posGhost.dir = GIU;
        break;

      case DESTRA:
        posGhost.x+=1;
        posGhost.dir = DESTRA;

        //effetto pacman
        if(posGhost.x+3 == 112)
          posGhost.x= 40;

        break;

      case SINISTRA:
        posGhost.x-=1;
        posGhost.dir = SINISTRA;

        //effetto pacman
        if(posGhost.x-1 == 38)
          posGhost.x = 108;

        break;
    }

    /*
      if(randRange(1,5) == 3)
      posGhost.sparo = true;
    */

    //aggiornamento della posizione nel buffer e pausa
    insertBuffer(dati, mutexDati, posGhost);
    switch(posGhost.entita){
      case BLINKY:
        usleep(100000);
        break;
      case PINKY:
        usleep(150000);
        break;
      case INKY:
        usleep(90000);
        break;
      case CLYDE:
        usleep(200000);
        break;
      case FUNKY:
        usleep(200000);
        break;
      case GLITCHY:
        usleep(10000);
        break;  
      default:
        usleep(0);
    }

  }
}
