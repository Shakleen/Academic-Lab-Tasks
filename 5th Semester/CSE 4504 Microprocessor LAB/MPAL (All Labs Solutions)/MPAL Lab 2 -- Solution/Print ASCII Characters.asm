; Input a number (0/1). For 0, print the first 128 ASCII characters. For 1, print the rest.

ORG 0100H

.DATA
	PROMPT_1 DB 'Enter a number: ', '$', 0Dh, 0Ah
	
.CODE

MAIN PROC
    
	MOV AH, 9
    LEA DX, PROMPT_1	; load and display the string PROMPT_1
    INT 21H
	
	MOV AH, 1
	INT 21H
	MOV BL, AL

	CMP BL, 48
	MOV CX, 0
	JE First

	CMP BL, 49
	MOV CX, 128
	JE Second

First:
	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H
	MOV DX, CX
	INT 21H
	INC CX
	CMP CX, 128
	JL First
	JE goHome

Second:
	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H
	MOV DX, CX
	INT 21H
	INC CX
	CMP CX, 256
	JL Second

goHome:
	MOV AH, 4CH
	INT 21H

	MAIN ENDP
END MAIN
RET
