//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

static void 	define_char(int a)
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
}

int 	main(void){
	char *s0 = "hello World!";
	char s[] = "hello C language!";
	printf("---My function---\n");
	ft_printf("%s\n", s0);
	ft_printf("%s\n", s);
	printf("\n---Std function---\n");
	printf("%s\n", s0);
	printf("%s\n", s);
	return 0;
}
