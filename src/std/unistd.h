#ifndef UNISTD_H
#define UNISTD_H
void syscall(int number);
int brk(void *addr);
int sbrk();
#endif
