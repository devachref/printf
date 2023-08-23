#include "main.h"

/**
 * p_hex_upper - Print unsigned integer in uppercase hexadecimal format
 * @args: Arguments containing the unsigned int to be printed
 *
 * Return: The number of characters printed
 */
int p_hex_upper(va_list args)
{
	unsigned int value = va_arg(args, unsigned int);
	char hex[20];
	int index = 0;
	int printed_chars;

	do {
		int digit = value % 16;

		hex[index++] = (digit < 10)
			? ('0' + digit) : ('A' + digit - 10);
		value /= 16;
	}
	while (value > 0);
	while (index > 0)
	{
		_putchar(hex[--index]);
		printed_chars++;
	}
	return (printed_chars);
}
