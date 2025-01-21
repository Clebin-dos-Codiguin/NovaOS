section .data
    msg db 'Pacote filtrado', 0xa
    len equ $ - msg

section .text
    global _start

_start:

     if (pacote é ICMP) então
   
    mov eax, 4
    mov ebx, 1 
    mov ecx, msg     
    mov edx, len      
    int 0x80          

    ; Saída do programa
    mov eax, 1
    xor ebx, ebx      
    int 0x80
