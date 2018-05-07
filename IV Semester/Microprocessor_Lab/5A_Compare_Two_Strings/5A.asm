.model small

.data
msg_1 db 10,13,"Enter 1st String $"	;Entering the first string
buff1 db 100
len1 db ?
str1 db 100 dup(?)
msg_2 db 10,13,'Enter 2nd String $'	;Entering the second string
buff2 db 100
len2 db ?
str2 db 100 dup(?)
msg_len1 db 10,13,'Len of str1 is : $'
msg_len2 db 10,13,'Len of str2 is : $'
msg_s db 10,13,'Strings are equal!$'
msg_ns db 10,13,'Strings are not equal.$'

.code
mov ax,@data
mov ds,ax
mov es,ax	;cmps works only in extra segment

lea dx,msg_1	;Enter string message
call printf
lea dx,buff1	;Enter string 1
call puts
lea dx,msg_2
call printf 
lea dx,buff2	;enter string 2
call puts
mov al,len1
cmp al,len2
JNE LenNotEqual		;lengths are not equal

;comparing 2 strings
mov cx,0000h
mov cl,len1
lea SI,str1
lea DI,str2
CLD
rep cmpsb
JE Str_Equal	;strings are same

LenNotEqual:	
	lea DX,msg_ns
	call printf
	jmp exit

Str_Equal:	lea dx,msg_s
		call printf

exit:	
	lea dx,msg_len1		;printing length of string 1
	call printf
	mov dl,len1
	call print_8bit
	lea dx,msg_len2		;printing length of string 2
	call printf
	mov dl,len2
	call print_8bit
mov ah,4ch
int 21h

;Procedure for Displaying Message
printf proc near
	mov ah,09h
	int 21h
	ret
printf endp

;procedure to enter a string
puts proc near	
	mov ah,0Ah
	int 21h
	ret
puts endp

;procedure to display 8 bit character in decimal
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
	ret	
print_8bit endp

end