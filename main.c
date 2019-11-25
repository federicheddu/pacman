#include <stdio.h>
#include "gioco.h"
#include "pacman.h"
#include "ghosts.h"

/** PROBLEMONE, COME FACCIAMO QUANDO I FANTASMI PASSANO SOPRA I PALLINI? **/
//TODO void printPacMan(coordinate vecchie, direzione); //da passare come parametro le vecchie coordinate e la direzione così sappiamo dove dobbiamo cancellare
//TODO void printGhost(coordinate vecchie, direzione e tipo) //vecchie coordinate e la direzione così sappiamo dove dobbiamo cancellare

int main() {
    int menu, level;
    int pipePacMan[2];
    pid_t pid_PacMan;

    initscr(); 					    /* inizializzazione dello schermo */
    noecho();					    /* i caratteri corrispondenti ai tasti premuti non saranno visualizzati sullo schermo del terminale */
    srand(time((time_t*)NULL)); 	/* inizializziamo il generatore di numeri random */
    curs_set(0); 				    /* nasconde il cursore */

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);

    menu = mainMenu();

    if(menu != EXIT) {
        if(pipe(pipePacMan) == -1) {
            perror("Errore nella creazione della pipe di PacMan!");
            _exit(1);
        }

        switch (pid_PacMan = fork()) {
            case -1:
                perror("Errore nell'esecuzione della fork di PacMan");
                break;
            case 0: //figlio -> pacman
                close(pipePacMan[0]);
                pacman(pipePacMan[1]);
                break;
            default: //padre -> gioco
                close(pipePacMan[1]);
                gameController(pipePacMan[0], level);
                break;
        }
    }


    refresh();

    while (getch()!='\n');//Aspetto che l'utente prema invio
    endwin();//Ripristino il normale funzionamento del terminale

    return 0;
}
