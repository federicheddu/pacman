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

    State stato = VIVO;
    BufferElement *node, *oldNode;
    node = buffer->first;
    //mvprintw(29, 160, "Dentro0");
    if(node != NULL){
       mvprintw(28, 160, "Dentro"); 

        //Controllo se la pos è il primo nodo
        if(pos.entita == node->posizione.entita) {
            mvprintw(29, 160, "Rosso");

            //Controllo se è anche l'ultimo nodo
            if(node->posizione.entita == buffer->last->posizione.entita){
                mvprintw(30, 160, "Nero");
                buffer->last = NULL;
            }
            
            buffer->first = node->next;
            free(node);
            stato = MORTO;

        //Se non è in testa    
        }else {
            mvprintw(31, 160, "Blu");
            //Scorro finché la lista non finisce
            while(node->next != NULL || stato == MORTO) {
                mvprintw(32,160,"Bianco");
                oldNode = node;
                node = node->next;

                //Controllo se la pos è quel nodo
                if(pos.entita == node->posizione.entita) {
                    mvprintw(33,160,"Giallo");
                    //Controllo se è anche l'ultimo nodo
                    if(buffer->last->posizione.entita == node->posizione.entita){
                        buffer->last = node->next;
                        mvprintw(33,160,"Arancione");
                    }
                        

                    oldNode->next = node->next;
                    free(node);
                    stato = MORTO;
                }
            }
        }
    }

    pthread_mutex_unlock(mutexCollisioni);

    return stato;

    

}