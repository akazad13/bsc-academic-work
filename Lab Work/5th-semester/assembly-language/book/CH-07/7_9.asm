.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 0AH,'TYPE A CHARACTER: $'
	MSG2 DB 0AH,'THE ASCII CODE OF $';
	MSG3 DB ' IN HEX IS $'
	I DB 0
.CODE
MAIN PROC

; initializing data segment
MOV AX,@DATA
MOV DS,AX

_TOP:
	LEA DX,MSG1  ; getting offset of 1st message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 1st message
	MOV AH,1     ; single character inpur function
	INT 21H      ; input a character

	CMP AL,0DH   ; checking for carriage return
	JE _EXIT

	MOV BL,AL    ; mov character to BL register

	LEA DX,MSG2  ; getting offset of 2nd message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 2nd message

	MOV AH,2
	MOV DL,BL    ; print the data
	INT 21H

	LEA DX,MSG3  ; getting offset of 3rd message 
	MOV AH,9     ; string print function
	INT 21H      ; printing 3rd message

	MOV AH,2
	MOV CL,4    ; CL=4
	MOV I,0     ; I=0
 
_LOOP:
	CMP I,4     ; compare if I=4
	JE _TOP     ; true than go to top for next input
	MOV DL,BH   ; DL=AH
	ROL BX,CL   ; Rotate BX to left 4 times
	SHR DL,CL   ; shift to right DL 4 times

	CMP DL,9    ; compare if DL<=9
	JLE _DIGIT  ; if true than go to _DIGIT
	ADD DL,55D  ; else ADD 55D to get the char
	JMP _OUTPUT ; Jump to display the character

_DIGIT:
	ADD DL,30H  ; conver number to ascii character

_OUTPUT:
	INT 21H    ; print the char

	INC I      ; I= I+1
	JMP _LOOP  ; jump to _LOOP

_EXIT:

MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme
