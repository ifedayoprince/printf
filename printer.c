/**
 * File: printer.c
 * Auth: Ifedayo P Oni <ifedayoprince@gmail.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int print_str(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count += print_char(*str);
		str++;
	}
	return count;
}

int print_char(int c)
{
	return write(1, &c, 1);
}

int print_digit(long n, int base, bool caps)
{
	int count;
	char *symbols;
	char *symbolsCaps;

	symbols = "0123456789abcdef";
	symbolsCaps = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base, caps) + 1;
	}
	else if (n < base)
		return print_char(caps ? symbolsCaps[n] : symbols[n]);
	else
	{
		count = print_digit(n / base, base, caps);
		return count + print_digit(n % base, base, caps);
	}
}
