.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'TYPE A HEX NUMBER, 0 - FFFF : $'
	MSG2 DB 0AH,'ILLEGAL HEX DIGIT, TRY AGAIN: $'
	MSG3 DB 0AH,'THE SUM IS $' 
	I DB 0
.CODE
MAIN PROC

; initializing data segment
MOV AX,@DATA
MOV DS,AX



JMP _TOP     ; jump to TOP

_ILLIGAL:    ; for printing illegal error message
	LEA DX,MSG2  ; getting offset of 2nd message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 2nd message

_TOP:  
    LEA DX,MSG1  ; getting offset of 1st message 
    MOV AH,9     ; string print function
    INT 21H      ; printing 1st message
	XOR BX,BX   ; reset BX 
	MOV CL,4    ; CL = 4
	MOV AH,1    ; single char function

_WHILE1:

	INT 21H    ; single char input
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _2ND_INPUT  ; if yes jump to _PRINT

	CMP AL,'0'  ; check if AL<0
	JL _ILLIGAL ; if yes, jump to _ILLIGAL
	CMP AL,'F'  ; check if AL>F
	JG _ILLIGAL ; if yes, jump to _ILLIGAL


	CMP AL,39H  ; check whether AL contain digit or letter
	JG _LETTER  ; if letter , jump to _LETTER

	AND AL,0FH  ; convert to digit
	JMP _SHIFT  ; go to _SHIFT

_LETTER:
  	SUB AL,37H

 _SHIFT:

 	SHL BX,CL
 	OR BL,AL

 	JMP _WHILE1 

_2ND_INPUT:

    LEA DX,MSG1  ; getting offset of 1st message 
    MOV AH,9     ; string print function
    INT 21H      ; printing 1st message
	XOR CX,CX   ; reset CX
	MOV AH,1    ; single char function

_WHILE2:

	INT 21H    ; single char input
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _PRINT  ; if yes jump to _PRINT

	CMP AL,'0'  ; check if AL<0
	JL _ILLIGAL ; if yes, jump to _ILLIGAL
	CMP AL,'F'  ; check if AL>F
	JG _ILLIGAL ; if yes, jump to _ILLIGAL


	CMP AL,39H  ; check whether AL contain digit or letter
	JG _LETTER1  ; if letter , jump to _LETTER

	AND AL,0FH  ; convert to digit
	JMP _SHIFT1  ; go to _SHIFT

_LETTER1:
  	SUB AL,37H

 _SHIFT1:
    ; SHIFT BX 4 TIME MANUALLY... BECAUSE WE USING CX REGISTER FOR SAVING DATA
 	SHL CX,1
 	SHL CX,1
 	SHL CX,1
 	SHL CX,1
 	
 	OR CL,AL

 	JMP _WHILE2

    
    
    
    

_PRINT: 

 LEA DX,MSG3  ; getting offset of 3rd message 
 MOV AH,9     ; string print function
 INT 21H      ; printing 3rd message
 ADD BX,CX
 JNC _NXT

 MOV AH,2
 MOV DL,31H  ; if there is a carry ... print it
 INT 21H

_NXT:
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