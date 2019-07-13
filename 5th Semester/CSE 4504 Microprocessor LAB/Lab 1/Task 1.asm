ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV AX, @data
    MOV DS, AX
    
    MOV AL, 30
    ADD AL, 15
    
    MOV BX, 575
    SUB BX, 225
    
    XOR AH, AH
    
    MUL BX
    
    ADD AX, 210
    
    MOV A, AX
    
MAIN ENDP
END MAIN
RET