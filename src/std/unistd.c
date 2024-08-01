#include "SYSCALL_DEFINITIONS/linux86_64.h"
void syscall(int number){
        asm volatile
        (
         "syscall"
         :
         :"a"(number)
        );
}
int brk(void *addr){
        int exitstat;
        asm volatile
        (
         "movq %[addr], %%rdi \n\t"
         "movq %[brk], %%rax \n\t"
         "syscall \n\t"
         "movl %%eax, %[status]"
         : [status] "=rm" (exitstat)
         : [addr] "rm" (addr), [brk] "i" (SYSBRK)
         : "rax", "rdi", "memory", "cc"
        );
        return exitstat;
}
int sbrk(){}
