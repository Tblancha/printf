#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("|%10d|\n", 123);
	printf("|%10d|\n", 123);
	return (0);
}