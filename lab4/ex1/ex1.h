#ifndef __EX1_H__
#define __EX1_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void* aligned_malloc(size_t size, size_t align);
void* aligned_free(void* ptr);

#endif