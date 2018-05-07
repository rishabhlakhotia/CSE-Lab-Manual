.model small

.data
x db 00h
y db 00h
m1 db 10,13,'enter the x coordinate : $'
m2 db 10,13,'enter the y coordinate  : $'
m3 db 'cursor $'

.code
mov ax,@data
mov ds,ax

mov ax,00h
lea dx,m1
mov ah,09h
int 21h

call read        ;reading x coordinate
mov x,al
lea dx,m2
mov ah,09h
int 21h

call read         ;reading y coordinate
mov y,al

mov ah,06h         ;clearing the screen
mov cx,0000h
mov bh,07h
mov dx,2479d
int 10h

mov ah,02h                           ;  setting the cursor at the specified location
mov bh,00h 
mov dh,x
mov dl,y
int 10h
lea dx,m3
mov ah,09h
int 21h
mov ah,4ch
int 21h

read proc near
  mov ah,01h
  int 21h
  sub al,30h
  mov bl,al
  mov ah,01h
  int 21h
  sub al,30h
  mov ah,bl
  aad
  ret
read endp

end
