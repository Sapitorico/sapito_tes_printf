#include "main.h"

int print_char(va_list list)
{
	int c;

	c = va_arg(list, int); 
		_putchar(c);
		return (1);
}


int print_string(va_list list)
{
	char *p;
	int s = 0;

	p = va_arg(list, char *);

	if (p == NULL)
	{
		p = "(null)";
	}
	while (p[s])
	{
		s++;
		_putchar(p[s]);
	}
	return (s);
}

