#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void printCharacter(char c, int *counter);
void printString(char *str, int *counter);
void printSString(char *str, int *counter);
void printPercent(int *counter);
void printDecimal(int num, int *counter);
void printBinary(unsigned int num, int *counter);
void printPointer(void *ptr, int *counter);
void printUnsignedDecimal(unsigned int num, int *counter);
void printOctal(unsigned int num, int *counter);
void printHexLower(unsigned int num, int *counter);
void printHexUpper(unsigned int num, int *counter);

#endif /* MAIN_H */
