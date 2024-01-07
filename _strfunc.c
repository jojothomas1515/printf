#include "main.h"

/**
 * _strlen - get the lenght of a string
 *
 * @str: target string
 * Return: length of the string
 */
u_int _strlen(char *str)
{
	u_int len;

	if (str == NULL)
	{
		return (0);
	}

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _strcat - concatenate two strings
 *
 * @dest: string to be concatenated to
 * @src: string to be appended
 *
 * Return: concantenated string
 */
char *_strcat(char *dest, char *src)
{
	u_int d_len = _strlen(dest), i;

	if (src == NULL || dest == NULL)
	{
		return (dest);
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[d_len + i] = src[i];
	}
	dest[d_len + i] = '\0';

	return (dest);
}

/**
 * _itoa - convert int to string
 * @nums: the number to convert to string
 * Return: string
 */
char *_itoa(int nums)
{
	char *num_str;
	int index = 0;
	int minus_flag = 0;
	long num = (long)nums;

	num_str = malloc(sizeof(char) * 64);

	if (num == 0)
	{
		num_str[0] = '0';
		num_str[1] = '\0';
		return (num_str);
	}

	if (num < 0)
	{
		minus_flag = 1;
		num *= -1;
	}

	if (num_str == NULL)
	{
		return (NULL);
	}

	while ((num / 10) != 0 || (num % 10) != 0)
	{
		num_str[index] = (num % 10) + '0';
		index++;
		num /= 10;
	}
	if (minus_flag == 1)
	{
		num_str[index] = '-';
		index++;
	}

	num_str[index] = '\0';

	return (_strrev(num_str));
}

/**
 * _strrev - reverse the string
 * @str: target string
 * Return: string
 */

char *_strrev(char *str)
{
	int end = _strlen(str), i;
	char temp;

	for (i = 0; i < end / 2; i++)
	{
		temp = str[end - i - 1];
		str[end - i - 1] = str[i];
		str[i] = temp;
	}

	return (str);
}

/**
 * _itob - convert int to string
 * @nums: the number to convert to string
 * Return: string
 */
char *_itob(int nums)
{
	char *num_str;
	int index = 0;
	long num = (long)nums;

	num_str = malloc(sizeof(char) * 64);

	if (num == 0)
	{
		num_str[0] = '0';
		num_str[1] = '\0';
		return (num_str);
	}

	if (num_str == NULL)
	{
		return (NULL);
	}

	while ((num / 2) != 0 && (num % 2) != 0)
	{
		num_str[index] = (num % 2) + '0';
		index++;
		num /= 2;
	}

	num_str[index] = '\0';

	return (_strrev(num_str));
}
