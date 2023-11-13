#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - this is the printf function constructed
 * from scratch
 * @format: this is a specifier that tells the "_printf"
 * function what to do. The formats can be any one of these:
 * "%d": Format as a signed decimal integer.
 * "%u": Format as an unsigned decimal integer.
 * "%f": Format as a floating-point number.
 * "%s": Format as a null-terminated string.
 * "%c": Format as a character.
 * "%x": Format as a hexadecimal number, lowercase.
 * "%X": Format as a hexadecimal number, uppercase.
 * 
 * Description: This function should do what printf does
 * 
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
	int integer;
	unsigned int unsignedInteger;
	float floater;
	char *stringer;
	char character;
	int charactercounter;
	size_t i;
	int n;
	/*
	 * This n variable will hold the length of the converted string
	 * so it can be used in the function "write"
	 * */
	char inttostr[12]; 
	/*
	 * This array assumes that there will be 11 digits
	 * in a number. We can defintley make it more.
	 */
	char uInttostr[12];
	char floattostr[30]; 
	/* 
	 * I looked for lower and uppercase hexadecimal printf initialization
	 * methods but all I got was the "%x" and "%X" that come with
	 * printf. I haven't looked more into it to yet. I WILL COME BACK
	 * TO THIS.
	 */
	va_list args;

	charactercounter = 0;
	va_start (args, format);

	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'd')
			{
				integer = va_arg(args, int);
				n = sprintf(inttostr, "%d", integer);
				write(1, inttostr, n);
				charactercounter += n;
			}
			else if (format[i] == 'u')
			{
				unsignedInteger = va_arg(args, unsigned int);
				n = sprintf(uInttostr, "%u", unsignedInteger);
				write(1, uInttostr, n);
				charactercounter += n;
			}
			else if (format[i] == 'f')
			{
				floater = va_arg(args, double);
				n = sprintf(floattostr, "%f", floater);
				write(1, floattostr, n);
				charactercounter += n;
			}
			else if (format[i] == 's')
			{
				stringer = va_arg(args, char *);
				write(1, stringer, strlen(stringer));
				charactercounter += strlen(stringer);
			}
			else if (format[i] == 'c')
			{
				character = va_arg(args, int);
				write(1, &character, 1);
				charactercounter++;
			}
			else
			{
				write(1, &format[i], 1);
				charactercounter++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			charactercounter++;
		}
	}
	va_end(args);
	return (charactercounter);
}
/*
int main (void)
{
    int count = _printf("%d%s", 78, "chupapimugagno");
    printf("\nNumber of characters printed: %d\n", count);
    return (0);
}
*/

