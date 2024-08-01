#ifndef UNISTD_H
#define UNISTD_H
#include "SYSCALL_DEFINITIONS/linux86_64.h"
void syscall(int number);
int brk(void *addr);
int sbrk();
#endif
