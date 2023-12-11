; coded on ubuntu version 22.04.03
;just a function that is called (expects an argument that is one byte of data)
;
;assemble: nasm -felf64 paritygen.nasm
;
;provided is paritygen.c which is a c function that can be used to call this nasm function
global       _paritygen

        section     .data
STDOUT  equ         1
SYS_wrt equ         1
        section     .bss
buffer  resb        1
        section     .text
_paritygen:
        xor         r11, r11
        xor         r10, r10
        xor         r9, r9
        mov         r11b, dil
loop:
        and         r11b, 0x01
        cmp         r11b, 1
        jne         continue
        inc         r9
continue:
        shr         dil, 1
        mov         r11b, dil
        inc         r10
        cmp         r10, 8
        je          done
        jmp         loop
done:
        mov         rax, r9
        mov         rcx, 2
        xor         rdx, rdx
        div         ecx
        cmp         rdx, 1
        je          zero
        mov         dl, 1
        jmp         print
zero:
        mov         dl, 0
print:
        add         dl, '0'
        mov         byte [buffer], dl
        mov         byte [buffer + 1], 10
        mov         rax, SYS_wrt
        mov         rdi, STDOUT
        mov         rsi, buffer
        mov         rdx, 2
        syscall

        ret
