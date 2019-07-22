.model tiny
.stack 100h
.data
ten	db	10
n	db	0
evmsg	db	"Il numero e' paro.$"
oddmsg	db	"Il numero e' disparo.$"

include ..\macro.txt

.code

start:	mov ax,@data
	mov ds,ax
	leggi2n n
	capo
	mov cx,8
loopp:	shl n,1
	jc uno
	scrivin 0
	jmp fini
uno:	scrivin 1
fini:	loop loopp
	capo
	mov ah,4ch
	int 21h
	end start