.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'TYPE A BINARY NUMBER, UP TO 8 DIGITS: $'
	MSG2 DB 0AH,'ILLEGAL BINARY DIGIT, TRY AGAIN: $';
	MSG3 DB 0AH,'THE BINARY SUM IS $'
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
	MOV AH,1    ; single char function 


_WHILE1:
    INT 21H

	CMP AL,0DH ; check whether AL = carriage return or not
	JE _2ND_INPUT  ; if yes jump to _PRINT

	CMP AL,'0'  ; check if AL<0
	JL _ILLIGAL ; if yes, jump to _ILLIGAL
	CMP AL,'1'  ; check if AL>1
	JG _ILLIGAL ; if yes, jump to _ILLIGAL

	AND AL,0FH  ; getting the digit
	SHL BL,1    ; shift 1 bit to left
	OR BL,AL    
 	JMP _WHILE1


_2ND_INPUT:
    LEA DX,MSG1  ; getting offset of 1st message 
    MOV AH,9     ; string print function
    INT 21H      ; printing 1st message
	MOV AH,1    ; single char function  


_WHILE2:
    INT 21H
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _CALCULATION  ; if yes jump to _PRINT

	CMP AL,'0'  ; check if AL<0
	JL _ILLIGAL ; if yes, jump to _ILLIGAL
	CMP AL,'1'  ; check if AL>1
	JG _ILLIGAL ; if yes, jump to _ILLIGAL

	AND AL,0FH  ; getting the digit
	SHL BH,1    ; shift 1 bit to left
	OR BH,AL    
 	JMP _WHILE2

_CALCULATION:
    
LEA DX,MSG3  ; getting offset of 1st message 
MOV AH,9     ; string print function
INT 21H      ; printing 1st message
MOV AH,2     ; single character output function

XOR CX,CX
MOV CL,8     ; setting CL to 8 for Looping

ADD BL,BH  ; adding two number


JNC TOP2

MOV DL,31H  ; if there is a carry ... print it
INT 21H



TOP2:
	MOV DL,0 ; settiong DL=0
	SHL BL,1 ; Shift BL to one bit left
	JNC PRINT ; jump if carry flag != 1

	MOV DL,1  ; set DL=1

	PRINT:

	ADD DL,30H ; Add 30H for ancii char output
	INT 21H    ; output the binary digit

	LOOP TOP2   ; loop condition




_EXIT:

MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme