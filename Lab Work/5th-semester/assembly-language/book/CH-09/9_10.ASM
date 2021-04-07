.MODEL SMALL
.STACK 100H

.DATA
ILLI_MSG DB 0AH,'ILLIGAL INPUT',0AH,'$'
OVER DB  0AH,'OVERFLOW!',0AH,'$'

MSG1 DB 0AH,'ENTER CENTS: $'
MSG2 DB 0AH,'HALF DOLAR: $'
MSG3 DB 0AH,'QUARTERS: $'
MSG4 DB 0AH,'DIMES: $'
MSG5 DB 0AH,'NIKLES: $'
MSG6 DB 0AH,'PENNIES: $'

.CODE

MAIN PROC

    MOV AX,@DATA ; initializing data segment
    MOV DS,AX
    
    ;print msg1
    MOV AH,9
    LEA DX,MSG1
    INT 21H
    
    CALL INDEC    ;calling INDEC procedure
    PUSH AX
    
     ; for half dollar
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
   
    XOR DX,DX
    MOV BX,50D  
    POP AX
    DIV BX
    PUSH DX
    CALL OUTDEC
    
    ;for quarter
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    XOR DX,DX
    POP AX
    MOV BX,25D
    DIV BX
    PUSH DX
    CALL OUTDEC 
    
    ; for dimes
    LEA DX,MSG4
    MOV AH,9
    INT 21H 
    XOR DX,DX
    POP AX  
    MOV BX,10D
    DIV BX
    PUSH DX
    CALL OUTDEC
    
    ;for nicle
    LEA DX,MSG5
    MOV AH,9
    INT 21H
    XOR DX,DX
    POP AX 
    MOV BX,5D  
    DIV BX 
    PUSH DX
    CALL OUTDEC
    
    ;for pennies
    LEA DX,MSG6
    MOV AH,9
    INT 21H
    
    XOR DX,DX
    POP AX
    
    CALL OUTDEC
    
    
    @END:
    MOV AH,4CH
    INT 21H
    
MAIN ENDP

INCLUDE OUTDEC.ASM
INCLUDE INDEC.ASM

END MAIN
