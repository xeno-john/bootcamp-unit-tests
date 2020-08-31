#ifndef STUBS_H_
#define STUBS_H_
/*********************************************************************
*
* Includes
*
*********************************************************************/

#include "../src/p9.h"


/*********************************************************************
*
* System Stubs Signature
*
*********************************************************************/

int pthread_create_stub(pthread_t *__restrict__ __newthread, const pthread_attr_t *__restrict__ __attr, void *(*__start_routine)(void *), void *__restrict__ __arg);
int pthread_join_stub(pthread_t __th, void **__thread_return);
int pthread_mutex_lock_stub(pthread_mutex_t *__mutex);
int pthread_mutex_unlock_stub(pthread_mutex_t *__mutex);
void *malloc_stub(size_t __size);


/*********************************************************************
*
* Define System Stubs
*
*********************************************************************/

#define pthread_create pthread_create_stub
#define pthread_join pthread_join_stub
#define pthread_mutex_lock pthread_mutex_lock_stub
#define pthread_mutex_unlock pthread_mutex_unlock_stub
#define malloc malloc_stub


/*********************************************************************
*
* Include p8.c
*
*********************************************************************/

#include "../src/p9.c"

/*********************************************************************
*
* Global Variables
*
*********************************************************************/

int pthread_create_RET;
int pthread_join_RET;
int pthread_mutex_lock_RET;
int pthread_mutex_unlock_RET;
void* malloc_RET;

/*********************************************************************
*
* End of file
*
*********************************************************************/

#endif