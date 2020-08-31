#ifndef P10_H_
#define P10_H_

#include "../../DBG_PRINT.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

/**
 *  @brief Function that receives an int through a void pointer (thread_id) and keeps the thread running as long as the given condition is met.
 *  @param arg [in] void ptr to an integer (casted to long to be the exact same size as void*)
 */
void *task(void *arg);
int handle_threads();

#endif