.MODEL SMALL
.STACK 100H
.DATA

MSG1 DB 'ENTER A STRING OF CAPITAL LETTERS:',0AH,'$'
MSG2 DB 'THE LONGEST CONSECUTIVELY INCREASING STRING IS:',0AH,'$'
NOW DB 0
I DB 0  ; to count the segment length
J DB 0  ; help to store initial position of segments
MAX DB 0  ; store the maximum length of the result
INIT DB 0 ; store the initial of resultant string

.CODE
MAIN PROC

;initializing data segment
MOV AX,@DATA
MOV DS,AX

LEA DX,MSG1  ; getting offset of 1st message
MOV AH,9     ; string output function
INT 21H      ; output 1st message

MOV CL,0     ; initialing CX to 0

MOV AH,1     ;  single character input function
INT 21H      ; getting 1st character of the srtring
CMP AL,0DH   ; checking if it is carriage return or not
JE RESULT    ; if it is carriage return , jump to RESULT

MOV I,1      ; setting I to 1
MOV NOW,AL   ; setting out current char to NOW
INC NOW      ; Increament NOW to find the next character
MOV J,AL     ; assign J to the initial of the string


TOP:

	INT 21H    ; getting another character
	CMP AL,0DH ; carriage return check 
	JE RESULT ;  if it is carriage return , jump to RESULT

	MOV BL,AL ; move the value of the char to BL register

	CMP BL,NOW ; if our entered char is equal to NOW... than the sequence is maintained
	JNE CALCULATE ; if not we calculate the segment we get so far

	INC I  ; increament I
	INC NOW  ; increment NOW
 
	JMP TOP ; Unconditional jump to top to get another input


SET_I:
	MOV I,1   ; set the value of I
	MOV J,BL  ; set the next initial
	JMP TOP  ; jump to top

CALCULATE:

	MOV NOW,BL
	INC NOW ; Next character initialize

	MOV AL,I	
	CMP MAX,AL  ; cheacking if our previous max is greater than our current max or not
	JGE SET_I   ; if yes, go to SET_I and stop updating MAX and go to SET_I

	MOV MAX,AL  ; if no, update our previous MAX
 
	MOV I,1  ; Set I

	MOV AL,J
	MOV INIT,AL  ; Set our new Initial

	MOV J,BL  ; insert J ,,, the new possible initial
	JMP TOP

RESULT:

MOV BL,I
CMP MAX,BL  ;  cheacking if our previous max is greater than our current max or not 
JGE _NEXT   ;  if yes, go to SET_I and stop updating MAX and go to _NEXT

MOV MAX,BL  ; Set MAX to new value
MOV AL,J    
MOV INIT,AL ; Set new initial

_NEXT:

;printing Second Message
LEA DX,MSG2
MOV AH,9
INT 21H

MOV CL,MAX  ; Set CL to MAX to do looping
MOV AH,2  ; Single character function

MOV DL,INIT ; Set DL to resultant string initial
 

OUTPUT:
	INT 21H  ; output result
	INC DL   ; increament DL
	LOOP OUTPUT

;exit from dos
MOV AH,4CH
INT 21H

MAIN ENDP
END MAIN
