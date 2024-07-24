//Linux 64-bit
#ifndef SYS_DEFS_LIN64
#define SYS_DEFS_LIN64
#include "stddef.h"
#define SYSEXIT 60
#define SYSWRITE 1
#define SYSREAD 0

// SYSTEM CALLS
void sysexit(int code){
	asm volatile
	(
		"syscall"
		:
		:"a"(SYSEXIT), "D"(code)
	);
}

void syswrite(unsigned fd, char  *buffer, size_t length){
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
	);
}
void sysfread(){}
void sysfclose(){}


// STD FUNCTIONS


#endif
