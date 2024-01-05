#include "main.h"

/**
 * _putchar - write out character to the standard output
 * @c: character to be written
 * Return: number of characters written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
