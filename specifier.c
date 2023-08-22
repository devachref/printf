#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", p_char},
		{"d", p_int},
		{"i", p_int},
		{"s", p_string},
		{"%", p_percent},
		{"b", p_binary},
		{"o", p_octal},
		{"u", p_unsigned},
		{"x", p_hex},
		{"X", p_HEX},
		{"p", p_adress},
		{"S", p_S},
		{"r", p_rev},
		{"k", p_rot13},
		(NULL, NULL)
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifiers[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag _finds the flag func
 * @s: the format strig
 * @params: the paramters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get modifier - finds the modifer func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new ponter
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '"')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}



