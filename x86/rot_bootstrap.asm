; rot_bootstrap.asm - a bunch of defs, with a little bit of startup code

extern rot_main
global rot_start

MBALIGN     equ  1<<0
MEMINFO     equ  1<<1
FLAGS       equ  MBALIGN | MEMINFO
MAGIC       equ  0x1BADB002
CHECKSUM    equ -(MAGIC + FLAGS)

section .multiboot_header
align 4

    DD MAGIC
    DD FLAGS
    DD CHECKSUM

section .tmpstack, nobits
align 4

stack_start:

    RESB 0FFFFh

stack_end:

section .text

rot_start:

    MOV esp, stack_end

    CALL rot_main

rot_limbo:

    CLI
    HLT
    JMP rot_limbo
