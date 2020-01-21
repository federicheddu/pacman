#include "game.h"

int main(){
  int livello;
  pthread_t pacmanID;
  pthread_t blinkyID;
  Buffer buffer;
  buffer.first = NULL;
  buffer.last = NULL;
  PosStart ghost1;
  ghost1.posizione.entita = BLINKY;
  ghost1.buffer = &buffer;
  ghost1.posizione.x = 41;
  ghost1.posizione.y = 3;

  srand(time((time_t*)NULL));
  initscr();
  noecho();
  curs_set(0);

  start_color();

  //BACKGROUND
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  //PACMAN
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  //BLINKY
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  //WALLS
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  

  livello = mainMenu()+1;
  pthread_create(&pacmanID, NULL, &pacman, (void*)&buffer);
  pthread_create(&blinkyID, NULL, &ghost, (void*)&ghost1);
  gameController(livello, &buffer);

  pthread_join(pacmanID, NULL);

  return 0;
}