#include "main.h"

int _printf(const char *format, ...)
{
  /* variable declarations and initialisations */
  int count = 0, index = 0;
  va_list listptr; 
  va_start(listptr, format); /* initialising listptr */

  /* terminate immediately if a null argument is passed to printf */
  if (format == NULL)
    return (-1); 

  while (format[index] != '\0')
  {/* check for % character in the passed arg at current index */
	if (format[index] == '%')
	{/* assume conversion is intended, pass next character to conversion handler */
		index++;
		if (format[index] == '%')
		{
			_putchar(format[i++]);
			count++;
			continue;
		}
		else if (format[index] == '\0')
			continue;
		if (finder(format[index]) == NULL)
		{
			_putchar(format[index - 1]);
			_putchar(format[index++]);
			count += 2;
			continue;
		}
		count += finder(format[index++])(args);
		continue;
	  }
	  else
	    _putchar(format[index]);
	  index++;
	  count++;
  }
  return (count);
}
