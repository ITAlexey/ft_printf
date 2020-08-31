//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

int 	main(void){
	long double k = 3213222222222222222222222222222222222222222222221.00003;
	//char *p = "hello programmers!";
	//printf("---My function---\n");
	printf("\nmy = %d\n", ft_printf("%Lf", k));
	//printf("\n---Std function---\n");
	//printf("\nsd = %d\n", printf("%.17Lf", k));
	return 0;
}
