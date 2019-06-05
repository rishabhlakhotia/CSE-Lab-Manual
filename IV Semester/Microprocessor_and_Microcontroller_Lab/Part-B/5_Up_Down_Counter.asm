;WRITE AN ASSEMBLY LANGUAGE PROGRAM TO IMPLEMENT (DISPLAY) AN EIGHT BIT UP/DOWN BINARY (HEX) COUNTER ON WATCH WINDOW

mov a,#0FFh 		//mov a, #00h for up counter
back: acall delay
dec a 				//inc a for binary up counter
jnz back
here: sjmp here
delay: mov r1,#0ffh
decr1: mov r2,#0ffh
decr: mov r3,#0ffh
djnz r3,$
djnz r2,decr
djnz r1,decr1
ret
end
