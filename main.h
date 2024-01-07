#ifndef _PRINTF
#define _PRINTF

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef unsigned int u_int;

/* Define functions prototypes */
int _printf(const char *format, ...);

/* string manipulations function */
char *_strcat(char *dest, char *src);
u_int _strlen(char *str);
char *_itoa(int num);
char *_itob(int nums);

char *_strrev(char *str);

/* operation functions */
int write_num(va_list);
int write_string(va_list);
int write_char(va_list);
int write_binary(va_list list);
int (*process_arg(char option))(va_list list);

/* utilities function */
int _putchar(char c);

/**
 * struct w_ops - map function with the character options
 * @op: the option for that specific function
 * @func: the function to run
 * Return: the count of what was outputted
 */
typedef struct w_ops
{
	char op;
	int (*func)(va_list list);
} write_ops;

#endif /* _PRINTF */
