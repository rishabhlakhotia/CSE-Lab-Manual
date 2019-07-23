.model small

.data
n db 01h
r db 01h
msg_1 db 10,13,'nCr is : $'
result db 00h

.code
mov AX,@data
mov DS,AX

lea dx,msg_1		;printing message
mov ah,09h
int 21h
call ncr			;call function

mov DL,result
call print_8bit

mov ah,4ch
int 21h

;recursive procedure to call NCR
ncr proc near
	mov AL,n		;nCn right leaf node
	cmp r,AL
	JNE right_tree
	add result,01h		;Leaf node result++
	ret
	right_tree:
	cmp r,00h		;nC0 left leaf node
	JNE main_fun
	add result,01h		;Leaf node result++
	ret
	main_fun:
	dec n 			;(n-1)Cr
	call ncr			;left tree
	dec r			;(n-1)C(r-1)
	call ncr			;right tree
	inc r			;traversing back to root
	inc n
	ret
ncr endp

;procedure to display 8 bit character in decimal value in DL
print_8bit proc near
	mov ax,0000h
	mov al,dl
	mov bx,0010d
	mov CX,0000h
	Loop_push:
		mov DX,0000h
		div BX
		push DX
		inc CX
		cmp AX,0000h
	JNE Loop_push
	Loop_pop:
		pop DX
		add dx,0030h		;converting the number to ASCII value
		mov ah,02h		;character display
		int 21h
	loop Loop_pop
	ret
print_8bit endp

end
