/*
 * File: setup.c
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_memory - Returns a malloc'd void pointer based on the specifier
 * @s: spec struct
 * @valist: pointer of type va_list
 *
 * Return: void pointer
 */
void *get_memory(spec s, va_list *valist)
{
	void *vp = NULL;

	switch (s.type)
	{
	case 'i':
		vp = malloc(sizeof(int));
		*(int *)vp = va_arg(*valist, int);
		break;
	case 's':
		vp = malloc(sizeof(char *));
		*(char **)vp = va_arg(*valist, char *);
		break;
	case 'I':
		vp = malloc(sizeof(unsigned int));
		*(unsigned int *)vp = va_arg(*valist, unsigned int);
		break;
	case 'l':
		vp = malloc(sizeof(long int));
		*(long int *)vp = va_arg(*valist, long int);
		break;
	case 'L':
		vp = malloc(sizeof(unsigned long));
		*(unsigned long *)vp = va_arg(*valist, unsigned long);
		break;
	}

	return (vp);
}

/**
 * get_full - Extracts the full set of flags, width, precision, and the
 * specifier from the format string
 * @string: Pointer to the format string
 * @specs: Pointer to the list of specifiers
 * @res: Pointer to the param struct to change the attributes of
 *
 * Return: Number of characters contained in the specifier including all
 * flags, width, precision, and specifiers (excluding the %)
 */
int get_full(const char *string, spec *specs, param *res)
{
	int offset = 0;
	int specifier;

	offset = setflags(string, res);
	offset += setwidth(string + offset, res);
	offset += setprecision(string + offset, res);

	specifier = setspecifier(string + offset, res, specs);
	if (specifier == -1)
		return (-1);

	offset += specifier;

	return (offset);
}

/**
 * get_specs - Provides a pointer to allocated space containing predefined
 * spec structs
 *
 * Return: Pointer to the first element in an array of `spec`s
 */
spec *get_specs(void)
{
	int j;
	spec *ret_spec;
	spec specs[] = {
		{"i", print_decimal, 'i'}, {"d", print_decimal, 'i'},
		{"s", print_string, 's'}, {"c", print_char, 'i'},
		{"x", print_hex, 'I'}, {"X", print_hex_unsig, 'I'},
		{"o", print_octal, 'I'}, {"u", print_unsig, 'I'},
		{"b", print_binary, 'I'}, {"r", print_reverse, 's'},
		{"S", print_special, 's'}, {"R", print_rot, 's'},
		{"p", print_pointer, 'L'}, {"li", print_long_decimal, 'l'},
		{"ld", print_long_decimal, 'l'}, {"lu", print_unsigned_long_decimal, 'L'},
		{"lx", print_long_hex, 'L'}, {"lX", print_long_hex_unsig, 'L'},
		{"lo", print_octal_long, 'L'}, {"hu", print_unsigned_short_decimal, 'i'},
		{"hd", print_short_decimal, 'i'}, {"hi", print_short_decimal, 'i'},
		{"ho", print_octal_short, 'i'}, {"hx", print_short_hex, 'i'},
		{"hX", print_short_hex_unsig, 'i'}, {NULL, NULL, '\0'}};

	ret_spec = malloc(sizeof(spec) * 26);
	if (ret_spec == NULL)
		return (NULL);

	for (j = 0; j < 26; j++)
		ret_spec[j] = specs[j];

	return (ret_spec);
}
