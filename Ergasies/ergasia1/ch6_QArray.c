/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ch6_QArray.h"


void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
	oura->CountIn = 0;
	oura->CountOut = 0;
}

int OuraKeni(TOuras oura)
{
	return ( oura.metritis == 0 );
}

int OuraGemati(TOuras oura) 
{
		return oura.metritis == QSIZE;
}

int OuraProsthesi(TOuras *oura, TSOuras stoixeio)
{
	if (OuraGemati(*oura))
		return 0;
	else
	{
		TSOurasSetValue(&(oura->pinakas[oura->piso]),stoixeio);
		oura->piso = ( oura->piso + 1 )% QSIZE;
		oura->metritis++;
		oura->CountIn++;
	}
	return 1;
}

int OuraApomakrynsh(TOuras *oura, TSOuras *stoixeio)
{
	if (OuraKeni(*oura))
		return 0;
	else
	{
		TSOurasSetValue(stoixeio, oura->pinakas[oura->embros]); 
		oura->embros = ( oura->embros + 1 )% QSIZE;
		oura->metritis--;
		oura->CountOut++;
	}
	return 1;
}

int OuraGetSize(TOuras oura)
{
	return oura.metritis;
}

int GetCountIn(TOuras oura)
{
	return oura.CountIn;
}

int GetCountOut(TOuras oura)
{
	return oura.CountOut;
}
