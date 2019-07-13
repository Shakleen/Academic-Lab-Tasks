ORG 100h

.DATA

A DW ?

.CODE

MAIN PROC
    
    MOV CL, 128
    MOV CH, 255
    MOV AH, 1
    INT 21h
    MOV BL, AL
    CMP BL, 0
    
    JE LABEL_JZ
    JNZ LABEL_JNZ
    
    LABEL_JZ:   DEC CL
                
                MOV AH, 2
                MOV DL, CL
                INT 21H
                
                CMP CL, 0
                JG LABEL_JZ
                
                MOV AH, 4Ch
                INT 21h
                
    LABEL_JNZ:  MOV AH, 2
                MOV DL, CH
                INT 21H
                
                DEC CH
                CMP CH, 128
                JG LABEL_JNZ                            
    
MAIN ENDP
END MAIN
RET                        
