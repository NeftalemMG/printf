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
void printReversedString(char *str, int *counter);
void rot13(char *c);
void printRot13String(char *str, int *counter);
void printLongDecimal(long num, int *counter);
void printShortDecimal(short num, int *counter);
void printLongUnsigned(unsigned long num, int *counter);
void printShortUnsigned(unsigned short num, int *counter);
void printLongOctal(unsigned long num, int *counter);
void printShortOctal(unsigned short num, int *counter);
void printLongHexLower(unsigned long num, int *counter);
void printShortHexLower(unsigned short num, int *counter);
void printLongHexUpper(unsigned long num, int *counter);
void printShortHexUpper(unsigned short num, int *counter);

#endif /* MAIN_H */
