#include "main.h"
/**
 * print_string - función que imprime una string de caracteres
 *
 * Return: posición inicial
 */
int print_string(va_list arg)
{
        char *str;
        int i = 0;

        str = va_arg(arg, char *);
        if (!str)
        {
                str = "(null)";
        }
        while (str[i])
        {
                _putchar(str[i]);
                i++;
        }
        return (i);
}
