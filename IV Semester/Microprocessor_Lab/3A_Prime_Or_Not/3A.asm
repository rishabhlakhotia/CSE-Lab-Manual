.model small

.data
msg_1 db 10,13,'Enter a 8 bit number: $'
num db ?
msg_prime db 10,13,'This number is prime!$'
msg_nprime db 10,13,'This number is not a prime$'

.code
mov AX,@data
mov DS,AX

lea dx,msg_1	;Display message
call printf
call read_8bit	;reading 8 bit number
mov cl,num		;counter as num-1
dec cl

loop1:				;for(i=num-1; i>=1; i--)
		cmp cl,01h		;if i == 1 return as prime
		JE Prime		
		mov ax,0000h
		mov al,num
		div cl			;num/i
		cmp ah,00h		;if num%i == 0 return not a prime
		JE Not_Prime
loop loop1

Prime:
	lea dx,msg_prime
	jmp exit

Not_Prime:
	lea DX,msg_nprime

exit:
	call printf
	mov AH,4Ch
	int 21h

;procedure to read 8 bit number
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
	mov num,AL
	ret
read_8bit endp

;procedure to print string
printf proc near
	mov ah,09h
	int 21h
	ret
printf endp

end