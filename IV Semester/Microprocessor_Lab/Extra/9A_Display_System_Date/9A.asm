.model small

.data
date db ?
month db ?
year dw ?

.code
mov ax,@data
mov ds,ax
mov ax,00h

mov ah,06h    ;clearing the screen
mov ch,00h
mov cl,00h
mov bh,07h
mov dh,24d
mov dl,79d
int 10h

mov ah,02h    ;setting the cursor to the middle of the screen
mov bh,00h
mov dh,12d
mov dl,40d
int 10h

mov ah,2ah
int 21h
mov date,dl
mov month,dh
mov year,cx

mov ah,00h
mov al,date
call display      ;displaying the date
call printc        ;printing the '/'

mov ah,00h
mov al,month        ;printing month
call display        ;printing '/'
call printc

mov ax,year        ;printing year
call display        ;printing '/'

mov ah,4ch
int 21h

display proc near
  mov bx,10d
  mov cx,00h
  l1:mov dx,00h
  div bx
  push dx
  inc cx
  cmp ax,00h
  jnz l1
  l2:pop dx
  add dl,30h
  mov ah,02h
  int 21h
  loop l2
  ret
display endp

printc proc near
  mov dl,'/'
  mov ah,02h
  int 21h
  ret
printc endp

end
