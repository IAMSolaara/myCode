.model tiny
.stack 100h
.data

PW	DB	10	dup(0)
SUCCMSG	DB	"La password rispetta i parametri di sicurezza.$"
ERRMSG	DB	"La password non rispetta i parametri di sicurezza.$"

include ..\macro.txt

.code
START:
	MOV AX,@DATA
	MOV DS,AX
	CALL PSWREAD
;verifica primo char
	MOV SI,0
	CMP PW[SI], 'A'
	JB FAILMSG
	CMP PW[SI], 'Z'
	JA FAILMSG
	INC SI
;verifica secondo char
	MOV CX,5
NCLOOP:	CMP PW[SI], 'a'
	JB FAILMSG
	CMP PW[SI], 'z'
	JA FAILMSG
	INC SI
	LOOP NCLOOP
;verifica settimo char
	CMP PW[SI], '.'
	JNE FAILMSG
	INC SI
;verifica ottavo char
	MOV CX,3
NMLOOP:	CMP PW[SI], '0'
	JB FAILMSG
	CMP PW[SI], '9'
	JA FAILMSG
	INC SI
	LOOP NMLOOP
	CAPO
	STRING SUCCMSG
	JMP MAINEND
FAILMSG:CAPO
	STRING ERRMSG
MAINEND:MOV AH,4Ch
	INT 21h
;proc lettura
	PSWREAD PROC NEAR
		MOV CX,10
		MOV SI,0
	RDLOOP:
		LEGGIC PW[SI]
		INC SI
		LOOP RDLOOP
		RET
		ENDP
	END START
;1 CapLetter
;five noncaps letter
;1 dot
;three numbers
;e.g.=Edivan.123