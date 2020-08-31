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

/*********************************************************************
*
* End of file
*
*********************************************************************/