#include "main.h"
/**
 * p_octal - Print unsigned integer in octal format
 * @args: Arguments containing the unsigned int to be printed
 *
 * Return: The number of characters printed
 */
int p_octal(va_list args)
{
	unsigned int value = va_arg(args, unsigned int);
	unsigned int num = value;
	unsigned int check = 1;
	int len = 0;

	while (num / check > 7)
	{
		check *= 8;
	}
	while (check != 0)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 8;
	}
	return (len);
}
