/*
 * File: print_reverse.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include <stddef.h>
#include "main.h"

/**
 * print_reverse - prints a string in reverse.
 * @s: a void pointer to a string
 * @params: a structure containing info about the argument
 * Return: the number of characters
 */
int print_reverse(void *s, param params)
{
	char *array = *(char **)s;
	int i = 0;
	int count = 0;
	(void)(params);

	if (array == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (i = 0; array[i] != '\0'; i++)
		;
	i--;
	for (; i > -1; i--)
	{
		_putchar(array[i]);
		count++;
	}
	return (count);
}


/**
 * print_rot - prints a string in ROT13 format.
 * @s: pointer to a string
 * @params: a structure containing info about the argument
 * Return: The number of characters printed.
 */
int print_rot(void *s, param params)
{
	int i, j;
	char *array = *(char **)s;
	int count = 0, flag = 0;
	char check[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	(void)(params);

	if (array == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (i = 0; array[i] != '\0'; i++, flag = 0)
	{
		for (j = 0; check[j] != '\0'; j++)
		{
			if (array[i] == check[j])
			{
				_putchar(rot[j]);
				count++;
				flag = 1;
			}
		}
		if (flag < 1)
		{
			_putchar(array[i]);
			count++;
		}
	}
	return (count);
}
