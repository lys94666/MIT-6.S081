### sleep (easy)
>Implement the UNIX program sleep for xv6; your sleep should pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. Your solution should be in the file user/sleep.c.

``` c
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc,char **argv)
{ 
    if(argc != 2)
    {
         fprintf(2,"error");
         exit(1);
    }
    else
    {
        int n = atoi(argv[1]);
        sleep(n);
        exit(0);
    }
    exit(0);
}
```

### pingpong (easy)
