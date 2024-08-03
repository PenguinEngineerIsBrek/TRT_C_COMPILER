#include "unistd.h"
#include "stdio.h"
#include "iso646.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
int main(){
	syswrite(1, "Hi!\n", 4);
	int *data = calloc(5, sizeof(int));
	free(data);
	return 0;
}
