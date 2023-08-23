#include "main.h"
#include <stdint.h>

/**
 * _printf - function that produces output according to a format
 * @format: the format used
 * Return: value
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;

	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{"b", p_binary},
		{"u", p_unsigned},
		{"o", p_octal},
		{"x", p_hex},
		{"X", p_hex_upper},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	/** call a parser function*/

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}
