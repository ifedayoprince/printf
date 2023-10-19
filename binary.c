/*
 * File: binary.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include "main.h"

/**
 * print_binary - Prints an unsigned number in binary.
 * @ip: A pointer to an unsigned int
 * @params: A structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_binary(void *ip, param params)
{
	unsigned int n = *(unsigned int *)ip;
	int count = 0;
	(void)(params);

	if (n == 0)
	{
		_putchar('0');
		return 1;
	}

	while (n > 0)
	{
		_putchar((n & 1) + '0');
		n >>= 1;
		count++;
	}

	return count;
}

/**
 * u_pow - Calculates exponents
 * @a: base
 * @b: exponent
 * Return: unsigned int of a^b
 */
unsigned int u_pow(unsigned int a, unsigned int b)
{
	unsigned int result = 1, i;

	for (i = 0; i < b; i++)
	{
		result *= a;
	}

	return result;
}
