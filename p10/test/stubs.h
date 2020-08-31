#ifndef STUBS_H_
#define STUBS_H_
/*********************************************************************
*
* Includes
*
*********************************************************************/

#include "../src/p10.h"


/*********************************************************************
*
* System Stubs Signature
*
*********************************************************************/

int pthread_create_stub(pthread_t *__restrict__ __newthread, const pthread_attr_t *__restrict__ __attr, void *(*__start_routine)(void *), void *__restrict__ __arg);
int pthread_join_stub(pthread_t __th, void **__thread_return);
int pthread_mutex_lock_stub(pthread_mutex_t *__mutex);
int pthread_mutex_unlock_stub(pthread_mutex_t *__mutex);
int pthread_cond_broadcast_stub(pthread_cond_t *__cond);
int pthread_cond_destroy_stub(pthread_cond_t *__cond);
int pthread_mutex_destroy_stub(pthread_mutex_t *__mutex);


/*********************************************************************
*
* Define System Stubs
*
*********************************************************************/

#define pthread_create pthread_create_stub
#define pthread_join pthread_join_stub
#define pthread_mutex_lock pthread_mutex_lock_stub
#define pthread_mutex_unlock pthread_mutex_unlock_stub
#define pthread_cond_broadcast pthread_cond_broadcast_stub
#define pthread_cond_destroy pthread_cond_destroy_stub
#define pthread_mutex_destroy pthread_mutex_destroy_stub


/*********************************************************************
*
* Include p8.c
*
*********************************************************************/

#include "../src/p10.c"

/*********************************************************************
*
* Global Variables
*
*********************************************************************/

int pthread_create_RET;
int pthread_join_RET;
int pthread_mutex_lock_RET;
int pthread_mutex_unlock_RET;
int pthread_cond_broadcast_RET;
int pthread_cond_destroy_RET;
int pthread_mutex_destroy_RET;

/*********************************************************************
*
* End of file
*
*********************************************************************/

#endif