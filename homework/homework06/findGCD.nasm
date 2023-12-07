; coded on ubuntu version 22.04.03
;
;assemble: nasm -felf64 findGCD.nasm 
;load: ld findGCD.o -o findGCD
;run: ./findGCD
global      _start           

        section     .data
msg1:   db          "Enter first number: ", 0
msg2:   db          10, "Enter second number: ", 0
msg3:   db          10, 0
msg4:   db          "The Greatest Common Divisor is ", 0
STDOUT  equ         1
STDIN   equ         0
SYS_wrt equ         1
SYS_ext equ         60
SYS_rd  equ         0


        section     .bss
num1:   resb        40
num2:   resb        40

        section     .text
_start:   
        mov         rdi, msg1   ;prints enter first number
        call        printMsg
        mov         rdi, num1   ;gets input
        call        getNum
        mov         rdi, num1   ;converts to decimal
        call        strToInt
        mov         r12, rax

        mov         rdi, msg2   ;prints enter second
        call        printMsg
        mov         rdi, num2   ;get input again
        call        getNum
        mov         rdi, num2   ;convert to decimal
        call        strToInt
        mov         r13, rax

        mov         rdi, msg3
        call        printMsg


        ;euclids on numbers in r12 and r13
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
        call        intToStr
        mov         rdi, rax
        call        printMsg
        mov         rdi, msg3
        call        printMsg


        mov         rax, SYS_ext
        xor         rdi, rdi
        syscall

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

;gets a string from the command line (address)
global      getNum
        section     .text
getNum:
        mov         r8, rdi ;address
        mov         r10, -1
        mov         rdx, 1
startIn:
        add         r10, 1
        mov         rax, SYS_rd
        mov         rdi, STDIN
        lea         rsi, [r8 + r10]
        syscall
        mov         al, [r8 + r10]
        cmp         al, 10
        jne         startIn

        ret

;converts from str to int (str)
global      strToInt
        section     .text
strToInt:
        mov         r8, rdi
        xor         rax, rax
        xor         r9, r9
startConv:
        movzx       r9, byte[r8]
        cmp         r9, 10
        je          terminate
        sub         r9, '0'
        imul        rax, 10
        add         rax, r9
        inc         r8
        jmp         startConv

       
terminate:
        ret

;convert from int to str (int)
global      intToStr
    section     .bss
numStr      resb    15
    section     .text
intToStr:
        mov         rax, rdi
        lea         r9, [rel numStr + 14]
        mov         r10, 0
        mov         [r9], r10b
        dec         r9

startIntConv:
        cmp         rax, 10
        jl          finConv
        mov         rbx, 10
        xor         rdx, rdx
        div         rbx         
        add         dl, '0'
        mov         [r9], dl
        dec         r9
        jmp         startIntConv
finConv:
        add         al, '0'
        mov         [r9], al
        mov         rax, r9

        ret