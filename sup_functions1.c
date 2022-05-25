#include "main.h"
/**
 * rev_string - reverses a string
 * @list: string to reverse
 * Return: reversed string
 */
char *rev_string(va_list list)
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
/**
 * itoOctal - change int to octal
 * @list: int to change
 * Return: string with octal
 */
char *itoOctal(va_list list)
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
/**
 * _itos - makes an int a string
 * @div: multiple of 10
 * @length: length of number
 * @n: number to convert to string
 * Return: string
 **/
char *_itos(int div, int length, int n)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
		return (NULL);

	if (n < 0) /* account for negative sign */
	{
		str[0] = '-';
		i++;
	}
	while (n < 0) /* convert each num to string */
	{
		str[i] = ((n / div) * -1 + '0'); /* *-1 to handle min int */
		n = n % div;
		div /= 10;
		i++;
	}
	while (div >= 1) /* same, this case for positives */
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/**
 * print_d - gets length to put in _itos
 * @list: takes arg
 * Return: integar string
 **/
char *print_d(va_list list)
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
/**
 * itob - change int to binary
 * @list: int to change
 * Return: string with binary
 */
char *itob(va_list list)
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
