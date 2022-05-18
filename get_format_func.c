#include "main.h"

char* (*get_func(char i))(va_list)
{
  int iterator = 0;

	typePick selectors[] = {
		{'c', char_print_handler},
		{'s', str_print_handler},
		{'d', int_print_handler},
		{'i', int_print_handler},
		{'b', itob_print_handler},
		{'R', rot13_print_handler},
		{'r', rev_string_print_handler},
		{'o', itoOctal_print_handler},
		{'\0', NULL}
	};

	while (selectors[iterator].conv != '\0')
	{
		if (selectors[iterator].conv == i)
			return (selectors[iterator].func);
		iterator++;
	}
	return (NULL);
}