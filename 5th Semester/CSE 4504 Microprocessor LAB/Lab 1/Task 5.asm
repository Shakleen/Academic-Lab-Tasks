ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV AX, @data
    MOV DS, AX
    MOV AX, 999
    SUB AX, 32
    
    MOV BX, 5
    MUL BX
    
    MOV BX, 9
    DIV BX
    
    ADD AX, 1
    
    MOV A, AX
    
MAIN ENDP
END MAIN
RET                        
