#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);	
        _printf("Character:[%c]\n", 'S');
        _printf("String:[%s]\n", "I am a string de sapito !");
       _printf("Percent:[%%]\n");
        _printf("%!\n");
        _printf("Negative:[%d]\n", -2343243240);
        _printf("Negative:[%i]\n", -7602342300);
        _printf("Positive:[%d]\n", 7620000000);
        _printf("Negative:[%i]\n", 76200000);
        return (0);
}
