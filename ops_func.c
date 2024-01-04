#include "main.h"

/**
 * write_num - convert the number passed to string then print is via stdout
 *
 * @list: list
 * Return: number of characters printed
 */
int write_num(va_list list)
{
	int num = va_arg(list, int);
	int len = _strlen(_itoa(num));

	return (write(1, _itoa(num), len));
}

/**
 * write_string - with the string to stdout
 *
 * @list: variable list
 * Return: number of characters printed
 */
int write_string(va_list list)
{
	char *str = va_arg(list, char *);
	int len = _strlen(str);

	return (write(1, str, len));
}
