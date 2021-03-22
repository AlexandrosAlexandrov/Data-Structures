/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/

#include <stdio.h>
#include "TStoixeiouOuras.h"

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras data)
{   
	*stoixeioPtr = data;  
}

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TSOuras stoixeio)
{
	return stoixeio.XronosEisodou;
}

void PelatisSetXronoEksipiretisis (TSOuras *stoixeioPtr, int duration)
{
	stoixeioPtr->XronosEksipiretisis=duration;
}

int PelatisGetXronoEksipiretisis (TSOuras stoixeio)
{
	return stoixeio.XronosEksipiretisis;
}
