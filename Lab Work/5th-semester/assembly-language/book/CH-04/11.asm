.MODEL SMALL
.STACK 100H
.DATA
	MSG DB '**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********',0AH,'**********$'  ;set 10*10 grid

.CODE
MAIN PROC

MOV AX,@DATA  ; initializing data segment
MOV DS,AX

LEA DX,MSG  ; getting offset
MOV AH,9
INT 21H   ; printig the message

MOV AH,4CH  ; dos exit function
INT 21H

MAIN ENDP   ; return from main
END MAIN
