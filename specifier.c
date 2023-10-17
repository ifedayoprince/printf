/**
 * File: specifier.c
 * Auth: Ifedayo P Oni <ifedayoprince@gmail.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int print_format(const char *specifier, va_list args)
{
    int count = 0;
    /* d, f, c, x, p, s */
    if (*specifier == 's')
        count += print_str(va_arg(args, char *));
    else if (*specifier == 'c')
        count += print_char(va_arg(args, int));
    else if (*specifier == 'd' || *specifier == 'i')
        count += print_digit((long)va_arg(args, int), 10, false);
    else if (*specifier == 'u')
        count += print_digit((long)va_arg(args, unsigned int), 10, false);
    else if (*specifier == 'X')
        count += print_digit((long)va_arg(args, unsigned int), 16, true);
    else if (*specifier == 'x')
        count += print_digit((long)va_arg(args, unsigned int), 16, false);
    else if (*specifier == 'b')
        count += print_digit((long)va_arg(args, unsigned int), 2, false);
    else if (*specifier == 'o')
        count += print_digit((long)va_arg(args, unsigned int), 8, false);
    else if (*specifier == '%')
        count += print_char((int)*specifier);
    else
        count += print_char((int)*specifier);

    return count;
}
