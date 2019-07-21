.model small

.data
msg_1 db 10,13,'Enter a Alphanumeric Character: $'
msg_2 db 10,13,'ASCII value is: $'
char dw ?

.code
mov AX,@data
mov DS,AX

lea DX,msg_1	;Display Message
mov AH,09h		;instruction
int 21h			;BIOS Interrupt
mov AH,01h		;Instruction to read character 
int 21h			;& store in AL as hex ASCII value
mov ah,00h
mov char,ax

;clear Screen
mov ah,06h	;clear screen instruction
mov al,00h	;number of lines to scroll
mov bh,07h	;display attribute - colors
mov ch,00d	;start row
mov cl,00d	;start col
mov dh,24d	;end of row
mov dl,79d	;end of col
int 10h		;BIOS interrupt

;cursor to middle
mov ah,02h	;move cursor Instruction
mov bh,00h	;Page 0
mov dh,12d	;row
mov dl,39d	;column
int 10h		;BIOS interrupt

;printing 8 bit value in decimal digit by digit
lea DX,msg_2		;Display Message
mov AH,09h		;instruction
int 21h			;BIOS Interrupt
mov AX,char		;ax = character
mov BX,10d
mov CX,0000h

L_Stack:			;pushing to stack	
	mov DX,0000h	;DX = remainder
	div BX
	push DX		;push(remainder)
	inc CX			;top++
	cmp AX,0000h
	JNE L_Stack		;jump if ax not equal to 0 
	loop_pop:		;popping from stack
		pop DX
		add DX,0030h		;HexD ASCII conversion 31h(ASCII) = 1
		mov AH,02h		;Display character which is in hexD ascii
		int 21h
loop loop_pop

mov AH,4Ch
int 21h
end
