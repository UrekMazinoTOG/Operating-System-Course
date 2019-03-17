#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ex1.h"

int main(int argc, char const *argv[])
{
    void* ptr = aligned_malloc(64, 16*16);
    assert(ptr != NULL && "Failed to allocate memory");

    printf("%p\n", ptr); ptr = aligned_free(ptr);

    return EXIT_SUCCESS;
}
