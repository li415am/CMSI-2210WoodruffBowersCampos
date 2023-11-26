global      _start           

        section     .data
msg1:   db          "Enter first number: ", 0
msg2:   db          10, "Enter second number: ", 0
msg3:   db          10, 0
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

        mov         rdi, rax
        call        intToStr
break:
        ;mov         rdi, rax
        ;call        printMsg


        mov         rdi, msg2
        call        printMsg

        mov         rdi, msg3
        call        printMsg


        ;euclids on numbers in r12 and r13
        cmp         r12, r13
        jl:         swap
loopEclid:
        mov         rax, r12
        mov         rbx, r13
        xor         rdx, rdx
        div         rbx
        cmp         rdx, 0
        je          foundGCD
        mov         rax, rbx
        mov         rbx, rdx
        jmp         loopEclid

        

swap:
        xor         r12, r13
        xor         r13, r12
        xor         r12, r13
foundGCD:
        mov         rax, rbx


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
    section     .text
intToStr:
        mov         rax, rdi
        xor         r10, r10
startIntConv:
        cmp         rax, 10
        jl          finConv
        mov         rbx, 10
        xor         rdx, rdx
        div         rbx         ;result in rax, remainer in rdx
        add         dl, '0'
        mov         [r9], dl
        inc         r9
        jmp         startIntConv
finConv:
        mov         [r9], al
        inc         r9
        xor         al, al
        mov         [r9], al
        mov         rax, r9
        ret