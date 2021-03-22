/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "Option.h"
#define MAX_OPTIONS 16

void print_options()
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create Session\n");
	printf("2. Open new tab\n");
	printf("3. Show tab\n");
	printf("4. Go to next tab\n");
	printf("5. Go to previous tab\n");
	printf("6. Move tab left\n");
	printf("7. Move tab right\n");
	printf("8. New opening address\n");
	printf("9. Show opening address\n");
	printf("10. Go to next site\n");
	printf("11. Go to previous site\n");
	printf("12. Show current site\n");
	printf("13. Close tab\n");
	printf("14. Close Session\n");
	printf("15. New Address\n");
	printf("Enter your input (0-%d): ", MAX_OPTIONS);
}

int get_option()
{
	char buf[100];
	int option;

	option = -1;
	while (option < 0 || option > MAX_OPTIONS) {
		print_options();
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &option);
	}
	return option;
}
