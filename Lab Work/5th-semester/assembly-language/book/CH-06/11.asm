.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 0AH,'ENTER A HEX DIGIT: $'
MSG2 DB 0AH,'IN DECIMAL IT IS $'
MSG3 DB 0AH,'DO YOU WANT TO DO IT AGAIN? $'
MSG4 DB 0AH,'ILLEGAL CHARACTER - ENTER 0..9 OR A..F: $'
MSG5 db 0AH,'YOU HAVE FAILED TO ENTER HEX DIGIT 3 TIMES$'
CHAR DB ?
.CODE
MAIN PROC

;initializing data segment
MOV AX,@DATA
MOV DS,AX

MOV CL,0

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

	INC CL  ; count number of failure in input
	CMP CL,3  ; compare with 3
	JE _TER ; if it is 3 times, terminate the program

	LEA DX,MSG4
	MOV AH,9
	INT 21H

	JMP FRM_IL  ; jump above

	NEXT:
	MOV CL,0  ; setting CL to zero

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
 
		JMP _WHILE ; jump to function name _EXIT below

	DIGIT:

		;for digit, print the 2nd message
		LEA DX,MSG2
		MOV AH,9
		INT 21H

		; print the digit
		MOV AH,2
		MOV DL,BL
		INT 21H


	_WHILE:

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
		JMP _EXIT

_TER:

LEA DX,MSG5
MOV AH,9
INT 21H

_EXIT:

;exit from dos
MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
