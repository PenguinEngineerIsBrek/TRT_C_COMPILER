#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "unistd.h"
int main();
void _start(){
	long int heap_size = 4096;
	long int init_size = brk(0);
	long int brk_size = init_size + heap_size;
	brk((void*)brk_size);
	main();
	sysexit(0);
}
