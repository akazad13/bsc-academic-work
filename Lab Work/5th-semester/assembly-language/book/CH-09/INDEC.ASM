INDEC PROC
    
PUSH BX  ; push BX to stack
PUSH CX  ; push CX to stack
PUSH DX  ; push DX to stack

@BEGIN:
   
    XOR BX,BX ; BX will hold the total
    
    XOR CX,CX ; CX will hold the sign
    
    MOV AH,1
    INT 21H
    
    CMP AL,'-' ;negative
    JE @MINUS
    CMP AL,'+'  ;positive
    JE @PLUS
    
    JMP @REPEAT
    
@MINUS:
    MOV CX,1  ; if negative CX=1
@PLUS:
    INT 21H
    
@REPEAT:
    
    CMP AL,'0'
    JNGE @ILLIGAL
    CMP AL,'9'
    JNLE @ILLIGAL
    
    AND AX,000FH  ; convert to digit
    PUSH AX     ; push AX into stack
      
    MOV AX,10   ; AX=10
    MUL BX      ; AX = AX*BX
    JO @OVERFLOW ; check overflow
    POP BX    ; pop into BX
    ADD BX,AX  ; BX  = AX + BX
    JO @OVERFLOW  ; check overflow

    MOV AH,1
    INT 21H
    CMP AL,0DH
    JNE @REPEAT
    
    MOV AX,BX
    
    OR CX,CX
    
    JE @EXIT
    NEG AX  ;negate AX
    
@EXIT:
    XOR CX,CX
    POP DX
    POP CX
    POP BX

RET
@ILLIGAL:
    LEA DX,ILLI_MSG
    MOV AH,9
    INT 21H
    JMP @END

RET

@OVERFLOW:
    LEA DX,OVER
    MOV AH,9
    INT 21H
    JMP @END
RET 
    
    
INDEC ENDP
  
