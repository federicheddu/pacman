#include "utility.h"

int randRange(int min, int max) {
    return min+rand()%(max-min+1);
}

_Bool entityMv(int x, int y, char dir) {
    pthread_mutex_trylock(mutexFantasmi);
    switch (dir) {
        case SU:
            if(scampo[y-1][x] == '#' || scampo[y-1][x+1] == '#' || scampo[y-1][x+2] == '#')
                return false;
            break;
        case GIU:
            if(scampo[y+3][x] == '#' || scampo[y+3][x+1] == '#' || scampo[y+3][x+2] == '#')
                return false;
            break;
        case DESTRA:
            if(scampo[y][x+3] == '#' || scampo[y+1][x+3] == '#' || scampo[y+2][x+3] == '#')
                return false;
            break;
        case SINISTRA:
            if(scampo[y][x-1] == '#' || scampo[y+1][x-1] == '#' || scampo[y+2][x-1] == '#')
                return false;
            break;
        default:
            return false;
    }
    return true;
        pthread_mutex_unlock(mutexFantasmi);

}

//azioni sul buffer
void insertBuffer(Buffer *buffer, pthread_mutex_t *mutex, Pos new){

    BufferElement *newElement = (BufferElement*) malloc(sizeof(BufferElement));
    newElement->posizione = new;
    newElement->next = NULL;

	pthread_mutex_lock(&mutexDatiAux);

    if(buffer->first == NULL)
        buffer->first = newElement;
    buffer->last = newElement;

	pthread_mutex_unlock(&mutexDatiAux);	
}

BufferElement* removeBuffer(Buffer *buffer){
    BufferElement *node;

   pthread_mutex_lock(mutexDati);

    node = buffer->first;
    if(buffer->first == buffer->last)
        buffer->last = NULL;
    if(buffer->first != NULL)
        buffer->first = buffer->first->next;

   pthread_mutex_unlock(mutexDati);

    return node;
}

//stampe di entità
void printEntity(Pos entita, pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);

    switch (entita.entita) {
        case BULLET:
            attron(COLOR_PAIR(2));
            mvprintw(entita.y,entita.x,"o");
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
            attron(COLOR_PAIR(3));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(3));
            break;
        case PINKY:
            attron(COLOR_PAIR(8));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(8));
            break;
        case CLYDE:
            attron(COLOR_PAIR(9));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(9));
            break;
        case INKY:
            attron(COLOR_PAIR(7));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(7));
            break;
        case FUNKY:
            attron(COLOR_PAIR(10));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(10));
            break;
        case GLITCHY:
            attron(COLOR_PAIR(7));
            mvprintw(entita.y,entita.x, "%s","GHO"); //1° riga
            attroff(COLOR_PAIR(7));
            attron(COLOR_PAIR(9));
            mvprintw(entita.y+1,entita.x, "%s","H S"); //2° riga
            attroff(COLOR_PAIR(9));
            attron(COLOR_PAIR(3));
            mvprintw(entita.y+2,entita.x, "%s","OST"); //3° riga
            attroff(COLOR_PAIR(3));
            break;
    }
    
    pthread_mutex_unlock(mutex);
}

void clearEntity(Pos entita, pthread_mutex_t *mutex, int num, int pallini[][num]) {
    pthread_mutex_lock(mutex);
    
    switch(entita.dir) {
      case SU:
        if(entita.entita != BULLET)
            mvprintw(entita.y+3,entita.x, "%s","   ");
        else
            mvprintw(entita.y+1,entita.x, "%s"," ");

        if(entita.entita>PACMAN)
            for(int i=0; i<NUM_PALLINI; i++)
                if(entita.y+3 == pallini[i][0] && entita.x+1 == pallini[i][1] && pallini[i][2] == 0)
                    mvprintw(entita.y+3,entita.x+1, "%c",'.');
        break;

      case GIU:
        if(entita.entita != BULLET)
            mvprintw(entita.y-1,entita.x, "%s", "   ");
        else
            mvprintw(entita.y-1,entita.x, "%s", " ");
        if(entita.entita>PACMAN)
            for(int i=0; i<NUM_PALLINI; i++)
                if(entita.y-1 == pallini[i][0] && entita.x+1 == pallini[i][1] && pallini[i][2] == 0)
                    mvprintw(entita.y-1,entita.x+1, "%c", '.');
        break;

      case SINISTRA:

        if(entita.entita != BULLET) {
            mvprintw(entita.y,entita.x+3, "%c", ' ');
            mvprintw(entita.y+1,entita.x+3, "%c", ' ');
            mvprintw(entita.y+2,entita.x+3, "%c", ' ');
        } else
            mvprintw(entita.y,entita.x+1, "%c", ' ');
        

        if(entita.entita>PACMAN)
            for(int i=0; i<NUM_PALLINI; i++)
                if(entita.y+1 == pallini[i][0] && entita.x+3 == pallini[i][1] && pallini[i][2] == 0)
                    mvprintw(entita.y+1,entita.x+3, "%c",'.');

        if(entita.x == 108) {
            mvprintw(entita.y,40, "%s","   ");
            mvprintw(entita.y+1,40, "%s","   ");
            mvprintw(entita.y+2,40, "%s","   ");
        }
        break;

      case DESTRA:
        mvprintw(entita.y,entita.x-1, "%c",' ');
        if(entita.entita != BULLET) {
            mvprintw(entita.y+1,entita.x-1, "%c",' ');
            mvprintw(entita.y+2,entita.x-1, "%c",' ');
        }
        
        if(entita.entita>PACMAN)
            for(int i=0; i<NUM_PALLINI; i++)
                if(entita.y+1 == pallini[i][0] && entita.x-1 == pallini[i][1] && pallini[i][2] == 0)
                    mvprintw(entita.y+1,entita.x-1, "%c",'.');

        if(entita.x == 40) {
            mvprintw(entita.y,108, "%s","   ");
            mvprintw(entita.y+1,108, "%s","   ");
            mvprintw(entita.y+2,108, "%s","   ");
        }
        break;
    }
    
    pthread_mutex_unlock(mutex);
}