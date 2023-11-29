; have to do gcc -static
        global      main
        extern      makeNBOC
        extern      printf

        section     .data
intro   db          "Starting testing", 10, 10, 0
introf  db          "%s", 0
intf    db          "0x%x", 10, 0
test1   db          10, "Test 1: ", 0 
test2   db          10, "Test 2: ", 0 
test3   db          10, "Test 3: ", 0 
test4   db          10, "Test 4: ", 0 
test5   db          10, "Test 5: ", 0 


        section     .text
main:
        push        rbx

        mov         rdi, introf
        mov         rsi, intro
        xor         rax, rax
        call        printf

        mov         rdi, introf
        mov         rsi, test1
        xor         rax, rax
        call        printf
        mov         rdi, 0x12345678
        call        makeNBOC
        mov         rsi, rax
        mov         rdi, intf
        xor         rax, rax
        call        printf


        mov         rdi, introf
        mov         rsi, test2
        xor         rax, rax
        call        printf
        mov         rdi, 0x11223344
        call        makeNBOC
        mov         rsi, rax
        mov         rdi, intf
        xor         rax, rax
        call        printf

        mov         rdi, introf
        mov         rsi, test3
        xor         rax, rax
        call        printf
        mov         rdi, 0x11221122
        call        makeNBOC
        mov         rsi, rax
        mov         rdi, intf
        xor         rax, rax
        call        printf


        mov         rdi, introf
        mov         rsi, test4
        xor         rax, rax
        call        printf
        mov         rdi, 0x87654321
        call        makeNBOC
        mov         rsi, rax
        mov         rdi, intf
        xor         rax, rax
        call        printf

        mov         rdi, introf
        mov         rsi, test5
        xor         rax, rax
        call        printf
        mov         rdi, 0x12344321
        call        makeNBOC
        mov         rsi, rax
        mov         rdi, intf
        xor         rax, rax
        call        printf


        pop         rbx



        mov         rax, 60
        xor         rdi, rdi
        syscall

        