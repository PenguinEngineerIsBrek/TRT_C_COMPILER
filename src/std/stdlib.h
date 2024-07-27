#ifndef STDLIB_H
#define STDLIB_H
#include "stddef.h"
#include "SYSCALL_DEFINITIONS/linux86_64.h"
#include "stdio.h"

void *calloc(size_t n_items, size_t size){
};
void *malloc(size_t size){
	void *addr;
	asm volatile
	(
	 "movq %[mmap], %%rax \n\t"
	 "movq %[addr], %%rdi \n\t"
	 "movq %[size], %%rsi \n\t"
	 "movq $3, %%rdx \n\t"
	 "movq $0x22, %%r10 \n\t"
	 "movq $-1, %%r8 \n\t"
	 "movq $0, %%r9 \n\t"
	 "push %[size]"
	 "syscall"
	 : [addr] "=r" (addr)
	 : [size] "r" (size), [mmap] "i" (SYSMMAP)
	 : "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9", "memory"
	);
	return addr;
};
void *realloc(void *ptr, size_t size){};
void free(void *ptr){
	asm volatile
	(
	 "movq %[munmap], %%rax \n\t"
	 "movq %[addr], %%rdi \n\t"
	 "pop %%rsi"
	 "syscall"
	 :
	 : [munmap] "i" (SYSMUNMAP), [addr] "r" (ptr)
	 : "rax", "rdi", "rsi"  
	);
};
#endif
