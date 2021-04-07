.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 'Please Enter 1st No: $'
MSG2 DB 'Please Enter 2nd No: $'
MSG3 DB 'Subtraction is: $'
MSG4 DB 'The result is Positive$'
MSG5 DB 'The result is Negative$'
MSG6 DB 'The result is Zero$'

A DB 00h
B DB 00h
res DB 00h


.CODE


MAIN PROC

MOV AX,@DATA ; adreesing data segment
MOV DS,AX

; printf the 1st message

LEA DX,MSG1
MOV AH,9
INT 21H

;input 1st number

MOV AH,1
INT 21H
SUB AL,30H
MOV A,AL



; print a new line

MOV AH,2
MOV DL,0AH
INT 21H


;print the second message

LEA DX,MSG2
MOV AH,9
INT 21H


; input 2nd number

MOV AH,1
INT 21H
SUB AL,30H
MOV B,AL

; print a new line

MOV AH,2
MOV DL,0AH
INT 21H


MOV BL,A
SUB BL,B
ADD BL,30H
MOV res,BL


;print the 3rd message

LEA DX,MSG3
MOV AH,9
INT 21H


CMP BL,'0'

JNLE first

JNGE second

JE third
JMP NEXT

first:

MOV AH,2
MOV DL,res
INT 21H

; print a new line

MOV AH,2
MOV DL,0AH
INT 21H


;print the 3dr message

LEA DX,MSG4
MOV AH,9
INT 21H
JMP NEXT


second:

MOV AL,'0'
SUB AL,res;
ADD AL,30H
MOV res,AL

MOV AH,2
MOV DL,2DH
INT 21H
MOV DL,res
INT 21H

; print a new line

MOV AH,2
MOV DL,0AH
INT 21H


;print the 3dr message

LEA DX,MSG5
MOV AH,9
INT 21H
JMP NEXT

third:

MOV AH,2
MOV DL,res
INT 21H

; print a new line

MOV AH,2
MOV DL,0AH
INT 21H


;print the 3dr message

LEA DX,MSG6
MOV AH,9
INT 21H

NEXT:

MOV AH,4CH ; get out from the dos
INT 21H

MAIN ENDP ; End procedure
END MAIN ; End programme
