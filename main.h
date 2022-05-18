#ifndef MAIN_H
#define MAIN_H


/* malloc, free */
#include <stdlib.h>

/* write */
#include <unistd.h>

/* va_list */
#include <stdarg.h>

/* utility methods */
char* (*finder(char i))(va_list);
char *_itos(int div, int length, int n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* printf prototypes */
int _printf(const char *format, ...); /* _printf a variadic function */
char *char_print_handler(va_list list);
char *str_print_handler(va_list list);
char *int_print_handler(va_list list);
char *itob_print_handler(va_list list);
char *rot13_print_handler(va_list list);
char *rev_string_print_handler(va_list list);
char *itoOctal_print_handler(va_list list);

/* typedefs structures */
typedef struct typeConvertor
{
  char conv;
  char *(*func)(va_list);
} typePick;

#endif
