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
	int count = 0;

	va_start(list, format);

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
			if (*format == '\0')
			{
				_putchar('\r');
				return (0);
			}
			if (*format == '!')
			{
				count += _putchar('%');
				count += _putchar('!');
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
	int i;

	for (i = 0; i < 4; i++)
	{

		if (operations[i].op == option)
		{
			return (operations[i].func);
		}
	}

	return (NULL);
}
