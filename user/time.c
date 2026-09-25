#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
   int pid;//result of fork
   int status;//child exit status
   int start;
   int end;
   int elapased;//elpased time
   int percent;//percentahe of elasped time in CPU
   struct rusage usage;//CPU usage return from wait2()

   if(argc < 2){//chekcs to make sure it has enough commands 
     printf("usage: time command [args missing\n");
     exit(1);
   }
 
   start = uptime();//start of uptime
   pid = fork();//make child
   if(pid < 0){
      printf("time: fork failed\n");
      exit(1);
   }

   if(pid == 0){
     exec(argv[1], &argv[1]);//replace child with command

     printf("time: exec failed\n");
     exit(1);
    }
   wait2(&status, &usage);//waitinf got child and return CPU usage
   end = uptime();//end og system time
   elapased = end-start;

   if(elapased > 0){//cant devide by 0 and cnat have meagtive time
      percent = (usage.cputime *100)/ elapased;//formaula for percent to calculate percent of child CPU time
   }
   else{
      percent =0;
   }
   printf("elapased time: %d ticks, cpu time: %d ticks, %d%% CPU\n", elapased, usage.cputime, percent);
  exit(0);
}
