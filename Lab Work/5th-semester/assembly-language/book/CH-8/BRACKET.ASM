.MODEL LARGE
 .STACK 500H

 .DATA
   MSG1          DB  0DH,0AH,'ENTER AN ALGEBRIC EQUATION',0DH,0AH,'$' 
   
   CORRECT_MSG         DB  0DH,0AH,'EXPRESSION IS CORRECT. $'   
   
   EXTRA_LEFT_BRACKETS   DB  'TOO MANY LEFT BRACKETS. BEGIN AGAIN! $'  
   
   EXTRA_RIGHT_BRACKETS  DB  0DH,0AH,'TOO MANY RIGHT BRACKETS. BEGIN AGAIN! $' 
   
   MISMATCH        DB  'BRACKET MISMATCHED. BEGIN AGAIN! $'      
   
   AGAIN        DB  0DH,0AH,'TYPE Y IF YOU WANT TO CONTINUE AGAIN : $'

 .CODE
   MAIN PROC
     MOV AX, @DATA                ; initialize DS
     MOV DS, AX

     @BEGIN:                     

     LEA DX, MSG1               ; print the MSG1
     MOV AH, 9
     INT 21H

     XOR CX, CX                   ; clear CX

     MOV AH, 1                    ; set input function

     _INPUT:                     
       INT 21H                    ; read a character

       CMP AL, 0DH                ; compare AL with Carriage return
       JE _END_INPUT              ; jump to label _END_INPUT if AL=CR

       CMP AL, "["                ; compare AL with "["
       JE _PUSH           ; jump to label _PUSH if AL="["

       CMP AL, "{"                ; compare AL with "{"
       JE _PUSH           ; jump to label _PUSH if AL="{"

       CMP AL, "("                ; compare AL with "("
       JE _PUSH           ; jump to label _PUSH if AL="("

       CMP AL, ")"                ; compare AL with ")"
       JE _FIRST_BRACKET          ; jump to label _FIRST_BRACKET if AL=")"

       CMP AL, "}"                ; compare AL with "}"
       JE _SECOND_BRACKET          ; jump to label _SECOND_BRACKET if AL="}"

       CMP AL, "]"                ; compare AL with "]"
       JE _THIRD_BRACKET         ; jump to label _THIRD_BRACKET if AL="]"

       JMP _INPUT                 ; jump to label _INPUT

       _PUSH:             

       PUSH AX                    ; push AX onto the STACK
       INC CX                     ; set CX=CX+1
       JMP _INPUT                 ; jump to label _INPUT

       _FIRST_BRACKET:            ; jump label

       POP DX                     ; pop a value from STACK into DX
       DEC CX                     ; set CX=CX-1

       CMP CX, 0                  ; compare CX with 0
       JL _EXTRA_RIGHT_BRACKETS         ; jump to label _EXTRA_RIGHT_BRACKETS if CX<0

       CMP DL, "("                ; compare DL with "("
       JNE _MISMATCH              ; jump to label _MISMATCH if DL!="("
       JMP _INPUT                 ; jump to label _INPUT

       _SECOND_BRACKET:            ; jump label

       POP DX                     ; pop a value from STACK into DX
       DEC CX                     ; set CX=CX-1

       CMP CX, 0                  ; compare CX with 0
       JL _EXTRA_RIGHT_BRACKETS         ; jump to label _EXTRA_RIGHT_BRACKETS if CX<0

       CMP DL, "{"                ; compare DL with "{"
       JNE _MISMATCH              ; jump to label _MISMATCH if DL!="{"
       JMP _INPUT                 ; jump to label _INPUT

       _THIRD_BRACKET:           ; jump label

       POP DX                     ; pop a value from STACK into DX
       DEC CX                     ; set CX=CX-1

       CMP CX, 0                  ; compare CX with 0
       JL _EXTRA_RIGHT_BRACKETS         ; jump to label _EXTRA_RIGHT_BRACKETS if CX<0

       CMP DL, "["                ; compare DL with "["
       JNE _MISMATCH              ; jump to label _MISMATCH if DL!="["
    JMP _INPUT                   ; jump to label _INPUT

     _END_INPUT:                  ; jump label

     CMP CX, 0                    ; compare CX with 0
     JNE _EXTRA_LEFT_BRACKETS           ; jump to label _EXTRA_LEFT_BRACKETS if CX!=0

     MOV AH, 9                    ; set string output function

     LEA DX, CORRECT_MSG              ; print CORRECT_MSG
     INT 21H

     LEA DX, AGAIN             ; print AGAIN
     INT 21H

     MOV AH, 1                    ; set input function
     INT 21H                      ; read a character

     CMP AL, "Y"                  ; compare AL with "Y"
     JNE @EXIT                    ; jump to label @EXIT if AL!="Y"
     JMP @BEGIN                  

     _MISMATCH:                  

     LEA DX, MISMATCH             ;print MISMATCH
     MOV AH, 9
     INT 21H

     JMP @BEGIN                  

     _EXTRA_RIGHT_BRACKETS:            

     LEA DX, EXTRA_RIGHT_BRACKETS       ; print EXTRA_RIGHT_BRACKETS
     MOV AH, 9
     INT 21H

     JMP @BEGIN                 

    _EXTRA_LEFT_BRACKETS:           

     LEA DX, EXTRA_LEFT_BRACKETS        ; print EXTRA_LEFT_BRACKETS
     MOV AH, 9
     INT 21H

     JMP @BEGIN                   ; jump to label @BEGIN

     @EXIT:                       ; jump label

     MOV AH, 4CH                  ; return control to DOS
     INT 21H
   MAIN ENDP
 END MAIN
