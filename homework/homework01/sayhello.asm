global      _start                   ; on Linux this should be "_start"

         section     .text
_start:   mov         rax, 1         ; system call for write [Linux should be "_start"]
         mov         rdi, 1                  ; file handle 1 is stdout
         mov         rsi, message            ; address of string to output
         mov         rdx, 15                 ; number of bytes
         syscall                             ; invoke operating system to do the write
         mov         rax, 60         ; system call for exit [Linux use "60"]
         xor         rdi, rdi                ; exit code 0
         syscall                             ; invoke operating system to exit

         section     .data
message: db          10, "Hello, World", 10, 10