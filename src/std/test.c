
#include "stdio.h"
#include <stdio.h>
int main(){
	char *str;
	sysread(0, str, 6);
       	syswrite(1, str, 6);
	sysexit(0);
}
