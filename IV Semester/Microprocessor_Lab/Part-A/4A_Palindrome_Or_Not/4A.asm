.model small

.data
msg_1 db 10,13,'Enter a String: $'
buff1 db 100
len1 db ?
str1 db 100 dup(?)
rstr db 100 dup(?)
msg_p db 10,13,'Its Palindrome$'
msg_np db 10,13,'Not Palindrome$'

.code
mov AX,@data
mov DS,AX
mov ES,AX

lea DX,msg_1	;Display message
call printf
lea DX,buff1	;Entering String
call gets		;stores in str1 with len1 as length

;reversing string by taking SI for source and DI for destination
lea SI,str1		
lea DI,rstr		;rstr[start]
mov CX,0000h
mov cl,len1		;CX = len(str)
add SI,CX
dec SI			;str[end]

reverse:
		mov AL,[SI]
		mov [DI],AL
		inc DI
		dec SI
loop reverse
mov AL,'$'		;ending the string
mov [DI],AL		;comparing strings
mov cx,0000h	
mov cl,len1		;counter set to length of string
lea SI,str1		
lea DI,rstr		
cld			;clear direction flag
repe cmpsb		;instruction to compare byte by byte
JE Palindrome
lea DX,msg_np
jmp exit

Palindrome:
	lea DX,msg_p

exit:
	call printf
	mov AH,4Ch
	int 21h

;procedure to scan a string
gets proc near	
	mov AH,0Ah	;instruction to read a string
	int 21h
	ret
gets endp

;procedure to print string
printf proc near
	mov AH,09h
	int 21h
	ret
printf endp

end