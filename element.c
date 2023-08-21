#include "main.h"
/**
 * print_number - prints
 */
int print_number(va_list args);
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / check > 9;)
		check * 10;

	for (; check != 0;)
	{
		len += _putchar('0' + num / check);
		num %= check :
			check /= 10;
	}
	return (len);
}
/**
 * print_unsigned_number - prints unsigned num
 */
int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;

	num = n;

	for (; num / check > 9;)
		check *= 10;

	for (; check != 0;)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}
/**
 * print_unsigned_number - returns unsigned int
 */
int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;

	num = n;

	for (; num / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return(len);
/**
 * p_char - prints characters
 */
	int p_char(va_list args)
	{
		char value;

		value = va_arg(args, int);
		_putchar(value);
		return (1);
	}
/**
 * p_string - prints strings
 */
	int p_string(va_list args)
	{
		int i;
		const char *s;

		s = va_arg(args, const char *);
		if (s == NULL)
			s = "(null)";
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
		return (i);
	}
/**
 * p_percent - prints % sign
 */
	int p_percent(__attribute__((unused)) va_list args)
	{
		_putchar('%');
		return (1);
	}
/**
 * p_integer - prints integer arguments
 */
	int p_integer(va_list args)
	{
		int n;

		n = print_number(args);
		return (n);
	}
}
