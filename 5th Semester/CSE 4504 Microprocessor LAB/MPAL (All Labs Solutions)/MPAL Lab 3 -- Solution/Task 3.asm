.MODEL SMALL
.STACK 100H

.DATA
	PROMPT_1 DB 'Enter a line of text: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'First Capital Letter: ', '$'
	PROMPT_3 DB 0Dh, 0Ah, 'Last Capital Letter: ', '$'
	PROMPT_4 DB 0Dh, 0Ah, '***** No Capital Letters *****', '$'

	PROMPT_5 DB 0Dh, 0Ah, 'First Small Letter: ', '$'
	PROMPT_6 DB 0Dh, 0Ah, 'Last Small Letter: ', '$'
	PROMPT_7 DB 0Dh, 0Ah, '***** No Small Letters *****', '$'

	CAPITAL_CHECK_FLAG         DB '0'
	CAPITAL_LETTER_CHECK_FLAG  DB '0'
	FIRST_CAPITAL_LETTER       DB '?'
	LAST_CAPITAL_LETTER        DB '?'

	SMALL_CHECK_FLAG           DB '0'
	SMALL_LETTER_CHECK_FLAG    DB '0'
	FIRST_SMALL_LETTER         DB '?'
	LAST_SMALL_LETTER          DB '?'

.CODE
MAIN PROC
	MOV AX, @DATA                          ; initialize DS
    MOV DS, AX

	MOV AH, 9
    LEA DX, PROMPT_1                       ; load and display the string PROMPT_1
    INT 21H

    MOV AH, 1                              ; set input function

    @INPUT:                                ; jump label
		INT 21H                            ; read a character

		MOV BL, AL                         ; set BL = AL
		
		CMP BL, 0Dh                        ; compare BL with CR
		JE @END_INPUT                      ; jump to label @END_INPUT if BL = CR

		CMP BL, ' '                        ; take input again if a space character is entered
		JE @INPUT						   ; jump to label @INPUT to take input again

		CMP BL, 'Z'                        ; compare BL with 'Z'
		JLE @CAPITAL                       ; jump to label @CAPITAL if BL < 'Z'
		JG @SMALL						   ; jump to label @SMALL if BL > 'Z'

	@CAPITAL:
		CMP CAPITAL_LETTER_CHECK_FLAG, 48  ; check if it is the first capital letter
		JE @NEXT_CAPITAL				   ; jump to label @NEXT_CAPITAL if it is the first capital letter

		MOV LAST_CAPITAL_LETTER, BL        ; set LAST_CAPITAL_LETTER = BL		
		JMP @INPUT						   ; jump to label @INPUT to take input again

	@NEXT_CAPITAL:                         ; jump label
		MOV CAPITAL_CHECK_FLAG, '1'        ; set CAPITAL_CHECK_FLAG = 1
		MOV CAPITAL_LETTER_CHECK_FLAG, '1' ; set CAPITAL_LETTER_CHECK_FLAG = 1

		MOV FIRST_CAPITAL_LETTER, BL       ; set FIRST_CAPITAL_LETTER = BL
		MOV LAST_CAPITAL_LETTER, BL        ; set LAST_CAPITAL_LETTER = BL
		JMP @INPUT					       ; jump to label @INPUT to take input again
		
	@SMALL:                                ; jump label
		CMP SMALL_LETTER_CHECK_FLAG, 48    ; check if it is the first small letter
		JE @NEXT_SMALL                     ; jump to label @NEXT_SMALL if it is the first small letter

		MOV LAST_SMALL_LETTER, BL          ; set LAST_SMALL_LETTER = BL
		JMP @INPUT						   ; jump to label @INPUT to take input again

	@NEXT_SMALL:                           ; jump label
		MOV SMALL_CHECK_FLAG, '1'          ; set SMALL_CHECK_FLAG = 1
		MOV SMALL_LETTER_CHECK_FLAG, '1'   ; set SMALL_LETTER_CHECK_FLAG = 1

		MOV FIRST_SMALL_LETTER, BL         ; set FIRST_SMALL_LETTER = BL
		MOV LAST_SMALL_LETTER, BL          ; set LAST_SMALL_LETTER = BL
		JMP @INPUT						   ; jump to label @INPUT to take input again
		
	@END_INPUT:							   ; jump label
	@END_INPUT1:                           ; jump label
		CMP CAPITAL_CHECK_FLAG, 49         ; compare CAPITAL_CHECK_FLAG with 1             
		JE @DISPLAY1                       ; jump to label @DISPLAY1 if CAPITAL_CHECK_FLAG = 1

		MOV AH, 9
		LEA DX, PROMPT_4                   ; load and display the string PROMPT_4
		INT 21H
		
	@END_INPUT2:                           ; jump label
		CMP SMALL_CHECK_FLAG, 49           ; compare SMALL_CHECK_FLAG with 1             
		JE @DISPLAY2                       ; jump to label @DISPLAY2 if SMALL_CHECK_FLAG = 1

	    MOV AH, 9
		LEA DX, PROMPT_7                   ; load and display the string PROMPT_7
		INT 21H

		JMP @END                           ; jump to label @END

	@DISPLAY1:                             ; jump label
		MOV AH, 9
		LEA DX, PROMPT_2                   ; load and display the string PROMPT_2
		INT 21H

		MOV AH, 2                          ; set output function
		MOV DL, FIRST_CAPITAL_LETTER       ; set DL = FIRST_CAPITAL_LETTER
		INT 21H                            ; print a character
		
		MOV AH, 9                  
		LEA DX, PROMPT_3                   ; load and display the string PROMPT_3
		INT 21H                    

		MOV AH, 2                          ; set output function
		MOV DL, LAST_CAPITAL_LETTER        ; set DL = LAST_CAPITAL_LETTER
		INT 21H                            ; print a character
		
		JMP @END_INPUT2                    ; jump to label @END_INPUT2 to print the small letters
	
	@DISPLAY2:							   ; jump label
		MOV AH, 9
		LEA DX, PROMPT_5                   ; load and display the string PROMPT_5
		INT 21H

		MOV AH, 2                          ; set output function
		MOV DL, FIRST_SMALL_LETTER         ; set DL = FIRST_SMALL_LETTER
		INT 21H                            ; print a character
		
		MOV AH, 9
		LEA DX, PROMPT_6                   ; load and display the string PROMPT_6
		INT 21H

		MOV AH, 2                          ; set output function
		MOV DL, LAST_SMALL_LETTER          ; set DL = LAST_SMALL_LETTER
		INT 21H                            ; print a character

	@END:                                  ; jump label
		MOV AH, 4CH                        ; return control to DOS
		INT 21H
		
		MAIN ENDP
	END MAIN
	RET
