#ifndef UNISTD_H
#define UNISTD_H
#include "link_os.h"
void syscall(int number);
int brk(void *addr);
int sbrk();
#endif
