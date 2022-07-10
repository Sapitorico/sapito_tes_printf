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
	printf("Negative:[%d]\n", -762534);
	_printf("Negative:[%d]\n", -32432);
	printf("Negative:[%i]\n", -762534);
	_printf("Negative:[%i]\n", -111100);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	_printf("%b\n", 98);
	return (0);
}

