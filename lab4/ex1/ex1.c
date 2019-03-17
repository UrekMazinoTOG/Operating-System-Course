#include "ex1.h"

bool isPowerOfTwo(size_t num);

void* aligned_malloc(size_t size, size_t align)
{
    if (!isPowerOfTwo(align) || align == 0) return NULL;

    void*  oriPnt;  // original block
    void** aliPnt;  // aligned  block

    size_t offset = align - 1 + sizeof(void*);
    // allocate necessary memory
    oriPnt = malloc(size + offset);
    if(oriPnt == NULL) return NULL;
    // address of the aligned memory
    aliPnt = (void**)((size_t)(oriPnt + offset) & ~(align - 1));
    // store the address of the malloc()
    aliPnt[-1] = oriPnt;

    return aliPnt;
}

void* aligned_free(void* ptr) 
{
    // restore poniter point to original block
    // deallocated it
    free(((void**)ptr)[-1]); 
    return NULL;
}

bool isPowerOfTwo(size_t num) {
    // checks whether a number is zero or not
    if(num == 0) return false;

    //true till a number is not equal to 1
    while(num != 1) {
        if(num % 2 != 0) return false;
        num /= 2; // is it divisible by 2 ?
    }

    return true;
}
