ORG 100h

.DATA
	PROMPT_1 DB 'Enter 6 Integer Numbers: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'ODD Digits: ', '$'
	PROMPT_3 DB 0Dh, 0Ah, 'EVEN Digits: ', '$'
	ARRAY DB 10 DUP(0)

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	MOV AH, 9
	LEA DX, PROMPT_1
	INT 21H

	MOV CX, 6					; because we will input 5 integers
	LEA SI, ARRAY
	
INPUTS:
	MOV AH, 1			
	INT 21h
	
	MOV [SI], AL				; Load the inputs in array one by one
	INC SI
	
	MOV AH, 2
	MOV DX, ' '
	INT 21h
	LOOP INPUTS

	CALL Odd_Numbers	
	CALL Even_Numbers
	
MAIN ENDP
	
Odd_Numbers PROC
	
	MOV AH, 9
	LEA DX, PROMPT_2
	INT 21H
	
	MOV CX, 6
	LEA SI, ARRAY
	
Loop_1:
	XOR AX, AX
	MOV AL, [SI]
	SUB AL, 48
	
	MOV BL, 2					; compare the integer with all elements of the one by one
	DIV BL
	
	CMP AH, 1
	JE Print1
	JL noPrint1
	
	Print1:
		MOV AH, 2
		MOV DX, [SI]
		INT 21h
		
		MOV DX, ' '
		INT 21h
	
	noPrint1:
		INC SI
		LOOP Loop_1

Odd_Numbers ENDP	
	
Even_Numbers PROC
	
	MOV AH, 9
	LEA DX, PROMPT_3
	INT 21H
	
	MOV CX, 6
	LEA SI, ARRAY
	
Loop_2:
	XOR AX, AX
	MOV AL, [SI]
	SUB AL, 48
	
	MOV BL, 2					; compare the integer with all elements of the one by one
	DIV BL
	
	CMP AH, 0
	JE Print2
	JG noPrint2
	
	Print2:
		MOV AH, 2
		MOV DX, [SI]
		INT 21h
		
		MOV DX, ' '
		INT 21h
	
	noPrint2:
		INC SI
		LOOP Loop_2

Even_Numbers ENDP

END MAIN
RET
