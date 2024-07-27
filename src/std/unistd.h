#ifndef UNISTD_H
#define UNISTD_H
void syscall(int number){
	asm volatile
	(
	 "syscall"
	 :
	 :"a"(number)
	);
}
#endif
