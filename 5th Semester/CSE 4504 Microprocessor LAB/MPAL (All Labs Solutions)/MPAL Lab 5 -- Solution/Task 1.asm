org 100h

.DATA
	NUM DB ?
	FACT DB 1
	ARR DB 10 DUP ('$')
	PROMPT_1 DB 'Input the value of N: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'The Factorial of N is: ', '$'

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	LEA DX, PROMPT_1
	MOV AH, 9
	INT 21h
	
	MOV AH, 1
	INT 21h
	
	SUB AL, 48
	MOV NUM, AL
	
	XOR AX, AX
	XOR CX, CX
	
	MOV AL, FACT
	MOV CL, NUM

LABEL1:
	MUL CX
	LOOP LABEL1
	
	LEA SI, ARR
	CALL HEX2DEC
	
	LEA DX, PROMPT_2
	MOV AH, 9
	INT 21h
	
	LEA DX, ARR
	MOV AH, 9
	INT 21h

	MOV AH, 4CH
	INT 21h
	
MAIN ENDP

HEX2DEC PROC
	MOV CX, 0
	MOV BX, 10
	
	LOOP1: 
		MOV DX, 0
		DIV BX
		ADD DL, 48
		PUSH DX
		INC CX
		CMP AX, 9
		JG LOOP1
		ADD AL, 48
		MOV [SI], AL
	LOOP2: 
		POP AX
		INC SI
		MOV [SI], AL
		LOOP LOOP2
	RET
HEX2DEC ENDP

END MAIN
RET
