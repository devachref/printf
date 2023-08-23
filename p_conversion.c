#include "main.h"

/**
 * p_addr - Print memory address
 * @args: Arguments containing the memory address to be printed
 *
 * Return: The number of characters printed
 */
int p_addr(va_list args)
{
	void *ptr = va_arg(args, void *);
	char buffer[20];
	int index = 0;
	unsigned long int value;
	int printed_chars;


	if (ptr == NULL)
	{
		return (_printf("(nil)"));
	}
	value = (unsigned long int)ptr;
	while (value > 0)
	{
		int digit = value % 16;

		buffer[index++] = (digit < 10) ? ('0' + digit)
			: ('a' + digit - 10);
		value /= 16;
	}
	printed_chars = 0;
	_printf("0x");
	while (index > 0)
	{
		_putchar(buffer[--index]);
		printed_chars++;
	}
	return (printed_chars);
}
