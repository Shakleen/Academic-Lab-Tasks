ORG 100h

.DATA
STRING DB 'WeareIUTStudents', 0Dh, 0Ah, '$'

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, string
    INT 21h   
    
    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h
    
    MOV BX, 0
    MOV CX, 30
    CHECK1: MOV AL, STRING [BX]
            CMP AL, 90
            JL CAP1
            INC BX
            LOOP CHECK1
    
    CAP1:   MOV DL, AL
            MOV AH, 2
            INT 21H
            
    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h
            
    MOV BX, 16
    MOV CX, 30
    CHECK2: DEC BX
            MOV AL, STRING [BX]
            CMP AL, 90
            JL CAP2
            LOOP CHECK2
            
    CAP2:   MOV DL, AL
            MOV AH, 2
            INT 21H   
            
    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h
            
    MOV BX, 0
    MOV CX, 30
    CHECK3: MOV AL, STRING [BX]
            CMP AL, 90
            JG SML1
            INC BX
            LOOP CHECK3
    
    SML1:   MOV DL, AL
            MOV AH, 2
            INT 21H

    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h
            
    MOV BX, 16
    MOV CX, 30
    CHECK4: DEC BX
            MOV AL, STRING [BX]
            CMP AL, 90
            JG SML2
            LOOP CHECK4
            
    SML2:   MOV DL, AL
            MOV AH, 2
            INT 21H
    
MAIN ENDP
END MAIN
RET                        
