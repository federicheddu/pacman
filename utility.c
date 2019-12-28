#include "utility.h"

void insertBuffer(Buffer *buffer, pthread_mutex_t *mutex, sem_t* semaphore, Pos new){

    BufferElement *newElement = (BufferElement*) malloc(sizeof(BufferElement));
    newElement->posizione = &new;
    newElement->next = NULL;

	pthread_mutex_lock(mutex);

    if(buffer->first == NULL)
        buffer->first = newElement;
    buffer->last = newElement;

    //sem_post(semaphore); // incrementa il semaforo

	pthread_mutex_unlock(mutex);	
}

BufferElement* removeBuffer(Buffer *buffer, pthread_mutex_t *mutex, sem_t* semaphore, int mode){
    BufferElement *node;

    /*
    //Ingresso nella sezione critica
    int value;
    if (mode == WAIT)
        value = sem_wait(semaphore); // se non ci sono job, li aspetta
    if (mode == TRYWAIT)
        value = sem_trywait(semaphore); // se non ci sono job, non li aspetta ma non esce
        
    if (value == 0){
        pthread_mutex_lock(mutex);
        
            message = buffer[(*counter)-1];
            memset(&buffer[(*counter)-1], 0, sizeof(Par)); //Nullizza la cella del buffer 
            (*counter)--; 
        
        pthread_mutex_unlock(mutex);
        return message;
    }
    message.entita = NOPE;
    */

   pthread_mutex_unlock(mutex);

    node = buffer->first;
    if(buffer->first == buffer->last)
        buffer->last = NULL;
    buffer->first = buffer->first->next;

   pthread_mutex_lock(mutex);

    return node;
}