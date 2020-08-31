#ifndef STUBS_H_
#define STUBS_H_
/*********************************************************************
*
* Includes
*
*********************************************************************/

#include "../src/p8.h"


/*********************************************************************
*
* System Stubs Signature
*
*********************************************************************/

int pthread_create_stub(pthread_t *__restrict__ __newthread, const pthread_attr_t *__restrict__ __attr, void *(*__start_routine)(void *), void *__restrict__ __arg);
int pthread_join_stub(pthread_t __th, void **__thread_return);


/*********************************************************************
*
* Define System Stubs
*
*********************************************************************/

#define pthread_create pthread_create_stub
#define pthread_join pthread_join_stub


/*********************************************************************
*
* Include p8.c
*
*********************************************************************/

#include "../src/p8.c"

/*********************************************************************
*
* Global Variables
*
*********************************************************************/

int pthread_create_RET;
int pthread_join_RET;

/*********************************************************************
*
* End of file
*
*********************************************************************/

#endif