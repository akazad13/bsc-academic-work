.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 'TYPE A CHARACTER: $'
	MSG2 DB 0AH,'THE ASCII CODE OF ';
	CHAR DB ?,' $'
	MSG3 DB 'IN BINARY IS $'
	MSG4 DB 0AH,'THE NUMBER OF 1 BITS IS $'
	CNT DB 0
.CODE
MAIN PROC

; initializing data segment
MOV AX,@DATA
MOV DS,AX


LEA DX,MSG1  ; getting offset of 1st message 
MOV AH,9     ; string print function
INT 21H      ; printing 1st message
MOV AH,1     ; single character inpur function
INT 21H      ; input a character


MOV CHAR,AL  ; mov character to CHAR variable
MOV BL,AL    ; mov character to BL register
MOV CL,8     ; setting CL to 8 for Looping
 
LEA DX,MSG2  ; getting offset of 2nd message 
MOV AH,9     ; string print function
INT 21H      ; printing 2nd message

LEA DX,MSG3  ; getting offset of 3rd message
INT 21H      ; printing 3rd message

MOV AH,2     ; single character output function


TOP:
	MOV DL,0 ; settiong DL=0
	SHL BL,1 ; Shift BL to one bit left
	JNC PRINT ; jump if carry flag != 1

	MOV DL,1  ; set DL=1
	INC CNT   ; increament CNT

	PRINT:

	ADD DL,30H ; Add 30H for ancii char output
	INT 21H    ; output the binary digit

	LOOP TOP   ; loop condition

LEA DX,MSG4   ; getting offset of 4th message
MOV AH,9      ; string print function
INT 21H       ; printing the string

MOV AH,2    ; single character output function
MOV DL,CNT  ; DL=CNT
ADD DL,30H  ; DL = DL+30H
INT 21H     ; output DL

MOV AH,4CH  ; dos return function
INT 21H  ; return from the dos

MAIN ENDP
END MAIN  ; terminate programme
