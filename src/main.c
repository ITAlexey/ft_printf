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
	//printf("my = %d\n", ft_printf("hello %%%-20d %% %% %-4c\n", 10, 'A'));
	printf("\nmy = %d\n", ft_printf("%d", 0));
	printf("\n---Std function---\n");
	//printf("std = %d\n", printf("hello %%%-20d %% %% %-4c\n", 10, 'A'));
	printf("\nsd = %d\n", printf("%d", 0));
	return 0;
}
