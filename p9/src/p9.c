#include "p9.h"

#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *task(void *arg)
{
    if(0 == pthread_mutex_lock(&mutex))
    {
        DBG_PRINT(5,"Argument: %d\n",(*(int*)arg)++); /* critical section */
        
        if (0 != pthread_mutex_unlock(&mutex))
        {
            fprintf(stderr,"Failed to unlock mutext.\n");
            return NULL;
        }
    }
    else
    {
        fprintf(stderr,"Failed to lock mutex.\n");
        return NULL;
    }
    

}

int handle_threads()
{
    pthread_t threads[NUM_THREADS];
    int                      i = 0; 
    int              *value = NULL;
    int                ret_val = 0;

    value = (int*)malloc(sizeof(int));
    
    if (NULL == value)
    {
        fprintf(stderr,"Error when allocating memory.\n");
        ret_val = 1;
    }
    else
    {

        for(i = 0; i < NUM_THREADS; ++i)
        {
            ret_val = pthread_create(&threads[i], NULL, task, (void*)value);

            if(0 != ret_val)
            {
                DBG_PRINT(1,"Error:creating thread. %d\n",pthread_create(&threads[i], NULL, task, (void*)value));
                break;
            }

        }

        if( 0 == ret_val)
        {
            for(i = 0; i < NUM_THREADS; ++i)
            {
                ret_val = pthread_join(threads[i],NULL);

                if(0 != ret_val)
                {
                    DBG_PRINT(1,"Error: joining thread. %d\n",pthread_join(threads[i],NULL));
                    break;
                }

            }

        }

        sleep(1); /* otherwise, memory would be deallocated before the threads join */
        free(value);
        value = NULL;
    }

    return ret_val;
}