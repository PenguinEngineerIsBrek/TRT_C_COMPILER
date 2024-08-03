#ifndef STDIO_H
#define STDIO_H
#include "stddef.h"
#include "link_os.h"
// SYSTEM CALLS
void sysexit(int code);
void syswrite(unsigned fd, char *buffer, size_t length);
void sysread(unsigned fd, char *var, size_t length);
void sysfread();
void sysfclose();


// STD FUNCTIONS


#endif
