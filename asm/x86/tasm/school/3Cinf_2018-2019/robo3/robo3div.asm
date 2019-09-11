.model small
.stack 100h
.data
N1      DB   0
N2      DB   0
TEN	DB  10
RIS     DB   0
RISS	DB   0
RIS2	DB   0
RIS22	DB   0
RIS3	DB   0
RIS33	DB   0
Q	DB   0
QQ	DB   0
R	DB   0
RR	DB   0
MSG1 DB "Inserisci primo numero.$"
MSG2 DB "Inserisci secondo numero.$"
MSG3 DB "La somma e' $"
MSG4 DB "La differenza e' $"
MSG5 DB "Il prodotto e' $"
MSG6 DB "Il quoziente e' $"
MSG7 DB "Il resto e' $"

LEGGI MACRO N
        MOV AH,01h
        INT 21h
        SUB AL,48
        MOV N,AL
        ENDM
STRING MACRO MSG
        LEA DX,MSG
        MOV AH,09h
        INT 21h
        ENDM
SCRIVI MACRO CHR
        MOV DL,CHR
        ADD DL,48
        MOV AH,02h
        INT 21h
        ENDM
CAPO MACRO
        MOV DL,13
        MOV AH,02h
        INT 21h
        MOV DL,10
        MOV AH,02h
        INT 21h
        ENDM

.code
INIZIO:
        MOV AX,@DATA
        MOV DS,AX
        STRING MSG1
        CAPO
        LEGGI N1
        CAPO
        STRING MSG2
        CAPO
        LEGGI N2
        CAPO
        ;somma
        MOV AL,N1
        ADD AL,N2
        MOV AH,0
        DIV TEN
        MOV RIS,AL
        MOV RISS,AH
        STRING MSG3
        SCRIVI RIS
        SCRIVI RISS
        CAPO
        ;sottrazione
        MOV AL,N1
        SUB AL,N2
        MOV AH,0
        DIV TEN
        MOV RIS2,AL
        MOV RIS22,AH
        STRING MSG4
        SCRIVI RIS2
        SCRIVI RIS22      
        CAPO
	;moltiplicazione
        MOV AL,N1
        MUL N2
        MOV AH,0
        DIV TEN
        MOV RIS3,AL
        MOV RIS33,AH
        STRING MSG5
        SCRIVI RIS3
        SCRIVI RIS33
        CAPO
        ;divisione
        MOV AL,N1
        MOV AH,0
        DIV N2
        MOV Q,AL
        MOV R,AH
        MOV AH,0
        DIV TEN
        MOV QQ,AL
        MOV AX,0
        MOV AL,R
        DIV TEN
        MOV RR,AL
        STRING MSG6
        SCRIVI QQ
        SCRIVI Q
        CAPO
        STRING MSG7
        SCRIVI RR
        SCRIVI R
        CAPO
        MOV AH,4Ch
        INT 21h
        END INIZIO