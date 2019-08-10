.model small
.stack 100h
.data
	MSG DB "Test$"
.code
START:
	MOV AX,@DATA
	MOV DS,AX
	JMP TESTA
TESTA:
	LEA DX,MSG
	MOV AH,09h
	INT 21h
	MOV AH,4Ch
	INT 21h
	END TESTA