/*
 * File: print_hex.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include "main.h"

/**
 * base_converter - Custom base conversion and printing function
 * @num: The unsigned integer to be converted and printed
 * @base: The base to be converted to
 * @set: The set of characters for base conversion,
 *           e.g., "0123456789abcdef" for hexadecimal
 *
 * Return: The number of characters printed
 */
int base_converter(unsigned int num, unsigned int base, char *set)
{
	char buffer[32];
	int charCount = 0, i;

	do {
		buffer[charCount++] = set[num % base];
		num /= base;
	} while (num > 0);

	for (i = charCount - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (charCount);
}

/**
 * print_hex - Custom function to print an unsigned integer as a hexadecimal
 * @numPtr: Pointer to an unsigned integer
 * @params: A structure containing information about the argument
 * Return: The number of characters printed
 */
int print_hex(void *numPtr, param params)
{
	unsigned int hexValue = *(unsigned int *)numPtr;
	char *characterSet = "0123456789abcdef";
	int charCount = 0;

	if (params.pound && hexValue != 0)
	{
		_putchar('0');
		_putchar('x');
		charCount += 2;
	}

	return (base_converter(hexValue, 16, characterSet) + charCount);
}

/**
 * print_hex_upper - Custom function to print an unsigned
 *                  integer as a hexadecimal in uppercase
 * @numPtr: Pointer to an unsigned integer
 * @params: A structure containing information about the argument
 * Return: The number of characters printed
 */
int print_hex_upper(void *numPtr, param params)
{
	unsigned int hexValue = *(unsigned int *)numPtr;
	char *characterSet = "0123456789ABCDEF";
	int charCount = 0;

	if (params.pound && hexValue != 0)
	{
		_putchar('0');
		_putchar('X');
		charCount += 2;
	}

	return (base_converter(hexValue, 16, characterSet) + charCount);
}

/**
 * print_hex_unsig - Prints an unsigned integer as a
 *                      hexidecimal in uppercase format
 * @uhp: Void pointer to an adress in memory which holds an unsigned integer
 * @params: a structure containing info about the argument
 * Return: The number of characters printed
 */
int print_hex_unsig(void *uhp, param params)
{
	unsigned int hex = *(unsigned int *)uhp;
	char *set = "0123456789ABCDEF";
	int count = 0;

	if (params.pound && hex != 0)
	{
		_putchar('0');
		_putchar('X');
		count += 2;
	}

	return (base_converter(hex, 16, set) + count);
}
