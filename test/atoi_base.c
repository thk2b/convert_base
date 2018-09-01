#include "ctest.h"
#include "convert_base.h"

static int	test1(void)
{
	test_eq_int(atoi_base("1", 10), 1, "1 base 10");
}

int			test_atoi_base(void)
{
	test_start("atoi_base");
	test1();
	test_end();
}

