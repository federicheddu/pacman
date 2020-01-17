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
        break;

      case SINISTRA:
        if(entityMv(posPacman.x, posPacman.y, SINISTRA)) {
          posPacman.x-=1;
          posPacman.dir = SINISTRA;
        } else posPacman.dir = FERMO;
        posPacman.sparo = false;
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
    usleep(200000);
  }
}

void * ghost (void * param){
  PosStart *start = (PosStart*) param; //parsing del buffer
  Pos posIniziale = start -> posizione;
  Buffer *buffer = start -> buffer;
  int dir, dirOpposta;

  nodelay(stdscr, true);

  Pos posGhost;
  posGhost.x = posIniziale.x;
  posGhost.y = posIniziale.y;
  posGhost.dir = FERMO;
  posGhost.sparo = false;
  posGhost.entita = posIniziale.entita;
  posGhost.id = pthread_self();

  //Segnalazione della posizione iniziale
  insertBuffer(buffer, mutexDati, posGhost);

  sleep(randRange(1,3));

  posGhost.dir = randRange(65,68);
  while(true){

    if(posGhost.dir % 2 == 0)
      dirOpposta = -1;
    else
      dirOpposta = 1;

      /*BEST RICORDO DEL PROGETTO DI SO1 EVER*/
    //while(dir=randRange(65,68) == posGhost.dir + dirOpposta && !entityMv(posGhost.x, posGhost.y,dir)) {};

    //Genera una direzione che non sia l'opposta a quella attuale, e che sia fattibile nella mappa
    do{
      dir = randRange(65,68);
    }while(dir == posGhost.dir + dirOpposta || !entityMv(posGhost.x, posGhost.y,dir));

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
          break;
      case SINISTRA:
          posGhost.x-=1;
          posGhost.dir = SINISTRA;
          break;
    }
    //aggiornamento della posizione nel buffer e pausa
    insertBuffer(buffer, mutexDati, posGhost);
    usleep(100000);
  }
}
