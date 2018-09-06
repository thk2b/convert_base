#include <limits.h>
#include "ctest.h"
#include "convert_base.h"

void		test_itoa_base(void)
{
	test_title("atoi_base");
	
	test_name(1, "base 10");
	test_eq_str(itoa_base(10, 10), "10", "10");
	test_eq_str(itoa_base(123, 10), "123", "123");
	test_eq_str(itoa_base(-10, 10), "-10", "-10");
	test_eq_str(itoa_base(INT_MAX / 2, 10), "1073741823", "INT_MAX / 2");
	test_eq_str(itoa_base(INT_MAX, 10), "2147483647", "INT_MAX");
	test_eq_str(itoa_base(INT_MIN, 10), "-2147483648", "INT_MIN");
	test_eq_str(itoa_base(INT_MIN / 2, 10), "-1073741824", "INT_MIN / 2");

	test_name(1, "base 2");
	test_eq_str(itoa_base(10, 2), "1010", "-10");
	test_eq_str(itoa_base(INT_MAX, 2), "1111111111111111111111111111111", "INT_MAX");

	test_name(1, "base 16");
	test_eq_str(itoa_base(47, 16), "2F", "47");
	test_eq_str(itoa_base(-47, 16), "-2F", "-47");

	test_end();
}

