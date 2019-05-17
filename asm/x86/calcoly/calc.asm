.model tiny
.stack 100h
.data
  N1 DB 0
  N2 DB 0
  RES DB 0
  MSG1 DB "Inserire primo numero.$",13,10
  MSG2 DB "Inserire secondo numero.$",13,10
.code
INIZIO:
  MOV AX, @DATA
  MOV DS,AX
  LEA DX,MSG1
  MOV AH,09h
  INT 21h; RICHIESTA
  MOV AH,01h
  INT 21h
  SUB AL,48; LETTO
  MOV N1,AL; SPOSTATO N1
  LEA DX,MSG2
  MOV AH,09h
  INT 21h; RICHIESTA
  MOV AH,01h
  INT 21h
  SUB AL,48; LETTO
  ADD AL,N1; SOMMA N1 N2
  
  
  
  
  
  MOV AH,4Ch
  INT 21h
  END INIZIO