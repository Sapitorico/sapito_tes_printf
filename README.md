# C-Printf Proyect
First Holberton School group project carried out by Sapitorico and Marcelo Casaña.
This project is based on recreating the printf function to print format lines
### _printf description:
The _printf function (which derives its name from "print formatted") prints a message to the screen using a "format string" that includes instructions for mixing multiple strings into the final string to be displayed on the screen.
### Use and formating options
**SYNTAX**

        _printf FORM [ ARGUMENT ]...

-The following example shows how the value of the counter variable is printed.

 ```c
   _printf("The value is %d.\n", contador);
```

-The symbol “%” denotes the beginning of the format mark. The mark “%d” is replaced by the value of the counter variable and the resulting string is printed. The "\n" symbol represents a line break.
### formating options

| Types | Description | Function prototype
| ------------ | ------------ | ------------ |
| %c | Print the corresponding ASCII character  | `int print_char(va_list arg);` |
| %d, %i | Signed decimal conversion of an integer  | `int print_decimal(va_list arg);` `int print_int(va_list arg);` |
| %s  |  Character string (terminated in '\0') | `int print_string(va_list arg);` |
| %u | Conversión decimal sin signo de un entero | `int print_unsig_deci(va_list arg);` |
| %r | prints the reversed string | `int print_strev(va_list arg);` |
| %% | Prints the % symbol |

## Examples used
```c
        int len;
        int len2;
        unsigned int ui;

        len = _printf("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");
        len = _printf("Percent:[%%]\n");
        len2 = printf("Percent:[%%]\n");
        _printf("Len:[%d]\n", len);
		printf("Len:[%d]\n", len2);
        _printf("Character:[%c]\n", 'S');
		_printf("Percent:[%%]\n");
		_printf("String:[%s]\n", "I am a string de sapito !");
		_printf("%!\n");
        _printf("Negative:[%d]\n", -2343243240);
        _printf("Negative:[%i]\n", -7602342300);
        _printf("Positive:[%d]\n", 7620000000);
        _printf("Negative:[%i]\n", 76200000);
        _printf("Unknown:[%r]\n", "hola");
        ui = (unsigned int)INT_MAX + 1024;
        _printf("Unsigned:[%u]\n", ui);
        return (0);
```

------------
# FILES:
# main.h
Soure file that is included in each header file in the correct order, includes libreries, structure and prototypes.

#### libraries
    #include <stdio.h> es un archivo de cabecera que tiene la información necesaria para incluir las funciones relacionadas con la entrada/salida en nuestro programa.
    #include <stdarg.h> debe contener un conjunto de macros que permite escribir funciones portátiles que aceptan listas de argumentos variables - va_list se definirá para las variables utilizadas para recorrer la lista - va_start () se invoca para inicializar ap al comienzo de la lista antes de cualquier llamada a va_arg ().
    #include <stdlib.h>  Es el archivo de cabecera de la biblioteca estándar de propósito general del lenguaje de programación C. Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.
    #include <string.h> El encabezado string.h define un tipo de variable, una macro y varias funciones para manipular matrices(array) de caracteres.
    #include <unistd.h>
    #include <limits.h> El encabezado limits.h determina varias propiedades de los distintos tipos de variables. Las macros definidas en este encabezado limitan los valores de varios tipos de variables como char, int y long.
    

#### prototypes

    
    int _putchar(char c);
    
    int _printf(const char *format, ...);
    
    /*PROTOTPEYS FUNCTIONS*/
    int (*get_formatted_funct(const char *format))(va_list arg);
    
    int print_char(va_list arg);
    int print_string(va_list arg);
    int print_int(va_list arg);
    int print_decimal(va_list arg);
    int print_unsig_deci(va_list arg);
    int print_strev(va_list arg);
    
    int str_len(const char *str);

#### function structure

    typedef struct f_types
        {
                char types;
                int (*f)(va_list arg);
        } f_types_t;


##_printf.c




    int _printf(const char *format, ...)                /**prototype function _printf**/
    {
            va_list args;
            int const1 = 0, const2 = 0;
            int (*f)(va_list arg);
			
			va_start(args, format);         /**initialize arguments list**/
            if (!format)                                                        /**check resiviod parameter**/
                    return (-1);
            while (format[const1] != '\0')      /*check and recognize the length of format*/
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
                    f = get_formatted_funct(&format[const1 + 1]);
                    if (f != NULL)
                    {
                            const2 += f(args);
                            const1 += 2;                /*print the following characters*/
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
            return (const2);              /*Returns the number of characters printed*/
    }

##FLOWCHART

#### get_formatted_funct.c

**prototype**

`int (*get_formatted_funct(const char *format))(va_list arg);`

####functions structure:

```c
 f_types_t funcs_ls[] = {
                {'c', print_char},
                {'s', print_string},
                {'i', print_int},
                {'d', print_decimal},
                {'u', print_unsig_deci},
                {'r', print_strev}
        };
```
**description:**This function is responsible for finding a match with the parameter received in the structure (funcs_ls), calls the function corresponding to that format, returns a pointer to that specifier function and the number of characters that are stored in the count variable
`if (*format == funcs_ls[i].types)
                        return (funcs_ls[i].f);`
-Compare a format structure with the received argument pattern and return the corresponding function

#### print_characters.c

|  prototype | type  |  description |
| ------------ | ------------ | ------------ |
| `int print_char(va_list arg)`  | %c  | function in charge print characters  |

#### print_numbers.c

|  prototype | type  | description |
| ------------ | ------------ | ------------ |
| `int print_int(va_list arg);` | %i  | function that prints integers  |
| `int print_decimal(va_list arg);`  |  %d | function that prints decimal numbers  |
| `int print_unsig_deci(va_list arg);` | %u | function that prints unsigned integers |

### print_string.c

|  prototype | type  | description |
| ------------ | ------------ | ------------ |
| `int print_string(va_list arg);` | %s | function that prints a string |
| `int str_len(const char *str);` | function that determines the length of a string |
| `int print_strev(va_list arg);` | %S | function that prints strings in reverse |
