.model tiny
.stack 100h
.data
outchr	db	'a'

include ..\macro.txt

.code

start:
	mov ax,@data
	mov ds,ax
	
	mov cl,outchr
	push cx
	call scrivi
	pop cx
	
	mov ah,4ch
	int 21h
	scrivi proc
		push ax
		push dx
		push bp
		mov bp,sp
		mov dl,[bp+8]
		mov ah,02
		int 21h
		pop bp
		pop dx
		pop ax
		ret
		ret
	endp
	
	end start