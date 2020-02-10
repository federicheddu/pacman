#include "game.h"

int main(){

  int livello, menu, highscore[3], score, aux;
  FILE *pf;

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
  //frutta
  init_pair(12, COLOR_GREEN, COLOR_RED);
  //fantasmi gnamgnam
  init_pair(13, COLOR_BLUE, COLOR_WHITE);

  pf = fopen("highscore.txt", "r");
  if(pf == NULL)
    exit(1);

  while(!feof(pf)){
    fscanf(pf, "%d\n", &highscore[0]);
    fscanf(pf, "%d\n", &highscore[1]);
    fscanf(pf, "%d\n", &highscore[2]);
  }
  fclose(pf);

  do {

    switch (mainMenu()) {
      case 0:
        livello = 0;
        break;

      case 2:
        livello = selLevel();
        break;

      default:
        endwin();
        return 0;
    }

  } while(livello == 3);

  score = gameController(livello, &dati, collisioni, highscore);

  for(int i=0; i<3; i++){
    if(highscore[i]<score){
      aux = highscore[i];
      highscore[i] = score;
      score = aux;
    }
  }

  pf = fopen("highscore.txt", "w");
  if(pf == NULL)
    exit(1);


  fprintf(pf, "%d\n", highscore[0]);
  fprintf(pf, "%d\n", highscore[1]);
  fprintf(pf, "%d\n", highscore[2]);

  fclose(pf);
  

  endwin();
  return 0;
}