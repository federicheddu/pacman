#include "game.h"

int main(){

  int livello;

  Buffer dati;
  _Bool *collisioni;
  dati.first = NULL;
  dati.last = NULL;
  collisioni = (_Bool*)malloc(sizeof(_Bool)*NUM_FANTASMI);
  for(int i=0; i<NUM_FANTASMI; i++)
    collisioni[i] = false;


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
  init_pair(3, COLOR_RED, COLOR_RED);
  //PINKY
  init_pair(8, COLOR_MAGENTA, COLOR_MAGENTA);
  //INKY
  init_pair(7, COLOR_CYAN, COLOR_CYAN);
  //CLYDE
  init_pair(9, COLOR_WHITE, COLOR_WHITE);
  //FUNKY
  init_pair(10, COLOR_GREEN, COLOR_GREEN);
  //WALLS
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  //BULLETS
  init_pair(6, COLOR_GREEN, COLOR_BLACK);
  //Prova
  init_pair(11, COLOR_BLACK, COLOR_BLACK);

  

  livello = mainMenu()+1;
  //pthread_create(&pacmanID, NULL, &pacman, (void*)&pacStart);
  gameController(livello, &dati, collisioni);

  endwin();
  return 0;
}