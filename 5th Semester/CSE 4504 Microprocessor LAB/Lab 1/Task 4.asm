ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV AX, @data
    MOV DS, AX
    MOV AX, 260
    
    MOV BX, 5
    DIV BX
    
    MOV CX, 9
    MUL CX
    
    ADD AX, 31
    
    MOV A, AX
    
MAIN ENDP
END MAIN
RET                        
