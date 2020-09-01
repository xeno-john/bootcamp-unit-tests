#include "p10.h"


int condition_met                                 = 0;
pthread_cond_t       cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;


/**
 *  @brief Function that receives an int through a void pointer (thread_id) and keeps the thread running as long as the given condition is met.
 *  @param arg [in] void ptr to an integer (casted to long to be the exact same size as void*)
 */
void *task(void *arg)
{
    int rc = 0;
    rc = pthread_mutex_lock(&mutex);
    long tid = (long)arg;

    if (0 == rc)
    {

        while (0 == condition_met)
        {
            DBG_PRINT(5,"Thread %li doing stuff.\n",tid);
            rc = pthread_cond_wait(&cond,&mutex);
            
        }

        rc = pthread_mutex_unlock(&mutex);
        if( 0 != rc)
        {
            return NULL;
        }
        
    }
    else
    {
        return NULL;
    }
    
}

int handle_threads()
{
    pthread_t threads[NUM_THREADS];
    int i = 0; 
    int rc = 0;

    for (i = 0; i < NUM_THREADS; ++i)
    {

        rc = pthread_create(&threads[i], NULL, task, (void*)(long)i);

        if (0 != rc)
        {
            DBG_PRINT(1,"Error: can't create thread. %d\n",pthread_create(&threads[i], NULL, task, (void*)(long)i));
            break;

        }

    }

    sleep(1);  /* Sleep is not a very robust way to serialize threads */

    if (0 == rc)
    {
        rc = pthread_mutex_lock(&mutex);
        /* The condition has occured. Set the flag and wake up any waiting threads */
        condition_met = 1;
        
        if(0 == rc)
        {
            printf("Wake up all waiting threads...\n");
            rc = pthread_cond_broadcast(&cond);
            

            if (0 == rc)
            {
                rc = pthread_mutex_unlock(&mutex);
                
                if (0 == rc)
                {

                    printf("Wait for threads and cleanup\n");

                    for (i=0; i<NUM_THREADS; ++i) 
                    {
                        rc = pthread_join(threads[i], NULL);

                        if (0 != rc)
                        {
                            DBG_PRINT(1,"Error: can't join thread. %d\n",rc);
                            break;
                        }
                    }
                    if (0 == rc)
                    {
                        rc = pthread_cond_destroy(&cond);

                        if (0 == rc)
                        {
                            rc = pthread_mutex_destroy(&mutex);
                            printf("All threads have finished.\n");
                        }
                        else
                        {
                            fprintf(stderr,"pthread_cond_destroy failed.\n");
                        }
                        
                        
                    }

                }
            }
        }
    }

    return rc;
}