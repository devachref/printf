#include "main.h"
/**
 * p_unsigned - Print unsigned integer
 * @args: Arguments containing the unsigned int to be printed
 *
 * Return: the number of characters printed
 */
int p_unsigned(va_list args)
{
	unsigned int value = va_arg(args, unsigned int);
	unsigned int numy = value;
	unsigned int chck = 1;
	int lenz = 0;

	while (numy / chck > 9)
	{
		chck *= 10;
	}
	while (chck != 0)
	{
		lenz += _putchar('0' + numy / chck);
		numy %= chck;
		chck /= 10;
	}
	return (lenz);
}
