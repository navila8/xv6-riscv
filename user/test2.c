#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char *argv[])
{
	int pid = getpid();

	printf("test2 start: pid=%d\n", pid);

	for(volatile int i =0; i < 100000000; i++){
		if (i % 20000000 ==0)
			printf("test2 pid=%d running\n", pid);
	}
	printf("test2 pid=%d finished\n", pid);
	exit(0);
}
