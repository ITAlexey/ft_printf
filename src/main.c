//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

int 	main(void){
	double k = 3.3;
	//char *p = "hello programmers!";
	printf("---My function---\n");
	printf("\nmy = %d\n", ft_printf("%f", k));
	printf("\n---Std function---\n");
	printf("\nsd = %d\n", printf("%.20f", k));
	return 0;
}
