#include "main.h"

int _printf(const char *format, ...)
{
 	int len = 0, total_len = 0, i = 0, j = 0;
	va_list list;
	char *holder, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	holder = create_holder();
	if (holder == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into holder until '%' */
		{
			len = temp_holder(holder, len);
			holder[len++] = format[i++];
			total_len++;
		}
		else /* if %, find function */
		{
			i++;
			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(list);
				free(holder);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = temp_holder(holder, len);
				holder[len++] = format[i];
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = temp_holder(holder, len);
					holder[len++] = '%'; total_len++;
					holder[len++] = format[i]; total_len++;
				}
				else /* return string, copy to holder */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(holder);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = temp_holder(holder, len);
						holder[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = temp_holder(holder, len);
						holder[len++] = str[j];
						total_len++; j++;
					}
					free(str);
				}
			} i++;
		}
	}
	write_holder(holder, len, list);
	return (total_len);
}
