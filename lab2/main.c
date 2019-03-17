#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "factorial.h"
#include "readline.h"

int main(int argc, char *argv[]) 
{
    char *line = (char*)malloc(sizeof(char)*50);
    char *stri = NULL;

    while(1)
    {
        // Print factorial
        if(read_line(line)) 
        {
            stri = factorial(atoi(line));
            printf("%s\n", stri); free(stri);
        }
        else printf("-1\n");
    }
}

