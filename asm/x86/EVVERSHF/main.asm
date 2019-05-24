.model tiny
.stack 100h
.data
n	db	0
evmsg	db	"Il numero e' paro.$"
oddmsg	db	"Il numero e' disparo.$"

include ..\macro.txt

.code

start:	mov ax,@data
	mov ds,ax
	leggin n
	capo
	shr n,1
	jc disparo
	string evmsg
	jmp fini
disparo:string oddmsg
fini:	capo
	mov ah,4ch
	int 21h
	end start