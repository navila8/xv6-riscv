#include "kernel/types.h"
#include "user/user.h"

int 
main(void){

   int rc;

   printf("Initial priority: %d\n", getpriority());

   rc = setpriority(10);
   printf("Set 10: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(-1);
   printf("Set -1: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(50);
   printf("Set 50: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(49);
   printf("Set 49: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(24);
   printf("Set 24: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(-10);
   printf("Set -10: return=%d priority=%d\n", rc, getpriority());

   rc = setpriority(0);
   printf("Set 0: return=%d priority=%d\n", rc, getpriority());
  
   exit(0);
}
