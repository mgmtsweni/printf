#include "main.h"
/**
 * get_func - returns needed function
 * @i: identifier for function
 * Return: Pointer to needed function
 */
char* (*get_func(char i))(va_list)
{
	int k = 0;

	print keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', itob},
		{'R', rot13},
		{'r', rev_string},
		{'o', itoOctal},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
			return (keys[k].func);
		k++;
	}
	return (NULL);
}
/**
 * create_holder - creates holder to hold string until it's ready for print
 * Return: pointer to holder created
 */
char *create_holder(void)
{
	char *holder;

	holder = malloc(sizeof(char) * 1024);
	if (holder == NULL)
		return (NULL);
	return (holder);
}

/**
 * write_holder - prints holder, then frees it and frees va_list
 * @holder: holder holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_holder(char *holder, int len, va_list list)
{
	char *hold;

	hold = realloc(holder, len); /* realloc to correct size */
	write(1, hold, len); /* print */

	free(hold);
	va_end(list);
}
/**
 * temp_holder - if writing over holdere,
 * print everything then revert length back to 0 to write at holder start
 * @holder: holder holding string to print
 * @len: position in holder
 * Return: length position
 */
int temp_holder(char *holder, int len)
{
	if (len > 1020)
	{
		write(1, holder, len);
		len = 0;
	}
	return (len);
}
