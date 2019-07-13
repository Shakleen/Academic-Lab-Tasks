org 100h

.DATA

A db 1, 2, 3, 4, 5, 6, 7, 8, 9
B db 00h
message db 'Enter the value of N:$'
C DW ?

.CODE
MAIN PROC
    mov ax, @DATA
    mov ds, ax
    xor ax, ax
    
    mov si, offset A
    mov di, offset B
    mov dx, offset message
    
    mov ah, 09h ;Show message to screen
    int 21h
    
    mov ah, 01h
    int 21h
    
    mov cl, al
    sub cl, 48
    xor bx, bx
    mov si, 0
    
    loop_1: xor ax, ax
            mov al, A[si]
            mul al
            add bx, ax  
            inc si
            loop loop_1
    
    mov C, bx
    add bl, 48  ; To convert the ascii value of the output to decimal
    
    mov ah, 02h
    mov dl, 0dh
    int 21h
MAIN ENDP
END MAIN
RET