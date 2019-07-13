ORG 0100H

.DATA

OUTPUT DW ?

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, 0FFFH
        
    MOV BL, 10H
    XOR BH, BH
    MUL BX
    
    ADD AX, 10101010B
    
    MOV OUTPUT, AX
	
    MAIN ENDP
END MAIN
RET