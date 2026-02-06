#!/bin/bash
nasm -f elf32 boot.asm -o boot.o
g++ -m32 -c kernel.cpp -o kernel.o -ffreestanding -O2 -fno-exceptions -fno-rtti -fno-stack-protector -fno-toplevel-reorder
ld -m elf_i386 -T linker.ld -o kernel.bin boot.o kernel.o
if [ -f kernel.bin ]; then
    qemu-system-i386 -kernel kernel.bin
fi
