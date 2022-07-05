#include "prtinf.h"
int _printf(const char *format, ...)
 {
     va_list args;
     unsigned int const1, const2;
     char *t_format;
    
    type_f_t formats [] = {    /*type_functions strunct*/
       {'c', print_char},
       {'s', print_string}
       {'%', print_format}
     };
     
     va_start(args, format);    /*initialize arguments list*/
