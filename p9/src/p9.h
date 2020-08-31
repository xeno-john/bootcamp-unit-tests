#ifndef P9_H_
#define P9_H_

#include "../../DBG_PRINT.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10

void *task(void *arg);
int handle_threads();

#endif
