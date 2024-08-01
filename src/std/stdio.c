#include "stdio.h"
// SYSTEM CALLS
void sysexit(int code){
        asm volatile
        (
                "syscall"
                :
                :"a"(SYSEXIT), "D"(code)
        );
}

void syswrite(unsigned fd, char *buffer, size_t length){
        asm volatile
        (
                "syscall"
                :
                :"a"(SYSWRITE), "D"(fd), "S"(buffer), "d"(length)
        );
}
void sysread(unsigned fd, char *var, size_t length){
        asm volatile
        (
                "syscall"
                :
                :"a"(SYSREAD), "D"(fd), "S"(var), "d"(length)
                :"memory"
        );
}
void sysfread(){}
void sysfclose(){}


// STD FUNCTIONS
