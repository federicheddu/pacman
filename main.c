#include "game.h"
#include "pacman.h"
#include "utility.h"

int main(){
  int livello;
  pthread_t pacmanID;
  Buffer buffer;
  buffer.first = NULL;
  buffer.last = NULL;

  srand(time((time_t*)NULL));
  initscr();
  noecho();
  curs_set(0);

  /*start_color();

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);*/

  livello = mainMenu();

  pthread_create(&pacmanID, NULL, &pacman, (void*)&buffer);

  gameController(livello, &buffer);

  pthread_join(pacmanID, NULL);

  return 0;
}