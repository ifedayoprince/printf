/**
 * File: printer.c
 * Auth: Ifedayo P Oni <ifedayoprince@gmail.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_str - Prints the characters in as string.
 * @str: The character string.
 * @caps: If the specifier was a capital 'S'
 *
 * Return: The number of bytes written.
 */
int print_str(char *str, bool caps)
{
    int count = 0;
    while (*str != '\0')
    {
        if (caps && ((*str > 0 && *str < 32) || *str >= 127))
        {
            count += print_str("\\x", false);
            count += print_digit((long)*str, 16, true, true);
            str++;
            continue;
        }
        else
        {
            count += print_char(*str);
            str++;
        }
    }
    return count;
}

/**
 * print_char - Prints the characters in as string.
 * @c: The integer representation of the character.
 *
 * Return: The number of bytes written.
 */
int print_char(int c)
{
    return write(1, &c, 1);
}

/**
 * print_digit - Prints the digit in a specified base with left padding.
 * @n: The number.
 * @base: The base to convert to.
 * @caps: If the number should be written with capital letters.
 * @fromS: If the function is called from the '%S' function.
 *
 * Return: The number of bytes written.
 */
int print_digit(long n, int base, bool caps, bool fromS)
{
    int count = 0;
    char *symbols = caps ? "0123456789ABCDEF" : "0123456789abcdef";
    int width = 2, length = 0;
    char buffer[32];

    if (n < 0) {
        write(1, "-", 1);
        n = -n;
        count++;
    }

    do {
        buffer[length++] = symbols[n % base];
        n /= base;
    } while (n != 0);

    while (length < width && fromS)  {
        write(1, "0", 1);
        count++;
        width--;
    }

    while (length > 0) {
        write(1, &buffer[--length], 1);
        count++;
    }

    return count;
}
