#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>


typedef struct data {
	int  Airport_ID;
	char Name[20];
	char City[20];
	char Country[20];
	char IATA[20];
	char ICAO[20];  
	int AirportIn;
	int AirportOut;
} TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source);

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem);

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem);

#endif
