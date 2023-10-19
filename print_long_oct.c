/*
 * File: print_long_oct.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include "main.h"

/**
 * print_octal_long - prints an unsigned long int as an octal.
 * @luop: Void pointer to an address in memory holding an unsigned long int.
 * @params: a structure containing info about the argument
 * Return: Number of characters printed.
 */
int print_octal_long(void *luop, param params)
{
	unsigned long int oct = *(unsigned long int *)luop;
	int count = 0;

	if (params.pound && oct != 0)
	{
		count += _putchar('0');
	}
	return (long_base_converter(oct, 8, "01234567") + count);
}

/**
 * print_unsigned_long - Prints an unsigned long integer
 * @luip: Void pointer to an address in memory which holds an unsigned long
 * integer.
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_unsigned_long(void *luip, param params)
{
	unsigned long int i = *(unsigned int *)luip;
	(void)(params);

	return (long_base_converter(i, 10, "0123456789"));
}
