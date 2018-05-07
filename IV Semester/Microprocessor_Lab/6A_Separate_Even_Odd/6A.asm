.model small

.data
arr db 10,20,99,98,97,100
len db $-arr
n db 2
d dw 10
eve db 5 dup(?)
odd db 5 dup(?)
m1 db 10,13,'even array elements are $'
m2 db 10,13,'odd array elements are $'

.code
mov ax,@data
mov ds,ax

mov ax,00h
lea si,arr
lea di,eve
lea bx,odd
mov ch,00h
mov cl,len

l2:mov al,[si]             ;checking if a number  is odd or even
	div n
	cmp ah,00h
	jz l1
	mov al,[si]                      ;storing the number in odd array
	mov [bx],al
	inc bx
	jmp lab
	l1:mov al,[si]
		mov [di],al                     ;storing the number in even array
		inc di
		lab:inc si
	loop l2

lea di,eve
lea bx,odd
lea dx,m1
mov ah,09h
int 21h

l5:mov ah,[di]
	cmp ah,00h
	jz go
	mov al,[di]
	call printspace      ;calling printspace  procedure to print the space
	call printf                 ;printing the values
	inc di
jmp l5

go:lea dx,m2
	mov ah,09h
	int 21h

back:mov ah,[bx]
	cmp ah,00h
	jz exit
	mov al,[bx]
	call printspace
	call printf
	inc bx
jmp back

exit:mov ah,4ch
	int 21h

printspace proc near
	mov n,al
	mov dl,' '
	mov ah,02h
	int 21h
	mov ah,00h
	mov al,n
	ret
printspace endp

printf proc near
	mov cx,00h
	l3:mov dx,0000h
	div d
	push dx
	inc cx
	cmp ax,00h
	jnz l3
	l4:pop dx
	add dl,30h
	mov ah,02h
	int 21h
	loop l4
	mov cx,00h
	ret
printf endp

end
