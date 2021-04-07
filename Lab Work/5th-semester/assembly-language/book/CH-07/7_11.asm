.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'TYPE A BINARY NUMBER, UP TO 16 DIGITS: $'
	MSG2 DB 0AH,'ILLEGAL BINARY DIGIT, TRY AGAIN: $';
	MSG3 DB 'IN HEX IT IS $'
	I DB 0
.CODE
MAIN PROC

; initializing data segment
MOV AX,@DATA
MOV DS,AX

LEA DX,MSG1  ; getting offset of 1st message 
MOV AH,9     ; string print function
INT 21H      ; printing 1st message

JMP _TOP     ; jump to TOP

_ILLIGAL:    ; for printing illegal error message
	LEA DX,MSG2  ; getting offset of 2nd message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 2nd message

_TOP:
	XOR BX,BX   ; reset BX 
	MOV AH,1    ; single char function

_WHILE:

	INT 21H    ; single char input
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _PRINT  ; if yes jump to _PRINT

	CMP AL,'0'  ; check if AL<0
	JL _ILLIGAL ; if yes, jump to _ILLIGAL
	CMP AL,'1'  ; check if AL>1
	JG _ILLIGAL ; if yes, jump to _ILLIGAL

	AND AL,0FH  ; getting the digit
	SHL BX,1    ; shift 1 bit to left
	OR BL,AL    
 	JMP _WHILE

_PRINT:

	LEA DX,MSG3  ; getting offset of 1st message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 1st message

	XOR DX,DX    ; Clear DX
	MOV CL,4  ; CL = 4
	MOV I,0
	MOV AH,2     ; single char output function

_WHILE1:
	
	CMP I,4
	JE _EXIT

	MOV DL,BH   ; DL = BH
	SHR DL,CL  ; shift DL , 4 time to right
	ROL BX,CL  ; shift BX to 1 bit left 

	CMP DL,9  ; if it is digit
	JLE _DIGIT  ; yes, then go to _DIGIT
	ADD DL,55D  ; else make it a letter
	JMP _OUTPUT  ;output function

_DIGIT:
	ADD DL,30H  ; conver number to ascii character

_OUTPUT:
	INT 21H    ; print the char

	INC I      ; I= I+1
	JMP _WHILE1  ; jump to _LOOP

_EXIT:

MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme
