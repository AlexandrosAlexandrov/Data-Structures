/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "Session.h"
#include "Option.h"

int main(){
	InfoSessionPtr 	MySession1=NULL, MySession2=NULL;
	int 	option;
	char 	*OpeningAddress;
	char 	*newsite;
	int 	*error;
	
	OpeningAddress = "a";

	do{		
		option = get_option();
		switch (option){
			case 1:
				SessionNew(OpeningAddress, MySession1);		
				printf("Session Created!\n");
				break;
			case 2:
				SessionNewTab(MySession1);
				printf("Tab Created!\n");
				break;
			case 3:
				SessionTabShow(MySession1);
				break;
			case 4:
				SessionTabNext(MySession1);
				break;
			case 5:
				SessionTabPrev(MySession1);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				SessionNewOpeningAddress(newsite, MySession1);
				break;
			case 9:
				SessionShowOpeningAddress(MySession1);
				break;
			case 10:
				SessionSiteNext(MySession1, error);
				if(error)
					printf("No next site.\n");
				else
					printf("Successfull move.\n");
				break;
			case 11:
				SessionSitePrev(MySession1, error);
				if(error)
					printf("No previous site.\n");
				else
					printf("Successfull move.\n");
				break;
			case 12:
				SessionSiteShow(MySession1);
				break;
			case 13:
				SessionTabClose(MySession1);
				break;
			case 14:
				SessionClose(MySession1);
				printf("Session Closed!\n");
				break;
			case 15:
				SessionNewAddress(newsite, MySession1);
				break;
			case 16:
				break;
			case 0:
				printf("\n");
				printf("Programm will now terminate\n");
				getchar();
				return 0;
		}
	} while (option);
	return 0;
}
