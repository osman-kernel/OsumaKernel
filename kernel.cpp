#include "milli_lib.h"

void draw_bayrak() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 14; j++) {
            milli_putc(' ', 1 + i, 63 + j, 0x44);
        }
    }
    milli_print("(", 3, 66, 0x4F);
    milli_print("*", 4, 70, 0x4F);
}

extern "C" void kmain() {
    milli_cls();
    draw_bayrak();
    
    milli_print("--- OSUMA MILLI KERNEL v3.5 ---", 0, 0, 0x0E);
    milli_print("Komut Satiri Aktif. (Tuslara basmayi dene)", 2, 0, 0x07);
    milli_print("> ", 4, 0, 0x0A);

    int cursor_x = 2;
    
    while(1) {
        // Klavyede yeni bir tus var mi? (Durum portu 0x64, 1. bit)
        if(inb(0x64) & 0x01) {
            uint8_t scancode = inb(0x60); // Veri portu 0x60
            
            // SADECE tusa basılma anını yakala (0x80'den küçükse basılmıştır)
            if (scancode < 0x80) {
                if(scancode == 0x1F) { milli_putc('S', 4, cursor_x++, 0x0F); }
                else if(scancode == 0x17) { milli_putc('I', 4, cursor_x++, 0x0F); }
                else if(scancode == 0x14) { milli_putc('T', 4, cursor_x++, 0x0F); }
                else if(scancode == 0x12) { milli_putc('E', 4, cursor_x++, 0x0F); }
                else if(scancode == 0x32) { milli_putc('M', 4, cursor_x++, 0x0F); }
                
                if(cursor_x >= 8) {
                    milli_print(" [ MILLI CEKIRDEK ONLINE ] ", 6, 0, 0x0B);
                }
            }
        }
    }
}
