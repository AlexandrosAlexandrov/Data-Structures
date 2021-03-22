/************************************************************************
Programma pelaths	: AirportManagement.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TSEvr.h"
#include "TSDDA.h"
#include "Evretirio.h"



int main(int argc, char *argv[]){
 	EvrPtr E;
 	char c;
	keyType key;
	TStoixeiouEvr Airp;
	
	E=EvrConstruct(7200);
  
  FILE *fp;
  fp = fopen("airportsWinRandom.txt", "r");
  if(fp == NULL){
  	printf("Can't open file!\n");
  	getchar();
  	return 0;
  }
  
  	while (c != 'EOF'){
		c = getc(fp);
		if (c == 'EOF')
			break;
		printf("%c",c);
	}
	fclose(fp);
  
  getchar();	
  return 0;
}

