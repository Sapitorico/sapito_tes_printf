#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        _printf("Character:[%c]\n", 'S');
        printf("Character:[%c]\n", 'H');
        _printf("String:[%s]\n", "I am a string de sapito !");
        printf("String:[%s]\n", "I am a string de pirntf !");
        _printf("Percent:[%%]\n");
        printf("Percent:[%%]\n");
        _printf("%!\n");
        printf("%k\n");
	printf("Negative:[%d]\n", -7625340000000000000000000000);
	_printf("Negative:[%d]\n", -76253400000000000000000000);
	printf("Negative:[%i]\n", -7625340000000000000000000000);
	_printf("Negative:[%i]\n", -7625340000000000000000000000);
	printf("Positive:[%d]\n", 7625340000000000000000000000);
	_printf("Positive:[%d]\n", 7625340000000000000000000000);
	printf("Negative:[%i]\n", 7625340000000000000000000000);
	_printf("Negative:[%i]\n", 7625340000000000000000000000);
	return (0);
}
