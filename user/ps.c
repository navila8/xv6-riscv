#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
// attribures for process table
  struct pstat uproc[NPROC];
  int nprocs;
  int i;
  char *state;
  uint now;

//states used
  static char *states[] = {
    [SLEEPING]  "sleeping",
    [RUNNABLE]  "runnable",
    [RUNNING]   "running ",
    [ZOMBIE]    "zombie  "
  };
//kernel returnd used entires
  nprocs = getprocs(uproc);
  if (nprocs < 0){
    fprintf(2, "ps: getprocs failed\n");
    exit(-1);
}
//read the current tick after getting process info
  now = uptime();

  printf("pid  state       size  age  priority  cputime  ppid  name\n");//trying to make a more readable format
  for (i=0; i<nprocs; i++) {
    state = states[uproc[i].state];
//casting to fit format
    printf(" %d   %s     %ld", uproc[i].pid, state,
                  (long) uproc[i].size);
//calculate age
   if(uproc[i].state == RUNNABLE){
     uint age = now - uproc[i].readytime;
     printf("  %d  ", (int)age);}
   else{
//used for states with no age
     printf("  -  ");
   }
   printf("%d   %d   %d   %s\n", uproc[i].priority, uproc[i].cputime, uproc[i].ppid, uproc[i].name);
  }

  exit(0);
}

