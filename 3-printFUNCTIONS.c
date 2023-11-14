#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * printUnsignedDecimal - Prints an unsigned decimal.
 *
 * @num: The unsigned decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printUnsignedDecimal(unsigned int num, int *counter)
{
	char decimalStr[12];
	int n;

	n = sprintf(decimalStr, "%u", num);
	write(1, decimalStr, n);
	(*counter) += n;
}

/**
 * printOctal - Prints an unsigned integer in octal.
 *
 * @num: The unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printOctal(unsigned int num, int *counter)
{
	char octalStr[12];
	int n;

	n = sprintf(octalStr, "%o", num);
	write(1, octalStr, n);
	(*counter) += n;
}

/**
 * printHexLower - Prints an unsigned integer in lowercase hexadecimal.
 *
 * @num: The unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printHexLower(unsigned int num, int *counter)
{
	char hexStr[12];
	int n;

	n = sprintf(hexStr, "%x", num);
	write(1, hexStr, n);
	(*counter) += n;
}

/**
 * printHexUpper - Prints an unsigned integer in uppercase hexadecimal.
 *
 * @num: The unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printHexUpper(unsigned int num, int *counter)
{
	char hexStr[12];
	int n;

	n = sprintf(hexStr, "%X", num);
	write(1, hexStr, n);
	(*counter) += n;
}
