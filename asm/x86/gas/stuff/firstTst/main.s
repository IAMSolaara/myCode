	.text
	.global _start

_start:
# put message in stdout
	mov $1, %rax
	mov $1, %rdi
	mov %rsi, msg
	mov $13, %rdi
	syscall
#return to OS
	mov $60, %rax
	xor %rdi, %rdi
	syscall
.data
	msg: .ascii "Test\n"
