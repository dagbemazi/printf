#include <stdarg.h>
#include "main.h"

int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);

/**
 * _printf - A printf function
 * @format: Format specifier
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				case 'd':
				case 'i':
					count += print_integer(args);
					break;
				default:
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * print_char - Print an character
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: Arguments
 * Return: A string and a string length
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}

	return (count);
}

/**
 * print_integer - Print an integer
 * @args: Argument list
 * Return: Number of characters printed
 */

int print_integer(va_list args)
{
	int n = va_arg(args, int);
	char buf[10];
	int num_length = 0, j;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n == 0)
	{
		buf[num_length++] = '0';	
	}
	else
	{
		int num_copy = n;

		while (num_copy != 0)
		{
			buf[num_length++] = num_copy % 10 + '0';
			num_copy /= 10;
		}
	}

	for (j = num_length - 1; j >= 0; j--)
	{
		write(1, &buf[j], 1);
	}

	return (num_length);
}
