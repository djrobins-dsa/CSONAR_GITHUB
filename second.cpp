#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
	char *ptr = (char*)malloc(42);

	if (NULL != ptr) {
		sprintf(ptr, "Scir Ltd with int Pi: %i", (int)M_PI);
	}

	goAndUse(ptr, ptr, 10);
}
