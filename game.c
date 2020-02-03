#include "game.h"

/** --- STAMPA DEL MENU ------------------------------------------------------------- **/

//gestione del menu
int mainMenu() {
    int menu = 0;
    char selMenu;

    do {

        switch(menu) {
            case NEWGAME:
                printNewGame();
                break;
            case EXIT:
                printExit();
                break;
            case SUGA:
                printSUGA();
                break;
        }

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
void printNewGame() {

    char newGame[60][152] = {"##==================================================================================================================================================##\n",
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
                             "##==================================================================================================================================================##"};

    attron(COLOR_PAIR(1));
    for(int i=0; i<=49; i++)
        mvprintw(i, 0, "%s", newGame[i]);

}

//stampa della schermata Esci
void printExit() {

    char newGame[60][152] = {"##==================================================================================================================================================##\n",
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
                             "##==================================================================================================================================================##"};

    attron(COLOR_PAIR(1));
    for(int i=0; i<=49; i++)
        mvprintw(i, 0, "%s", newGame[i]);

}

//Stampa della schermata Selezione Progetto
void printSUGA() {

    char newGame[60][152] = {"##==================================================================================================================================================##\n",
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
                             "##==================================================================================================================================================##"};

    attron(COLOR_PAIR(1));
    for(int i=0; i<=49; i++)
        mvprintw(i, 0, "%s", newGame[i]);

}


/** --- STAMPA DEL GIOCO ------------------------------------------------------------ **/

//stampa del gioco
void printCampo(int level){
    pthread_mutex_lock(mutexTerminale);

    attron(COLOR_PAIR(1));
    for (int i=0; i<=59; i++){
        for(int j=0; j<=151; j++){
            if(Campo[i][j] == '#' && (j> 2 && j< 145)){
                attron(COLOR_PAIR(4));
                mvprintw(i,j, "%c", Campo[i][j]);
                attroff(COLOR_PAIR(4));
            }else{
                mvprintw(i,j,"%c", Campo[i][j]);
            }
        }
    }

    pthread_mutex_unlock(mutexTerminale);
}

void printStats(int livello, int score){
    pthread_mutex_lock(mutexTerminale);

    //stampo livello
    mvprintw(5, 18, "%d", livello);
    //stampo score
    mvprintw(6, 18, "%d", score);

    pthread_mutex_unlock(mutexTerminale);
}

void printDot(int num, int pallini[][num]){
    pthread_mutex_lock(mutexTerminale);

    for(int i; i<NUM_PALLINI; i++){
        if(pallini[i][2]==0){
            mvprintw(pallini[i][0], pallini[i][1], "%c", '.');
        }
    }

    pthread_mutex_unlock(mutexTerminale);;
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

/** --- CONTROLLI DI GIOCO ---------------------------------------------------------- **/
_Bool canShoot(Pos proiettili[][MAX_PROIETTILI], Entity entita) {
    return !proiettili[entita][SU-SHIFT_MOVIMENTO].sparo && !proiettili[entita][GIU-SHIFT_MOVIMENTO].sparo && !proiettili[entita][DESTRA-SHIFT_MOVIMENTO].sparo && !proiettili[entita][SINISTRA-SHIFT_MOVIMENTO].sparo;
}

int checkScore(int x, int y, int num, int pallini[][num]){
    for (int i; i<NUM_PALLINI; i++){
        if(pallini[i][0] == y+1)
            if(pallini[i][1] == x+1)
                if(pallini[i][2] == 0){
                    pallini[i][2] = 1;
                    return 10;
                }
    }
    return 0;
}

_Bool bulletMv(int x, int y, char dir) {

    switch (dir) {
        case SU:
            if(scampo[y-1][x] == '#' )
                return false;
            break;
        case GIU:
            if(scampo[y+1][x] == '#' )
                return false;
            break;
        case DESTRA:
            if(scampo[y][x+1] == '#' )
                return false;
            break;
        case SINISTRA:
            if(scampo[y][x-1] == '#' )
                return false;
            break;
        default:
            return false;
    }
    
    return true;
}

/** --- ENTITÀ GENERALI ------------------------------------------------------------- **/
void * bullet(void * param) {
    PosStart *start = (PosStart*) param;
    Pos posIniziale = start -> posizione;
    Buffer* buffer = start -> buffer;

    Pos posBullet;
    posBullet.x = posIniziale.x;
    posBullet.y = posIniziale.y;
    posBullet.dir = posIniziale.dir;
    posBullet.sparo = true;
    posBullet.entita = BULLET;
    posBullet.id = pthread_self();

    //Movimento bullet
    while(bulletMv(posBullet.x, posBullet.y, posBullet.dir)) {

        mvprintw(posBullet.y+1, posBullet.x+1, " ");

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

        pthread_mutex_lock(mutexTerminale);
        mvprintw(posBullet.y+1, posBullet.x+1, "o");
        pthread_mutex_unlock(mutexTerminale);

        insertBuffer(buffer, mutexDati, posBullet);
        usleep(200000);
    }

    posBullet.sparo = false;
    insertBuffer(buffer,mutexDati,posBullet);
    pthread_exit(NULL);
}

/** --- GIOCO ----------------------------------------------------------------------- **/
void gameController(int livello, Buffer *buffer){

    int score = 0;

    int ciclo = 0;
    clock_t start, end;
    double deltaTime;

    Pos entita, fantasmi[NUM_FANTASMI];
    PosStart posPartenza, posPartenza_SU, posPartenza_GIU, posPartenza_DESTRA, posPartenza_SINISTRA;
    posPartenza.buffer = buffer;
    posPartenza_SU.buffer = buffer;
    posPartenza_GIU.buffer = buffer;
    posPartenza_DESTRA.buffer = buffer;
    posPartenza_SINISTRA.buffer = buffer;

    Par personaggi[NUM_PERSONAGGI];
    startCharacter(personaggi);
    Pos proiettili[NUM_PERSONAGGI][MAX_PROIETTILI];
    startBullet(MAX_PROIETTILI, proiettili);

    BufferElement *node;

    usleep(500);

    printCampo(livello);
    start = clock();
    //refresh();

    startGhost(3, pallini, fantasmi);
    for(int i=0; i<NUM_FANTASMI; i++) {
        personaggi[i+1].posizione = fantasmi[i];
        personaggi[i+1].vite = 0;
        personaggi[i+1].colpiSubiti = 0;
    }

    while(personaggi[PACMAN].vite > 0) {

        node = removeBuffer(buffer);

        if(node != NULL) {

            entita = node->posizione;
 
            //backup delle posizioni in locale
            if(entita.entita < NUM_PERSONAGGI)
                personaggi[entita.entita].posizione = entita;
            else
                for(int i = 0; i<NUM_PERSONAGGI ; i++)
                    for(int j = 0; j<MAX_PROIETTILI; j++)
                        if(proiettili[i][j].id == entita.id)
                            proiettili[i][j] = entita;
        
            score += checkScore(personaggi[PACMAN].posizione.x, personaggi[PACMAN].posizione.y, 3, pallini);

            for(int i=0; i< NUM_FANTASMI; i++){
                if(fantasmi[i].x == personaggi[PACMAN].posizione.x && fantasmi[i].y == personaggi[PACMAN].posizione.y && personaggi[i+1].vite == 0) {
                    personaggi[i+1].vite = 1;
                    posPartenza.posizione = personaggi[i+1].posizione;
                    pthread_create(&(personaggi[i+1].posizione.id), NULL, &ghost, (void*)&posPartenza);
                }
                    
            }

            //se un entità ha sparato
            if(entita.entita < NUM_PERSONAGGI && entita.sparo) {
                if(canShoot(proiettili, entita.entita)) {
                    if(entityMv(entita.x, entita.y, SU)) {
                        proiettili[entita.entita][SU-SHIFT_MOVIMENTO].x = entita.x+1;
                        proiettili[entita.entita][SU-SHIFT_MOVIMENTO].y = entita.y-1;
                        proiettili[entita.entita][SU-SHIFT_MOVIMENTO].sparo = true;
                        posPartenza_SU.posizione = proiettili[entita.entita][SU-SHIFT_MOVIMENTO];
                        pthread_create(&(proiettili[entita.entita][SU-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_SU);
                    }
                    if(entityMv(entita.x, entita.y, GIU)) {
                        proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].x = entita.x+1;
                        proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].y = entita.y-3;
                        proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].sparo = true;
                        posPartenza_GIU.posizione = proiettili[entita.entita][GIU-SHIFT_MOVIMENTO];
                        pthread_create(&(proiettili[entita.entita][GIU-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_GIU);
                    }
                    if(entityMv(entita.x, entita.y, DESTRA)) {
                        proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].x = entita.x+3;
                        proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].y = entita.y+1;
                        proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].sparo = true;
                        posPartenza_DESTRA.posizione = proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO];
                        pthread_create(&(proiettili[entita.entita][DESTRA-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_DESTRA);
                    }
                    if(entityMv(entita.x, entita.y, SINISTRA)) {
                        proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].x = entita.x-1;
                        proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].y = entita.y+1;
                        proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].sparo = true;
                        posPartenza_SINISTRA.posizione = proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO];
                        pthread_create(&(proiettili[entita.entita][SINISTRA-SHIFT_MOVIMENTO].id), NULL, &bullet, (void*)&posPartenza_SINISTRA);
                    }
                }
                
            }
    
        }

        printStats(livello, score);

        #if DEBUG == 1

        pthread_mutex_lock(mutexTerminale);

        end = clock();
        deltaTime = ((double) (end-start))/CLOCKS_PER_SEC;
        mvprintw(3, 160, "Tempo: %f", deltaTime);
        
        ciclo++;
        mvprintw(2, 160, "Cicli per secondo: %f", ciclo/deltaTime);

        if(entita.entita == PACMAN) {
            mvprintw(5, 160, "PACMAN [0]");
            mvprintw(6, 160, "X: %d  \t Y: %d  ", entita.x, entita.y);
            mvprintw(7, 160, "Sparo: %d, ID: %d", entita.sparo, entita.id);
        }
        
        mvprintw(9, 160, "BULLET [SU]");
        mvprintw(10, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][SU-SHIFT_MOVIMENTO].x, proiettili[PACMAN][SU-SHIFT_MOVIMENTO].y);
        mvprintw(11, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][SU-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][SU-SHIFT_MOVIMENTO].id);
        if(entita.entita == BULLET && entita.dir == SU)
            mvprintw(9, 172, "SPARATO al ciclo %d", ciclo);


        mvprintw(13, 160, "BULLET [GIU]");
        mvprintw(14, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].x, proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].y);
        mvprintw(15, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][GIU-SHIFT_MOVIMENTO].id);
        if(entita.entita == BULLET && entita.dir == GIU)
            mvprintw(13, 172, "SPARATO al ciclo %d", ciclo);


        mvprintw(17, 160, "BULLET [DESTRA]");
        mvprintw(18, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].x, proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].y);
        mvprintw(19, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][DESTRA-SHIFT_MOVIMENTO].id);
        if(entita.entita == BULLET && entita.dir == DESTRA)
            mvprintw(17, 172, "SPARATO al ciclo %d", ciclo);


        mvprintw(21, 160, "BULLET [SINISTRA]");
        mvprintw(22, 160, "X: %d  \t Y: %d  ", proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].x, proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].y);
        mvprintw(23, 160, "Sparo: %d, ID: %d", proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].sparo, proiettili[PACMAN][SINISTRA-SHIFT_MOVIMENTO].id);
        if(entita.entita == BULLET && entita.dir == SINISTRA)
            mvprintw(21, 172, "SPARATO al ciclo %d", ciclo);

        
        mvprintw(25, 160, "BLINKY [1]");
        mvprintw(26, 160, "X: %d  \t Y: %d  ", personaggi[BLINKY].posizione.x, personaggi[BLINKY].posizione.y);
        mvprintw(27, 160, "Sparo: %d, ID: %d", personaggi[BLINKY].posizione.sparo, personaggi[BLINKY].posizione.id);
    


        mvprintw(29, 160, "PINKY [2]");
        mvprintw(30, 160, "X: %d  \t Y: %d  ", personaggi[PINKY].posizione.x, personaggi[PINKY].posizione.y);
        mvprintw(31, 160, "Sparo: %d, ID: %d", personaggi[PINKY].posizione.sparo, personaggi[PINKY].posizione.id);
    

    
        mvprintw(33, 160, "CLYDE [3]");
        mvprintw(34, 160, "X: %d  \t Y: %d  ", personaggi[CLYDE].posizione.x, personaggi[CLYDE].posizione.y);
        mvprintw(35, 160, "Sparo: %d, ID: %d", personaggi[CLYDE].posizione.sparo, personaggi[CLYDE].posizione.id);
    

    
        mvprintw(37, 160, "INKY [4]");
        mvprintw(38, 160, "X: %d  \t Y: %d  ", personaggi[INKY].posizione.x, personaggi[INKY].posizione.y);
        mvprintw(39, 160, "Sparo: %d, ID: %d", personaggi[INKY].posizione.sparo, personaggi[INKY].posizione.id);

        /*
        if(node != NULL)
            mvprintw(29 + (ciclo % 47), 160, "%d : %s", ciclo, EntityName[node->posizione.entita]);
        else
            mvprintw(29 + (ciclo % 47), 160, "%d : NULL     ", ciclo);
        */

        pthread_mutex_unlock(mutexTerminale);
        #endif

        //se vuoi ridere togli la refresh (anche se vuoi piangere)
        refresh();

    }
}

void startGhost(int num, int pallini[][num], Pos fantasmi[]){
    int x, posGhosts[NUM_FANTASMI];
    _Bool flag;
    
    for(int i=0; i<NUM_FANTASMI; i++){
        do {
            posGhosts[i] = randRange(0, NUM_PALLINI);

            flag = true;
            for(int j=0; j<i; j++){
                if(posGhosts[i] == posGhosts[j])
                    flag = false;
            }
        } while(!flag);

        for(int i=0; i<NUM_FANTASMI; i++) {
            fantasmi[i].y = pallini[posGhosts[i]][0] -1;
            fantasmi[i].x = pallini[posGhosts[i]][1] -1;
            fantasmi[i].dir = FERMO;
            fantasmi[i].entita = i % MAX_FANTASMI + 1;
            fantasmi[i].sparo = false;
            fantasmi[i].id = NULL;
        }
    }
}
