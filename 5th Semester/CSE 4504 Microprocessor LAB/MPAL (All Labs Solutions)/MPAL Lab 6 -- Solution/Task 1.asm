ORG 100h

.DATA
	COUNT DW 5
	INDEX DW ?

	LARGEST DB 0
	SMALLEST DB 10
	
	ARR DB 10 DUP (0)
	PROMPT_1 DB 'Input 5 numbers: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'AVERAGE = ', '$'
	PROMPT_3 DB ' LARGEST = ', '$'
	PROMPT_4 DB ' SMALLEST = ', '$'

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	LEA DX, PROMPT_1
	MOV AH, 9
	INT 21h
	
	MOV CX, COUNT
	
	LEA SI, ARR
	MOV INDEX, SI
	
Loop_1:
	MOV AH, 1
	INT 21h
	
	SUB AL, 48
	MOV [SI], AL
	INC SI
	
	MOV AH, 2
	MOV DX, ' '
	INT 21h
	LOOP Loop_1

	LEA DX, PROMPT_2
	MOV AH, 9
	INT 21h
	CALL CALC_AVERAGE
	
	MOV AH, 2
	MOV DX, AX
	ADD DX, 48
	INT 21h            
	
	LEA DX, PROMPT_3
	MOV AH, 9
	INT 21h
	CALL CALC_LARGEST
	
	MOV AH, 2
	MOV DL, LARGEST
	ADD DL, 48
	INT 21h				; Code is OK up to this line
	
	LEA DX, PROMPT_4
	MOV AH, 9
	INT 21h
	CALL CALC_SMALLEST
	
	MOV AH, 2
	MOV DL, SMALLEST
	ADD DL, 48
	INT 21h

MAIN ENDP

CALC_AVERAGE PROC

	MOV CX, COUNT
	MOV SI, INDEX
	
	XOR AX, AX
	XOR BX, BX
	XOR DX, DX
	
	Loop_Average:
		MOV BL, [SI]
		ADD AL, BL
		INC SI
		LOOP Loop_Average
			
	MOV BX, 5
	DIV BX
		
	RET
CALC_AVERAGE ENDP

CALC_LARGEST PROC

	MOV CX, COUNT
	MOV SI, INDEX
	
	XOR AX, AX
	
	Loop_Largest:
		MOV AL, [SI]
		CMP AL, LARGEST
		JLE LessEqual
		MOV LARGEST, AL
	
	LessEqual:
		INC SI
		LOOP Loop_Largest
	
	RET
CALC_LARGEST ENDP

CALC_SMALLEST PROC

	MOV CX, COUNT
	MOV SI, INDEX
	
	XOR AX, AX
	
	Loop_Smallest:
		MOV AL, [SI]
		CMP AL, SMALLEST
		JGE GreaterEqual
		MOV SMALLEST, AL
	
	GreaterEqual:
		INC SI
		LOOP Loop_Smallest
		
	RET
CALC_SMALLEST ENDP

END MAIN
RET