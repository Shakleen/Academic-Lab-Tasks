ORG 100h

.DATA
	PROMPT_1 DB 'Enter 5 Integer Numbers: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'Input a number to search: ', '$'
	PROMPT_3 DB 0Dh, 0Ah, 'Digit ', '$'
	PROMPT_4 DB ' Found', '$'
	PROMPT_5 DB ' Not Found', '$'
	ARRAY DB 10 DUP(0)

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	MOV AH, 9
	LEA DX, PROMPT_1
	INT 21H

	MOV CX, 5					; because we will input 5 integers
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
	
	MOV AH, 9
	LEA DX, PROMPT_2
	INT 21H
	
	MOV CX, 5
	LEA SI, ARRAY
	
	MOV AH, 1
	INT 21h
	MOV BL, AL					; save the integer to search in the array
	
Loop_1:
	CMP BL, [SI]				; compare the integer with all elements of the one by one
	JZ Print
	JNZ noPrint
	
	Print:
		MOV AH, 9
		LEA DX, PROMPT_3
		INT 21H
		
		MOV AH, 2
		MOV DL, BL
		INT 21h
		
		MOV AH, 9
		LEA DX, PROMPT_4
		INT 21H
		JMP goHome
	
	noPrint:
		LOOP Loop_1
		
	MOV AH, 9
	LEA DX, PROMPT_3
	INT 21H
	
	MOV AH, 2
	MOV DL, BL
	INT 21h
	
	MOV AH, 9
	LEA DX, PROMPT_5
	INT 21H
	
goHome:
	MOV AH, 4CH
	INT 21H
	
	MAIN ENDP
END MAIN
RET
