#include "_printf.h"
int (*get_format(const char *format))(va_list arg)
{
        f_types_t funcs_ls[] = {        /*type_format_functions strunct*/
                {'c', print_char},
                {'s', print_string},
		{'i', print_int},
		{'d', print_decimal}
        };
        int i = 0;

        for (; funcs_ls[i].types; i++)
        {
                if (*format == funcs_ls[i].types)
                        return (funcs_ls[i].f);
        }
        return (NULL);
}
int _printf(const char *format, ...)
{
        va_list args;
        int const1 = 0, const2 = 0;
        int (*f)(va_list arg);

        va_start(args, format);         /*initialize arguments list*/
        if (!format)
                return (-1);
        while (format[const1] != '\0')  /*check and recognize the length of format*/
        {
                for (; format[const1] != '%' && format[const1]; const1++)       /*recognize and position in the % indicator*/
                {
                        _putchar(format[const1]);
                        const2++;
                }
                if (!format[const1])
                {
                        return (const2);
                }
                f = get_format(&format[const1 + 1]);
                if (f != NULL)
                {
                        const2 += f(args);
                        const1 += 2;    /*print the following characters*/
                        continue;
                }
                if (!format[const1 + 1])
                {
                        return (-1);
                }
                _putchar(format[const1]);
                const2++;       /*print the string*/
                if (format[const1 + 1] == '%')
                        const1 += 2;
                else
                const1++;
	}
	va_end(args);
	return (const2);        /*Returns the number of characters printed*/
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
	if (!str)
	{
		str = "(null)";
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
int print_int(va_list arg)
{
	int num, cont = 0, i = 1;
	num = va_arg(arg, int);

	if (!num)
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
int print_decimal(va_list arg)
{
	return (print_int(arg));
}
