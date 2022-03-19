/**
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 * https://github.com/afiskon/stm32-SH1106
 * 
 * I modified and optimized the library to suit my application
 */

#ifndef SH1106_H__
#define SH1106_H__

#define SH1106_HEIGHT          64 // SH1106 OLED height in pixels
#define SH1106_WIDTH           132 // SH1106 width in pixels
#define SH1106_BUFFER_SIZE   SH1106_HEIGHT * SH1106_WIDTH / 8

// Enumeration for screen colors
typedef enum {
    Black = 0x00, // Black color, no pixel
    White = 0x01  // Pixel is set. Color depends on OLED
} SH1106_COLOR;

extern void SH1106_Init(void);
extern void SH1106_UpdateScreen(void);
extern void SH1106_DrawPixel(uint8_t x, uint8_t y, SH1106_COLOR color);
extern char SH1106_WriteChar(char ch, SH1106_COLOR color);
extern char SH1106_WriteString(char* str, SH1106_COLOR color);
extern void SH1106_SetCursor(uint8_t x, uint8_t y);
extern void SH1106_ClearScreen(void);

#endif //SH1106_H__
