#include "main.h"

/**
 * _printf - format and print string
 *
 * @format: the string with the format
 *
 * Return: number of character written
 */
int _printf(const char *format, ...)
{
	return (write(1, format, _strlen(format)));
}