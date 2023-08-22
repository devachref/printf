#include "main.h"
/**
 * print_number - prints
 * @args: arguments
 * Return: len
 */
int print_number(va_list args)
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
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}
	while (num / check > 9)
	{
		check *= 10;
	}
	while (check != 0)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}
/**
 * p_char - prints characters
 * @args: arguments
 * Return: 1 value
 */
	int p_char(va_list args)
	{
		char value;

		value = (char)va_arg(args, int);
		_putchar(value);
		return (1);
	}
/**
 * p_string - prints strings
 * @args: argument
 * Return: i
 */
	int p_string(va_list args)
	{
		int i = 0;
		const char *s;

		s = va_arg(args, const char *);
		if (s == NULL)
		{
			s = "(null)";
		}
		while (s[i] != '\0')
		{
			_putchar(s[i]);
			i++;
		}
		return (i);
	}
/**
 * p_percent - prints % sign
 * @args: arguments
 * Return: 1
 */
	int p_percent(__attribute__((unused)) va_list args)
	{
		_putchar('%');
		return (1);
	}
/**
 * p_integer - prints integer arguments
 * @args: arguments
 * Return: n
 */
	int p_integer(va_list args)
	{
		int n;

		n = print_number(args);
		return (n);
	}

