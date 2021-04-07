.MODEL SMALL
.STACK 100H
.DATA
	
	MSG1 DB 0AH,'***********',0AH,'***********',0AH,'***********',0AH,'***********',0AH,'***********',0AH,'****'
	VAL1 DB ?  ; first initial
	VAL2 DB ?  ; second initial
	VAL3 DB ?  ; third initial
	MSG2 DB '****',0AH,'***********',0AH,'***********',0AH,'***********',0AH,'***********',0AH,'***********$'  ;set 11*11 arterisks  grid

.CODE
MAIN PROC

MOV AX,@DATA  ; initializing data segment
MOV DS,AX

; printing '?'
MOV AH,2
MOV DL,'?'
INT 21H

MOV DL,0AH ; printing new line
INT 21H

MOV AH,1   		 ; first input
MOV VAL1,AL  	 ; moving the value of AL to VAL1
INT 21H          ; second input
MOV VAL2,AL      ; moving the value of AL to VAL2
INT 21H          : third input
MOV VAL3,AL      ; moving the value of AL to VAL3

LEA DX,MSG1  ; getting offset
MOV AH,9
INT 21H   ; printig the message

MOV AH,2
MOV DL,07H  ; beep
INT 21H

MOV AH,4CH  ; dos exit function
INT 21H

MAIN ENDP   ; return from main
END MAIN
