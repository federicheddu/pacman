//
// Created by Fabio Pili on 25/11/2019.
//

#include "pacman.h"


void pacman(int pipe) {
    int currDir = STOP;
    int nextDir = STOP;



    printPacMan(29,45,0);
}

_Bool pacmanMv(int x, int y, int dir) {
    switch (dir) {
        case SU:
            if(mvinch(y-1,x) == '#' && mvinch(y-1,x+1) == '#' && mvinch(y-1,x+2) == '#')
                return false;
            break;
        case GIU:
            if(mvinch(y+4,x) == '#' && mvinch(y+4,x+1) == '#' && mvinch(y+4,x+2) == '#')
                return false;
            break;
        case DESTRA:
            if(mvinch(y,x+4) == '#' && mvinch(y+1,x+4) == '#' && mvinch(y+2,x+4) == '#')
                return false;
            break;
        case SINISTRA:
            if(mvinch(y,x-1) == '#' && mvinch(y+1,x-1) == '#' && mvinch(y+2,x-1) == '#')
                return false;
            break;
    }
    return true;
}

void printPacMan(int x, int y, int direction) {
    char pacmanSU[3][3] = {{' ','1',' '},{'1',' ','1'},{'1','1','1'}};
    char pacmanGIU[3][3] = {{'1','1','1'},{'1',' ','1'},{' ','1',' '}};
    char pacmanDESTRA[3][3] = {{'1','1',' '},{'1',' ','1'},{'1','1',' '}};
    char pacmanSINISTRA[3][3] = {{' ','1','1'},{'1',' ','1'},{' ','1','1'}};

    switch (direction) {
        case SU:
            for(int i=0; i<=2; i++) {
                for(int j=0; j<=2; j++) {
                    if(pacmanSU[j][i] == '1') {
                        attron(COLOR_PAIR(2));
                        mvaddch(x+i, y+j, pacmanSU[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        mvaddch(x+i, y+j, pacmanSU[i][j]);
                    }
                }
            }
            break;
        case GIU:
            for(int i=0; i<=2; i++) {
                for(int j=0; j<=2; j++) {
                    if(pacmanGIU[j][i] == '1') {
                        attron(COLOR_PAIR(2));
                        mvaddch(x+i, y+j, pacmanGIU[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        mvaddch(x+i, y+j, pacmanGIU[i][j]);
                    }
                }
            }
            break;
        case DESTRA:
            for(int i=0; i<=2; i++) {
                for(int j=0; j<=2; j++) {
                    if(pacmanDESTRA[j][i] == '1') {
                        attron(COLOR_PAIR(2));
                        mvaddch(x+i, y+j, pacmanDESTRA[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        mvaddch(x+i, y+j, pacmanDESTRA[i][j]);
                    }
                }
            }
            break;
        case SINISTRA:
            for(int i=0; i<=2; i++) {
                for(int j=0; j<=2; j++) {
                    if(pacmanSINISTRA[j][i] == '1') {
                        attron(COLOR_PAIR(2));
                        mvaddch(x+i, y+j, pacmanSINISTRA[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        mvaddch(x+i, y+j, pacmanSINISTRA[i][j]);
                    }
                }
            }
            break;
        default:
            for(int i=0; i<=2; i++) {
                for(int j=0; j<=2; j++) {
                    if(pacmanSU[i][j] == '1') {
                        attron(COLOR_PAIR(2));
                        mvaddch(x+i, y+j, pacmanSU[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        mvaddch(x+i, y+j, pacmanSU[i][j]);
                    }
                }
            }
            break;
    }

}

void clearPacMan(int x, int y) {
    attron(COLOR_PAIR(0));
    for(int i=0; i<3; i++)
        for(int j=0; j<0; j++)
            mvaddch(x+i, y+j, ' ');
}