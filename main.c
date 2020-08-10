//
// Created by alexey on 10.08.2020.
//

#include <stdio.h>
#include "ft_printf.h"

int 	main(void){
	// percentage test:
	//printf("%%", 123);
	//flags test:

	// check '-':
	/*printf("%-d\n", 1);
	printf("%-2d\n", -1);
	printf("%-2d\n", 10);
	printf("%-2d\n", -10);
	printf("%-2c\n", 'h');
	printf("%-2s\n", "test flag: -");
	printf("%-s\n", NULL);*/
	ft_printf("hello%-d", 13);
	return 0;
}