ORG 0100h

.DATA

CEL DW 260
FER DW ?

.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, CEL
    
	MOV BL, 9
	XOR BH, BH
	MUL BX
	
	MOV BL, 5
	DIV BX
	
	ADD AX, 32
	SUB AX, 1
	
    MOV FER, AX
	
	MAIN ENDP
END MAIN
RET