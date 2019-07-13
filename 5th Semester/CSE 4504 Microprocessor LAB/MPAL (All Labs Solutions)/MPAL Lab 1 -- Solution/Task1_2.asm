ORG 0100H

.DATA

OUTPUT DW ?

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
     
    XOR AL, AL
    XOR AH, AH    
    MOV AL, 200
    SUB AX, 225
    
    MOV BL, 0BH
    XOR BH, BH
    MUL BX
    
    ADD AX, 127 ; in this condition, at most 274 can be added to AX        
    
    MOV OUTPUT, AX
	
    MAIN ENDP
END MAIN
RET