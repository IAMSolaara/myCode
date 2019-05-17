.model small
.stack 100h
.data
  N1 DB 12
  N1W DW 12
  N2 DB 5
  R1 DB	0
  R2 DB	0
  R3 DW	0
  Q DB 0
  R DB 0
.code
INIZIO:
  MOV AX, @DATA
  MOV DS,AX
  MOV AL, N1
  ADD AL, N2
  MOV R1, AL
  MOV AL, N1
  SUB AL, N2
  MOV R2, AL
  MOV AL, N1
  MOV CH, N2
  MUL CH
  MOV R3, AX
  MOV AX, N1W
  MOV CH, N2
  DIV CH
  MOV Q, AL
  MOV R, AH
  MOV AH,4Ch
  INT 21h
  END INIZIO