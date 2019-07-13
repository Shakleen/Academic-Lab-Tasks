ORG 0100H

.DATA

OUTPUT DW ?

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
     
    MOV AL, 30h
    XOR AH, AH
    ADD AX, 15
    
    MOV BX, 575
	SUB BX, 225
	
	MUL BX
	
	ADD AX, 210
	
    MOV OUTPUT, AX
	
    MAIN ENDP
END MAIN
RET