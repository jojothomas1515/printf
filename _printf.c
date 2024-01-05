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
	int (*func)(va_list);

	va_start(list, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
			{
				count += _putchar('%');
				format++;
				continue;
			}
			func = process_arg(*format);

			if (func != NULL)
			{
				count += func(list);
			}
			format++;
		}
		else
		{

			count += _putchar(*format);
			format++;
		}
	}

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
	};
	int i = 0;

	for (i; i < 4; i++)
	{
		if (operations[i].op == option)
		{
			return (operations[i].func);
		}
	}

	return (NULL);
}
