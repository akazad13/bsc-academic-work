.MODEL LARGE
.STACK 500H

.DATA

POINTER1 DW 400H  ; to hold 1st stack pointer
POINTER2 DW 200H  ; to hold 2nd stack pointer
CNT DW 000H       ; count the number of alphabet

.CODE
MAIN PROC
    
    MOV AX,@DATA  ; initializing data segment
    MOV DS,AX
    
    XOR CX,CX     ; clear CX
    XOR BX,BX     ; clear BX
    MOV AH,1      ; input function
   
    MOV SP,POINTER1   ; set stack pointer to POINTER1
    
    _WHILE:
        INT 21H       ; input
        MOV BL,AL
        CMP BL,0DH    ; compare with carriage return
        JE @NEXT1
        CMP BL,' '    ; compare  with space
        JE @NEXT
        PUSH BX       ; push BX to the stack
        INC CX        ; CX = CX + 1
        INC CNT       ; CNT = CNT + 1
        JMP _WHILE
    
    @NEXT:
    
    INC CNT     ; CNT = CNT + 1(counting space also)
    
    @NEXT1:
; for moving character from one stack segment to another    
    TOP:
       POP DX  ; pop from stack to DX
       
       MOV POINTER1,SP  ; set POINTER1 = SP
       MOV SP,POINTER2  ; set SP = POINTER2
       PUSH DX          ; push DX into the stack
       MOV POINTER2,SP  ; set POINTER2= SP
       MOV SP,POINTER1   ; set SP = POINTER1
   
       LOOP TOP
    
    XOR CX,CX
    CMP BL,0DH
    JE _END
    
    MOV SP,POINTER2  ; set SP = POINTER2
    PUSH BX          ; push BX into the stack
    MOV POINTER2,SP  ; set POINTER2= SP
    MOV SP,POINTER1   ; set SP = POINTER1
    JMP _WHILE
    
    _END:
    
    
    MOV POINTER1,400H
    MOV CX,CNT
    ; final time moving all the character to 1st stack
    TOP2:
        
        MOV SP,POINTER2   ; set SP = POINTER2
        POP DX            ; pop into DX form stack
        MOV POINTER2,SP   ; set POINTER2 = SP
        MOV SP,POINTER1   ; set SP = POINTER1
        PUSH DX           ; push DX into stack
        MOV POINTER1,SP   ; set POINTER2 = SP
        
        LOOP TOP2:
    
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV CX,CNT
    
    MOV SP,POINTER1       ; set SP = POINTER1
    
    ; print the character
    TOP1:
       POP DX  ; pop out from the stack to DX
       INT 21H 
       LOOP TOP1
        
    MOV AH,4CH  ; terminating function
    INT 21H
    
    MAIN ENDP  ; main procedure ending
END MAIN
        
              
