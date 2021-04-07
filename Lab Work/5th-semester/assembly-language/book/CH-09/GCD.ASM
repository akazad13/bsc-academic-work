.MODEL SMALL
.STACK 100H

.DATA
ILLI_MSG DB 0AH,'ILLIGAL INPUT',0AH,'$'
OVER DB  0AH,'OVERFLOW!',0AH,'$'

MSG1 DB 'M: $'
MSG2 DB 0DH,0AH,'N: $'
MSG3 DB 0DH,0AH,'GCD IS : $'

N DW ?

.CODE

MAIN PROC

MOV AX,@DATA  ;initalizing data segment
MOV DS,AX

;msg 1 print
LEA DX,MSG1  
MOV AH,9
INT 21H

CALL INDEC  ; calling INDEC procedure for 1st number
PUSH AX

;printing second msg
LEA DX,MSG2
MOV AH,9
INT 21H

CALL INDEC ; again calling INDEC procedure for second number
PUSH AX

XOR BX,BX   ; clear BX

POP BX    ; pop one number in BX
POP AX    ; pop another number in AX

CMP AX,BX  ; compare AX,BX
JL CHANGE  ; if AX<Bx
JMP TOP


CHANGE:
 XCHG AX,BX  ; exchange AX and BX


TOP:

XOR DX,DX ;clearing DX
MOV N,BX  ; N = BX
DIV N     ; Divide AX by N


CMP DX,0  ; if Dx=0
JE OUTPUT  ; yes, then go to output

MOV AX,BX  ; AX=BX
MOV BX,DX ; BX = DX
JMP TOP


OUTPUT:
;printing 3rd msg  
LEA DX,MSG3
MOV AH,9
INT 21H

MOV AX,N
CALL OUTDEC   ;calling outdec


@END:
MOV AH,4CH
INT 21H

MAIN ENDP

INCLUDE OUTDEC.ASM
INCLUDE INDEC.ASM

END MAIN
