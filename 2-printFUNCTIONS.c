#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * printSString - Prints a string.
 *
 * @str: The string to print.
 * @counter: Pointer to the count of characters printed.
 */
void printSString(char *str, int *counter)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			char hex[4];

			sprintf(hex, "\\x%02X", (unsigned char)*str);
			write(1, hex, 4);
			(*counter) += 4;
		}
		else
		{
			write(1, str, 1);
			(*counter)++;
		}
		str++;
	}
}

/**
 * printPointer - Prints a pointer.
 *
 * @ptr: The pointer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printPointer(void *ptr, int *counter)
{
	unsigned long int value;
	char hex[18];
	int n;

	value = (unsigned long int)ptr;
	n = sprintf(hex, "0x%lx", value);
	write(1, hex, n);
	(*counter) += n;
}
