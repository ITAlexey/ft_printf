//
// Created by alexey on 30.08.2020.
//

#include "ft_printf.h"

char 	*powered_value_of_base_two(int exp)
{
	static const char *pow2tab[65] =
			{
					"1", "2", "4", "8", "16", "32", "64",
					"128", "256", "512", "1024", "2048", "4096", "8192", "16384", "32768",
					"65536", "131072", "262144", "524288", "1048576", "2097152", "4194304",
					"8388608", "16777216", "33554432", "67108864", "134217728", "268435456",
					"536870912", "1073741824", "2147483648", "4294967296", "8589934592",
					"17179869184", "34359738368", "68719476736", "137438953472",
					"274877906944", "549755813888", "1099511627776", "2199023255552",
					"4398046511104", "8796093022208", "17592186044416", "35184372088832",
					"70368744177664", "140737488355328", "281474976710656",
					"562949953421312", "1125899906842624", "2251799813685248",
					"4503599627370496", "9007199254740992", "18014398509481984",
					"36028797018963968", "72057594037927936", "144115188075855872",
					"288230376151711744", "576460752303423488", "1152921504606846976",
					"2305843009213693952", "4611686018427387904", "9223372036854775808",
					"18446744073709551616"
			};
	return ((char*)pow2tab[exp]);
}

char 	*powered_value_of_base_five(int exp)
{
	static const char *pow5tab[28] =
			{
					"1", "5", "25", "125", "625", "3125", "15625",
					"78125", "390625", "1953125", "9756625", "48828125",
					"244140625","1220703125", "6103515625", "30517578125",
					"152587890625", "762939453125", "3814697265625",
					"19073486328125", "95367431640625", "476837158203125",
					"2384185791015625", "11920928955078125", "59604644775390625",
					"298023223876953125", "1490116119384765625", "7450580596923828125"
			};
	return ((char*)pow5tab[exp]);
}


char	*powered_by_ten(char *nbr, int exp)
{
	char 	*tmp;
	char 	*zeros;

	tmp = nbr;
	zeros = ft_strnew(exp);
	ISNULL(zeros);
	ft_memset(zeros, '0', exp);
	nbr = ft_strjoin(nbr, zeros);
	ISNULL(nbr);
	ft_strdel(&tmp);
	ft_strdel(&zeros);
	return (nbr);
}

char 	*do_power(int exp, int max_exp, char*(*pow_raise)(int))
{
	char	*result;
	char 	*powered_nbr;

	result = ft_strdup("1");
	while (exp > max_exp)
	{
		powered_nbr = ft_strdup(pow_raise(max_exp));
		result = multiplication(result, powered_nbr, ft_strlen(result), ft_strlen(powered_nbr));
		exp -= max_exp;
	}
	powered_nbr = ft_strdup(pow_raise(exp));
	result = multiplication(result, powered_nbr, ft_strlen(result), ft_strlen(powered_nbr));
	return (result);
}