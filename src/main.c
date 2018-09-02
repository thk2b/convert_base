#include <stdio.h>
#include <stdlib.h>
#include "convert_base.h"

int		main(int argc, char **argv)
{
	char *n = 0;
	int in_base = 10;
	int out_base = 10;
	int in;
	char *out;

	if (argc > 1)
		n = argv[1];
	if (argc == 3)
		out_base = atoi(argv[2]);
	else if (argc > 3)
	{
		in_base = atoi(argv[2]);
		out_base = atoi(argv[3]);
	}
	if (in >= 36 || out >= 36)
		return (1);
	in = atoi_base(n, in_base);
	out = itoa_base(in, out_base);
	printf("%s\n", out);

	return (0);
}
