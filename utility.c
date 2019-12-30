#include "utility.h"

int randRange(int min, int max) {
    return min+rand()%(max-min+1);
}

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

   pthread_mutex_unlock(mutexDati);

    node = buffer->first;
    if(buffer->first == buffer->last)
        buffer->last = NULL;
    if(buffer->first != NULL)
        buffer->first = buffer->first->next;

   pthread_mutex_lock(mutexDati);

    return node;
}