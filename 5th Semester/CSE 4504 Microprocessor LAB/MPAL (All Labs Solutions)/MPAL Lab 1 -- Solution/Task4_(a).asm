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
	
	NEG AX ; (65536 - 499 = 65037) || (10000h - 1F3h = FE0Dh) 
    MOV FER, AX
	
	MAIN ENDP
END MAIN
RET