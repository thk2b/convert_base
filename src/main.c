#include <stdio.h>
#include "convert_base.h"

int		main(int argc, char **argv)
{
	int n = 0;
	int in_base = 10;
	int out_base = 10;
	int in, out;

	if (argc > 1)
		n = argv[1];
	if (argc == 3)
		out_base = argv[2];
	else if (argc > 3)
	{
		in_base = argv[2]
		out_base = argv[3];
	}
	in = atoi_base(n, in_base);
	out = itoa_base(in, out_base);
	printf("%d\n", out);
}
