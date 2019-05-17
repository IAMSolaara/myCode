.model small
.stack 100h
.data
tuzi DB "Tua zia e' bruttina e la cosa non mi piace proprio capito che ti sfascio molto tanto col cinto di papa' e il gelatino alla fragola che ti piace tanto tanto te lo vedi l'anno prossimo$"
cpt DB "Capito? [y/n]$"
.code
INIZIO:
  MOV AX, @DATA
  MOV DS,AX
  LEA DX,tuzi
  MOV AH,09h
  INT 21h
  LEA DX,cpt
  MOV AH,09h
  INT 21h
  MOV AH,01h
  INT 21h
  MOV AH,4Ch
  INT 21h
  END INIZIO