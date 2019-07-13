.MODEL SMALL
.STACK 100H

.DATA
	PROMPT_1 DB 'Enter a line of text: ', '$'
	PROMPT_2 DB 0Dh, 0Ah, 'First Small Letter: ', '$'
	PROMPT_3 DB 0Dh, 0Ah, 'Last Small Letter: ', '$'
	PROMPT_4 DB 0Dh, 0Ah, '***** No small Letters *****', '$'

	SMALL_CHECK_FLAG        DB '0'
	SMALL_LETTER_CHECK_FLAG DB '0'
	FIRST_LETTER            DB '?'
	LAST_LETTER             DB '?'

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

		CMP BL, 'Z'                        ; compare BL with 'A'
		JLE @INPUT                         ; jump to label @INPUT if BL < A

		CMP SMALL_LETTER_CHECK_FLAG, 48
		JE @NEXT
		
		MOV LAST_LETTER, BL                ; set FIRST_LETTER = BL		
		CMP BL, LAST_LETTER                ; compare BL with variable FIRST_LETTER
		JE @INPUT                          ; jump to label @NEXT if BL > FIRST_LETTER

	@NEXT:                                 ; jump label
		MOV SMALL_CHECK_FLAG, '1'          ; set CAPITAL_CHECK_FLAG = 1
		MOV SMALL_LETTER_CHECK_FLAG, '1'
		
		MOV FIRST_LETTER, BL               ; compare BL with variable LAST_LETTER
		MOV LAST_LETTER, BL                ; jump to label @INPUT if BL < LAST_LETTER
		CMP BL, LAST_LETTER                ; set LAST_LETTER = BL
		JE @INPUT                          ; jump to label @INPUT

	@END_INPUT:                            ; jump label
		CMP SMALL_CHECK_FLAG, 49          ; compare CAPITAL_CHECK_FLAG with 1             
		JE @DISPLAY                        ; jump to label @DISPLAY if CAPITAL_CHECK_FLAG = 1

		LEA DX, PROMPT_4                   ; load and display the string PROMPT_4
		MOV AH, 9                    
		INT 21H

		JMP @END                           ; jump to label @END

	@DISPLAY:                              ; jump label
		MOV AH, 9
		LEA DX, PROMPT_2                   ; load and display the string PROMPT_2
		INT 21H

		MOV AH, 2                          ; set output function
		MOV DL, FIRST_LETTER               ; set DL = FIRST_LETTER
		INT 21H                            ; print a character
		
		MOV AH, 9                  
		LEA DX, PROMPT_3                   ; load and display the string PROMPT_3
		INT 21H                    

		MOV AH, 2                          ; set output function
		MOV DL, LAST_LETTER                ; set DL = LAST_LETTER
		INT 21H                            ; print a character

	@END:                                  ; jump label
		MOV AH, 4CH                        ; return control to DOS
		INT 21H
		
		MAIN ENDP
	END MAIN
	RET
