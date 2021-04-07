OUTDEC PROC
    
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    
    OR AX,AX
    JGE @POSITIVE  ; check if AX>=0
    
    ;else
    PUSH AX
    MOV DL,'-'
    MOV AH,2
    INT 21H
    POP AX
    NEG AX ;neagte AX
    
@POSITIVE:
    
    XOR CX,CX
    MOV BX,10D  ; BX = 10D
    
@REPEAT1:
    XOR DX,DX  ; Clear DX
    DIV BX  ; AX/BX
    PUSH DX ; reaminder= DX push into stack
    INC CX  ; CX = CX+1
    
    OR AX,AX 
    
    JNE @REPEAT1
    
    MOV AH,2
    
@PRINT:

    POP DX
    OR DL,30H  ; convert digit to ascii char
    INT 21H
    LOOP @PRINT
    
    
    POP DX
    POP CX
    POP BX
    POP AX
    
 RET
 
 OUTDEC ENDP
