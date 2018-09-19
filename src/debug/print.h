//
// Created by Carl on 2018/6/27.
//

#ifndef INC_64BITKERNEL_PRINT_H
#define INC_64BITKERNEL_PRINT_H
#include <type.h>

/**
 * Clears the first plane of VGA memory, effectively clearing all text from
 * the screen.
 */
void vga_clear(void);

/**
 * Checks if character is printable, if so it places it in VGA memory,
 * along with a color byte. If the character is not printable, it deals
 * with it accordingly
 *
 * @param c the input character
 */
void vga_put(char c);


/**
 * Prints every character in a character array , until it reaches
 * a NULL terminator.
 *
 * @param str the string to print
 * @see vga_put
 */
void vga_print(char *str);

/**
 * Prints a number using any base between 2 and 16, inclusive.
 *
 * @param n number to be printed
 * @param base base to use when printing the number
 * @see vga_print
 */
void vga_printnum(u32 n, u32 base);


#define is_ansi(x) ((x == 'A') || (x == 'B') || (x == 'C') || (x == 'D') || (x == 's') || (x == 'u') || (x == 'H') || (x == 'J') || (x == 'K') || (x == 'm'))
#endif //INC_64BITKERNEL_PRINT_H
