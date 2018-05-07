.MODEL SMALL
.DATA
KEYS DB '0123456789ABCDEFGHIJKLMN'
M1 DB 10,13,'Row: $'
M2 DB 10,13,'Column: $'
M3 DB 10,13,'Value: $'
ROW DB ?
COL DB ?

PA EQU 0D800H
PB EQU 0D801H
PC EQU 0D802H
CW EQU 0D803H

.CODE
MOV AX,@DATA
MOV DS,AX

MOV DX,CW
MOV AL,90H		;port A is input
OUT DX,AL

READ:
	MOV DX,PC		;trigger port C for row 1
	MOV AL,01H
	OUT DX,AL

	MOV DX,PA		;read input from port A
	IN AL,DX
	CMP AL,00H
	JNZ FR

	MOV DX,PC		;trigger port C for row 2
	MOV AL,02H
	OUT DX,AL

	MOV DX,PA		;read input from port A
	IN AL,DX
	CMP AL,00H
	JNZ SR

	MOV DX,PC		;trigger port C for row 3
	MOV AL,04H
	OUT DX,AL

	MOV DX,PA		;read input from port A
	IN AL,DX
	CMP AL,00H
	JNZ TR
JMP READ

FR:					;First row
	MOV ROW,31H
	MOV COL,31H
	LEA SI,KEYS

	L1:
		SHR AL,01H	;shift right until you get column
		JC DISPLAY
		INC COL
		INC SI
	JMP L1

SR:					;Second row
	MOV ROW,32H
	MOV COL,31H
	LEA	SI,KEYS+8D

	L2:
		SHR	AL,01H	;shift right until you get column
		JC DISPLAY
		INC COL
		INC SI
	JMP L2

TR:					;Third row
	MOV ROW,33H
	MOV COL,31H
	LEA SI,KEYS+16D

	L3:
		SHR AL,01H	;shift right until you get column
		JC DISPLAY
		INC COL
		INC SI
	JMP L3

DISPLAY:
	LEA DX,M3		;display value
	MOV AH,09H
	INT	21H
	MOV DL,[SI]		;extract character
	MOV AH,02H
	INT 21H

	LEA DX,M1		;display row
	MOV AH,09H
	INT 21H
	MOV DL,ROW
	MOV AH,02H
	INT 21H

	LEA DX,M2		;display column
	MOV AH,09H
	INT 21H
	MOV DL,COL
	MOV AH,02H
	INT 21H

MOV AH,4CH
INT 21H

END
