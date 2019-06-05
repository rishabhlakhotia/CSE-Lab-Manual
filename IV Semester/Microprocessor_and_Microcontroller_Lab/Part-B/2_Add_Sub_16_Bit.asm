;WRITE AN ASSEMBLY LANGUAGE PROGRAM TO PERFORM THE ADDITION AND SUBTRACTION OF TWO 16-BIT NUMBERS.

;ADDITION
mov r0,#43h  //lower nibble of No.1
mov r1,#21h  //higher nibble of No.1
mov r2,#0cdh  //lower nibble of No.2
mov r3,#0efh  //higher nibble of No.2
clr c
mov a,r0
add a,r2
mov 22h,a
mov a,r1
addc a,r3
mov 21h,a
mov 00h,c

;SUBTRACTION
mov r0,#0cdh //lower nibble of No.1
mov r1,#0efh //higher nibble of No.1
mov r2,#43h //lower nibble of No.2
mov r3,#21h //higher nibble of No.2
clr c 
mov a,r0
subb a,r2
mov 32h,a
mov a,r1
subb a,r3
mov 31h,a
mov 00h,c
end

