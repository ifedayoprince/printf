#ifndef MAIN_H
#define MAIN_H

/**
 * File: main.h
 * Auth: Ifedayo P Oni <ifedayoprince@gmail.com>
 */

#include <stdarg.h>
#include <stdbool.h>

int _printf(const char *format, ...);
int print_format(const char *specifier, va_list args);

/* Printer functions */
int print_str(char *str, bool caps);
int print_char(int c);
int print_digit(long n, int base, bool caps, bool fromS);

#endif
