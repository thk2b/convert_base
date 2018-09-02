#include <limits.h>
#include "ctest.h"
#include "convert_base.h"


void	test_atoi_base(void)
{
	test_start("atoi_base");

	test_eq_int(atoi_base("1", 10), 1, "1 base 10");
	test_eq_int(atoi_base("-1", 10), -1, "-1 base 10");
	test_eq_int(atoi_base("1", 2), 1, "1 base 2");
	test_eq_int(atoi_base("9210", 10), 9210, "9210 base 10");
	test_eq_int(atoi_base("2147483647", 10), INT_MAX, "INT_MIN base 10");
	test_eq_int(atoi_base("-2147483648", 10), INT_MIN, "INT_MIN base 10");

	test_eq_int(atoi_base("1", 2), 1, "3 base 2");
	test_eq_int(atoi_base("1111111111111111111111111111111", 2), INT_MAX, "INT_MAX base 2");
	test_eq_int(atoi_base("-1111111111111111111111111111111", 2), INT_MIN+1, "INT_MIN+1 base 2");
	test_eq_int(atoi_base("10000000000000000000000000000000", 2), INT_MIN, "INT_MIN base 2");
	test_eq_int(atoi_base("1010", 2), 10, "10 base 2");

	test_eq_int(atoi_base("2f", 16), 47, "47 base 16");
	test_eq_int(atoi_base("2F", 16), 47, "47 base 16 uppercase");
	test_eq_int(atoi_base("-2F", 16), -47, "-47 base 16");
	test_eq_int(atoi_base("7FFFFFFF", 16), INT_MAX, "INT_MAX base 16");
	test_eq_int(atoi_base("-7FFFFFFF", 16), INT_MIN+1, "INT_MIN+1 base 16");
	test_eq_int(atoi_base("7DE86A9F", 16), 2112383647, "2112383647 base 16");
	
	test_eq_int(atoi_base("122+4", 10), 122, "invalid symbol");
	test_eq_int(atoi_base("12229a12", 10), 12229, "symbol beyond base");
	test_eq_int(atoi_base("01201", 2), 1, "symbol beyond base");
	test_end();
}
