.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'ENTER A DECIMAL DIGIT STRING: $'
	MSG2 DB 0AH,'THE SUM OF DIGIT IN HEX IS $'
	I DB 0
.CODE
MAIN PROC

; initializing data segment
MOV AX,@DATA
MOV DS,AX

 
    LEA DX,MSG1  ; getting offset of 1st message 
    MOV AH,9     ; string print function
    INT 21H      ; printing 1st message
	XOR BX,BX   ; reset BX 
	MOV AH,1    ; single char function

_WHILE:

	INT 21H    ; single char input
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _PRINT  ; if yes jump to _PRINT

	AND AL,0FH ; CONVERTING DIGIT TO VALUE
	
	ADD BL,AL
	
	JMP _WHILE 

_PRINT: 

 LEA DX,MSG2  ; getting offset of 2nd message 
 MOV AH,9     ; string print function
 INT 21H      ; printing 3rd message
 
 MOV AH,2
 XOR CX,CX
 MOV CL,4    ; CL=4
 MOV I,0     ; I=0 
 
_LOOP:
	CMP I,4     ; compare if I=4
	JE _EXIT     ; true than go to top for next input
	MOV DL,BH   ; DL=AH
	ROL BX,CL   ; Rotate BX to left 4 times
	SHR DL,CL   ; shift to right DL 4 times

	CMP DL,9    ; compare if DL<=9
	JLE _DIGIT  ; if true than go to _DIGIT
	ADD DL,55D  ; else ADD 55D to get the char
	JMP _OUTPUT1 ; Jump to display the character

_DIGIT:
	ADD DL,30H  ; conver number to ascii character

_OUTPUT1:
	INT 21H    ; print the char

	INC I      ; I= I+1
	JMP _LOOP  ; jump to _LOOP

 	
_EXIT:
 	
MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme