org 100h


.data
    array db 4,5,1,3,2,6
    len equ 6

.code
    mov si, 0 ; first index
    
    siloop:
        cmp si, len ; si >= len
        jge end; boundary condition
        mov di, si 
        inc di ;di = si + 1
        
        diloop:
            cmp di, len ; di >= len
            jge nextsi ;goes back to outer loop
            
            mov ah, [array + si] ; moves the value at index i to ah
            mov al, [array + di] ; moves the value at index j to al
            
            cmp ah, al
            jle nextdi;jump if less than or equal to
             
            mov [array + di], ah
            mov [array + si], al
            
            nextdi:
                inc di   ;j++
                jmp diloop
            
        nextsi:
            inc si  ;i++
            jmp siloop
    
    
    end:
        HLT
ret                                                               
