.MODEL SMALL
.DATA

PA EQU 0D800H
PB EQU 0D801H
PC EQU 0D802H
CW EQU 0D803H

NUM DW 0FFFFH		;16 bit intput number taken

TABLE DB 0C0H, 0F9H, 0A4H, 0B0H, 99H, 92H, 82H, 0F8H, 80H, 90H		; 0 1 2 3 .... 9 numbers
LIST DB 0FFH, 0FFH, 0FFH, 0FFH, ? , ? , ? , ? , ? , 0FFH, 0FFH, 0FFH, 0FFH

.CODE
MOV AX,@DATA
MOV DS,AX

MOV DX,CW		;all ports are output
MOV AL,80H
OUT DX,AL

mov ax,NUM		;AX = NUM
MOV CX,00H		;Counter is 0
MOV BX,010D

L1:
	MOV DX,00H
	DIV BX		;divide by 10
	PUSH DX		;push remainder, the last digit
	INC CX
	CMP AX,00H
JNZ L1

LEA SI,LIST+8
LEA BX,TABLE	;converting to BCD digits

L2:
	POP AX
	XLAT			;match with the table which is in bx
	MOV [SI],AL		;store it in list digits in BCD
	DEC SI			;in reverse order
LOOP L2

mov bh,010d			; display from left To right
lea di,list

l3:
	mov si,di		;si is going to change when display is used
	call DISPLAY
	call DELAY
	INC DI
	DEC BH			;loop for 10 times
JNZ L3

MOV BH,09D			; display from right to left
lea DI,LIST+8

L4:
	MOV SI,DI
	CALL DISPLAY
	CALL DELAY
	DEC DI
	DEC BH			;loop for 9 times
JNZ L4

mov ah,4ch
int 21h

DISPLAY PROC NEAR		;display using port B for LED
   MOV CX,04H
   letter:
		MOV BL,08H
		MOV AL,[SI]
		segments:
			ROL AL,01H
			MOV DX,PB	;7 segment display with port B
			OUT DX,AL

			PUSH AX
			MOV AL,00H	;clock trigger
			MOV DX,PC
			OUT DX,AL
			MOV AL,01H
			OUT DX,AL
			POP AX

			DEC BL
		JNZ segments

		INC SI
	LOOP letter
RET
DISPLAY ENDP

DELAY PROC NEAR
	PUSH SI
	PUSH DI

	MOV SI,0FFFFH
	Outer:
		MOV DI,0FFFFH
		Inner:
			DEC DI
		JNZ Inner
		DEC SI
	JNZ Outer

	POP DI
	POP SI
	RET
DELAY ENDP

END
