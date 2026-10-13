#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  struct pstat uproc[NPROC];
  int nprocs;
  int i;
  char *state;
  uint now;

  static char *states[] = {
    [SLEEPING]  "sleeping",
    [RUNNABLE]  "runnable",
    [RUNNING]   "running ",
    [ZOMBIE]    "zombie  "
  };

  nprocs = getprocs(uproc);
  if (nprocs < 0){
    fprintf(2, "ps: getprocs failed\n");
    exit(-1);
}
//read the current tick after getting process info
  now = uptime();

  printf("pid  state       size  age  priority  cputime  ppid  name\n");
  for (i=0; i<nprocs; i++) {
    state = states[uproc[i].state];
    printf(" %d   %s     %ld", uproc[i].pid, state,
                  (long) uproc[i].size);

   if(uproc[i].state == RUNNABLE){
     uint age = now - uproc[i].readytime;
     printf("  %d  ", (int)age);}
   else{
     printf("  -  ");
   }
   printf("%d   %d   %d   %s\n", uproc[i].priority, uproc[i].cputime, uproc[i].ppid, uproc[i].name);
  }

  exit(0);
}

