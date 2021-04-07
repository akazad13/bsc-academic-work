.MODEL SMALL
.STACK 100H
.DATA
	A DB 0
	B DB 0
.CODE
MAIN PROC

MOV CX,256   ; setting the max loop value
MOV AH,2  ; single character print function

TOP:
	
	CMP B,9  ; after 10 data this will print a new line
	JG PRINT ; jump to PRINT function if b=10
	MOV DL,A ; preparing for printing A
	INT 21H  ; print A
	INC A    ; increament A
	INC B    ; increament B
	LOOP TOP ; if CX!=0 , go to TOP
	JMP _NEXT ; else go to _NEXT

PRINT:
	MOV DL,0AH 
	INT 21H ; printing new line
	MOV B,0 ; setting value B to 0
	JMP TOP

_NEXT:

MOV AH,4CH ; DOS return function
INT 21H


MAIN ENDP 
END MAIN ; end the process



