#include "_printf.h"

int _printf(const char *format, ...)
{
	 va_list args;
	 int const1 = 0, const2;
	 int str;

	f_types_t funcs_ls[] = {	/*type_format_functions strunct*/
		{'c', print_char},
		{'s', print_string},
		{'%', print_indic}
	 };

	 va_start(args, format);	/*initialize arguments list*/

	while (format && format[const1])	/*check and recognize the length of format*/
	{
		while (format[const1] == '%')	/*recognize and position in the % indicator*/
		{
			_putchar(format[const1]);
				const1++;
		}
		const2 = 0;
		while (funcs_ls[const2 + 1].types)	/*recognize and position the next character*/
		{
			if (format[const1] == funcs_ls[const2 + 1].types)	/*compare the string character by character*/
			{
				str = funcs_ls[const2].f(args);		/*print the format*/
				_putchar(str);
			}
			const2 += 2;	/*print the following characters*/
		}
		const1++;	/*print the string*/
	}
	return (const1);	/*Returns the number of characters printed*/

	 va_end(args);
}

  /*format functions*/
int print_char(va_list arg)
{
	char character;

	character = va_arg(arg, int);
	_putchar(character);
	return (0);
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
	return (i);
}
/*indicator function*/
int print_indic(va_list arg)
{
	char in;

	in = va_arg(arg, int);
		_putchar(in);
	return (in);
}
