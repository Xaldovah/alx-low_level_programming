section .data
    msg db 'Hello, Holberton!', 0x0a, 0x00

section .text
    global main

    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rdi, msg
    xor rax, rax
    call printf

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret
