#ifndef STDLIB_H
#define STDLIB_H
#include "stddef.h"
#include "SYSCALL_DEFINITIONS/linux86_64.h"
#include "stdio.h"
void *calloc(size_t n_items, size_t size){
};
void *malloc(size_t size){
	asm volatile(
			"syscall"
			:
			:"a"(SYSMMAP), "D"(0), "S"(size), "d"(3), "r10"(0x22), "r8"((void*)-1), "r9"(0)
		    	:"rax", "rdi", "rsi", "rdx",  "r10", "r8", "r9"
			);
};
void *realloc(void *ptr, size_t size){};
void free(void *ptr){}
#endif
