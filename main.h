#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if space_flag specified
 * @hashtag_flag: on if hashtag_flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field presision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_midifier: on if l_modifiter is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier	: 1;
	unsigned int l_midifier		: 1;
} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: The function associated
 */

typedef struct specifier
{
	char *spacifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* struct convert*/
/*{*/
/*	char *sym;*/
/*	int (*f)(va_list);*/
/*};*/
/*typedef struct convert conver_t;*/


/*int _putchar(char c);*/
int _puts(char *str);
int _putchar(int c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);

/*print_functions.c module */
int p_char(va_list ap, params_t *params);
int p_string(va_list ap, params_t *params);
int p_percent(va_list ap, params_t *params);
int p_integer(va_list ap, params_t *params);
int p_s(va_list ap, params_t *params);

/*number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int p_unsigned(va_list ap, params_t *params);
int p_address(va_list ap, params_t *params);

/*specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*convert_number.c module */
int p_hex(va_list ap, params_t *params);
int p_Hex(va_list ap, params_t *params);
int p_binary(va_list ap, params_t *params);
int p_octal(va_list ap, params_t *params);

/*simple_printers.c module */
int p_from_to(char *start, char *stop, char *except);
int p_rev(va_list ap, params_t *params);
int p_rot13(va_list ap, params_t *params);

/*print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int p_number(char *str, params_t *params);
int p_number_right_shift(char *str, params_t *params);
int p_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c module */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

/*int p_integer(va_list args);*/
/*int print_unsigned_number(unsigned int n);*/
/*int print_number(va_list);*/
#endif
