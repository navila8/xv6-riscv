#include "kernel/types.h"
#include "user/user.h"

int 
main(void){

   int p;
//making sure prioirty is inherited
   printf("Initial priority: %d\n", getpriority());

   p = setpriority(10);
   printf("Set 10: return=%d priority=%d\n", p, getpriority());
//invails
   p = setpriority(-1);
   printf("Set -1: return=%d priority=%d\n", p, getpriority());
//invaild
   p = setpriority(50);
   printf("Set 50: return=%d priority=%d\n", p, getpriority());
//edge
   p = setpriority(49);
   printf("Set 49: return=%d priority=%d\n", p, getpriority());
//fav num
   p = setpriority(24);
   printf("Set 24: return=%d priority=%d\n", p, getpriority());
//invails
   p = setpriority(-10);
   printf("Set -10: return=%d priority=%d\n", p, getpriority());
//edge
   p = setpriority(0);
   printf("Set 0: return=%d priority=%d\n", p, getpriority());
  
   exit(0);
}
