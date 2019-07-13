ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV AX, @data
    MOV DS, AX
    
    MOV AL, 0Bh
    
    MOV BX, 200
    SUB BX, 225
    
    XOR AH, AH
    
    MUL BX
    
    ADD AX, 127
    
    MOV A, AX
    
MAIN ENDP
END MAIN
RET