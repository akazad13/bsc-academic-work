INDEC PROC
    
PUSH BX
PUSH CX
PUSH DX

@BEGIN:
    ;MOV AH,2
    ;MOV DL,'?'
    ;INT 21H
    
    XOR BX,BX ; BX will hold the total
    
    XOR CX,CX ; CX will hold the sign
    
    MOV AH,1
    INT 21H
    
    CMP AL,'-'
    JE @MINUS
    CMP AL,'+'
    JE @PLUS
    
    JMP @REPEAT
    
@MINUS:
    MOV CX,1
@PLUS:
    INT 21H
    
@REPEAT:

    CMP AL,'/'
    
    JE @NEXT
    
    CMP AL,'0'
    JNGE @ILLIGAL
    CMP AL,'9'
    JNLE @ILLIGAL
    
    AND AX,000FH
    PUSH AX
    
    MOV AX,10
    MUL BX
    JO @OVERFLOW
    POP BX
    ADD BX,AX
    JO @OVERFLOW

    MOV AH,1
    INT 21H
    CMP AL,0DH
    JNE @REPEAT
    
    MOV AX,BX
    
    OR CX,CX
    
    JE @EXIT
    NEG AX
    
    
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

@NEXT:
    MOV N,BX
    JMP @BEGIN
    
    
INDEC ENDP