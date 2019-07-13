ORG 100h

.DATA
	ARR DB 10 DUP(0)
	COUNT DB ?
	PROMPT_1 DB 'Input the value of N (3/4/5/6/7): ', '$' ; Because if input is greater than 7, sum will exceed 2 digit
	PROMPT_2 DB 0Dh, 0Ah, 'Fibonacci Series: ', '$'

.CODE
MAIN PROC

	MOV AX, @DATA
	MOV DS, AX
	
	MOV AH, 9
	LEA DX, PROMPT_1
	INT 21h
	
	MOV AH, 1			; Input a number between 3 to 7
	INT 21h
	
	MOV CL, AL
	SUB CL, 50			; 50 because whatever we input, first two numbers are already printed
	MOV COUNT, CL		; save the CL for printing
	
	MOV AH, 9
	LEA DX, PROMPT_2
	INT 21h
	
	LEA SI, ARR			; Load Effective Address of ARR in SI
	MOV DI, SI			; save SI for printing
		
	MOV AX, 0           ; Default 0
	MOV BX, 1           ; Default 1

L1:
	ADD AX, BX          ; save BX into AX
	MOV [SI], AX		; save AX into 'memory location SI'
	MOV AX, BX			; make BX as AX
	MOV BX, [SI]		; assign BX with the value in 'memory location SI'
	INC SI				; Increment SI for next memory location
	LOOP L1

	MOV AH, 2
	
	MOV DX, 48          ; Print first 2 Fibonacci number
	INT 21h
	MOV DX, ' '
	INT 21h
	
	MOV DX, 49
	INT 21h
	MOV DX, ' '
	INT 21h
	
	MOV CL, COUNT       ; Assign CL with the value of COUNT for printing the elements
	
Loop_1:
	MOV DX, [DI]		; assign DX with the value in 'memory location DI'
	ADD DX, 48			; add 48 for making it a decimal
	INT 21h
	
	MOV DX, ' '
	INT 21h
	INC DI
	LOOP loop_1
	
	MAIN ENDP
END MAIN
RET
