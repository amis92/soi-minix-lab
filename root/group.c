#include <stdlib.h>
#include <lib.h>
#include <stdio.h>

int getprocgroup()
{
	message msg;
	return _syscall(0, 58, &msg);
};

int main(int argc, char** agrv)
{
	for (int i = 0; i < 30; i++)
	{
		printf("ProcID: %d", i);
		printf(" proc group: %d", getprocgroup(i);
	}
};

