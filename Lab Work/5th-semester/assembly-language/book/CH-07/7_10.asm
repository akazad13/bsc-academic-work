.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'TYPE A HEX NUMBER (0 TO FFFF) : $'
	MSG2 DB 0AH,'ILLEGAL HEX DIGIT, TRY AGAIN: $';
	MSG3 DB 'IN BINARY IT IS $'
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
	MOV CL,4    ; CL = 4
	MOV AH,1    ; single char function

_WHILE:

	INT 21H    ; single char input
	CMP AL,0DH ; check whether AL = carriage return or not
	JE _PRINT  ; if yes jump to _PRINT

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

 	JMP _WHILE

_PRINT:

	LEA DX,MSG3  ; getting offset of 1st message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 1st message

	XOR DX,DX    ; Clear DX
	MOV CX,16    ; CX = 16
	MOV AH,2     ; single char output function

_WHILE1:

	SHL BX,1  ; shift BX to 1 bit left 
	JNC _ZERO ; jump if not carry

	MOV DL,'1' ; DL=1
	JMP _DIS   ; jump to _DIS

_ZERO:
	MOV DL,'0' ; DL=0
_DIS:
	INT 21H  ; display binary digit

LOOP _WHILE1

MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme
