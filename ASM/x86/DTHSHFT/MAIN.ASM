.model tiny
.stack 100h
.data
lh	db	0
hh	db	0
base	db	1
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
;split in half
	mov bl,n
	mov lh,bl
	mov hh,bl
	shr hh,4
	shl lh,4
	shr lh,4
;scrivere primo numero
        cmp hh,9
        ja char1
        scrivin hh
        jmp secondo
        char1: add hh,'A'
	sub hh,10
        scrivic hh
secondo:cmp lh,9
	ja char2
	scrivin lh
	jmp fine
	char2: add lh,'A'
	sub lh,10
	scrivic lh
	
	fine:	capo
	mov ah,4ch
	int 21h
	end start