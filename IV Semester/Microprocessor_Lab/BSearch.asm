.model small

.data
    key db 40
    A db 10, 20, 30, 40, 50
    l db $-A
    m1 db 10,13,'Element Found$'
    m2 db 10,13,'Element not found$'

.code
    mov ax, @data
    mov ds, ax
    mov ax, 0
    lea Si, a
    mov di, Si
    Add dl, A
    dec di
    L1: cmp Si, di
    JA NF
    mov bx, Si
    Add bx, di
    shr bx, 01h
    mov al, key
    cmp al, [bx]
    JE YF
    JA NLOW
    mov di, bx
    dec di
    jmp L1

NLOW:
    mov Si, bx
    inc Si
    jmp L1

NF:
    lea dx, m2
    jmp exit

YF:
    lea dx, m1

exit:
    mov ah, 09h
    int 21h
end
