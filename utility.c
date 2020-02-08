#include "utility.h"

int randRange(int min, int max) {
    return min+rand()%(max-min+1);
}

_Bool entityMv(int x, int y, char dir, int lv) {

    switch (dir) {
        case SU:
            if(scampo[lv][y-1][x] == '#' || scampo[lv][y-1][x+1] == '#' || scampo[lv][y-1][x+2] == '#'|| scampo[lv][y-1][x] == 'D' || scampo[lv][y-1][x+1] == 'D' || scampo[lv][y-1][x+2] == 'D')
                return false;
            break;
        case GIU:
            if(scampo[lv][y+3][x] == '#' || scampo[lv][y+3][x+1] == '#' || scampo[lv][y+3][x+2] == '#' || scampo[lv][y+3][x] == 'U' || scampo[lv][y+3][x+1] == 'U' || scampo[lv][y+3][x+2] == 'U')
                return false;
            break;
        case DESTRA:
            if(scampo[lv][y][x+3] == '#' || scampo[lv][y+1][x+3] == '#' || scampo[lv][y+2][x+3] == '#' || scampo[lv][y][x+3] == 'L' || scampo[lv][y+1][x+3] == 'L' || scampo[lv][y+2][x+3] == 'L')
                return false;
            break;
        case SINISTRA:
            if(scampo[lv][y][x-1] == '#' || scampo[lv][y+1][x-1] == '#' || scampo[lv][y+2][x-1] == '#' || scampo[lv][y][x-1] == 'R' || scampo[lv][y+1][x-1] == 'R' || scampo[lv][y+2][x-1] == 'R')
                return false;
            break;
        default:
            return false;
    }
    return true;

}

void insertBuffer(Buffer *buffer, pthread_mutex_t *mutex, Pos new){

    BufferElement *newElement = (BufferElement*) malloc(sizeof(BufferElement));
    newElement->posizione = new;
    newElement->next = NULL;

	pthread_mutex_lock(mutex);

    if(buffer->first == NULL)
        buffer->first = newElement;
    buffer->last = newElement;

	pthread_mutex_unlock(mutex);	
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

void clearBuffer(Buffer *buffer, Entity entita) {
    BufferElement *oldNode, *node = buffer->first;

    if(node != NULL) {

        if(entita == node->posizione.entita) { //trovato in testa

            //check coda
            if(node->posizione.id == buffer->last->posizione.id)
                buffer->last = node->next;

            //tolgo dalla lista il nodo
            buffer->first = node->next;
            free(node);

        }

        //ricerca fino a buffer vuoto
        while(node->next != NULL) {
            oldNode = node;
            node = node->next;
            //check
            if(entita == node->posizione.entita) {

                //controllo coda
                if(buffer->last->posizione.entita == node->posizione.entita)
                    buffer->last = node->next;

                //tolgo dalla lista il nodo
                oldNode->next = node->next;
                free(node);
            }
        }

    }
}