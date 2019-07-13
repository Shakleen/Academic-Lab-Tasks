ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV AX, @data
    MOV DS, AX
    MOV AX, 0FFFh
    
    MOV BX, 10h
    
    MUL BX
    
    ADD AX, 1111b
    
    MOV A, AX
    
MAIN ENDP
END MAIN
RET                        
