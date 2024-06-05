#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goAndUse(char *x, char *y, int t)
{
	int ret = rand();
	
	if (ret)
	{
		free(x);
		return;
	}
	else
	{
		//free(x);
		// leak - no free() on this path
		// return;
	}
}

int r = 12 - 1;

void memoryLeak()
{
	// null pointer dereference - malloc may fail
	char *ptr = (char*)malloc(24);

	// buffer overrun - ptr not large enough for string copy
	sprintf(ptr, "Scir Ltd with Pi: %.10f", 3.14159265359);

	goAndUse(ptr, ptr, 10);
}
