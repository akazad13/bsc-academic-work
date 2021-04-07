.MODEL SMALL
.STACK 500H

.DATA

MSG1 DB 'ENTER A BINARY NUMBER: $'
MSG2 DB 'RANDOM NUMBERS ARE: $'
MSG3 DB 'ILLIGAL INPUT $'

CNT1 DB 0
CNT2 DB 0
TEMP DW ?

.CODE

MAIN PROC
    MOV AX,@DATA    ;initializing data segment
    MOV DS,AX
    
    
    CALL READ     ; call READ procedure
    
    LEA DX,MSG2   ; printing MSG2
    MOV AH,9
    INT 21H
    
    _WHILE:
    
        CALL RANDOM  ; Call RANDOM procedure
    
        CALL WRITE   ; Call WRITE procedure
        
        MOV AH,2     ; Single char outpur function
        MOV DL,' '   ; print  space
        INT 21H
        
        INC CNT1     ; CMT1 = CNT1 + 1
        
        CMP CNT1,4   ; if CNT1 == 4
        JE _NEWLINE  ; if CNT1=4
        
        JMP _WHILE   ; jump to _WHILE
        
     _NEWLINE:
        MOV CNT1,0   ; CNT1=0
        MOV AH,2
        MOV DL,0AH   ; print newline
        INT 21H
        INC CNT2
        
        CMP CNT2,25  ; if CNT2==25
        JE @END      ; if CNT2=25 , go to @END
        
        JMP _WHILE
        
    
  @END:  
    
    MOV AH,4CH  ; return to DOS
    INT 21H
    
    MAIN ENDP

; beginning of read procedure
READ PROC
    
    LEA DX,MSG1  ; prepate MSG1
    MOV AH,9  
    INT 21H      ; print MSG1
    
    XOR CX,CX    ; CX=0
    MOV CX,16    ; CX=16
    
    XOR BX,BX    ; BX=0
    MOV AH,1     ; single char input function
     
    TOP:
      INT 21H    ; input a char
      CMP AL,0DH ; compare with CR
      JE _END
      CMP AL,'1'
      JG ILLIGAL
      AND AL,0FH  ; convert to digit
      
      ; binary input
      SHL BX,1
      OR BL,AL
      LOOP TOP
      
      JMP _END
  
  ; illigal msg
  ILLIGAL:
    
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    
_END:
    
RET ; return to main

READ ENDP

; random procedure
RANDOM PROC
    SHL BX,1  ; Shift to left 1 bit
    
    MOV AX,BX  ; Ax=BX
    MOV TEMP,BX ; TEMP = BX
    
    SHL AX,1  ; Shift to left 1 bit
    XOR AX,TEMP ; XOR with 14 and 15 bit
    ROL AX,1    ; Rotate to left 1 bit
    JNC CONTINUE ; if no carry, jump to continue
    OR BX,0001H  ; set 1st bit
    
    CONTINUE:
        AND BX,0BFFFH ; clear 15 bit
    

RET

RANDOM ENDP

;write procedure
WRITE PROC
    
    XOR CX,CX  ; CX=0
    MOV CX,16  ; CX = 16
    
    MOV AH,2   ; single char function
    
    TOP1:
      ROL BX,1  ; Rotate to left 1 time
      JC ONE  ; jump if carry
      
      MOV DL,'0'
      INT 21H
      JMP NEXT
      
      ONE:
       MOV DL,'1'
       INT 21H 
       
      NEXT:
      
      LOOP TOP1 
RET

WRITE ENDP


END MAIN
