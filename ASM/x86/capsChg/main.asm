.model tiny
.stack 100h
.data
inPhrase	DB	20	dup(0)

include ..\macro.txt
.code
START:	MOV AX,@DATA
	MOV DS,AX
	CALL phrRead
	CALL caseChg
	CAPO
	CALL phrWrt
	MOV AH,4Ch
	INT 21h
	phrRead PROC NEAR
		MOV CX,0
		MOV CL,20
		MOV SI,0
	RDLOOP:	MOV AH,01
		INT 21h
		MOV inPhrase[SI], AL
		INC SI
		LOOP RDLOOP
		RET
	ENDP
	caseChg PROC NEAR
		MOV CX,0
		MOV CL,20
		MOV SI,0
	CLOOP:	CMP inPhrase[SI], 'Z'
		JBE MAI
		JMP LEND
	MAI:	CMP inPhrase[SI], 'A'
		JAE MAI2
		JMP LEND
	MAI2:	ADD inPhrase[SI], 32
	LEND:	INC SI
		LOOP CLOOP
		RET
	ENDP
	phrWrt PROC NEAR
		MOV CX,0
		MOV CL,20
		MOV SI,0
	WRLOOP:	MOV DL,inPhrase[SI]
		MOV AH,02
		INT 21h
		INC SI
		LOOP WRLOOP
		RET
	ENDP

	END START