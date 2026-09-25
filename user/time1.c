#include "kernel/types.h"//xv6 data types
#include "kernel/stat.h"// for the struct
#include "user/user.h"//lets me use system calls

int main(int argc, char *argv[]){
	int pid;//for fork
	int start;//start time
	int end;//end time
	int lap;//difference

	if(argc<2){// if not enought user input is inputed it  exits
	printf("usage: time1 command [args ...]\n");
	exit(1);
	}

	start = uptime(); // time before child process starts

	pid = fork();//child process 

	if(pid <0){//fork didnt work 
	printf("time1: failed\n");
	exit(1);
	}
	if(pid==0){//in child process
	exec(argv[1], &argv[1]);//sending argv[1] command and &argv[1] is the argument
	printf("exec failed\n");//only conti in exec fails
	exit(1);
	}

	wait(0);//waiting for child to finsih 
	end = uptime();//time after child finsihes 
	lap = end-start;//total elapsed time 

	printf("elapsed time: %d ticks\n", lap);

	exit(0);
}
