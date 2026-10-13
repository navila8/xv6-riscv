#include "kernel/types.h"
#include "user/user.h"

int 
main(void){

	int ready[2], go[2];
	int priorities[2] = {5,10};
	char token = 'x';

	if(pipe(ready) < 0 || pipe(go) < 0)
	   exit(1);

	//Keep parent 
	setpriority(49);
	for(int i =0; i < 2; i++){
	   int pid = fork();

	   if(pid < 0)
	     exit(1);
	   if(pid == 0){
	     close(ready[0]);
	     close(go[1]);
	     setpriority(priorities[i]);
	     //parent ready wait for signal
	     write(ready[1], &token, 1);
	     close(ready[1]);
	     uint arrival;
	     if(read(go[0],&arrival, sizeof(arrival)) !=sizeof(arrival))
		exit(1);
	     close(go[0]);
	     uint first = uptime();

	    printf("Start pid=%d priority=%d\n", getpid(), getpriority());
	    volatile unsigned long work =0;
	    for(unsigned long j = 0; j<3000000000UL; j++)
	       work = work +1;
	    uint finish = uptime();
	    printf("pid=%d priority=%d response=%d turnaround=%d ticks\n",
		getpid(), getpriority(),
		(int)(first - arrival),
		(int)(finish - arrival));

	    exit(0);
	   }
         }

	close(ready[1]);
	close(go[0]);

      // wait until children set pro
	for(int i =0; i<2; i++){
	  if(read(ready[0], &token, 1) !=1)
	     exit(1);
	}
	close(ready[0]);

	uint arrival = uptime();
	for(int i =0; i<2; i++)
	   write(go[1], &arrival, sizeof(arrival));
	close(go[1]);

	wait(0);
	wait(0);
	exit(0);
}
