.global _start

.text

_start:
	movq $1, %rax
	movq $1, %rdi
	movq $msg, %rsi
	movq $4, %rdx
	syscall

	movq $60, %rax
	movq $0, %rdi
	syscall

msg:
	.ascii "Hi!\n"
