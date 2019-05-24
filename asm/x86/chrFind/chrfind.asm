.model tiny
.stack 100h
.data

include ..\macro.txt

posarr		DB	10	dup(0)
numarr		DB	10	dup(0)
findnm		DB	0
ftimes		DB	0
loadmsg		DB	"Inserire un carattere.$"
findmsg		DB	"Che carattere devo trovare?$"
foundmsg1	DB	"Il carattere e' stato trovato $"
foundmsg2	DB	" volte.$"
posmsg		DB	"Il carattere si trova nelle posizioni$"

.code
START:	MOV AX,@DATA
	MOV DS,AX
	CALL ARRLOAD
	CALL ARRFIND
	CALL POSLIST
	MOV AH,4Ch
	INT 21h
	ARRLOAD PROC NEAR
		MOV CX,10
		MOV SI,0
	LOAD:	STRING LOADMSG
		CAPO
		LEGGIC NUMARR[SI]
		CAPO
		INC SI
		LOOP LOAD
		RET
	ENDP
	ARRFIND PROC NEAR
		STRING FINDMSG
		CAPO
		LEGGIC FINDNM
		CAPO
		MOV CX,10
		MOV SI,0
		MOV DI,0
	FIND:	MOV BL,NUMARR[SI]
		CMP BL,FINDNM
		JE POSMV
		JMP LEND
	POSMV:	MOV AX,SI
		MOV POSARR[DI],AL
		INC DI
		INC FTIMES
	LEND:	INC SI
		LOOP FIND
		RET
	ENDP
	POSLIST PROC NEAR
		STRING FOUNDMSG1
		SCRIVIN FTIMES
		STRING FOUNDMSG2
		CAPO
		STRING POSMSG
		CAPO
		MOV CX,DI
		MOV SI,0
	POSLP:	SCRIVIN POSARR[SI]
		CAPO
		INC SI
		LOOP POSLP
		RET
	ENDP
	END START