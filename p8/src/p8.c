#include "p8.h"

void *task(void *arg)
{
    long thread_id = (long)arg;

    DBG_PRINT(5,"Argument: %li\n",thread_id);
    
}

int handle_threads()
{
    int         process_status = 0;
    pthread_t threads[NUM_THREADS];
    int                      i = 0; 

    for(i = 0; i < NUM_THREADS; ++i)
    {
        process_status = pthread_create(&threads[i], NULL, task, (void*)(long)i);

        if(0 != process_status)
        {
            DBG_PRINT(1,"Error: failed to  create thread. %d\n",pthread_create(&threads[i], NULL, task, (void*)(long)i));
            break;
        }

    }

    if (0 == process_status)
    {

        for(i = 0; i < NUM_THREADS; ++i)
        {
            process_status = pthread_join(threads[i],NULL);

            if(0 != process_status)
            {
                DBG_PRINT(1,"Error: failed to join thread. %d\n",pthread_create(&threads[i], NULL, task, (void*)(long)i));
                break;
            }

        }

    }

    return process_status;
}