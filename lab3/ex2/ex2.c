#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main()
{
    int b ;
    int c ;
    int d ;
    int e ;
    int f ;
    int g ;
    int h ;
    int i ;

    b = fork();

    if(b == 0)
    {
        e = fork();

        if(e == 0) 
        {
            i = fork();

            if(i == 0) 
                printf("%i : I\n", getpid());
            else
                printf("%i : E\n", getpid());
        }
        else
        {
            f = fork();

            if(f == 0) 
                printf("%i : F\n", getpid());
            else
                printf("%i : B\n", getpid());
        }
    }
    else
    {
        c = fork();

        if(c == 0)
        {
            g = fork();

            if(g == 0) 
                printf("%i : G\n", getpid());
            else
                printf("%i : C\n", getpid());
        }
        else
        {
            d = fork();

            if(d == 0) 
                printf("%i : D\n", getpid());
            else
                printf("%i : A\n", getpid());
        }
    }
    
    sleep(100);

    return EXIT_SUCCESS;
}

// How to run this file
// cd ${yourworkspace}
// gcc ex2.c -o ex2
// ./ex2 &
// htop
