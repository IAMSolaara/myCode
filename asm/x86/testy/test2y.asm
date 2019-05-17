.model small
.stack 100h
.data
tuzi DB 13,10,"Tua zia e' bruttina$",13,10

.code
INIZIO:
  MOV AX, @DATA
  MOV DS,AX
  LEA DX,tuzi
  MOV AH,09h
  INT 21h
  MOV AH,4Ch
  INT 21h
  END INIZIO