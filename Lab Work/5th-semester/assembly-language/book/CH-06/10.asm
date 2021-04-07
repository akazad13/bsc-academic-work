.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 0AH,'ENTER A HEX DIGIT: $'
MSG2 DB 0AH,'IN DECIMAL IT IS $'
MSG3 DB 0AH,'DO YOU WANT TO DO IT AGAIN? $'
MSG4 DB 0AH,'ILLEGAL CHARACTER - ENTER 0..9 OR A..F: $'
CHAR DB ?
.CODE
MAIN PROC

;initializing data segment
MOV AX,@DATA
MOV DS,AX

TOP:
	;print user promt
	LEA DX,MSG1
	MOV AH,9 ;function for printing string
	INT 21H

	FRM_IL:

	;input hex digit from the user
	MOV AH,1
	INT 21H
	MOV BL,AL ; moving the value to BL register

	CMP BL,'F'
	JNLE ILLEGAL ; if illigal char has been pressed jump to ILLEGAL scope
	JMP NEXT

	ILLEGAL:  ; if a illegal char has been intered

	LEA DX,MSG4
	MOV AH,9
	INT 21H

	JMP FRM_IL  ; jump above

	NEXT:

	CMP BL,'A' ;check if it is digit or char
	JL DIGIT  ; if digit , jump to DIGIT function


		;print the 2nd message
		LEA DX,MSG2
		MOV AH,9
		INT 21H;

		MOV AH,2
		MOV DL,'1' ;print the 1st digit of hex number A to F
		INT 21H

		;subtract by A to get the second digit
		SUB BL,'A'
		ADD BL,30H

		;print the 2nd digit
		MOV DL,BL
		INT 21H
 
		JMP _EXIT ; jump to function name _EXIT below

	DIGIT:

		;for digit, print the 2nd message
		LEA DX,MSG2
		MOV AH,9
		INT 21H

		; print the digit
		MOV AH,2
		MOV DL,BL
		INT 21H


	_EXIT:

		;print the 3rd message
		LEA DX,MSG3
		MOV AH,9
		INT 21H

		MOV AH,1
		INT 21H

		;check wheter user will carry on or exit
		CMP AL,'Y'
		JE TOP  ; jump to top of the programe to get another input
		CMP AL,'y'
		JE TOP ; jump to top of the programe to get another input

;exit from dos
MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
