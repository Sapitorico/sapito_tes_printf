#include "main.h"

int _printf(const char *format, ...)
{
	int x = 0, z = 0, c = 0;
	va_list list;

	print atr[] = {
	       	{'c', print_char},
		{'s', print_string}
	};
	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (format[x] != '\0')
	{
		for (; format[x] != '%' && format[x]; x++)
		{
			_putchar(format[x]);
			c++;
		}
		if (!format[x])
		{
			return (x);
		}
		for (; atr[z].letter; z++)
		{
			if (format[x + 1] == atr[z].letter)
			{
				c += atr[z].f(list);
			}
		}
		if (atr[z].letter)
		{
			x += 2;
			continue;
		}
		if (!format[x + 1])
		{
			return (-1);
		}
		_putchar(format[x]);
		c++;
		if (format[x + 1] == '%')
			x += 2;
		else
		x++;
	}
	va_end(list);
	return (c);
}
