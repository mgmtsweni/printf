#include "main.h"

int _printf(const char *format, ...)
{
  /* variable declarations and initialisations */
  int index = 0;
  va_list listptr; 
  va_start(listptr, format); /* initialising listptr */

  /* terminate immediately if a null argument is passed to printf */
  if (format == NULL)
    return (-1); 

  while (format[index] != '\0')
  {
    /* check for % character in the passed arg at current index */
    if (format[index] == '%')
    {
      /* assume conversion is intended, pass next character to conversion handler */

    }
  }
}