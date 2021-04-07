.MODEL SMALL
.STACK 100H
.DATA

M1 DB 'THE SUM OF $'
M2 DB  ' AND $'
M3 DB  ' IS $'

.CODE


MAIN PROC

MOV AX,@DATA ; adreesing data segment
MOV DS,AX

;print ?

MOV AH,2 
MOV DL,'?'
INT 21H

;input 1st number

MOV AH,1
INT 21H
MOV BL,AL

; input 2nd number

INT 21H
MOV CL,AL

; print a new line

MOV AH,2
MOV DL,0AH
INT 21H

; printf the 1st message

LEA DX,M1
MOV AH,9
INT 21H

;print the 1st mumber

MOV AH,2
MOV DL,BL
INT 21H

;print the second message

LEA DX,M2
MOV AH,9
INT 21H

;print the second number

MOV AH,2
MOV DL,CL
INT 21H

;print the 3dr message

LEA DX,M3
MOV AH,9
INT 21H

; print the sum

MOV AH,2
ADD BL,CL  ; add two number
SUB BL,48D ; subtract ascii value of 0 to get the number
MOV DL,BL
INT 21H

MOV AH,4CH ; get out from the dos
INT 21H

MAIN ENDP ; End procedure
END MAIN ; End programme
