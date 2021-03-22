/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/

#ifndef __TController__
#define __TController__

typedef struct {
	int TimeBusy;			/*time controller was busy*/	
	int TimeInactive;		/*time controller was inactive*/
	int ArithmoPelaton;		/*number of clients*/
	int enapomenonXronos;	/*time left for controller to assist a client*/
} TController;

void ControllerDimiourgia(TController *Controller); 

void ControllerNewCustomer(TController *Controller);

void ControllerSetXrono(TController *Controller, int xronosEksipiretisis); 

void ControllerNoWork(TController *Controller);

void ControllerBusy(TController *Controller); 

int ControllerFree(TController Controller);

int ControllerGetArithmosPelatwn(TController Controller);

int ControllerGetEnapomenonXronos(TController Controller);

int ControllerGetInactiveXronos(TController Controller);

int ControllerGetBusyXronos(TController Controller);

#endif
