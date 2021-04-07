.MODEL SMALL
.STACK 100H
.DATA
    A DB ?
    B DB ?
    C DB ?

.CODE
MAIN PROC

;printing '?'
MOV AH,2
MOV DL,'?'
INT 21H

MOV DL,0AH  ; printing a new line
INT 21H

MOV AH,1   ; input function
INT 21H    ; first char input
MOV A,AL   ; mov to A
INT 21H    ; second char input
MOV B,AL   ; mov to B


MOV AH,2
MOV DL,0AH  ; Again printing a new line
INT 21H

MOV BL,B    ; mov B to BL register
CMP A,BL    ; compare with A

JNG _NEXT   ; if A is not greater than B , jump to _NEXT

; assigning B to C
MOV BL,B  
MOV C,BL 
JMP _PRINT  ; unconditional jump to _PRINT

_NEXT:
   ; Assigning A to C
   MOV BL,A
   MOV C,BL
  
_PRINT:

MOV AH,2  ;single char print function
MOV DL,C  ; mov the smallest Character to DL
INT 21H   ; print the smallest Character

MOV AH,4CH ; DOs return function
INT 21H


MAIN ENDP 
END MAIN ; end the process



