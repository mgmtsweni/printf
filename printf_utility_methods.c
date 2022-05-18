#include "main.h"

/* utility method converting an integer into a string */ 
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

/* string copy utility method */ 
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = src[x];
	return (dest);
}

/* string length calculator utility method*/ 
int _strlen(char *s)
{
	int a = 0;

	while (*(s + a))
		a++;

	return (a);
}
