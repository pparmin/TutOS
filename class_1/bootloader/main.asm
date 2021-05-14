; clear ax
xor ax, ax      ; compares the value in ax and if not equal sets a flag

; set direction flag to forward
cld


; ----- following segment sets up the stack -----
; move the address of the segment location the BIOS loads into ax
mov ax, 0x07c0

; add decimal 288 to the segment location the BIOS loads
add ax, 288

; move the value of the ax register into the ss register (stack segment)
mov ss, ax

; set the offset of the stack
mov sp, 65024

; move the address of the segment location into ax again
mov ax, 0x07c0

; mov ax into the ds register (data segment)
mov ds, ax
; -----------------------------------------------

mov bx, FirstName      ; move our string label to bx

call printirm           ; call the print function

mov bx, LastName

call printirm

; infinite loop to prevent shutdown
jmp $

printirm:
    mov ah, 0x0E    ; print a char in the basic VGA text mode
    main:
        cmp [bx], byte 0    ; compare dereferenced bx to a byte 0
        je end              ; if it is equal, return
        mov al, [bx]        ; move the char that is inside dereferenced bx to the char the will be printed out
        int 0x10            ; call the interrupt
        inc bx              ; increment the memory address
        jmp main            ; jump back to our label
    end:
        ret ; return

FirstName:
    db 'Kenix', 10, 10, 10, 10, 13, 0        ; 10 = \n new line; 13 = cursor to leftmost; 0 for null termination

LastName:
    db 'Kil', 10, 13, 0

; fill in the bytes with zeros
times 510-($-$$) db 0   ; db = define byte | creates a loop that that fills all bytes with 0

; standard boot signature --> Boot signatures tell the BIOS that it is a bootable device
dw 0xAA55   ; dw = double word (16 bit value)