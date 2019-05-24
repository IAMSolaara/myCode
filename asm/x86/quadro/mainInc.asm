.model small
.stack 100h
.data
TEN	DB	10
LMSG	DB	"Inserire larghezza.$"
HMSG	DB	"Inserire altezza.$"
HASH	DB	"#$"
l	DB	12
h	DB	6

include ..\macro.txt

.code
START:
	MOV AX,@DATA
	MOV DS,AX
	STRING LMSG
	CAPO
	LEGGI2C L		;lettura larghezza
	CAPO
	STRING HMSG
	CAPO
	LEGGI2C H		;lettura altezza
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