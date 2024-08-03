#if defined(__linux__) && defined(__x86_64__)
	#include "SYSCALL_DEFINITIONS/linux86_64.h"
#elif defined(__linux__) && defined(__i386__) 
	#include "SYSCALL_DEFINITIONS/linuxi386.h"
#elif defined(__linux__) && defined(__arm__)
	#include "SYSCALL_DEFINITIONS/linuxarm.h"
#else
#error "Unsupported architecture or operating system."
#endif
