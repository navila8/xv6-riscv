#include "kernel/types.h"
#include "user/user.h"

int 
main(int argc, char *argv[]){	
	
	int ticks;

	ticks = uptime(); // uses uptime system call from xv6
	printf("up %d clock ticks\n", ticks);

	exit(0);
}
