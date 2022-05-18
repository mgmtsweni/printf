#include "main.h"

/* character printing handler */ 
char *char_print_handler(va_list list)
{
	char *s;
	char c;

	c = va_arg(list, int);
	
	if (c == 0)
		c = '\0';

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = c;
	s[1] = '\0';

	return (s);
}

/* string print handler */ 
char *str_print_handler(va_list list)
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

/* integer print handler */ 
char *int_print_handler(va_list list)
{
	int length, div, n, temp;

	n = va_arg(list, int);
	temp = n;
	length = 0;
	div = 1;

	if (n == 0) /* account for 0 having length 1 */
	{
		length++;
		return (_itos(div, length, n));
	}

	while (temp != 0) /* find multiple of ten to divide */
	{
		length += 1;
		if (length > 1)
			div *= 10;
		temp /= 10;
	}

	return (_itos(div, length, n));
}

/* integer to binary conversion and printer handler*/ 
char *itob_print_handler(va_list list)
{
	int j = 0, twos = 1;
	int i, k;
	char *s;

	k = va_arg(list, int);
	i = k;

	/* malloc up to max int in binary */
	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	/* account for negative numbers with '1' at index 0 */
	if (k < 0)
	{
		s[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	/* find biggest power of 2 it's divisible by */
	while (k > 1)
	{
		k /= 2;
		twos *= 2;
	}

	/* divide down and store binary num */
	while (twos > 0)
	{
		s[j++] = (i / twos + '0');
		i %= twos;
		twos /= 2;
	}
	s[j] = '\0';

	return (s);
}

/* rot13 encryption handler method */ 
char *rot13_print_handler(va_list list)
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

/* handler for reverse order printing */
char *rev_string_print_handler(va_list list)
{
        char *rev;
	char *str;
	int i = 0, len, j;

	str = va_arg(list, char *); /* store argument to access only once */
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	rev = malloc(sizeof(char) * (len + 1)); /* malloc new variable */
	if (rev == NULL)
		return (NULL);

	for(j = (len - 1); j >= 0; j--) /* store reverse in new variable */
	{
		rev[i++] = str[j];
	}
	rev[i] = '\0';

	return (rev);
}

/* handler for conversion from int to octal and printing */ 
char *itoOctal_print_handler(va_list list)
{
	int j = 0, eights = 1;
	int i, k;
	char *s;

	k = va_arg(list, int);
	i = k;

	/* malloc up to max int in octal*/
	s = malloc(sizeof(char) * 12);
	if (s == NULL)
		return (NULL);

	if (k < 0)
	{
		s[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	/* find biggest power of 8 it's divisible by */
	while (k > 1)
	{
		k /= 8;
		eights *= 8;
	}

	/* divide down and store octal num */
	while (eights > 0)
	{
		s[j++] = (i / eights + '0');
		i %= eights;
		eights /= 8;
	}
	s[j] = '\0';

	return (s);
}