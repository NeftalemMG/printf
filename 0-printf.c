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
    int i;

    int integer;
    unsigned int unsignedInteger;
    float floater;
    char *stringer;
    char character;

    int n;
    /*
    this n variable will hold the length of the converted string
    so it can be used in the function "write"
    */
    char inttostr[12]; 
            /*
            This array assumes that there will be 11 digits
            in a number. We can defintley make it more.
            */
    char uInttostr[12];
    char floattostr[30]; 

    /* 
    I looked for lower and uppercase hexadecimal printf initialization
    methods but all I got was the "%x" and "%X" that come with
    printf. I haven't looked more into it to yet. I WILL COME BACK
    TO THIS.
    */
    
    va_list args;
    va_start (args, format);

    for (i = 0; i < strlen(format); i++)
    {
        if (format[i] == '%' && format[i + 1] == 'd')
        {
            integer = va_arg(args, int);
            i++;
            n = sprintf(inttostr, "%d", integer);
            write(1, inttostr, n);
        }
        else if (format[i] == '%' && format[i + 1] == 'u')
        {
            unsignedInteger = va_arg(args, unsigned int);
            i++;
            n = sprintf(uInttostr, "%u", unsignedInteger);
            write(1, uInttostr, n);
        }
        else if (format[i] == '%' && format[i + 1] == 'f')
        {
            floater = va_arg(args, double);
            i++; 
            n = sprintf(floattostr, "%f", floater);
            write(1, floattostr, n);
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            stringer = va_arg(args, char *);
            i++;
            write(1, stringer, strlen(stringer));
        }
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
            character = va_arg(args, int);
            i++;
            write(1, &character, 1);
        }
        else
        {
            printf("Input the right format!");
            /**
             * This defintely is not going to be the else
             * case. We will make changes to it.
            */
        }
    }
    va_end(args);
    return (0);
}
/**
int main (void)
{
    _printf("%d%s", 78, "chupapimugagno");
    _printf("%s", "whatishappening");
    _printf("%f", 2.5);
    _printf("%u", 90);

    return (0);
}
*/
