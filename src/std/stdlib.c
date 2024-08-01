#include "stddef.h"
#include "SYSCALL_DEFINITIONS/linux86_64.h"
#include "unistd.h"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 2147483647
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
         "syscall"
         : [addr] "=r" (addr)
         : [size] "r" (size), [mmap] "i" (SYSMMAP)
         : "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9", "memory"
        );
        return addr;
};

void free(void *ptr){
        asm volatile
        (
         "movq %[munmap], %%rax \n\t"
         "movq %[addr], %%rdi \n\t"
         "movq %[size], %%rsi \n\t"
         "syscall"
         :
         : [munmap] "i" (SYSMUNMAP), [addr] "r" (ptr), [size] "r" (sizeof(ptr))
         : "rax", "rdi", "rsi"  
        );
};
void *realloc(void *ptr, size_t size){
        if(ptr == NULL){
                if(size == 0){
                        return NULL;
                }
                return malloc(size);
        }else{
                if(size == 0){
                        free(ptr);
                        return NULL;
                } else{
                        asm volatile
                        (
                         "movq %[mmap], %%rax \n\t"
                         "movq %[addr], %%rdi \n\t"
                         "movq %[size], %%rsi \n\t"
                         "movq $3, %%rdx \n\t"
                         "movq $0x22, %%r10 \n\t"
                         "movq $-1, %%r8 \n\t"
                         "movq $0, %%r9 \n\t"
                         "syscall"
                         :
                         : [mmap] "i" (SYSMMAP), [addr] "r" (ptr), [size] "r" (size)
                         : "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9", "memory"
                        );
                        return ptr;

                }
        }
};
void *calloc(size_t n_items, size_t size){
        return malloc(n_items*size);
};

