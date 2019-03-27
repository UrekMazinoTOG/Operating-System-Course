#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//#define PI 3.1415926535897

void calPI();

uint64_t  count = 0, range;        // Shared data
time_t    start = 0, end = 0;      // Time variables

int main(int argc, char const *argv[])
{
    assert(argc == 2    && "TheNumberOfArgumentsIsWrong");
    assert(atoll(argv[1]) > 0 && "Argument must be >= 0");

    // Set test range
    range = atoll(argv[1]);

    //*---------------------------------------*//
    time(&start); // Start counting time

    calPI();

    time(&end); // End counting time
    //*---------------------------------------*//

    double pi = 4.0*(double)count/(double)range;
    printf("%.5lf\n", pi);          // Print PI Number
    
    double time = difftime(end, start);
    printf("%.5lf(s)\n", time);    // Print time to excute

    return EXIT_SUCCESS;
}

void calPI() {
    // Initialize the pseudo number
    srand(time(NULL));
    // Monte Carlo technique

    for(uint64_t i = 0; i < range; ++i) {
        // Create point
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand()/(double)RAND_MAX;
        // Calculator radius
        double r = sqrt(x*x + y*y);
        // Is it in a circle
        if(r <= 1) count = count + 1;
    }
}