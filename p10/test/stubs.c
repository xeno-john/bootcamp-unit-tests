/*********************************************************************
*
* Includes
*
*********************************************************************/

#include "stubs.h"


/*********************************************************************
*
* Stubs Logic
*
*********************************************************************/
int pthread_create_stub(pthread_t *__restrict__ __newthread, const pthread_attr_t *__restrict__ __attr, void *(*__start_routine)(void *), void *__restrict__ __arg)
{
	return pthread_create_RET;
}

int pthread_join_stub(pthread_t __th, void **__thread_return)
{
	return pthread_join_RET;
}

int pthread_mutex_lock_stub(pthread_mutex_t *__mutex)
{
    return pthread_mutex_lock_RET;
}

int pthread_mutex_unlock_stub(pthread_mutex_t *__mutex)
{
    return pthread_mutex_unlock_RET;
}

int pthread_cond_broadcast_stub(pthread_cond_t *__cond)
{
    return pthread_cond_broadcast_RET;
}

int pthread_cond_destroy_stub(pthread_cond_t *__cond)
{
    return pthread_cond_destroy_RET;
}

int pthread_mutex_destroy_stub(pthread_mutex_t *__mutex)
{
    return pthread_mutex_destroy_RET;
}

/*********************************************************************
*
* End of file
*
*********************************************************************/