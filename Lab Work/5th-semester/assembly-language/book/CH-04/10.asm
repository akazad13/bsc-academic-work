.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 'ENTER A HEX DIGIT: $'
MSG2 DB 0AH,'IN DECIMAL IT IS $'

.CODE
MAIN PROC

;initializing data segment
MOV AX,@DATA
MOV DS,AX

;print user promt
LEA DX,MSG1
MOV AH,9 ;function for printing string
INT 21H

;input hex digit from the user
MOV AH,1
INT 21H
MOV BL,AL ; moving the value to BL register


;print the output message
LEA DX,MSG2
MOV AH,9
INT 21H

MOV AH,2
MOV DL,'1' ;print the 1st digit of hex number A to F
INT 21H

;subtract by A to get the second digit
SUB BL,'A'
ADD BL,30H

;print the 2nd digit
MOV DL,BL
INT 21H

;exit from dos
MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
