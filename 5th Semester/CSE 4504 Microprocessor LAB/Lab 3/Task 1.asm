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
    
    XOR CX, CX
    XOR AX, AX
    XOR BX, BX
    MOV CX, 30
    
    CHECK1:
        MOV AL, STRING[BX]
        CMP AL, 90
        JL CAP
        INC BX
        LOOP CHECK1
    
    CHECK2:
        INC BX
        MOV AL, STRING[BX]
        CMP AL, 90
        JG SMALL
        LOOP CHECK2
    
    CAP:
        MOV DL, AL
        MOV AH, 2
        INT 21H
        INC BX
        JMP CHECK2
        
    SMALL:
        MOV DL, AL
        MOV AH, 2
        INT 21H
    
MAIN ENDP
END MAIN
RET                        
