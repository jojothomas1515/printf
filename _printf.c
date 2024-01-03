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
			func = process_arg(*format);
			count += func(list);
			format++;
		}
		else
		{

			count += write(1, format, 1);
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
		{'i', 'i'}
	}
}