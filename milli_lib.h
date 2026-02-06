#ifndef MILLI_LIB_H
#define MILLI_LIB_H

// Tipleri derleyiciye manuel öğretiyoruz (Harici kütüphane bağımlılığını kesmek için)
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

static volatile char* const VGA_MEM = (volatile char*)0xB8000;

// Porttan veri okuma fonksiyonu
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

__attribute__((noinline))
void milli_putc(char c, int row, int col, uint8_t color) {
    int offset = (row * 80 + col) * 2;
    VGA_MEM[offset] = c;
    VGA_MEM[offset + 1] = (char)color;
}

__attribute__((noinline))
void milli_cls() {
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        VGA_MEM[i] = ' ';
        VGA_MEM[i + 1] = 0x07;
    }
}

__attribute__((noinline))
void milli_print(const char* str, int row, int col, uint8_t color) {
    for (int i = 0; str[i] != '\0'; i++) {
        milli_putc(str[i], row, col + i, color);
    }
}

#endif
