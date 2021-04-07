.MODEL SMALL
.STACK 100H
.DATA
	A DB ?
	B DB ?
	C DB ?
MSG DB 'ENTER THREE INITIALS: $'

.CODE
MAIN PROC

;initialize data segment
MOV AX,@DATA
MOV DS,AX

;printing user promt message
LEA DX,MSG
MOV AH,9
INT 21H

;user input
MOV AH,1
INT 21H
MOV A,AL
INT 21H
MOV B,AL
INT 21H
MOV C,AL

;output
MOV AH,2

; line feed
MOV DL,0AH 
INT 21H

; print 1st initail
MOV DL,A 
INT 21H

; line feed
MOV DL,0AH
INT 21H

; print second initial
MOV DL,B 
INT 21H

; line feed
MOV DL,0AH
INT 21H

; print third initial
MOV DL,C 
INT 21H

;exit DOS
MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
