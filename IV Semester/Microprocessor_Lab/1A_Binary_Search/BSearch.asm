.model small
.data
    key db ?
    A db 05h,03h,07d,04h,01h
    l db $-A
    m db 10,13,"Enter the key to be searched: $"
    m1 db 10,13,'The key was Found$'
    m2 db 10,13,'Key not found$'
.code
mov ax,@data
mov ds,ax

lea dx,m
call printf

call read8 ;read 8 bit number

mov key,al
mov bl,l   ;bubble sort
dec bl
xor bh,bh
l2:
    mov cx,bx
    lea si,A
    l1: mov al,[si]
        inc si
        cmp al,[si]
        jbe noswap
        xchg al,[si]
        mov [si-1],al
        noswap:loop l1
        dec bx
jnz l2;sorting ends

;binary search
lea si,A
mov di,si
mov bl,l
xor bh,bh
add di,bx
dec di
lp1:cmp si,di
    ja nf
    mov bx,si
    add bx,di
    shr bx,01h
    mov al,key
    cmp al,[bx]
    jz found
    ja nlow
    mov di,bx
    dec di
    jmp lp1
    nlow:mov si,bx
    inc si
jmp lp1
found:lea dx,m1
    call printf
    jmp exit
nf:lea dx,m2
    call printf
exit:
    mov ah,4ch
    int 21h
    
printf proc near  ; procedure for printf
mov ah,09h
int 21h
ret 
printf endp

read8 proc near  ;procedure for reading 8 bit number
mov ah,01h
int 21h
mov bh,al
sub bh,30h
mov ah,01h
int 21h
sub al,30h
mov ah,bh
aad
ret
read8 endp

end
