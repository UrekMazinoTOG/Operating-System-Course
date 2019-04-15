#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <assert.h>

#define NUM_THREAD 4
//#define PI 3.1415926535897

void* calPI(void *param);

pthread_t thdIDs[NUM_THREAD] = {0}; // Thread IDs
uint64_t  counts[NUM_THREAD] = {0}; // Points count
uint64_t  sumPoint = 0, range;      // Shared data
time_t    start = 0, end = 0;       // Time variables

int main(int argc, char const *argv[])
{
    assert(argc == 2   &&  "TheNumberOfArgumentsIsWrong");
    assert(atoll(argv[1]) > 0 && "Argument must be >= 0");

    // Set test range
    range = atoll(argv[1])/NUM_THREAD;

    //*---------------------------------------*//
    time(&start); // Start counting time
    srand(time(NULL));

    for(int8_t i = 0; i < NUM_THREAD; ++i)
        pthread_create(&thdIDs[i], NULL, calPI, &counts[i]);

    for(int8_t i = 0; i < NUM_THREAD; ++i) {
        pthread_join(thdIDs[i], NULL);
        sumPoint += counts[i]; ; // The number of points in the circle
    }

    time(&end); // End counting time
    //*---------------------------------------*//

    double pi = 4.0*(double)sumPoint/(double)range/(double)NUM_THREAD;
    printf("%.5lf\n", pi);          // Print PI Number
    
    double time = difftime(end, start);
    printf("%.5lf(s)\n", time);    // Print time to excute

    pthread_exit(EXIT_SUCCESS);
}

void* calPI(void *arg) {
    // Initialize the pseudo number
    // Monte Carlo technique
    uint64_t* pcount = (uint64_t*)arg;
    unsigned int seed = rand()%30000;

    for(uint64_t i = 0; i < range; ++i) {
        // Create point
        double x = (double)rand_r(&seed)/(double)RAND_MAX;
        double y = (double)rand_r(&seed)/(double)RAND_MAX;
        // Calculator radius
        double r = sqrt(x*x + y*y);
        // Is it in a circle
        if(r <= 1) *pcount = *pcount + 1;
    }

    // End thread
    pthread_exit(EXIT_SUCCESS);
}