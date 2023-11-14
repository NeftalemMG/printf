#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

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

/**
 * printReversedString - Prints a reversed string.
 *
 * @str: The string to print in reverse.
 * @counter: Pointer to the count of characters printed.
 */
void printReversedString(char *str, int *counter)
{
	int len;

	len = strlen(str);
	while (len > 0)
	{
		write(1, &str[len - 1], 1);
		(*counter)++;
		len--;
	}
}

/**
 * rot13 - Applies ROT13 substitution to a character.
 *
 * @c: The character to apply ROT13 to.
 * Return: The ROT13'ed character.
 */
void rot13(char *c)
{
	char base;

	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
	{
		base = (*c >= 'a' && *c <= 'z') ? 'a' : 'A';
		*c = ((*c - base + 13) % 26 + base);
	}
}

/**
 * printRot13String - Prints a string after applying ROT13.
 *
 * @str: The string to print.
 * @counter: Pointer to the count of characters printed.
 */
void printRot13String(char *str, int *counter)
{
	while (*str != '\0')
	{
		rot13(str);
		write(1, str, 1);
		(*counter)++;
		str++;
	}
}
