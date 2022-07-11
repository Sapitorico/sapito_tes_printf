#include "main.h"
int _convert(unsigned int num, int base)
{
	static char repre[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = repre[num%base];
		num /= base;
	}while (num != 0);
	return (0);
}
