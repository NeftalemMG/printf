#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * printShortOctal - Prints a short unsigned integer in octal format.
 *
 * @num: The short unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printShortOctal(unsigned short num, int *counter)
{
	char shortOctalStr[8];
	int n;

	n = sprintf(shortOctalStr, "%ho", num);
	write(1, shortOctalStr, n);
	(*counter) += n;
}

/**
 * printLongHexLower - Prints a long unsigned integer in
 * lowercase hexadecimal format.
 *
 * @num: The long unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printLongHexLower(unsigned long num, int *counter)
{
	char longHexLowerStr[20];
	int n;

	n = sprintf(longHexLowerStr, "%lx", num);
	write(1, longHexLowerStr, n);
	(*counter) += n;
}

/**
 * printShortHexLower - Prints a short unsigned integer in
 * lowercase hexadecimal format.
 *
 * @num: The short unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printShortHexLower(unsigned short num, int *counter)
{
	char shortHexLowerStr[8];
	int n;

	n = sprintf(shortHexLowerStr, "%hx", num);
	write(1, shortHexLowerStr, n);
	(*counter) += n;
}

/**
 * printLongHexUpper - Prints a long unsigned integer in
 * uppercase hexadecimal format.
 *
 * @num: The long unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printLongHexUpper(unsigned long num, int *counter)
{
	char longHexUpperStr[20];
	int n;

	n = sprintf(longHexUpperStr, "%lX", num);
	write(1, longHexUpperStr, n);
	(*counter) += n;
}

/**
 * printShortHexUpper - Prints a short unsigned integer
 * in uppercase hexadecimal format.
 *
 * @num: The short unsigned integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printShortHexUpper(unsigned short num, int *counter)
{
	char shortHexUpperStr[8];
	int n;

	n = sprintf(shortHexUpperStr, "%hX", num);
	write(1, shortHexUpperStr, n);
	(*counter) += n;
}
