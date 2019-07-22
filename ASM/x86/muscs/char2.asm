;Daniel Muscas,Gabriel Testa 9/11/18
;testo: dati due numeri N1 e N2 eseguire la somma,sottrazione,,moltiplicazione,divisione e visualizzarli in caratteri

.model small
.stack 100h
.data 
n1 db 0
n2 db 0
q db 0
r db 0
r1 db 0
r2 db 0
r3 db 0
op db 0
dieci db 10
re db 0
MSG1 db " inserisci il primo numero $"
MSG2 db " inserisci il secondo numero $"
MSG3 db " il risultato vale $"
MSG8 db " inserisci operatore $"

;dichiarazione macro istruzioni

stringa macro MSG
         lea dx,MSG
         mov ah,09h
         int 21h
         endm

akapo macro
         mov dl,13
         mov ah,02h
         int 21h
         mov dl,10
         mov ah,02h
         int 21h
         endm

leggi macro n
         mov ah,01h
         int 21h
         sub al,48
         mov n,al
         endm
         
scrivi macro r
         mov dl,r
         add dl,48
         mov ah,02
         int 21h
         endm  
         
cifre macro num
         mov ax, 0
         mov al, num
      
         div dieci                                    
         mov q,al
         mov re,ah 
         scrivi q
         scrivi re
         endm

leggichar macro c
         mov ah,01
         int 21h
	 mov c, al                                                                                                              
         endm
.code                        
inizio:                      
         mov ax,@data
         mov ds,ax

;output stringa        
         stringa MSG1
         
;input primo numero                                                                                                                                                              
         leggi n1                                                                                                                                                                      
         
;input carattere          
         akapo
         stringa MSG8
         leggichar op
         
;output stringa        
         akapo
         stringa MSG2
         
;input secondo numero                                                                                                                                  
         leggi n2                                                                                                                                                                      
 
;confronto dei segni    
         cmp op,'+'
         je somma
         cmp op,'-'
         je sottrazione
         cmp op,'*'
         je moltiplicazione
         cmp op,'/'
         je divisione
        
somma:     
         mov ah,n1
         add ah,n2
         mov r, ah
         
         jmp esci
        
sottrazione:
         mov bh,n1
         sub bh,n2
         mov r, bh
        
         jmp esci
         
moltiplicazione:
         mov al,n1
         mul n2
         mov r,al
       
         jmp esci

divisione:  
         mov ax,0
         mov al, n1
         div n2
         mov r,al
         jmp esci
         
esci:
         akapo
         stringa MSG3 
         cifre r
      
        mov ah,4ch
        int 21h

end inizio