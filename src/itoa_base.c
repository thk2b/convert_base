#include <stdlib.h>
#include "convert_base.h"

static char *sym = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *itoa_base(int n, unsigned base)
{
	int		pow;
	int		len;
	int		is_neg;
	char	*s;
	char	*t;
	int		d;

	pow = 1;
	len = 0;
	is_neg = 0;
	if (n < 0)
	{
		n = n * -1;
		is_neg = 1;
	}
	while ((long)(pow * base) <= n)
	{
		pow = pow * base;
		len++;
	}
	if ((s = (char*)malloc((len + is_neg + 1) * sizeof(char))) == NULL)
		return (NULL);
	t = s;
	if (is_neg)
		*s++ = '-';
	while (pow > 0)
	{
		d = n / pow;
		n -= d * pow;
		pow /= base;
		*s++ = sym[d];
	}
	*++s = '\0';
	return (t);
}
