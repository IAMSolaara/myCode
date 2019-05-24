;Edivan Steri 3C 08/03/2019
.MODEL SMALL
.STACK 100H
.DATA

num   DB 0
dieci DB 0
MSG1  DB "Inserici la decina del numero $"
MSG2  DB "Inserici la unita' del numero $"

LEGGI MACRO N
mov ah,01h
int 21h
sub al,48
mov n,al
endm

STRINGA MACRO MSG
lea dx,msg
mov ah,09
int 21h
endm

ACAPO MACRO
mov dl,13
mov ah,02h
int 21h
mov dl,10
mov ah,02h
int 21h	
endm

SCRIVIN MACRO CAR
mov dl,car
add dl,48
mov ah,02
int 21h
ENDM

SCRIVIL MACRO CAR
mov dl,car
add dl,55
mov ah,02
int 21h
ENDM



.CODE
Inizio:
        mov ax,@data
        mov ds,ax
	
;lettura di un numero 
        STRINGA MSG1
        LEGGI num

;stampare il numero in esadecimale
        push num
        
        shr num,1
        shr num,1
        shr num,1
        shr num,1
        
        cmp num,9
        ja lettera
        jmp numero
        
        
        
        
        
        
        
        
