/**
 * File: specifier.c
 * Auth: Ifedayo P Oni <ifedayoprince@gmail.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_format - Pairs a specifier to an arg and prints it.
 * @specifier: The specifier.
 * @args: The list of arguments passed to _printf.
 *
 * Return: The number of bytes written.
 */
int print_format(const char *specifier, va_list args)
{
    int count = 0;

    if (*specifier == 's')
        count += print_str(va_arg(args, char *), false);
    else if (*specifier == 'c')
        count += print_char(va_arg(args, int));
    else if (*specifier == 'd' || *specifier == 'i')
        count += print_digit((long)va_arg(args, int), 10, false, false);
    else if (*specifier == 'u')
        count += print_digit((long)va_arg(args, unsigned int), 10, false, false);
    else if (*specifier == 'X')
        count += print_digit((long)va_arg(args, unsigned int), 16, true, false);
    else if (*specifier == 'x')
        count += print_digit((long)va_arg(args, unsigned int), 16, false, false);
    else if (*specifier == 'b')
        count += print_digit((long)va_arg(args, unsigned int), 2, false, false);
    else if (*specifier == 'o')
        count += print_digit((long)va_arg(args, unsigned int), 8, false, false);
    else if (*specifier == 'S')
        count += print_str(va_arg(args, char *), true);
    else if (*specifier == '%')
        count += print_char((int)*specifier);
    else
        count += print_char((int)*specifier);

    return count;
}
