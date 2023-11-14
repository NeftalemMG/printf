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
				case 'i':
					printDecimal(va_arg(args, int), &counter);
					break;
				case 'u':
					printUnsignedDecimal(va_arg(args, unsigned int), &counter);
					break;
				case 'o':
					printOctal(va_arg(args, unsigned int), &counter);
					break;
				case 'x':
					printHexLower(va_arg(args, unsigned int), &counter);
					break;
				case 'X':
					printHexUpper(va_arg(args, unsigned int), &counter);
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
/*int main(void)
{
    _printf("Characters: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Decimal: %d\n", 42);
    _printf("Binary: %b\n", 42);
    return (0);
}*/
