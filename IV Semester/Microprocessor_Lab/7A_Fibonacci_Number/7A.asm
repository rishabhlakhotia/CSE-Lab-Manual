.model small

.data
msg_1 db 10,13,'Enter the Number: $'
msg_2 db 10,13,'0 1 $'
num dw ?
a dw 0h
b dw 01h

.code
mov AX,@data
mov DS,AX
lea DX,msg_1
call printf
call read_8bit

mov cx,num		;counter till nth number
sub cx,02h		;decrement by 2 as first 2 are printed
lea DX,msg_2
call printf

loop1:				;Fibonacci loop
		mov AX,a		;temporarily assigning to REG
		add AX,b		;a = a + b ; c = AX
		mov a,AX		;restoring a as c
		mov DI,CX			;storing the counter temporarily in DI
		mov DX,AX			;stored in DL to print Number
		call print_8bit		;display nth number
		mov AX,a
		XCHG AX,b			;a=b and b=a(which is c)
		mov a,AX
		mov CX,DI			;restoring counter
loop loop1

mov AH,4Ch
int 21h

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
		add dx,0030h	;converting the number to ASCII value
		mov ah,02h		;character display
		int 21h
	loop Loop_pop
	mov dl,' '		;printing space
	mov ah,02h
	int 21h
	ret
print_8bit endp

;procedure to read 8 bit numbers & store in AL
read_8bit proc near
	mov AH,01h		;reading 1st nibble
	int 21h
	sub AL,30h
	mov BL,AL
	mov AH,01h		;reading 2nd Nibble
	int 21h
	sub AL,30h
	mov AH,BL
	AAD				;ASCCI adjust before division
	mov num,AX
	ret
read_8bit endp

;procedure to print message
printf proc near
	mov AH,09h
	int 21h
	ret
printf endp

end
