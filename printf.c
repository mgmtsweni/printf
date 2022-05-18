#include "main.h"
/**
 * _printf - mini printf version
 * @format: initial string with all identifiers
 * Return: strings with identifiers expanded
 */
int _printf(const char *format, ...)
{
	int len = 0, count = 0, index = 0, j = 0;
	va_list list;
	char *holder, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	holder = create_holder();
	if (holder == NULL)
		return (-1);

	va_start(list, format);

	while (format[index] != '\0')
	{
		if (format[index] != '%') /* copy format into holder until '%' */
		{
			len = temp_holder(holder, len);
			holder[len++] = format[index++];
			count++;
		}
		else /* if %, find function */
		{
			index++;
			if (format[index] == '\0') /* handle single ending % */
			{
				va_end(list);
				free(holder);
				return (-1);
			}
			if (format[index] == '%') /* handle double %'s */
			{
				len = temp_holder(holder, len);
				holder[len++] = format[index];
				count++;
			}
			else
			{
				f = get_func(format[index]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = temp_holder(holder, len);
					holder[len++] = '%'; count++;
					holder[len++] = format[index]; count++;
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
					if (format[index] == 'c' && str[0] == '\0')
					{
						len = temp_holder(holder, len);
						holder[len++] = '\0';
						count++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = temp_holder(holder, len);
						holder[len++] = str[j];
						count++; j++;
					}
					free(str);
				}
			} index++;
		}
	}
	write_holder(holder, len, list);
	return (count);
}
