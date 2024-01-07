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

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	return (write(1, str, len));
}
/**
 * write_binary - with the string to stdout
 *
 * @list: variable list
 * Return: number of characters printed
 */
int write_binary(va_list list)
{
	int num = va_arg(list, int);
	char *str = _itob(num);
	int len = _strlen(str);

	return (write(1, str, len));
}

/**
 * write_char - write out character gotten from valist
 * @list: valist
 * Return: the number of character written to stdout
 */
int write_char(va_list list)
{

	char c = va_arg(list, int);

	return (write(1, &c, 1));
}
