#ifndef PRINT_FORMATTED_H
#define PRINT_FORMATTED_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/*PROTOTYPES*/
typedef strut type_f
{
    char types;
    int (*f)(va_list arg);
} type_f_t;

int _putchar(char c);

int _printf(const char *format, ...);

/*PROTOTPYES FUNCTIONS*/

int print_char(va_list arg);
int print_string(va_list arg);
int print_op(va_list arg)

#endif PRINT_FORMATTED_H
