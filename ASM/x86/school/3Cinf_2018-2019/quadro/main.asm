.model small
.stack 100h
.data
TEN	DB	10
LMSG	DB	"Inserire larghezza.$"
HMSG	DB	"Inserire altezza.$"
HASH	DB	"#$"
l	DB	12
h	DB	6
LEGGI MACRO N
	MOV AH,01h
	INT 21h
	SUB AL,48
	MUL TEN
	MOV N,AL
	MOV AH,01h
	INT 21h
	SUB AL,48
	ADD N,AL	
	ENDM
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
START:
	MOV AX,@DATA
	MOV DS,AX
	STRING LMSG
	CAPO
	LEGGI L		;lettura larghezza
	CAPO
	STRING HMSG
	CAPO
	LEGGI H		;lettura altezza
	CAPO
	MOV CX,0	;zerofill CX
	MOV CL,H	;spostamento di H in CL
HEIGHT:	PUSH CX		;loop altezza e push di cx per preservare il loop
	MOV CL,L	;spostamento di L in CL
DRAW:	STRING HASH	;scrittura cancelletto
	LOOP DRAW	;loop larghezza fine
	POP CX		;riporto loop altezza alla fine di loop larghezza
	CAPO		;ritorno a capo
	LOOP HEIGHT	;loop altezza fine
	MOV AH,4Ch
	INT 21h
	END START