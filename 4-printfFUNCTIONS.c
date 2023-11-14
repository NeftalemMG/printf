#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * printLongDecimal - Prints a decimal in the long format.
 *
 * @num: The long decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printLongDecimal(long num, int *counter)
{
	char longDecimalStr[20];
	int n;

	n = sprintf(longDecimalStr, "%ld", num);
	write(1, longDecimalStr, n);
	(*counter) += n;
}

/**
 * printShortDecimal - Prints a decimal in the long format.
 *
 * @num: The short decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printShortDecimal(short num, int *counter)
{
	char shortDecimalStr[8];
	int n;

	n = sprintf(shortDecimalStr, "%hd", num);
	write(1, shortDecimalStr, n);
	(*counter) += n;
}

/**
 * printLongUnsigned - Prints a decimal in the long
 * unsigned format.
 *
 * @num: The long unsigned decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printLongUnsigned(unsigned long num, int *counter)
{
	char longUnsignedStr[20];
	int n;

	n = sprintf(longUnsignedStr, "%lu", num);
	write(1, longUnsignedStr, n);
	(*counter) += n;
}

/**
 * printShortUnsigned - Prints a decimal in the short
 * unsigned format.
 *
 * @num: The short unsigned decimal to print.
 * @counter: Pointer to the count of characters printed.
 */
void printShortUnsigned(unsigned short num, int *counter)
{
	char shortUnsignedStr[8];
	int n;

	n = sprintf(shortUnsignedStr, "%hu", num);
	write(1, shortUnsignedStr, n);
	(*counter) += n;
}

/**
 * printLongOctal - Prints an integer in the long
 * octal format.
 *
 * @num: The long octal integer to print.
 * @counter: Pointer to the count of characters printed.
 */
void printLongOctal(unsigned long num, int *counter)
{
	char longOctalStr[20];
	int n;

	n = sprintf(longOctalStr, "%lo", num);
	write(1, longOctalStr, n);
	(*counter) += n;
}
