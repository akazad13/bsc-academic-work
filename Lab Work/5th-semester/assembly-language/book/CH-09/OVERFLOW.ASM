.MODEL SMALL
.STACK 100H
.DATA
ILLI_MSG DB 0AH,'ILLIGAL INPUT',0AH,'$'
OVER DB  0AH,'OVERFLOW!',0AH,'$'
.CODE
MAIN PROC
	MOV AX,@DATA   ;initializing data segment
	MOV DS,AX
	CALL INDEC  ; call INDEC procedure
	PUSH AX     ; push AX into stack
	MOV AH,2 
	MOV DL,0AH
	INT 21H
	POP AX
	CALL OUTDEC  ; Call OUTDEC procedure
@END:
	MOV AH,4CH  ; DOC return function
	INT 21H 
	MAIN ENDP
	INCLUDE OUTDEC.ASM  ; including OUTDEC procedure
	INCLUDE INDEC.ASM   ; including INDEC procedure
END MAIN
