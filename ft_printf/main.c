#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define TST "%0*.*s  %% %15c yujk %% %18p %% |%00-0-0-0-18.x|%%%%%%%% %18.15X  %% |%012d| hgjgh %% %-032u  %% |%015.*i|\n", 8, 5, NULL, 'j', NULL, 0, 45, -1, 22554478, -2, INT_MIN
#define TST "%0*.*s  %% %15c yujk %% %18p %% |%00-0-0-0-18.x|%%%%%%%% %18.15X  %% |%012d| hgjgh %% %-032u  %% |%015.*i|\n", 8, 5, NULL, 'j', NULL, 0, 45, -1, 22554478, -2, INT_MIN
#define TST1 "%*.*s %s , %-3.*s '%-2c-%.c'|%.%| %p| %s \n", 6, 2, str, NULL, 1, "ld", 'r', 0, &p, "wow"
#define TST2 "%*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 50000, 1, 300, 22, -55, 1, -60
#define TST3 "%*.*d %*.*s %x %X\n", 1, 50, 5000, 1, 0, "hey", 45, 0
#define TST4 "0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x\n", 7, 5, "ABC", 15, 0, 20, 0x99
#define TST5 "hello fghjk's %%%s%%%s call his %02%%-2%%%%s\n", "friend", "fghjk", "dad"
#define TST6 "%012.*i", 22, 5525251550

int main()
{
	int i;
	int j;
	int l;
	int m;
	int x, y, p;
	char str[] = "hello";

	printf("|%d|\n", ft_printf(TST));
	printf("|%d|\n", printf(TST));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST1));
	printf("|%d|\n", printf(TST1));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST2));
	printf("|%d|\n", printf(TST2));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST3));
	printf("|%d|\n", printf(TST3));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST4));
	printf("|%d|\n", printf(TST4));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	l = ft_printf("\n%%%-15%%.3% %15d\n", 20);
	printf("\nl == %d\n", l);
	m = printf("\n%%%-15%%.3% %15d\n", 20);
	printf("\nm == %d\n", m);

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST5));
	printf("|%d|\n", printf(TST5));

	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("|%d|\n", ft_printf(TST6));
	printf("|%d|\n", printf(TST6));
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
	i = ft_printf("%015.*i\n", -32, INT_MIN);
	printf("\ni == %d\n", i);
	j = printf("%015.*i\n", -32, INT_MIN);
	printf("\nj == %d\n", j);

	return (0);
}
