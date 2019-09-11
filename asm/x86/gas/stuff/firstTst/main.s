	.text
	.global _start

_start:
	mov $10, %eax
	mov $60, %rax
	xor %rdi, %rdi
	syscall
