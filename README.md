# C-Printf Proyect
### Description.
The _printf function (which derives its name from "print formatted") prints a message to the screen using a "format string" that includes instructions for mixing multiple strings into the final string to be displayed on the screen.
### Use and formating options
**SINOPSIS**

`printf FORM [ ARGUMENT ]...`

-The following example shows how the value of the counter variable is printed.

`printf("El valor es %d.\n", contador);`

-The symbol “%” denotes the beginning of the format mark. The mark “%d” is replaced by the value of the counter variable and the resulting string is printed. The "\n" symbol represents a line break.
### formating options

| Types | Description |
| ------------ | ------------ |
| %c | Print the corresponding ASCII character  |
| %d, %i | Signed decimal conversion of an integer  |
| %s  |  Cadena de caracteres (terminada en '\0') |
| %% | Imprime el símbolo % |
