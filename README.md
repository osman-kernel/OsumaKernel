# 🇹🇷 OSUMA Milli Kernel v3.5

![Kernel Status](https://img.shields.io/badge/Status-Stable-brightgreen)
![Compiler](https://img.shields.io/badge/Compiler-GCC%2011.4%2B-blue)
![Platform](https://img.shields.io/badge/Platform-x86_32-orange)

OSUMA is a minimalist operating system kernel developed on an open-source environment, operating in 32-bit Protected Mode and communicating directly with hardware components.

## 🚀 Key Features

* **Armored Compilation:** A stable architecture capable of running under `-O2` (High-level optimization) without corrupting memory layout.
* **Hardware Drivers:** Core support for VGA Text Mode (0xB8000) and PS/2 Keyboard Controller (Ports 0x60/0x64).
* **Mini Shell:** An interactive command-line interface that captures user inputs via raw scancodes.
* **Bootloader Compatibility:** Designed with a Multiboot header to be launched directly by any compliant bootloader.

## 🛠️ Technical Infrastructure

This kernel is protected against modern compiler features like instruction reordering and dead code elimination using the following techniques:

- **Volatile Qualifiers:** Prevents the compiler from incorrectly optimizing memory-mapped I/O operations.
- **`__attribute__((noinline))`:** Ensures the integrity of critical I/O functions by preventing them from being inlined.
- **Stack Protector Disabled:** Minimizes internal dependencies by disabling stack canary mechanisms for a freestanding environment.



## 📂 File Structure

| File | Responsibility |
|------|----------------|
| `boot.asm` | Entry point and transition to high-level language. |
| `kernel.cpp` | Main kernel logic and the shell loop. |
| `milli_lib.h` | I/O port operations and display library. |
| `linker.ld` | Memory layout (Aligning the kernel at the 1MB mark). |
| `run.sh` | One-click build and emulation script. |

## 🏗️ Build and Execution

### Prerequisites
Ensure that the compiler (g++), assembler (nasm), and emulator (qemu) packages are installed on your system.

### Compiling and Testing
Execute the following command to start the process:
```bash
chmod +x run.sh
./run.sh
