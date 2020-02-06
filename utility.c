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

State checkDeathBuffer(Buffer *buffer, Pos pos) {

    pthread_mutex_lock(mutexCollisioni);

    BufferElement *node, *oldNode;
    node = buffer->first;

    if(node != NULL)

        if(pos.id == node->posizione.id) { //trovato in testa

            //check coda
            if(node->posizione.id == buffer->last->posizione.id)
                buffer->last = node->next;

            //tolgo dalla lista il nodo
            buffer->first = node->next;
            free(node);
            return MORTO;

        } else { //non in testa

            //ricerca fino a buffer vuoto
            while(node->next != NULL) {
                oldNode = node;
                node = node->next;
                //check
                if(pos.id == node->posizione.id) {

                    //controllo coda
                    if(buffer->last->posizione.id == node->posizione.id)
                        buffer->last = node->next;

                    //tolgo dalla lista il nodo
                    oldNode->next = node->next;
                    free(node);
                    return MORTO;
                }
            }
        }

    pthread_mutex_unlock(mutexCollisioni);

    return VIVO;
}