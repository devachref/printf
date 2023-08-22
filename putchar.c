#include <unistd.h>
/**
 * _putchar - writes a char to the standard output
 * @c: the character to be written
 * Return: On success, returns the number of characters written.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
