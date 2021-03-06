#include <stdio.h>
#include <stdlib.h>
#include "convert_base.h"

int		usage(void)
{
	printf("Usage: num [[ input_base ] output_base ]\n");
	return (0);
}

int		main(int argc, char **argv)
{
	char *n = 0;
	int in_base = 10;
	int out_base = 10;
	int in;
	char *out;

	if (argc == 1)
		return (usage());
	if (argc > 1)
		n = argv[1];
	if (argc == 3)
		out_base = atoi(argv[2]);
	else if (argc > 3)
	{
		in_base = atoi(argv[2]);
		out_base = atoi(argv[3]);
	}
	if (in_base >= 36 || out_base >= 36)
		return (1);
	in = atoi_base(n, in_base);
	out = itoa_base(in, out_base);
	printf("%s\n", out);

	return (0);
}
