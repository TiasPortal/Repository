.section .data
msg1:
    .ascii "Hello, programmers!\n"
msg1_len = . - msg1

msg2:
    .ascii "Welcome to the world of,\n"
msg2_len = . - msg2

msg3:
    .ascii "Linux assembly programming!\n"
msg3_len = . - msg3

.section .text
.global _start

#Macro to print messages
.macro PRINT_MESSAGE msg, msg_len
    movl $4, %eax        #System call number (sys_write)
    movl $1, %ebx        #File descriptor (stdout)
    movl \msg, %ecx      #Message address
    movl \msg_len, %edx  #Message length
    int $0x80
.endm

_start:
    PRINT_MESSAGE $msg1, $msg1_len   #Printing "Hello, programmers!"
    PRINT_MESSAGE $msg2, $msg2_len   #Printing "Welcome to the world of,"
    PRINT_MESSAGE $msg3, $msg3_len   #Printing "Linux assembly programming!"

    #Exiting the program
    movl $1, %eax       #System call number (sys_exit)
    xorl %ebx, %ebx     #Exit status 0
    int $0x80

