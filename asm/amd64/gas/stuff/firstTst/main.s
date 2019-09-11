	.text
	.global _start

_start:
# use write syscall
	movq $1, %rax
# select stdout write destination
	movq $1, %rdi
# use variable msg as string to write
	movq $msg, %rsi
# write 5 chars
	movq $5, %rdx
# do syscall
	syscall
#return to OS
	mov $60, %rax
	xor %rdi, %rdi
	syscall
.data
	msg: .ascii "Test\n"
