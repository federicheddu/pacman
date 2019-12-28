#include "game.h"
#include "pacman.h"
#include "utility.h"

int num_vite = 3;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){
  pthread_t pacmanID;
  Pos pos_pacman;
  Par par_pacman;

  par_pacman.num_vite=&num_vite;
  par_pacman.mutex=&mutex;
  par_pacman.posizione=&pos_pacman;

  srand(time((time_t*)NULL));
  initscr();
  noecho();
  curs_set(0);

  /*start_color();

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);*/


  printCampo(mainMenu());
  pthread_create(&pacmanID, NULL, &pacman, (void*)&par_pacman);



  areaGioco(&pos_pacman, num_vite);

  pthread_join(pacmanID, NULL);

  while(getch()!='\n');
  endwin();
  return 0;
}