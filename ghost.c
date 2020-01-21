#include "ghost.h"

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
