#include "convert_base.h"

static	int value_of(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	return -1;
}

int		atoi_base(char *s, unsigned base)
{
	int n;
	int v;
	int sign;

	n = 0;
	while (*s <= ' ')
		s++;
	sign = *s == '-' ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	while ((v = value_of(*s++)) >= 0 && v <= (int)base-1)
		n = n * base + v;
	return (n * sign);
}
