#include "factorial.h"

char* factorial (const uint64_t aNumber) {
    uint64_t fact, tmp, count;
    // calculate factorial
    fact = tmp = aNumber;
    while(--tmp) fact *= tmp;
    // count number of digit
    count = 0; tmp   = fact;
    while(tmp) { tmp /= 10; ++count; }
    // convert ret(int) to ret(string)
    char *ret = (char*) malloc(sizeof(char)*(count + 1));
    sprintf(ret, "%I64lu", fact);
    // return result
    return ret;
}
