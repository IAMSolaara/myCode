  ;; INES HEADER
  .inesprg 1
  .ineschr 1
  .inesmap 0
  .inesmir 1

  ;; BANK 0 CONTENT
  .bank 0
  .org $8000
start:
  lda #%00001000
  sta $2000
  lda #%00011110
  sta $2001

  ;; BANK 1 CONTENT
  .bank 1
  .org $FFFA
  .dw 0
  .dw start
  .dw 0
