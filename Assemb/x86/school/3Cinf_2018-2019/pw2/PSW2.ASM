.model tiny
.stack 100h
.data
PW	DB	'P','i','s','s','l','o','v','e','r','5','4','!'
PWIN	DB	12	dup(0)
ERRMSG	DB	"Le password non combaciano.$"
SUCCMSG	DB	"Le password combaciano.$"

include ..\macro.txt

.code
START:	MOV AX,@DATA
	MOV DS,AX
	CALL PSWREAD
	CAPO
	CALL MATCH
	
	
	MOV AH,4Ch
	INT 21h
	PSWREAD PROC NEAR
	MOV CX,12
	MOV SI,0
	RDLOOP:
		LEGGIC PWIN[SI]
		INC SI
		LOOP RDLOOP
		RET
		ENDP
	MATCH PROC NEAR
	MOV CX,12
	MOV SI,0
	MATCHLP:
		MOV AL,PWIN[SI]
		CMP PW[SI], AL
		JNE BRUT
		INC SI
		LOOP MATCHLP
		STRING SUCCMSG
		CAPO
		JMP FINE
	BRUT:	STRING ERRMSG
		CAPO
	FINE:	RET
		ENDP
	END START