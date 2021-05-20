.set magic_num, 0x1BADB002
.set flags, (1<<0 | 1<<1)
.set checksum, -(magic_num + flags)

//our multiboot section

.section .multiboot
    .long magic_num
    .long flags
    .long checksum

.section .text
.extern kmain
.global kstartup

//function that will execute at the beggining
kstartup:
    //we set up the stack using the 32-bit extended stack pointer register
    mov $stack, %esp
    //call our function written in C
    call kmain

end:
    cli //disable interrupts
    hlt //halt
    jmp end //jump back

.section .bss
    //we define our stack that will be 2MB
    .space 2*1024*1024
    stack: