//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

int 	main(void){
	printf("---My function---\n");
	ft_printf("%-d\n", -0);
	ft_printf("%-d\n", -10);
	ft_printf("%-d\n", -100);
	ft_printf("%-d\n", -1000);
	ft_printf("%-d\n", -10000);
	ft_printf("%-d\n", -100000);
	ft_printf("%-d\n", -1000000);
	ft_printf("%-d\n", -10000000);
	printf("\n---Std function---\n");
	printf("%-d\n", -0);
	printf("%-d\n", -10);
	printf("%-d\n", -100);
	printf("%-d\n", -1000);
	printf("%-d\n", -10000);
	printf("%-d\n", -100000);
	printf("%-d\n", -1000000);
	printf("%-d\n", -10000000);


	return 0;
}
