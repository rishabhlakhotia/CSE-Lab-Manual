;WRITE AN ASSEMBLY LANGUAGE PROGRAM TO FIND THE LARGEST ELEMENT IN A GIVEN ARRAY OF N =___ H BYTES AT LOCATION 4000H. STORE THE LARGEST ELEMENT AT LOCATION 4062H.

;Let N = 07h
org 00h
mov a,#0x05
mov dptr,#0x4000
mov r0,#0x07
here:
	movx @dptr,a
	inc a
	inc dptr
	djnz r0,here
mov r3,#07h 
mov dptr,#4000H 
movx a,@dptr
mov r1,a
nextbyte: inc dptr
movx a,@dptr
clr c 
mov r2,a 
subb a,r1 
jc skip 
mov a,r2 
mov r1,a
skip: djnz r3,nextbyte
mov dptr, #4062H 
mov a,r1 
movx @dptr,a 
end
