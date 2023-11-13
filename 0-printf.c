#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * printCharacter - Prints a character.
 *
 * @c: The character to print.
 * @counter: Pointer to the count of characters printed.
 */
void printCharacter(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

/**
 * printString - Prints a string.
 *
 * @str: The string to print.
 * @counter: Pointer to the count of characters printed.
 */
void printString(char *str, int *counter)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		(*counter)++;
	}
}

/**
 * printPercent - Print a percent sign.
 *
 * @counter: Pointer to the count of characters printed.
 */
void printPercent(int *counter)
{
	write(1, "%", 1);
	(*counter)++;
}

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

/*
 * int main(void)
{
    int count;

    count = _printf("Hello, %s!%c and the percent sign is %%.\n", "John", 'A');
    printf("\nNumber of characters printed: %d\n", count);

    return 0;
}
*/

