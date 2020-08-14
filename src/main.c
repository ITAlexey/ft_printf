//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

int 	main(void){
	printf("---My function---\n");
	ft_printf("%d\n", -10);
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 10);
	ft_printf("%before d\n", -10);
	ft_printf("%d after\n", -10);
	ft_printf("before and %d after\n", -10);
	ft_printf("%d %d %d %d\n", 1, 10000, 3214, -5555);
	/*ft_printf("%-d\n", 10);
	ft_printf("%-d\n", 0);
	ft_printf("%-d\n", -10);*/
/*
	printf("\n---Std function---\n");
	printf("%-d", 10);
	printf("%-d\n", 0);
	printf("%-d\n", -10);*/
	return 0;
}
