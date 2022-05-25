#include "main.h"
/**
 * _strlen - prints length string in integer
 * @s: string passed to function
 * Return: a
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a])
		a += 1;
	return (a);
}
/**
 * print_s - takes string and return string
 * @list: string
 * Return: string
 */
char *print_s(va_list list)
{
	char *s;
	char *p;
	int len;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	len = _strlen(s);

	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, s));
}
/**
 * _strcpy - Copies information from each element
 * @dest: destination file
 * @src: source file
 * Return: array
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}
/**
 * rot13 - encrypts string with rot13
 * @list: string to change
 * Return: modified string
 */
char *rot13(va_list list)
{
	int i = 0;
	char *str;
	char *nstr;

	/* store va_arg to only access argument once */
	str = va_arg(list, char *);

	/* malloc new variable to assign over new rot13 characters */
	nstr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (nstr == NULL)
		return (NULL);

	/* iterate str and assign rot13 char to nstr */
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			nstr[i] = str[i] + 13;
		}
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
		{
			nstr[i] = str[i] - 13;
		}
		else
			(nstr[i] = str[i]);
		i++;
	}
	nstr[i] = '\0';

	return (nstr);
}
