#include "main.h"
#include <stdio.h>
/**
 * p_binary - prints binary forms
 * @args: arguments to be passed
 * Return: value
 */
int p_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;
	char binary[32];

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	int index = 0;

	while (num > 0)
	{
		binary[index] = (num % 2) + '0';
		num /= 2;
		index++;
	}
	for (int i = index - 1; i >= 0; i--)
	{
		_putchar(binary[i]);
		len++;
	}
	return (len);
}
