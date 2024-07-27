#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
void _start(){
	malloc(sizeof(size_t));
	sysexit(0);
}
