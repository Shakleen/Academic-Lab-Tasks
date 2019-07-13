ORG 100h

.data
PROMPT_1 DB 'Enter 10 Integer Values: ', '$'
PROMPT_2 DB 0Dh, 0Ah, 'Ascending Order: ', '$'
PROMPT_3 DB 0Dh, 0Ah, 'Descending Order: ', '$'
ARRAY DB 10 DUP(0)

.CODE
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	
	MOV AH, 9
	LEA DX, PROMPT_1
	INT 21H

	MOV CX, 10			; because we will input 10 integers
	LEA SI, ARRAY
	
INPUTS:
	MOV AH, 1			
	INT 21h
	
	MOV [SI], AL		; Load the inputs in array one by one
	INC SI
	
	MOV AH, 2
	MOV DX, ' '
	INT 21h
	LOOP INPUTS
	
	MOV CX, 10
	DEC CX				; because n - 1 elements need to be checked

First:
	MOV SI, CX
	MOV BX, 0
	
Second:
	MOV AL, ARRAY[BX]
	MOV DL, ARRAY[BX+1]
	CMP AL, DL

	JL noSwap

	MOV ARRAY[BX], DL
	MOV ARRAY[BX+1], AL

noSwap:
	INC BX
	DEC SI
	JNZ Second
	
	LOOP First
	
	CALL Ascending_Sort
	CALL Descending_Sort

MAIN ENDP
	
Ascending_Sort PROC

	MOV AH, 9
	LEA DX, PROMPT_2
	INT 21H

	MOV CX, 10
	LEA SI, ARRAY
	
Print1:					; This loop prints the ARRAY elements on the screen
	MOV AH, 2
	MOV DL, [SI]
	INT 21H
	INC SI
	
	MOV DX, ' '
	INT 21h
	LOOP Print1

Ascending_Sort ENDP

Descending_Sort PROC

	MOV AH, 9
	LEA DX, PROMPT_3
	INT 21H

	MOV CX, 10
	LEA SI, ARRAY
	ADD SI, 9			; to get the last address of the 10 sized array, we need to add 9 with the first address
	
Print2:					; This loop prints the ARRAY elements on the screen
	MOV AH, 2
	MOV DL, [SI]
	INT 21H
	DEC SI
	
	MOV DX, ' '
	INT 21h
	LOOP Print2

Descending_Sort ENDP

END MAIN
RET
