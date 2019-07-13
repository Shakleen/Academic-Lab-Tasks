ORG 0100h

.DATA

CEL DW ?
FER DW 999

.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, FER
	SUB AX, 32
	
	MOV BL, 5
	XOR BH, BH
	MUL BX
	
	MOV BL, 9
	DIV BX
	
	ADD AX, 1
	
    MOV CEL, AX
	
	MAIN ENDP
END MAIN
RET