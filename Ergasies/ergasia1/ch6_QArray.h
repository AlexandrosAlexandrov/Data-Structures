/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/

#ifndef __CH2_QARRAY__
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"


#define QSIZE 1000

typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	int CountIn;		/* counter of cars that got in */
	int CountOut;	/* counter of cars that got out */
	TSOuras pinakas[QSIZE];	/* array of queue elements */
} TOuras;	   /* New Name of Type Queue */

void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);

int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);

int OuraGetSize	(TOuras oura);

int GetCountIn	(TOuras oura);

int GetCountOut	(TOuras oura);

#endif
