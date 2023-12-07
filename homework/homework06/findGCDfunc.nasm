; coded on ubuntu version 22.04.03
;assemble: nasm -felf64 findGCDfunc.nasm 
global      findGCDfunc           
        section     .data
msg3:   db          10, 0
msg4:   db          "The Greatest Common Divisor is ", 0
STDOUT  equ         1
STDIN   equ         0
SYS_wrt equ         1
SYS_ext equ         60
        section     .text
findGCDfunc:   
        ;euclids on numbers
        mov         r12, rdi
        mov         r13, rsi
        cmp         r12, r13
        jl          swap
doneSwap:
        mov         rax, r12
        mov         rbx, r13
        cmp         rbx, 0
        je          aNumIsZero
loopEuclid:
        xor         rdx, rdx
        div         rbx
        cmp         rdx, 0
        je          foundGCD
        mov         rax, rbx
        mov         rbx, rdx
        jmp         loopEuclid

swap:
        xor         r13, r12
        xor         r12, r13
        xor         r13, r12
        jmp         doneSwap

aNumIsZero:
        mov         rbx, rax
        jmp         foundGCD

foundGCD:
        mov         rdi, msg4
        call        printMsg
        mov         rdi, rbx
        push        rbx
        call        intToStr
        mov         rdi, rax
        call        printMsg
        mov         rdi, msg3
        call        printMsg
        pop         rax
        ret

;prints to command line (string)
global      printMsg
        section     .text
printMsg:
        mov         r8, rdi
        xor         rdx, rdx
strCount:
        cmp         byte [r8], 0
        je          print
        inc         rdx
        inc         r8
        jmp         strCount
print:
        mov         rax, SYS_wrt  
        mov         rsi, rdi
        mov         rdi, STDOUT                 
        syscall           

        ret

;convert from int to str (int)
global      intToStr
    section     .bss
numStr      resb    15
    section     .text
intToStr:
        mov         rax, rdi
        lea         r9, [numStr + 14]
        mov         r10, 0
        mov         [r9], r10b
        dec         r9

startIntConv:
        cmp         rax, 10
        jl          finConv
        mov         rbx, 10
        xor         rdx, rdx
        div         rbx         ;result in rax, remainer in rdx
        add         dl, '0'
        mov         [r9], dl
        dec         r9
        jmp         startIntConv
finConv:
        add         al, '0'
        mov         [r9], al
        mov         rax, r9

        ret