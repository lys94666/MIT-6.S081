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
         fprintf(2,"error in sleep");
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
>Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file user/pingpong.c.

```c
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int 
main(int argc, char const **argv)
{
	int pid;
	int p[2];
	pipe(p);

	if (fork() == 0) // child (receive -> send)
	{
		pid = getpid();
		char buf[2];
		if (read(p[0], buf, 1) != 1)
		{
			fprintf(2, "failed to read in child\n");
			exit(1);
		}
		close(p[0]);
		printf("%d: received ping\n", pid);
		if(write(p[1], buf, 1) != 1)
		{
			fprintf(2, "failed to write in child\n");
			exit(1);
		}
		close(p[1]);
		exit(0);
	}else{			// parent (send -> receive)
		pid = getpid();
		char info[2] = "a";
		char buf[2];
		buf[1] = 0;
		if (write(p[1], info, 1) != 1)
		{
			fprintf(2, "failed to write in parent\n");
			exit(1);
		}
		// wait for child to receive ping
		close(p[1]);
		wait(0);
		if(read(p[0], buf, 1) != 1){
			fprintf(2, "failed to read in parent\n");
			exit(1);
		}
		printf("%d: received pong\n", pid);
		close(p[0]);
		exit(0);
	}
}

```

### primes (moderate)/(hard)
>Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down this page and the surrounding text explain how to do it. Your solution should be in the file user/primes.c.

```C
```



