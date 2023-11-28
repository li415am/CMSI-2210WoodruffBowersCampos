global      paritygen
        section     .text
paritygen:
        xor         r10, r10
        xor         r12, r12
        mov         r11b, dl

loop:
        and         r11b, 0x01
        cmp         r11b, 1
        jne         isZero
        inc         r12

isZero:
        shr         r11b
        inc         r10
        cmp         r10, 7
        je          done
        jmp         loop
done:
        mov         rax, r12
        ret
