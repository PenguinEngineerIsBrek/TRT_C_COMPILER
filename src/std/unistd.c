#include "unistd.h"
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
	if(addr == 0){
		void *returnaddr;
		asm volatile
		(
		 "movq $0, %%rdi \n\t"
		 "movq %[brk], %%rax \n\t"
		 "syscall \n\t"
		 "movq %%rax, %[ret] \n\t"
		 : [ret] "=rm" (returnaddr)
		 : [brk] "i" (SYSBRK)
		);
		return (long int)returnaddr;
	}
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
