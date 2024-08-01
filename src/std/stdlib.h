#ifndef STDLIB_H
#define STDLIB_H
#include "stddef.h"
#include "unistd.h"
#include "SYSCALL_DEFINITIONS/linux86_64.h"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 2147483647

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t n_items, size_t size);

#endif
