.MODEL SMALL
.DATA

PA EQU 0D800H
PB EQU 0D801H
PC EQU 0D802H
CW EQU 0D803H

.CODE
MOV AX,@DATA
MOV DS,AX

MOV DX,CW
MOV AL,80H		;all ports are outputs
OUT DX,AL

MOV DX,PA		;port A as output for bcd
MOV AL,00H		;initial value 0

UP:
	OUT DX,AL	;Display BCD
	CALL DELAY
	INC AL
	DAA			;Decimal Adjust after Addition
	CMP AL,00H
JNZ UP

MOV AL,98d

DOWN:
	OUT DX,AL	;Display BCD
	CALL DELAY
	DEC	AL
	DAS			;Decimal Adjust after Subtraction
	CMP AL,99d
JNZ	DOWN

MOV AH,4CH
INT 21H

DELAY PROC NEAR
	MOV SI,0FFFFH
	Outer:
		MOV DI,0FFFFH
		Inner:
			DEC DI
		JNZ Inner
		DEC SI
	JNZ Outer
	RET
DELAY ENDP

END
