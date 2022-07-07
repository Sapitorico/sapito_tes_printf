#include "_printf.h"

int (*get_op_format(const char *str))(va_list arg)
{
	f_types_t funcs_ls[] = {	/*type_format_functions strunct*/
		{'c', print_char},
		{'s', print_string}
	};
	int i = 0;

	while (funcs_ls[i].types)
	{
		if (*str == funcs_ls[i].types)
			return (funcs_ls[i].f);
		i++;
	}
	return (NULL);
}

int _printf(const char *format, ...)
{
	 va_list args;
	 int const1 = 0, const2 = 0;
	 int (*f)(va_list arg);

	 va_start(args, format);	 /*initialize arguments list*/

	while (format[const1])	/*check and recognize the length of format*/
	{
		for (; format[const1] != '%' && format[const1]; const1++)	/*recognize and position in the % indicator*/
		{
			_putchar(format[const1]);
			const2++;
		}
		if (!format[const1])
			return(const2);

		f = get_op_format(&format[const1 + 1]);
		if (f != NULL)
		{
			const2 += f(args);
			const1 += 2;	/*print the following characters*/
			continue;
		}
		if (!format[const1 + 1])
				return(-1);
		_putchar(format[const1]);
		const2++;	/*print the string*/
		if(format[const1 + 1] == '%')
			const1 += 2;
		else
		const1++;
	}
	va_end(args);
	return (const1);	/*Returns the number of characters printed*/
}

  /*format functions*/
int print_char(va_list arg)
{
	char character;

	character = va_arg(arg, int);
	_putchar(character);
	return (1);
}

int print_string(va_list arg)
{
	char *str;
	int i = 0;

	str = va_arg(arg, char *);
	while (str[i])
	{
		i++;
		_putchar(str[i]);
	}
	return (1);
}
