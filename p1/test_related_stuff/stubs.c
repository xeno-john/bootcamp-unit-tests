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

char *fgets_stub(char *s, int size, FILE *stream)
{
	if (NULL != fgets_RET)
	{
		strcpy(s,fgets_RET);
	}
	return fgets_RET;
}

void *malloc_stub(size_t size)
{
	return malloc_RET;
}

/*********************************************************************
*
* End of file
*
*********************************************************************/