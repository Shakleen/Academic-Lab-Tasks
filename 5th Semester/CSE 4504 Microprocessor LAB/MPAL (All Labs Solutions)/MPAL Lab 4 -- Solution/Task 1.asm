org 100h

.DATA
	ARR DB 10 DUP ('$')
	PROMPT_1 DB 'Input the value of N: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'The result of sum of squares is: ', '$'

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	LEA DX, PROMPT_1
	MOV AH, 9
	INT 21h
	
	MOV AH, 1
	INT 21h
	
	XOR CX, CX
	
	MOV CL, AL				; To convert the ASCII value to decimal
	SUB CL, 48
	
	XOR AX, AX				; Reset the values of AX and BX
	XOR BX, BX

Loop_1:
	MOV AX, CX				; Move CX into AX
 	MUL CX					; Multiply CX with AX
	ADD BX, AX				; add the results into BX one by one
	LOOP Loop_1				; loop through. CX will auto decrease
	
	MOV AX, BX
	
	LEA SI, ARR				; Load Effective Address of ARR into SI
	CALL PRINT_ARRAY		; Call the function PRINT_ARRAY
	
	LEA DX, PROMPT_2
	MOV AH, 9
	INT 21h
	
	LEA DX, ARR				; PRINT_ARRAY the result of sum of squares
	MOV AH, 9
	INT 21h

	MOV AH, 4CH
	INT 21h
	
MAIN ENDP

PRINT_ARRAY PROC
	MOV CX, 0
	MOV BX, 10
	
	LOOP1: 
		MOV DX, 0			
		DIV BX				; Divide AX by BX, quotient will be stored in AX, remainder will be stored in DX
		ADD DL, 48			; Add 48 to get the decimal value
		PUSH DX				; PUSH the value into the stack
		INC CX				; CX will increase upto the number of digits in the number
		CMP AX, 9			; check if only one digit is left
		JG LOOP1			
		ADD AL, 48			; add 48 with the last digit and save it in the first index of array
		MOV [SI], AL
	LOOP2: 
		POP AX				; POP from the stack and save it in next positions of the array one by one 
		INC SI
		MOV [SI], AL
		LOOP LOOP2
	RET
PRINT_ARRAY ENDP

END MAIN
RET