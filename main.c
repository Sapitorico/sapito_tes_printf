#include <limits.h>
#include <stdio.h>
#include "_printf.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

    _printf("Character:[%c]\n", 'S');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string de sapito ! ");
    printf("String:[%s]\n", "I am a string !");
    return (0);
}
