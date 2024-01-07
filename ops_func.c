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
	char *str = _itoa(num);
	int len = _strlen(str);
	int write_count = write(1, _itoa(num), len);

	free(str);
	return (write_count);
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
	int write_count = write(1, _itob(num), len);

	free(str);
	return (write_count);
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
