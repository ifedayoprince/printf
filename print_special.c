/**
 * File: print_special.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include "main.h"
#include <stddef.h>

/**
 * print_special - Prints a string and prints non-printable characters as
 * their ASCII value
 * @ssp: Void pointer to an adress where a pointer to the first character in
 * the string to be printed is stored
 * @params: a structure containing info about the argument
 * Return: Number of characters printed
 */
int print_special(void *ssp, param params)
{
	unsigned char *s = *(unsigned char **)ssp;
	char *hex = "0123456789ABCDEF";
	int count = 0;
	(void)(params);

	for (; *s; s++)
	{
		if (*s >= 32 && *s < 127)
		{
			_putchar(*s);
			count++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			_putchar(hex[*s / 16]);
			_putchar(hex[*s % 16]);
			count += 4;
		}
	}

	return (count);
}

/**
 * print_unsigned_short_decimal - prints an unsigned short int in base 10.
 * @usivp: void pointer to mallocd mem containing an unsigned short int.
 * @params: a structure containing info about the argument
 * Return: the number of characters printed.
 */
int print_unsigned_short_decimal(void *usivp, param params)
{
	unsigned short int usi = *(unsigned short int *)usivp;
	(void)(params);

	return (short_base_converter(usi, 10, "0123456789"));
}

/**
 * print_string - prints a string
 * @sp: void pointer to a string
 * @params: A structure containing info about the argument description.
 * Return: The number of characters printed.
 */
int print_string(void *sp, param params)
{
	char *s = *(char **)sp;
	int i = 0;
	(void)(params);

	if (s == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (; *s; s++, i++)
		_putchar(*s);

	return (i);
}

/**
 * print_unsigned_short - Prints an unsigned short integer in base 10.
 * @suip: Void opinter to an address in memory which holds an unsigned short
 * integer.
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_unsigned_short(void *suip, param params)
{
	unsigned short int i = *(unsigned short int *)suip;
	(void)(params);

	return (short_base_converter(i, 10, "0123456789"));
}

/**
 * print_unsigned - Prints an unsigned integer
 * @uip: Void pointer to an adress in memory which holds an unsigned integer
 * @params: a structure containing info about the argument
 * Return: The number of characters printed
 */
int print_unsigned(void *uip, param params)
{
	unsigned int i = *(unsigned int *)uip;
	(void)(params);

	return (base_converter(i, 10, "0123456789"));
}
