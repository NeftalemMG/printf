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
		(*counter)++;
		str++;
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
 * printDecimal - Prints a decimal.
 *
 * @num: The decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printDecimal(int num, int *counter)
{
	char decimalStr[12];
	int n;

	n = sprintf(decimalStr, "%d", num);
	write(1, decimalStr, n);
	(*counter) += n;
}

/**
 * printBinary - Prints an unsigned integer in binary.
 *
 * @num: The unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printBinary(unsigned int num, int *counter)
{
	int i;
	char bit;

	for (i = 31; i >= 0; i--)
	{
		bit = ((num >> i) & 1) + '0';
		write(1, &bit, 1);
		(*counter)++;
	}
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

