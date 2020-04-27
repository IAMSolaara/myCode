; Lorenzo Cauli 3C
.model small
.stack 100h
.data
tree1	DB	"    #    $"
tree2	DB	"   ###   $"
tree3	DB	"  #####  $"
tree4	DB	" ####### $"
tree5	DB	"#########$"
CAPO MACRO
	MOV DL,13
	MOV AH,02h
	INT 21h
	MOV DL,10
	MOV AH,02h
	INT 21h
	ENDM
STRING MACRO MSG
	LEA DX,MSG
	MOV AH,09h
	INT 21h
	ENDM
.code
START:	MOV AX,@DATA
	MOV DS,AX
	STRING tree1
	CAPO
	STRING tree2
	CAPO
	STRING tree3
	CAPO
	STRING tree4
	CAPO
	STRING tree5
	CAPO
	MOV AH,4Ch
	INT 21h
	END START
