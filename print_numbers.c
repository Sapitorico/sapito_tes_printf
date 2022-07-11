#include "main.h"
/**
 * print_int - función que imprime numeros enteros
 *
 * Return: retorna al contador inicial
 */
int print_int(va_list arg)
{
        long int num;
	long int i = 1;
	int cont = 0;

        num = va_arg(arg, int);

        if (num == 0)
        {
                _putchar('0');
                return (i);
        }
        if (num < 0)
        {
                _putchar('-');
                cont++;
                num = num *-1;
        }
        for (;i <= num; i *= 10)
                cont++;
        i /= 10;
        for(; i > 0; i /= 10)
        {
                _putchar(((num / i) % 10) + '0');
        }
        return (cont);
}
/**
 * print_decimal - función que imprime numeros decimales
 *
 * Retur: retorna a la función int llamando a esta función
 */
int print_decimal(va_list arg)
{
        return (print_int(arg));
}
