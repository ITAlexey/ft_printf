//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

/*static void 	define_char(int a)
{
	char letter = 'A';
	if (a == 0)
	{
		while (letter <= 'Z')
			ft_printf("# %c !", letter++);
	}
	else
	{
		while (letter <= 'Z')
			printf("# %c !", letter++);
	}
}*/

int 	main(void){
	printf("---My function---\n");
	ft_printf("%-10d\n", 0);
	/*ft_printf("%-2d\n", -0);
	ft_printf("%-2d\n", +0);
	ft_printf("%-2d\n", 10);
	ft_printf("%-2d\n", -10);
	printf("\n---Std function---\n");
	printf("%-2d\n", 0);
	printf("%-2d\n", -0);
	printf("%-2d\n", +0);
	printf("%-2d\n", 10);
	printf("%-2d", -10);*/
	return 0;
}
