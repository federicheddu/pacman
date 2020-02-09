#include "game.h"

/** --- STAMPA DEL MENU ------------------------------------------------------------- **/

//gestione del menu
int mainMenu() {
    int menu = 0;
    char selMenu;

    do {
        printMenu(menu);

        selMenu = getch();
        switch (selMenu) {
            case GIU:
                menu++;
                break;
            case SU:
                menu--;
                break;
        }
        menu = menu%3;

    } while(selMenu != '\n');
    return menu;
}

//stampa della schermata Nuova Partita
void printMenu(int j) {

    char menu[3][60][152] = {{"##==================================================================================================================================================##\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                    =       ======  =======     ==============  =====  =====  =====  =======  =                                   ||\n",
                             "||                                    =  ====  ====    =====  ===  =============   ===   ====    ====   ======  =                                   ||\n",
                             "||                                    =  ====  ===  ==  ===  ===================  =   =  ===  ==  ===    =====  =                                   ||\n",
                             "||                                    =  ====  ==  ====  ==  ===================  == ==  ==  ====  ==  ==  ===  =                                   ||\n",
                             "||                                    =       ===  ====  ==  ========         ==  =====  ==  ====  ==  ===  ==  =                                   ||\n",
                             "||                                    =  ========        ==  ===================  =====  ==        ==  ====  =  =                                   ||\n",
                             "||                                    =  ========  ====  ==  ===================  =====  ==  ====  ==  =====    =                                   ||\n",
                             "||                                    =  ========  ====  ===  ===  =============  =====  ==  ====  ==  ======   =                                   ||\n",
                             "||                                    =  ========  ====  ====     ==============  =====  ==  ====  ==  =======  =                                   ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                                || NUOVA  PARTITA ||                                                              ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                        ESCI                                                                      ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                        SUGA                                                                      ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "##==================================================================================================================================================##"}, 
                             {"##==================================================================================================================================================##\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                    =       ======  =======     ==============  =====  =====  =====  =======  =                                   ||\n",
                             "||                                    =  ====  ====    =====  ===  =============   ===   ====    ====   ======  =                                   ||\n",
                             "||                                    =  ====  ===  ==  ===  ===================  =   =  ===  ==  ===    =====  =                                   ||\n",
                             "||                                    =  ====  ==  ====  ==  ===================  == ==  ==  ====  ==  ==  ===  =                                   ||\n",
                             "||                                    =       ===  ====  ==  ========         ==  =====  ==  ====  ==  ===  ==  =                                   ||\n",
                             "||                                    =  ========        ==  ===================  =====  ==        ==  ====  =  =                                   ||\n",
                             "||                                    =  ========  ====  ==  ===================  =====  ==  ====  ==  =====    =                                   ||\n",
                             "||                                    =  ========  ====  ===  ===  =============  =====  ==  ====  ==  ======   =                                   ||\n",
                             "||                                    =  ========  ====  ====     ==============  =====  ==  ====  ==  =======  =                                   ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                   NUOVA  PARTITA                                                                 ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                                ||      ESCI      ||                                                              ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                        SUGA                                                                      ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "##==================================================================================================================================================##"},
                             {"##==================================================================================================================================================##\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                    =       ======  =======     ==============  =====  =====  =====  =======  =                                   ||\n",
                             "||                                    =  ====  ====    =====  ===  =============   ===   ====    ====   ======  =                                   ||\n",
                             "||                                    =  ====  ===  ==  ===  ===================  =   =  ===  ==  ===    =====  =                                   ||\n",
                             "||                                    =  ====  ==  ====  ==  ===================  == ==  ==  ====  ==  ==  ===  =                                   ||\n",
                             "||                                    =       ===  ====  ==  ========         ==  =====  ==  ====  ==  ===  ==  =                                   ||\n",
                             "||                                    =  ========        ==  ===================  =====  ==        ==  ====  =  =                                   ||\n",
                             "||                                    =  ========  ====  ==  ===================  =====  ==  ====  ==  =====    =                                   ||\n",
                             "||                                    =  ========  ====  ===  ===  =============  =====  ==  ====  ==  ======   =                                   ||\n",
                             "||                                    =  ========  ====  ====     ==============  =====  ==  ====  ==  =======  =                                   ||\n",
                             "||                                    ===========================================================================                                   ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                   NUOVA  PARTITA                                                                 ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                        ESCI                                                                      ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                                ||      SUGA      ||                                                              ||\n",
                             "||                                                                ##================##                                                              ||\n",
                             "||                                                              super user general access                                                           ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "||                                                                                                                                                  ||\n",
                             "##==================================================================================================================================================##"}};

    attron(COLOR_PAIR(1));
    for(int i=0; i<60; i++)
        mvprintw(i, 0, "%s", menu[j][i]);

}


/** --- STAMPA DEL GIOCO ------------------------------------------------------------ **/

//stampa del gioco
void printCampo(int level){

    attron(COLOR_PAIR(1));
    for (int i=0; i<60; i++){
        for(int j=0; j<152; j++){
            if(Campo[level][i][j] == '#' && (j> 2 && j< 145)){
                attron(COLOR_PAIR(4));
                mvprintw(i,j, "%c", Campo[level][i][j]);
                attroff(COLOR_PAIR(4));
            }else{
                mvprintw(i,j,"%c", Campo[level][i][j]);
            }
        }
    }
    attroff(COLOR_PAIR(1));
}

void printLevelComplete(){

    attron(COLOR_PAIR(1));
    for (int i=0; i<60; i++){
        for(int j=0; j<152; j++){
            if(levelComplete[i][j] == '#' && (j> 2 && j< 145)){
                attron(COLOR_PAIR(10));
                mvprintw(i,j, "%c", levelComplete[i][j]);
                attroff(COLOR_PAIR(10));
            }else{
                mvprintw(i,j,"%c", levelComplete[i][j]);
            }
        }
    }
    attroff(COLOR_PAIR(1));
    usleep(500000);
}

void printStats(int livello, int score, Par pacman, double deltaTime, int highscore[], int scoreTotale){
    //stampo livello
    mvprintw(5, 18, "%d", livello+1);
    //stampo score
    mvprintw(6, 18, "%d", score+scoreTotale);
    mvprintw(7, 11, "Prossima vita a %d", 2000-score);

    //stampo highscore
    mvprintw(11, 13, "%d", highscore[0]);
    mvprintw(12, 13, "%d", highscore[1]);
    mvprintw(13, 13, "%d", highscore[2]);
    //stampo vite
    mvprintw(5, 131, "%d", pacman.vite);
    //stampo tempo
    mvprintw(6, 131, "%.3f", deltaTime);
}

void printEntity(Pos entita, pthread_mutex_t *mutex, _Bool flagPower) {
        pthread_mutex_lock(mutex);

    switch (entita.entita) {
        case BULLET:
            attron(COLOR_PAIR(2));
            mvprintw(entita.y,entita.x, "o");
            attroff(COLOR_PAIR(2));
            break;
        case PACMAN:
            attron(COLOR_PAIR(5));
            mvprintw(entita.y,entita.x, "%s","P M"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s"," A "); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","N C"); //3° riga
            attroff(COLOR_PAIR(5));
            break;
        case BLINKY:
            if(!flagPower){
                attron(COLOR_PAIR(3));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(3));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            
            break;
        case PINKY:
            if(!flagPower){
                attron(COLOR_PAIR(8));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(8));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            break;
        case CLYDE:
            if(!flagPower){
                attron(COLOR_PAIR(9));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(9));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            break;
        case INKY:
            if(!flagPower){
                attron(COLOR_PAIR(7));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(7));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            break;
        case FUNKY:
            if(!flagPower){
                attron(COLOR_PAIR(10));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(10));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            break;
        case GLITCHY:
            if(!flagPower){
                attron(COLOR_PAIR(7));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                attroff(COLOR_PAIR(7));
                attron(COLOR_PAIR(9));
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                attroff(COLOR_PAIR(9));
                attron(COLOR_PAIR(3));
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(3));
            }else{
                attron(COLOR_PAIR(13));
                mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
                mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
                mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
                attroff(COLOR_PAIR(13));
            }
            break;
    }
            pthread_mutex_unlock(mutex);
}

void clearEntity(Pos entita, pthread_mutex_t *mutex, int lv, int num, int par, int pallini[][num][par]) {
    pthread_mutex_lock(mutex);

    switch(entita.dir) {
      case SU:

        if(entita.entita == BULLET)
            mvprintw(entita.y+1, entita.x, "   ");

        if(entita.entita>PACMAN && entita.entita<BULLET)
            for(int i=0; i<num; i++) {
                if(entita.y+3 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 0)
                    mvprintw(entita.y+3,entita.x+1, "%c",'.');
                if(entita.y+3 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 4)
                    mvprintw(entita.y+3,entita.x+1, "%c",'0');
                if(entita.y+3 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 2) {
                    attron(COLOR_PAIR(12));
                    mvprintw(entita.y+3,entita.x+1, "%c",'Y');
                    attroff(COLOR_PAIR(12));
                }
            }
        break;

      case GIU:

        if(entita.entita == BULLET)
            mvprintw(entita.y-1, entita.x, "   ");

        if(entita.entita>PACMAN && entita.entita<BULLET)
            for(int i=0; i<num; i++) {
                if(entita.y-1 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 0)
                    mvprintw(entita.y-1,entita.x+1, "%c", '.');
                if(entita.y-1 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 4)
                    mvprintw(entita.y-1,entita.x+1, "%c", '0');
                if(entita.y-1 == pallini[lv][i][0] && entita.x+1 == pallini[lv][i][1] && pallini[lv][i][2] == 2) {
                    attron(COLOR_PAIR(12));
                    mvprintw(entita.y-1,entita.x+1, "%c", 'Y');
                    attroff(COLOR_PAIR(12));
                }
                    
            }
        break;

      case SINISTRA:

        if(entita.entita == BULLET){
            mvprintw(entita.y, entita.x+1, " ");
            mvprintw(entita.y+1, entita.x+1, " ");
            mvprintw(entita.y+2, entita.x+1, " ");
        }
            

        if(entita.entita>PACMAN && entita.entita<BULLET)
            for(int i=0; i<num; i++){
                if(entita.y+1 == pallini[lv][i][0] && entita.x+3 == pallini[lv][i][1] && pallini[lv][i][2] == 0)
                    mvprintw(entita.y+1,entita.x+3, "%c",'.');
                if(entita.y+1 == pallini[lv][i][0] && entita.x+3 == pallini[lv][i][1] && pallini[lv][i][2] == 4)
                    mvprintw(entita.y+1,entita.x+3, "%c", '0');
                if(entita.y+1 == pallini[lv][i][0] && entita.x+3 == pallini[lv][i][1] && pallini[lv][i][2] == 2) {
                    attron(COLOR_PAIR(12));
                    mvprintw(entita.y+1,entita.x+3, "%c", 'Y');
                    attroff(COLOR_PAIR(12));
                }
            }

        if(entita.x == 108 && entita.entita>PACMAN && entita.entita<BULLET) {
            mvprintw(entita.y,40, "%s","   ");
            mvprintw(entita.y+1,40, "%s","   ");
            mvprintw(entita.y+2,40, "%s","   ");
        }
        break;

      case DESTRA:

        if(entita.entita == BULLET){
            mvprintw(entita.y, entita.x-1, " ");
            mvprintw(entita.y+1, entita.x-1, " ");
            mvprintw(entita.y+2, entita.x-1, " ");
        }
            
        
        if(entita.entita>PACMAN && entita.entita<BULLET)
            for(int i=0; i<num; i++){
                if(entita.y+1 == pallini[lv][i][0] && entita.x-1 == pallini[lv][i][1] && pallini[lv][i][2] == 0)
                    mvprintw(entita.y+1,entita.x-1, "%c",'.');
                if(entita.y+1 == pallini[lv][i][0] && entita.x-1 == pallini[lv][i][1] && pallini[lv][i][2] == 4)
                    mvprintw(entita.y+1,entita.x-1, "%c", '0');
                if(entita.y+1 == pallini[lv][i][0] && entita.x-1 == pallini[lv][i][1] && pallini[lv][i][2] == 2) {
                    attron(COLOR_PAIR(12));
                    mvprintw(entita.y+1,entita.x-1, "%c", 'Y');
                    attroff(COLOR_PAIR(12));
                }
            }

        if(entita.x == 40 && entita.entita>PACMAN && entita.entita<BULLET) {
            mvprintw(entita.y,108, "%s","   ");
            mvprintw(entita.y+1,108, "%s","   ");
            mvprintw(entita.y+2,108, "%s","   ");
        }
        break;
    }
    
    pthread_mutex_unlock(mutex);
}

/** --- INIZIALIZZAZIONE DATI ------------------------------------------------------- **/

//inizializzazione dei proiettili
void startBullet(int num, Pos proiettili[][num]) {
    for(int i=0; i<7; i++) {
        for (int j=0; j<4; j++) {
            proiettili[i][j].x = -1;
            proiettili[i][j].y = -1;
            proiettili[i][j].id = NULL;
            proiettili[i][j].sparo = false;
            proiettili[i][j].entita = BULLET;
            proiettili[i][j].dir = j+SHIFT_MOVIMENTO;
        }
    }
}

//inizializzazione dei personaggi
void startCharacter(Par personaggi[]) {
    for(int i=0; i<NUM_PERSONAGGI; i++) {
        personaggi[i].vite = 3;
        personaggi[i].colpiSubiti = 0;
    }
}

void startGhost(int lv, int num, int par, int pallini[][num][par], Pos fantasmi[]){
    int x, posGhosts[NUM_FANTASMI];
    _Bool flag;
    
    for(int i=0; i<NUM_FANTASMI; i++){
        do {
            posGhosts[i] = randRange(0, num);

            flag = true;
            for(int j=0; j<i; j++){
                if(posGhosts[i] == posGhosts[j])
                    flag = false;
            }
        } while(!flag);

        for(int i=0; i<NUM_FANTASMI; i++) {
            fantasmi[i].y = pallini[lv][posGhosts[i]][0] -1;
            fantasmi[i].x = pallini[lv][posGhosts[i]][1] -1;
            fantasmi[i].dir = FERMO;
            fantasmi[i].entita = i % MAX_FANTASMI + 1;
            fantasmi[i].sparo = false;
            fantasmi[i].id = NULL;
        }
    }
}

/** --- CONTROLLI DI GIOCO ---------------------------------------------------------- **/
_Bool canShoot(Pos proiettili[][MAX_PROIETTILI], Entity entita) {
    return !proiettili[entita][SU-SHIFT_MOVIMENTO].sparo && !proiettili[entita][GIU-SHIFT_MOVIMENTO].sparo && !proiettili[entita][DESTRA-SHIFT_MOVIMENTO].sparo && !proiettili[entita][SINISTRA-SHIFT_MOVIMENTO].sparo;
}

int checkScore(int x, int y, int lv, int num, int par, int pallini[][num][par]){
    for (int i; i<num; i++){
        if(pallini[lv][i][0] == y+1)
            if(pallini[lv][i][1] == x+1) {
                if(pallini[lv][i][2] == 0 || pallini[lv][i][2] == 4){
                    pallini[lv][i][2] = 1;
                    return 10;
                }
                if(pallini[lv][i][2] == 2){
                    pallini[lv][i][2] = 1;
                    return 50;
                }
            }
    }
    return 0;
}

_Bool checkPower(int x, int y, int lv, int num, int par, int pallini[][num][par]) {
    for (int i; i<num; i++){
        if(pallini[lv][i][0] == y+1)
            if(pallini[lv][i][1] == x+1) {
                if(pallini[lv][i][2] == 4){
                    return true;
                }
            }
    }
    return false;
}

_Bool bulletMv(int x, int y, char dir, int lv) {

    _Bool flag=true;

    pthread_mutex_lock(mutexFantasmi);
    switch (dir) {
        case SU:
            //for (int i; i<NUM_PALLINI; i++)
                if(scampo[lv][y-1][x] == '#' || scampo[lv][y-1][x] == 'D' /*|| (pallini[i][0] == y-1 && pallini[i][1] == x && pallini[i][2] == 1)*/)
                    flag = false;
            break;
        case GIU:
            //for (int i; i<NUM_PALLINI; i++)
                if(scampo[lv][y+1][x] == '#' || scampo[lv][y+1][x] == 'U' /*|| (pallini[i][0] == y+3 && pallini[i][1] == x && pallini[i][2] == 1)*/)
                    flag = false;
            break;
        case DESTRA:
            //for (int i; i<NUM_PALLINI; i++)
                if(scampo[lv][y][x+1] == '#' || scampo[lv][y][x+1] == 'L' /*|| (pallini[i][0] == y && pallini[i][1] == x+3 && pallini[i][2] == 1)*/)
                    flag = false;
            break;
        case SINISTRA:
            //for (int i; i<NUM_PALLINI; i++)
                if(scampo[lv][y][x-1] == '#' || scampo[lv][y][x-1] == 'R' /*|| (pallini[i][0] == y && pallini[i][1] == x-1 && pallini[i][2] == 1)*/)
                    flag = false;
            break;
        default:
            flag = false;
    }
    pthread_mutex_unlock(mutexFantasmi);

    return flag;
}

/** --- ENTITÀ GENERALI ------------------------------------------------------------- **/
void * bullet(void * param) {
    PosStart *start = (PosStart*) param;
    Pos posIniziale = start->posizione;
    Buffer* dati = start->dati;
    _Bool* collisioni = start->collisioni;
    int lv = start->lv;
    clock_t birth, death;
    double deltaTime;

    Pos posBullet;
    posBullet.x = posIniziale.x;
    posBullet.y = posIniziale.y;
    posBullet.dir = posIniziale.dir;
    posBullet.sparo = true;
    posBullet.entita = BULLET;
    posBullet.id = pthread_self();


    birth=clock();
    //Movimento bullet
    while(bulletMv(posBullet.x, posBullet.y, posBullet.dir, lv) && deltaTime < 6) {
        switch (posBullet.dir) {
            case SU:
            posBullet.y -= 1;
            break;
        case GIU:
            posBullet.y += 1;
            break;
        case DESTRA:
            posBullet.x += 1;

            /*//effetto pacman
            if(posBullet.x+3 == 111)
                posBullet.x= 40;*/
            break;
        case SINISTRA:
            posBullet.x -= 1;

            /*//effetto pacman
            if(posBullet.x-1 == 39)
                posBullet.x = 108;*/
            break;
        }

        insertBuffer(dati, mutexDati, posBullet);
        usleep(85000);
        death = clock();
        deltaTime = ((double) (death-birth))/CLOCKS_PER_SEC;
    }

    posBullet.sparo = false;

    //PUNTO DI MORTEH
    switch (posBullet.dir) {
        case SU:
            posBullet.y -= 1;
            break;
        case GIU:
            posBullet.y += 1;
            break;
        case DESTRA:
            posBullet.x += 1;
            break;
        case SINISTRA:
            posBullet.x -= 1;
            break;
    }
    
    insertBuffer(dati,mutexDati,posBullet);
    pthread_exit(NULL);
}

/** --- GIOCO ----------------------------------------------------------------------- **/
int gameController(int livello, Buffer *dati, _Bool *collisioni, int highscore[]){

    int scorePallini = 0, scoreLivello = 0, scoreFantasmi = 0, scoreFrutta = 0, scoreTotale = 0, scoreAux = 0;
    int dirOpposta = 0;
    //variabili tempo
    int ciclo = 0;
    clock_t start, end, clockPower;
    double deltaTime, deltaPower;
    _Bool flagPower = false;

    //pallini in gioco: [0]y [1]x [2] attivo(0) - disattivato(1) - frutto(2) - porcamadonna(3) - powerpill(4)
    int numPallini[2] = {NUM_PALLINI_1, NUM_PALLINI_2};
    int maxScore[2] = {2100, 1900};
    int frutto;
    _Bool flagFrutta;
    int pallini[2][210][3]= {{
        {4, 42, 0},{4, 45, 0},{4, 48, 0},{4, 51, 0},
        {4, 55, 0},{4, 58, 0},{4, 61, 0},{4, 64, 0},{4, 66, 0},{4, 69, 0},
        {4, 81, 0},{4, 84, 0},{4, 86, 0},{4, 89, 0},{4, 92, 0},{4, 95, 0},
        {4, 99, 0},{4, 102, 0},{4, 105, 0},{4, 108, 0},{7, 42, 4},{7, 55, 0},
        {7, 69, 0},{7, 81, 0},{7, 95, 0},{7, 108, 4},{10, 42, 0},{10, 55, 0},
        {10, 69, 0},{10, 81, 0},{10, 95, 0},{10, 108, 0},{13, 42, 0},{13, 45, 0},
        {13, 48, 0},{13, 51, 0},{13, 55, 0},{13, 58, 0},{13, 61, 0},{13, 64, 0},
        {13, 66, 0},{13, 69, 0},{13, 72, 0},{13, 75, 0},{13, 78, 0},{13, 81, 0},
        {13, 84, 0},{13, 86, 0},{13, 89, 0},{13, 92, 0},{13, 95, 0},{13, 99, 0},
        {13, 102, 0},{13, 105, 0},{13, 108, 0},{16, 42, 0},{16, 55, 0},{16, 64, 0},
        {16, 86, 0},{16, 95, 0},{16, 108, 0},{19, 42, 0},{19, 45, 0},{19, 48, 0},
        {19, 52, 0},{19, 55, 0},{19, 64, 0},{19, 69, 0},{19, 81, 0},{19, 86, 0},
        {19, 95, 0},{19, 98, 0},{19, 102, 0},{19, 105, 0},{19, 108, 0},{22, 55, 0},
        {22, 69, 0},{22, 81, 0},{22, 95, 0},{25, 55, 0},{25, 64, 0},{25, 67, 0},
        {25, 70, 0},{25, 73, 0},{25, 77, 0},{25, 80, 0},{25, 83, 0},{25, 86, 0},
        {25, 95, 0},{28, 55, 0},{28, 64, 0},{28, 86, 0},{28, 95, 0},{30, 55, 0},
        {30, 58, 0},{30, 61, 0},{30, 64, 0},{30, 86, 0},{30, 89, 0},{30, 92, 0},
        {30, 95, 0},{32, 55, 0},{32, 64, 0},{32, 86, 0},{32, 95, 0},{35, 55, 0},
        {35, 64, 0},{35, 67, 0},{35, 70, 0},{35, 73, 0},{35, 77, 0},{35, 80, 0},
        {35, 83, 0},{35, 86, 0},{35, 95, 0},{39, 42, 0},{39, 45, 0},{39, 48, 0},
        {39, 51, 0},{39, 55, 0},{39, 58, 0},{39, 61, 0},{39, 64, 0},{39, 67, 0},
        {39, 70, 0},{39, 80, 0},{39, 83, 0},{39, 86, 0},{39, 89, 0},{39, 92, 0},
        {39, 95, 0},{39, 99, 0},{39, 102, 0},{39, 105, 0},{39, 108, 0},{42, 42, 0},
        {42, 55, 0},{42, 70, 0},{42, 80, 0},{42, 95, 0},{42, 108, 0},{45, 42, 4},
        {45, 45, 0},{45, 49, 0},{45, 55, 0},{45, 58, 0},{45, 61, 0},{45, 64, 0},
        {45, 67, 0},{45, 70, 0},{45, 73, 0},{45, 77, 0},{45, 80, 0},{45, 83, 0},
        {45, 86, 0},{45, 89, 0},{45, 92, 0},{45, 95, 0},{45, 101, 0},{45, 105, 0},
        {45, 108, 4},{48, 49, 0},{48, 55, 0},{48, 64, 0},{48, 86, 0},{48, 95, 0},
        {48, 101, 0},{51, 42, 0},{51, 45, 0},{51, 48, 0},{51, 52, 0},{51, 55, 0},
        {51, 64, 0},{51, 67, 0},{51, 70, 0},{51, 80, 0},{51, 83, 0},{51, 86, 0},
        {51, 95, 0},{51, 98, 0},{51, 102, 0},{51, 105, 0},{51, 108, 0},{53, 42, 0},
        {53, 70, 0},{53, 80, 0},{53, 108, 0},{55, 42, 0},{55, 45, 0},{55, 48, 0},
        {55, 51, 0},{55, 54, 0},{55, 57, 0},{55, 60, 0},{55, 63, 0},{55, 66, 0},
        {55, 69, 0},{55, 72, 0},{55, 75, 0},{55, 78, 0},{55, 81, 0},{55, 84, 0},
        {55, 87, 0},{55, 90, 0},{55, 93, 0},{55, 96, 0},{55, 99, 0},{55, 102, 0},
        {55, 105, 0},{55, 108, 0}},
        {{4, 42, 0}, {4, 45, 0}, {4, 49, 0}, {4, 53, 0}, {4, 56, 0}, {4, 69, 0}, {4, 72, 0}, 
        {4, 75, 0}, {4, 78, 0}, {4, 81, 0}, {4, 94, 0}, {4, 97, 0}, {4, 101, 0}, {4, 105, 0}, 
        {4, 108, 0}, {7, 42, 4}, {7, 56, 0}, {7, 69, 0}, {7, 81, 0}, {7, 94, 0}, {7, 108, 4}, 
        {10, 42, 0}, {10, 45, 0}, {10, 49, 0}, {10, 53, 0}, {10, 56, 0}, {10, 69, 0}, {10, 81, 0}, 
        {10, 94, 0}, {10, 97, 0}, {10, 101, 0}, {10, 105, 0}, {10, 108, 0}, {13, 42, 0}, {13, 56, 0}, 
        {13, 59, 0}, {13, 63, 0}, {13, 66, 0}, {13, 69, 0}, {13, 81, 0}, {13, 84, 0}, {13, 88, 0}, 
        {13, 91, 0}, {13, 94, 0}, {13, 108, 0}, {16, 42, 0}, {16, 56, 0}, {16, 66, 0}, {16, 84, 0}, 
        {16, 94, 0}, {16, 108, 0}, {19, 42, 0}, {19, 45, 0}, {19, 49, 0}, {19, 53, 0}, {19, 56, 0}, 
        {19, 59, 0}, {19, 63, 0}, {19, 66, 0}, {19, 70, 0}, {19, 75, 0}, {19, 80, 0}, {19, 84, 0}, 
        {19, 88, 0}, {19, 91, 0}, {19, 94, 0}, {19, 97, 0}, {19, 101, 0}, {19, 105, 0}, {19, 108, 0}, 
        {22, 56, 0}, {22, 70, 0}, {22, 80, 0}, {22, 94, 0}, {25, 56, 0}, {25, 65, 0}, {25, 68, 0}, 
        {25, 71, 0}, {25, 75, 0}, {25, 79, 0}, {25, 82, 0}, {25, 85, 0}, {25, 94, 0}, {28, 56, 0}, 
        {28, 65, 0}, {28, 85, 0}, {28, 94, 0}, {30, 56, 0}, {30, 61, 0}, {30, 65, 0}, {30, 85, 0}, 
        {30, 89, 0}, {30, 94, 0}, {32, 56, 0}, {32, 65, 0}, {32, 85, 0}, {32, 94, 0}, {35, 56, 0}, 
        {35, 65, 0}, {35, 68, 0}, {35, 71, 0}, {35, 75, 0}, {35, 79, 0}, {35, 82, 0}, {35, 85, 0}, 
        {35, 94, 0}, {39, 42, 0}, {39, 45, 0}, {39, 48, 0}, {39, 52, 0}, {39, 56, 0}, {39, 60, 0}, 
        {39, 64, 0}, {39, 67, 0}, {39, 70, 0}, {39, 75, 0}, {39, 80, 0}, {39, 83, 0}, {39, 86, 0}, 
        {39, 90, 0}, {39, 94, 0}, {39, 98, 0}, {39, 102, 0}, {39, 105, 0}, {39, 108, 0}, {42, 42, 0}, 
        {42, 56, 0}, {42, 70, 0}, {42, 75, 0}, {42, 80, 0}, {42, 94, 0}, {42, 108, 0}, {45, 42, 4}, 
        {45, 45, 0}, {45, 49, 0}, {45, 56, 0}, {45, 60, 0}, {45, 64, 0}, {45, 67, 0}, {45, 70, 0}, 
        {45, 80, 0}, {45, 83, 0}, {45, 86, 0}, {45, 90, 0}, {45, 94, 0}, {45, 101, 0}, {45, 105, 0}, 
        {45, 108, 4}, {48, 49, 0}, {48, 64, 0}, {48, 86, 0}, {48, 101, 0}, {51, 42, 0}, {51, 45, 0}, 
        {51, 49, 0}, {51, 64, 0}, {51, 67, 0}, {51, 70, 0}, {51, 80, 0}, {51, 83, 0}, {51, 86, 0}, 
        {51, 101, 0}, {51, 105, 0}, {51, 108, 0}, {53, 42, 0}, {53, 70, 0}, {53, 80, 0}, {53, 108, 0}, 
        {55, 42, 0}, {55, 45, 0}, {55, 48, 0}, {55, 51, 0}, {55, 54, 0}, {55, 57, 0}, {55, 60, 0}, 
        {55, 63, 0}, {55, 66, 0}, {55, 70, 0}, {55, 73, 0}, {55, 77, 0}, {55, 80, 0}, {55, 84, 0}, 
        {55, 87, 0}, {55, 90, 0}, {55, 93, 0}, {55, 96, 0}, {55, 99, 0}, {55, 102, 0}, {55, 105, 0}, {55, 108, 0}}
    };

    //variabili per lettura dal buffer e posizioni di partenza dei fantasmi
    BufferElement *node;
    Pos entita, fantasmi[NUM_FANTASMI];
    PosStart posPacmanSpawn, posGhostSpawn, posPartenza, posPartenza_SU, posPartenza_GIU, posPartenza_DESTRA, posPartenza_SINISTRA;

    posPacmanSpawn.posizione.x = 45;
    posPacmanSpawn.posizione.y = 29;
    posPacmanSpawn.dati = dati;
    posPacmanSpawn.collisioni = collisioni;

    posGhostSpawn.posizione.x = 74;
    posGhostSpawn.posizione.y = 29;
    posGhostSpawn.dati = dati;
    posGhostSpawn.collisioni = collisioni;

    posPartenza.dati = dati;
    posPartenza_SU.dati = dati;
    posPartenza_GIU.dati = dati;
    posPartenza_DESTRA.dati = dati;
    posPartenza_SINISTRA.dati = dati;
    posPartenza.collisioni = collisioni;
    posPartenza_SU.collisioni = collisioni;
    posPartenza_GIU.collisioni = collisioni;
    posPartenza_DESTRA.collisioni = collisioni;
    posPartenza_SINISTRA.collisioni = collisioni;

    //copie in locale dei personaggi e rispettivi proiettili
    Par personaggi[NUM_PERSONAGGI];
    startCharacter(personaggi);
    Pos proiettili[NUM_PERSONAGGI][MAX_PROIETTILI];
    startBullet(MAX_PROIETTILI, proiettili);
    

    _Bool collisioneXdestra, collisioneXsinistra, collisioneYsu, collisioneYgiu;

    while(livello<2) {
        livello =1;
        //pronti partenza via
        usleep(500);

        //stampa del campo e partenza cronometro
        printCampo(livello);
        start = clock();

        //inizializzazione ed estrazione fantasmi
        startGhost(livello, numPallini[livello], 3, pallini, fantasmi);
        for(int i=0; i<NUM_FANTASMI; i++) {
            personaggi[i+1].posizione = fantasmi[i];
            personaggi[i+1].vite = 0;
            personaggi[i+1].colpiSubiti = 0;
        }

        //estrazione del frutto
        do {
            frutto = randRange(0, numPallini[livello]-1);

            flagFrutta = true;
            for(int i=0; i<NUM_FANTASMI; i++){
                if(fantasmi[i+1].y == pallini[livello][frutto][0] && fantasmi[i+1].x == pallini[livello][frutto][1])
                    flagFrutta = false;
            }
        } while(!flagFrutta);
        pallini[livello][frutto][2] = 2;
        attron(COLOR_PAIR(12));
        mvprintw(pallini[livello][frutto][0], pallini[livello][frutto][1], "Y");
        attroff(COLOR_PAIR(12));

        //messe le powerpills
        mvprintw(7, 42, "0");
        mvprintw(7, 108, "0");
        mvprintw(45, 42, "0");
        mvprintw(45, 108, "0");

        #if CHEATS == 1
            attron(COLOR_PAIR(3));
            mvprintw(fantasmi[0].y+1, fantasmi[0].x+1, "G");
            attroff(COLOR_PAIR(3));

            attron(COLOR_PAIR(8));
            mvprintw(fantasmi[1].y+1, fantasmi[1].x+1, "G");
            attroff(COLOR_PAIR(8));

            attron(COLOR_PAIR(9));
            mvprintw(fantasmi[2].y+1, fantasmi[2].x+1, "G");
            attroff(COLOR_PAIR(9));

            attron(COLOR_PAIR(7));
            mvprintw(fantasmi[3].y+1, fantasmi[3].x+1, "G");
            attroff(COLOR_PAIR(7));
        #endif

        posPacmanSpawn.lv = livello;
        posGhostSpawn.lv = livello;
        posPartenza.lv = livello;
        posPartenza_SU.lv = livello;
        posPartenza_GIU.lv = livello;
        posPartenza_DESTRA.lv = livello;
        posPartenza_SINISTRA.lv = livello;
        pthread_create(&(personaggi[PACMAN].posizione.id), NULL, &pacman, (void*)&posPacmanSpawn);

        while(personaggi[PACMAN].vite > 0 && scorePallini < maxScore[livello]) {

            node = removeBuffer(dati);

            if(node != NULL) {

                entita = node->posizione;

                //pulisce sempre la vecchia posizione
                if(entita.entita != BULLET){
                    mvprintw(personaggi[entita.entita].posizione.y,personaggi[entita.entita].posizione.x, "%s", "   ");
                    mvprintw(personaggi[entita.entita].posizione.y+1,personaggi[entita.entita].posizione.x, "%s", "   ");
                    mvprintw(personaggi[entita.entita].posizione.y+2,personaggi[entita.entita].posizione.x, "%s", "   ");
                    mvprintw(entita.y,entita.x, "%s", "   ");
                    mvprintw(entita.y+1,entita.x, "%s", "   ");
                    mvprintw(entita.y+2,entita.x, "%s", "   ");
                    clearEntity(personaggi[entita.entita].posizione, mutexTerminale, livello, numPallini[livello], 3, pallini);

                    mvprintw(43,160, "%s", "Cancello");
                }else{
                    
                    for(int i=0; i<numPallini[livello]; i++){
                        if(entita.y == pallini[livello][i][0] && entita.x == pallini[livello][i][1] && pallini[livello][i][2] == 0){
                                entita.sparo = false;
                                pthread_cancel(entita.id);
                        } 
                    }

                    for(int i = 0; i<NUM_PERSONAGGI; i++){
                        for(int j=0; j<MAX_PROIETTILI; j++){
                            if(entita.id == proiettili[i][j].id)
                                mvprintw(proiettili[i][j].y,proiettili[i][j].x, "%s", " ");
                        }
                    }
                }
                    
                
                //stampa solo se è un personaggio oppure un proiettile ancora in vita (motivo del controllo)
                if(!(entita.entita == BULLET && entita.sparo == false)) {
                    mvprintw(personaggi[entita.entita].posizione.y,personaggi[entita.entita].posizione.x, "%s", "   ");
                    mvprintw(personaggi[entita.entita].posizione.y+1,personaggi[entita.entita].posizione.x, "%s", "   ");
                    mvprintw(personaggi[entita.entita].posizione.y+2,personaggi[entita.entita].posizione.x, "%s", "   ");
                    printEntity(entita, mutexTerminale, flagPower);
                }

                //backup delle posizioni in locale
                if(entita.entita < NUM_PERSONAGGI)
                    personaggi[entita.entita].posizione = entita;
                else
                    for(int i = 0; i<NUM_PERSONAGGI ; i++)
                        for(int j = 0; j<MAX_PROIETTILI; j++)
                            if(proiettili[i][j].id == entita.id)
                                proiettili[i][j] = entita;
                
                //check collisioni tra fantasmi e pacman
                if(entita.entita > PACMAN && entita.entita < NUM_PERSONAGGI) {
                    collisioneXdestra = entita.x == personaggi[PACMAN].posizione.x || entita.x == personaggi[PACMAN].posizione.x+1 || entita.x == personaggi[PACMAN].posizione.x+2;
                    collisioneXsinistra = entita.x == personaggi[PACMAN].posizione.x || entita.x+1 == personaggi[PACMAN].posizione.x || entita.x+2 == personaggi[PACMAN].posizione.x;
                    collisioneYsu = entita.y == personaggi[PACMAN].posizione.y || entita.y == personaggi[PACMAN].posizione.y-1 || entita.y == personaggi[PACMAN].posizione.y-2;
                    collisioneYgiu = entita.y == personaggi[PACMAN].posizione.y || entita.y-1 == personaggi[PACMAN].posizione.y || entita.y-2 == personaggi[PACMAN].posizione.y;
                    if((collisioneXdestra || collisioneXsinistra) && (collisioneYgiu || collisioneYsu) && !flagPower) {

                        //uccido pacman
                        pthread_cancel(personaggi[PACMAN].posizione.id);

                        //getto il corpo nel fiume
                        personaggi[PACMAN].posizione.x = 160;
                        personaggi[PACMAN].posizione.y = 30;
                        personaggi[PACMAN].posizione.dir = FERMO;

                        //nascondo le prove
                        attron(COLOR_PAIR(11));
                        mvprintw(personaggi[PACMAN].posizione.y,personaggi[entita.entita].posizione.x, "%s", "   ");
                        mvprintw(personaggi[PACMAN].posizione.y+1,personaggi[entita.entita].posizione.x, "%s", "   ");
                        mvprintw(personaggi[PACMAN].posizione.y+2,personaggi[entita.entita].posizione.x, "%s", "   ");
                        attroff(COLOR_PAIR(11));

                        //respawn di pacman
                        pthread_create(&(personaggi[PACMAN].posizione.id), NULL, &pacman, (void*)&posPacmanSpawn);
                        personaggi[PACMAN].vite--;
                        personaggi[PACMAN].colpiSubiti = 0;

                        attron(COLOR_PAIR(4));
                        for(int i=0; i<152; i++)
                            if(Campo[livello][32][i] == '#')
                                mvprintw(32, i, "#");
                        attroff(COLOR_PAIR(4));
                    }

                    if((collisioneXdestra || collisioneXsinistra) && (collisioneYgiu || collisioneYsu) && flagPower) {

                        //uccido fantasma
                        pthread_cancel(entita.id);

                        //getto l'ectoplasma nel fiume
                        entita.x = 170;
                        entita.y = 30;
                        entita.dir = FERMO;

                        //respawn fantasma
                        posGhostSpawn.posizione.entita = entita.entita;
                        personaggi[entita.entita].colpiSubiti = 0;
                        personaggi[entita.entita].vite--;
                        pthread_create(&(personaggi[entita.entita].posizione.id), NULL, &ghost, (void*)&posGhostSpawn);
                        scoreFantasmi += 200;

                        attron(COLOR_PAIR(4));
                        for(int i=0; i<152; i++)
                            if(Campo[livello][32][i] == '#')
                                mvprintw(32, i, "#");
                        attroff(COLOR_PAIR(4));
                    }
                }

                //bump fantasmi
                if(entita.entita != PACMAN) {
                    for(int i=1; i<NUM_PERSONAGGI; i++) {
                        if(entita.entita != personaggi[i].posizione.entita) {
                            collisioneXdestra = entita.x == personaggi[i].posizione.x || entita.x == personaggi[i].posizione.x+1 || entita.x == personaggi[i].posizione.x+2;
                            collisioneXsinistra = entita.x == personaggi[i].posizione.x || entita.x+1 == personaggi[i].posizione.x || entita.x+2 == personaggi[i].posizione.x;
                            collisioneYsu = entita.y == personaggi[i].posizione.y || entita.y == personaggi[i].posizione.y-1 || entita.y == personaggi[i].posizione.y-2;
                            collisioneYgiu = entita.y == personaggi[i].posizione.y || entita.y-1 == personaggi[i].posizione.y || entita.y-2 == personaggi[i].posizione.y;
                            if((collisioneXdestra || collisioneXsinistra) && (collisioneYgiu || collisioneYsu)) {
                                collisioni[i-1] = true;
                                collisioni[entita.entita-1] = true;
                            }
                        }
                    }
                }

                //collisioni proiettili personaggi
                if(entita.entita == BULLET){
                    for(int i=0; i<NUM_PERSONAGGI; i++){
                        collisioneXdestra = entita.x == personaggi[i].posizione.x || entita.x == personaggi[i].posizione.x+1 || entita.x == personaggi[i].posizione.x+2;
                        collisioneXsinistra = entita.x == personaggi[i].posizione.x || entita.x+1 == personaggi[i].posizione.x || entita.x+2 == personaggi[i].posizione.x;
                        collisioneYsu = entita.y == personaggi[i].posizione.y || entita.y == personaggi[i].posizione.y-1 /*|| entita.y == personaggi[i].posizione.y-2*/;
                        collisioneYgiu = entita.y == personaggi[i].posizione.y || entita.y-1 == personaggi[i].posizione.y /*|| entita.y-2 == personaggi[i].posizione.y*/;
                        if((collisioneXdestra || collisioneXsinistra) && (collisioneYgiu || collisioneYsu)) {

                            //giustiziamo il proiettile
                            pthread_cancel(entita.id);
                            mvprintw(entita.y,entita.x, "%s", " ");
                            for(int i = 0; i<NUM_PERSONAGGI ; i++)
                                for(int j = 0; j<MAX_PROIETTILI; j++)
                                    if(proiettili[i][j].id == entita.id)
                                        proiettili[i][j].sparo = false;

                            //multiamo il personaggio
                            personaggi[i].colpiSubiti++;

                            #if CHEATS == 1 //aimbot
                            if(personaggi[i].posizione.entita > PACMAN && personaggi[i].posizione.entita < BULLET)
                                personaggi[i].colpiSubiti+=9;
                            #endif


                            if(personaggi[i].colpiSubiti == 10) {
                                personaggi[i].vite--;
                                pthread_cancel(personaggi[i].posizione.id);

                                if(personaggi[i].posizione.entita == PACMAN && personaggi[i].vite > 0) {
                                    personaggi[PACMAN].colpiSubiti = 0;
                                    pthread_create(&(personaggi[PACMAN].posizione.id), NULL, &pacman, (void*)&posPacmanSpawn);
                                }
                                if(personaggi[i].posizione.entita > PACMAN && personaggi[i].posizione.entita < BULLET && personaggi[i].vite > 0) {
                                    posGhostSpawn.posizione.entita = personaggi[i].posizione.entita;
                                    personaggi[i].colpiSubiti = 0;
                                    pthread_create(&(personaggi[personaggi[i].posizione.entita].posizione.id), NULL, &ghost, (void*)&posGhostSpawn);
                                    scoreFantasmi += 100;
                                }

                            }
                        }
                    }

                    /*if(scampo[livello][]){
                        //giustiziamo il proiettile
                            entita.sparo =false;
                            pthread_cancel(entita.id);
                            mvprintw(entita.y,entita.x, "%s", " ");
                            for(int i = 0; i<NUM_PERSONAGGI ; i++)
                                for(int j = 0; j<MAX_PROIETTILI; j++)
                                    if(proiettili[i][j].id == entita.id)
                                        proiettili[i][j].sparo = false;
                    }*/
                }

                if(checkPower(personaggi[PACMAN].posizione.x, personaggi[PACMAN].posizione.y, livello, numPallini[livello], 3, pallini)) {
                    flagPower = true;
                    clockPower = clock();
                }
                end = clock();
                deltaPower = ((double) (end-clockPower))/CLOCKS_PER_SEC;
                if(flagPower && deltaPower > 8)
                    flagPower = false;
                
                
                scoreAux = checkScore(personaggi[PACMAN].posizione.x, personaggi[PACMAN].posizione.y, livello, numPallini[livello], 3, pallini);
                if(scoreAux > 0)
                    scorePallini += 10;
                if(scoreAux == 50)
                    scoreFrutta += 40;

                scoreLivello = scoreFantasmi+scoreFrutta+scorePallini;

                //spawn fantasmi
                for(int i=0; i< NUM_FANTASMI; i++){
                    if(fantasmi[i].x == personaggi[PACMAN].posizione.x && fantasmi[i].y == personaggi[PACMAN].posizione.y && personaggi[i+1].vite == 0) {
                        personaggi[i+1].vite = 5;
                        posPartenza.posizione = personaggi[i+1].posizione;
                        pthread_create(&(personaggi[i+1].posizione.id), NULL, &ghost, (void*)&posPartenza);
                    }
                }

                //se un entità ha sparato
                if(entita.entita < NUM_PERSONAGGI && entita.sparo) {
                    if(canShoot(proiettili, entita.entita)) {
                        if(bulletMv(entita.x+1, entita.y, SU, livello)) {
                            proiettili[entita.entita][SU-SHIFT_MOVIMENTO].x = entita.x+1;
                            proiettili[entita.entita][SU-SHIFT_MOVIMENTO].y = entita.y-1;
                            proiettili[entita.entita][SU-SHIFT_MOVIMENTO].sparo = true;
                            posPartenza_SU.posizione = proiettili[entita.entita][SU-SHIFT_MOVIMENTO];
                            pthread_create(&(proiettili[entita.entita][SU-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_SU);
                        }
                        if(bulletMv(entita.x+1, entita.y+2, GIU, livello)) {
                            proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].x = entita.x+1;
                            proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].y = entita.y+3;
                            proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].sparo = true;
                            posPartenza_GIU.posizione = proiettili[entita.entita][GIU-SHIFT_MOVIMENTO];
                            pthread_create(&(proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_GIU);
                        }
                        if(bulletMv(entita.x+2, entita.y+1, DESTRA, livello)) {
                            proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].x = entita.x+3;
                            proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].y = entita.y+1;
                            proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].sparo = true;
                            posPartenza_DESTRA.posizione = proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO];
                            pthread_create(&(proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_DESTRA);
                        }
                        if(bulletMv(entita.x, entita.y+1, SINISTRA, livello)) {
                            proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].x = entita.x-2;
                            proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].y = entita.y+1;
                            proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].sparo = true;
                            posPartenza_SINISTRA.posizione = proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO];
                            pthread_create(&(proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_SINISTRA);
                        }
                    }
                    
                }


        
            }

            end = clock();
            deltaTime = ((double) (end-start))/CLOCKS_PER_SEC;
            mvprintw(3, 160, "Tempo: %f", deltaTime);

            printStats(livello, scoreLivello, personaggi[PACMAN], deltaTime, highscore, scoreTotale);
            

            #if DEBUG == 1

                
                
                ciclo++;
                mvprintw(2, 160, "Cicli per secondo: %f", ciclo/deltaTime);

                mvprintw(5, 160, "PACMAN [0]");
                mvprintw(6, 160, "X: %d  \t Y: %d  ", personaggi[PACMAN].posizione.x, personaggi[PACMAN].posizione.y);
                mvprintw(7, 160, "Sparo: %d, ID: %d, Vite: %d, Colpi Subiti: %d", personaggi[PACMAN].posizione.sparo, personaggi[PACMAN].posizione.id, personaggi[PACMAN].vite, personaggi[PACMAN].colpiSubiti);

                
                mvprintw(9, 160, "BULLET [SU]");
                mvprintw(10, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][SU-SHIFT_MOVIMENTO].x, proiettili[PACMAN][SU-SHIFT_MOVIMENTO].y);
                mvprintw(11, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][SU-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][SU-SHIFT_MOVIMENTO].id);
                if(entita.entita == BULLET && entita.dir == SU)
                    mvprintw(9, 180, "MORTO %d", ciclo);


                mvprintw(13, 160, "BULLET [GIU]");
                mvprintw(14, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].x, proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].y);
                mvprintw(15, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].id);
                if(entita.entita == BULLET && entita.dir == GIU)
                    mvprintw(13, 180, "MORTO %d", ciclo);


                mvprintw(17, 160, "BULLET [DESTRA]");
                mvprintw(18, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].x, proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].y);
                mvprintw(19, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].id);
                if(entita.entita == BULLET && entita.dir == DESTRA)
                    mvprintw(17, 180, "MORTO %d", ciclo);


                mvprintw(21, 160, "BULLET [SINISTRA]");
                mvprintw(22, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].x, proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].y);
                mvprintw(23, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].id);
                if(entita.entita == BULLET && entita.dir == SINISTRA)
                    mvprintw(21, 180, "MORTO %d", ciclo);

                
                mvprintw(25, 160, "BLINKY [1]");
                mvprintw(26, 160, "X: %d  \t Y: %d  ", personaggi[BLINKY].posizione.x, personaggi[BLINKY].posizione.y);
                mvprintw(27, 160, "Sparo: %d, ID: %d, Vite: %d, Colpi Subiti: %d", personaggi[BLINKY].posizione.sparo, personaggi[BLINKY].posizione.id, personaggi[BLINKY].vite, personaggi[BLINKY].colpiSubiti);
            


                mvprintw(29, 160, "PINKY [2]");
                mvprintw(30, 160, "X: %d  \t Y: %d  ", personaggi[PINKY].posizione.x, personaggi[PINKY].posizione.y);
                mvprintw(31, 160, "Sparo: %d, ID: %d, Vite: %d, Colpi Subiti: %d", personaggi[PINKY].posizione.sparo, personaggi[PINKY].posizione.id, personaggi[PINKY].vite, personaggi[PINKY].colpiSubiti);
            

            
                mvprintw(33, 160, "CLYDE [3]");
                mvprintw(34, 160, "X: %d  \t Y: %d  ", personaggi[CLYDE].posizione.x, personaggi[CLYDE].posizione.y);
                mvprintw(35, 160, "Sparo: %d, ID: %d, Vite: %d, Colpi Subiti: %d", personaggi[CLYDE].posizione.sparo, personaggi[CLYDE].posizione.id, personaggi[CLYDE].vite, personaggi[CLYDE].colpiSubiti);
            

            
                mvprintw(37, 160, "INKY [4]");
                mvprintw(38, 160, "X: %d  \t Y: %d  ", personaggi[INKY].posizione.x, personaggi[INKY].posizione.y);
                mvprintw(39, 160, "Sparo: %d, ID: %d, Vite: %d, Colpi Subiti: %d", personaggi[INKY].posizione.sparo, personaggi[INKY].posizione.id, personaggi[INKY].vite, personaggi[INKY].colpiSubiti);

                /*
                if(node != NULL)
                    mvprintw(29 + (ciclo % 47), 160, "%d : %s", ciclo, EntityName[node->posizione.entita]);
                else
                    mvprintw(29 + (ciclo % 47), 160, "%d : NULL     ", ciclo);
                */

            #endif

            //se vuoi ridere togli la refresh (anche se vuoi piangere)
            //refresh();

        }
        for(int i=0; i< NUM_PERSONAGGI; i++)
            pthread_cancel(personaggi[i].posizione.id);
        nodelay(stdscr, FALSE);

        scoreTotale += scoreLivello;

        if(scoreLivello >= 2000)
            personaggi[PACMAN].vite++;

        scoreLivello = 0;
        scorePallini = 0;
        scoreFantasmi = 0;
        scoreFrutta = 0;
        livello++;

        printLevelComplete();
        while(getch()!= '\n'){}
    }

    //bonus tempo
    scoreTotale+=(scoreTotale/deltaTime)*175;

    return scoreTotale;
}
