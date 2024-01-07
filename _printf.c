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
	va_list list;
	int count;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	count = process_format(format, list);
	va_end(list);
	return (count);
}

/**
 * process_arg - get the proper funtion need
 * @option: option
 * Return: function pointer
 */
int (*process_arg(char option))(va_list list)
{

	write_ops operations[] = {
	    {'i', write_num},
	    {'d', write_num},
	    {'s', write_string},
	    {'c', write_char},
	    {'b', write_binary},
	};
	int i;

	for (i = 0; i < 5; i++)
	{

		if (operations[i].op == option)
		{
			return (operations[i].func);
		}
	}

	return (NULL);
}

/**
 * process_format - get and format all the items in the va_list
 *
 * @format: string with the format to be parsed and substituted
 * @list: va_list with the variable number of argument of diff types
 * Return: number of character written to the stdout;
 */
int process_format(const char *format, va_list list)
{
	int (*func)(va_list), count = 0;

	while (*format != '\0')
	{
		if (*format == '%' && format++)
		{
			if (*format == '%')
			{
				count += _putchar('%');
				format++;
				continue;
			}
			if (*format == '\0')
			{
				_putchar('\r');
				return (-1);
			}
			func = process_arg(*format);
			if (func != NULL)
			{
				count += func(list);
			}
			else
			{
				format--;
				count += _putchar(*format);
			}
			format++;
			continue;
		}
		count += _putchar(*format);
		format++;
	}

	return (count);
}
