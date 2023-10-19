/*
 * File: flags.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include <stdio.h>
#include <stddef.h>
#include "main.h"

/**
 * setflags - Sets the flags portion of the pointed to param
 * @string: Pointer to the first character to check for flags
 * @p: Pointer to the param to modify
 *
 * Return: Number of flag chars found (to skip)
 */
int setflags(const char *string, param *p)
{
	unsigned int offset = 0;

	while (string[offset] == '-' || string[offset] == '+' ||
		   string[offset] == '0' || string[offset] == ' ' || string[offset] == '#')
	{
		switch (string[offset])
		{
		case '-':
			p->minus = 1;
			break;

		case '+':
			p->plus = 1;
			break;

		case '0':
			p->zero = 1;
			break;

		case ' ':
			p->space = 1;
			break;

		case '#':
			p->pound = 1;
			break;
		}
		offset++;
	}

	return (offset);
}

/**
 * setwidth - Sets the width portion of the pointed to param
 * @string: Pointer to the first character to check for width
 * @p: Pointer to the param to modify
 *
 * Return: Number of width chars found (to skip)
 */
int setwidth(const char *string, param *p)
{
	int offset = 0;

	while (string[offset] >= '0' && string[offset] <= '9')
	{
		p->width = p->width * 10 + (string[offset] - '0');
		offset++;
	}

	return (offset);
}

/**
 * setprecision - Sets the precision portion of the pointed to param
 * @string: Pointer to the first character to check for precision
 * @p: Pointer to the param to modify
 *
 * Return: Number of precision chars found (to skip)
 */
int setprecision(const char *string, param *p)
{
	int offset = 0;

	if (string[offset] == '.' && isdig(string[offset + 1]))
	{
		offset++;
		p->precision = 0;
		while (isdig(string[offset]))
		{
			p->precision = p->precision * 10 + (string[offset] - '0');
			offset++;
		}
	}

	return (offset);
}

/**
 * setspecifier - Sets the specifier portion of the pointed to param
 * @string: Pointer to the first character to check for specifier
 * @p: Pointer to the param to modify
 * @specs: Pointer to the first item in an array of specifiers to compare
 * against
 *
 * Return: Number of specifier chars found (to skip)
 */
int setspecifier(const char *string, param *p, spec *specs)
{
	int offset = 0;
	int i;

	for (i = 0; (specs + i)->type != '\0'; i++)
	{
		int match = 1;

		for (offset = 0; string[offset] &&
						 (specs + i)->spec_string[offset] != '\0';
			 offset++)
		{
			if (string[offset] != (specs + i)->spec_string[offset])
			{
				match = 0;
				break;
			}
		}

		if (match && (specs + i)->spec_string[offset] == '\0')
		{
			p->specifier = (specs + i);
			return (offset);
		}
	}

	return (-1);
}

/**
 * isdig - Checks if character is a digit
 * @c: The character to check
 *
 * Return: 1 if digit, 0 if not
 */
int isdig(char c)
{
	return (c >= '0' && c <= '9');
}
