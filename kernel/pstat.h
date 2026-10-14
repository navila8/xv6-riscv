#ifndef PSTAT_H
#define PSTAT_H
struct rusage{//given by instructor return usage info
	uint cputime;//number of CPU ticks by child
};

enum procstate{
	UNUSED,
	USED,
	SLEEPING,
	RUNNABLE,
	RUNNING,
	ZOMBIE
};

//info copied from kernel to user for ps
struct pstat {
	int pid; //Process ID
	enum procstate state;// Process state
	uint64 size; //Size of process memory bytes
	int ppid; //parent process Id
	char name[16]; //parent comman name
	int priority; //priory
	uint readytime; ///time
	int cputime; //cputime
};
#endif
