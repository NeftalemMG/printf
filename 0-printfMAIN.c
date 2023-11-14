#include "main.h"
#include <stdio.h>

/**
 * _printf - A function that duplicates all the functionalities
 * of the "printf" function built from scratch
 *
 * @format: Format string with optional conversion specifiers.
 *
 * Description: printf
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter;

	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printCharacter(va_arg(args, int), &counter);
					break;
				case 's':
					printString(va_arg(args, char *), &counter);
					break;
				case '%':
					printPercent(&counter);
					break;
				case 'd':
					if (format[1] == 'l')
					{
						format++;
						printLongDecimal(va_arg(args, long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortDecimal(va_arg(args, int), &counter);
					}
					else
					{
						printDecimal(va_arg(args, int), &counter);
					}
					break;
				case 'i':
					if (format[1] == 'l')
					{
						format++;
						printLongDecimal(va_arg(args, long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortDecimal(va_arg(args, int), &counter);
					}
					else
					{
						printDecimal(va_arg(args, int), &counter);
					}
					break;
				case 'u':
					if (format[1] == 'l')
					{
						format++;
						printLongUnsigned(va_arg(args, unsigned long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortUnsigned(va_arg(args, unsigned int), &counter);
					}
					else
					{
						printUnsignedDecimal(va_arg(args, unsigned int), &counter);
					}
					break;
				case 'o':
					if (format[1] == 'l')
					{
						format++;
						printLongOctal(va_arg(args, unsigned long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortOctal(va_arg(args, unsigned int), &counter);
					}
					else
					{
						printOctal(va_arg(args, unsigned int), &counter);
					}
					break;
				case 'x':
					if (format[1] == 'l')
					{
						format++;
						printLongHexLower(va_arg(args, unsigned long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortHexLower(va_arg(args, unsigned int), &counter);
					}
					else
					{
						printHexLower(va_arg(args, unsigned int), &counter);
					}
					break;
				case 'X':
					if (format[1] == 'l')
					{
						format++;
						printLongHexUpper(va_arg(args, unsigned long), &counter);
					}
					else if (format[1] == 'h')
					{
						format++;
						printShortHexUpper(va_arg(args, unsigned int), &counter);
					}
					else
					{
						printHexUpper(va_arg(args, unsigned int), &counter);
					}
					break;
				case 'b':
					printBinary(va_arg(args, unsigned int), &counter);
					break;
				case 'S':
					printSString(va_arg(args, char *), &counter);
					break;
				case 'p':
					printPointer(va_arg(args, void *), &counter);
					break;
				case 'r':
					printReversedString(va_arg(args, char *), &counter);
					break;
				case 'R':
					printRot13String(va_arg(args, char *), &counter);
					break;
				default:
					printPercent(&counter);
					write(1, format, 1);
					counter += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
