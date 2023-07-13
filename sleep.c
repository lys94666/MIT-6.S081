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
