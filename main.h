#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Auth: Ifedayo P Oni
 *       Tiyani Chauke
 */

#include <stdarg.h>

typedef struct specifier spec;
/**
 * struct parameters - used for storing printf argument descriptions
 * @plus: '+' flag
 * @minus: '-' flag
 * @zero: '0' flag
 * @space: ' ' flag
 * @pound: '#' flag
 * @width: int value of width
 * @precision: int value of precision
 * @specifier: a struct with a specifier, it's relevant function ptr, and type
 */
typedef struct parameters
{
	/* Flags */
	char plus;
	char minus;
	char zero;
	char space;
	char pound;

	int width;
	int precision;

	spec *specifier;
} param;

/**
 * struct specifier - used for comparing printf specifiers.
 * @spec_string: The printf specifier
 * @func: The specifier's corresponding function pointer
 * @type: The type of input the function takes, represented as a char.
 *
 * Description: This will be used as an array. It holds all the printf
 * specifiers in spec_string, it's corresponding function pointer in func, and
 * the type of input the function takes in type.
 */
struct specifier
{
	char *spec_string;
	int (*func)(void *, param);
	char type;
};

spec *get_specs(void);
void print_number(int n);
int _pow(int a, int b);
int getnum(int num, int index);
int getlen(int num);
int base_converter(unsigned int, unsigned int, char *);

int setflags(const char *string, param *p);
int setwidth(const char *string, param *p);
int setprecision(const char *string, param *p);
int setspecifier(const char *string, param *p, spec *specs);
int isdig(char c);
int get_full(const char *string, spec *specs, param *);

int print_decimal(void *, param);
int print_string(void *, param);
int print_char(void *, param);
int print_hex(void *, param);
int print_hex_unsig(void *, param);
int print_octal(void *, param);
int print_unsig(void *, param);
int print_special(void *, param);

void *get_memory(spec, va_list *);
int loop_specifiers(va_list *, unsigned int, char, spec *, int *, int *);
int _putchar(char);
int _printf(const char *, ...);
int print_binary(void *, param);
unsigned int u_pow(unsigned int, unsigned int);
int print_reverse(void *, param);
int print_rot(void *, param);

/* short number functions */
int short_base_converter(unsigned short int, unsigned short int, char *);
int print_short_hex(void *, param);
int print_short_hex_unsig(void *, param);
int print_octal_short(void *, param);
int print_unsigned_short(void *, param);

/* long number functions */
int long_base_converter(unsigned long int, unsigned long int, char *);
int print_long_hex(void *, param);
int print_long_hex_unsig(void *, param);
int print_unsigned_long(void *, param);
int print_pointer(void *, param);
int print_octal_long(void *, param);

int print_long_decimal(void *ip, param p);
void print_long_number(long int n);
long int _pow_long(int a, int b);
long int getnum_long(long int num, long int index);
long int getlen_long(long int num);

int print_unsigned_long_decimal(void *ulivp, param params);

int print_short_decimal(void *ip, param p);
void print_short_number(short int n);
short int _pow_short(short int a, short int b);
short int getnum_short(short int num, short int index);
short int getlen_short(short int num);

int print_unsigned_short_decimal(void *usivp, param params);

#endif
