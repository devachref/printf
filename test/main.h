#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
/**
 * struct convert - structure to take in args
 * @sym: specifier
 * @f: flag
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;


int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int p_integer(va_list args);
int p_integer(va_list args);
int print_unsigned_number(unsigned int n);
int print_number(va_list);
int p_binary(va_list args);
int p_unsigned(va_list args);
int p_octal(va_list args);
int p_hex(va_list args);
int p_hex_upper(va_list args);
#endif
