org 100h 
mov si, 1300h     ; source index
mov cl, [si]  ; count register
DEC cl   ;Decrement--
inc si   ;increment address by 1
mov al, [si]   ; moves first number to al
inc si ; si 1302 

back: mov bl, [si]
add al, bl ;al = al + bl
inc si ;1303
dec cl  ;cl--
jnz back  ;jump non zero

mov di, 1400h
mov [di],al
hlt            