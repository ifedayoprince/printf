/*
 * File: pointer_print.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include "main.h"

/**
 * print_pointer - Prints the address held by a pointer in hexadecimal.
 * @p: Void pointer to an unsigned long int.
 * @params: A structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_pointer(void *p, param params)
{
	char *set = "0123456789abcdef";
	unsigned long int ptr_ul = *(unsigned long int *)p;
	int count = 0;

	if (ptr_ul == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return 6;
	}

	if (params.plus)
	{
		count += _putchar('+');
	}
	else if (params.space)
	{
		count += _putchar(' ');
	}

	_putchar('0');
	_putchar('x');
	return 2 + count + base_converter(ptr_ul, 16, set);
}

/**
 * print_char - Prints a character from a void pointer
 * @cp: Void pointer which points to an address where a character is stored
 * @params: a structure containing info about the argument
 * Return: Number of characters printed (Always 1)
 */
int print_char(void *cp, param params)
{
	int c = *(int *)cp;
	(void)(params);

	_putchar(c);
	return (1);
}


/**
 * print_octal - Prints an unsigned int as an octal
 * @uop: Void pointer to an adress in memory holding an unsigned int
 * @params: a structure containing info about the argument
 * Return: Number of characters printed
 */
int print_octal(void *uop, param params)
{
	unsigned int oct = *(unsigned int *)uop;
	int count = 0;

	if (params.pound && oct != 0)
		count += _putchar('0');

	return (base_converter(oct, 8, "01234567") + count);
}
