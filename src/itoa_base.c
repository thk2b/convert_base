#include <stdlib.h>
#include "convert_base.h"

static char *sym = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *itoa_base(int n, unsigned base)
{
	unsigned un;
	int		pow;
	int		len;
	int		is_neg;
	char	*s;
	char	*t;
	long	tmp;

	is_neg = 0;
	if (n < 0)
	{
		un = (unsigned)n * -1;
		is_neg = 1;
	}
	else
		un = (unsigned)n;
	pow = 1;
	len = 0;
	while ((tmp = pow * base) <= un && tmp % base == 0)
	// HACK: detect overflow
	{
		pow = (int)tmp;
		len++;
	}
	if ((s = (char*)malloc((len + is_neg + 1) * sizeof(char))) == NULL)
		return (NULL);
	t = s;
	if (is_neg)
		*s++ = '-';
	while (pow > 0)
	{
		*s++ = sym[un / pow];
		un %= pow;
		pow /= base;
	}
	*++s = '\0';
	return (t);
}
