/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "ch6_QArray.c"
#include "TStoixeiouOuras.c"
#include "TController.h"
#include "TController.c"
#define plithos 3

int main(void)
{	TOuras      	oura;						 /*oura pelatwn-aytokinhtvn */
	TController		controller;					/*elegktis pelatwn-aytokinhtwn */
	float			pithanotita_afiksis;		 /*pi8anothta afikshs*/
	unsigned int	xronos_prosomoiosis; 		/*synolikos xronos prosomoiwshs*/
	unsigned int 	MAXxronos;					/*megistos xronos eksipiertisis pelath*/
	unsigned int 	MINxronos;					/*elaxistos xronos eksipiretisis pelath*/
	unsigned int 	xronosEksipiretisis; 		/*tuxaios xronos eksipiretisis pelath*/
	unsigned int	xronos;						 /*roloi prosomoiwshs*/
	unsigned int	duration;					/*xronos eksipiretisis pelath */
	unsigned int	xronos_anamonis;			 /*synolikos xronos anamonhs*/
	TSOuras			Pelatis;		 			/* o pelaths sthn oyra*/
	float			mesos_xronos;				 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int				i;
	int 			j;
	int 			k;
	time_t			t;

	printf("Dwste units of time prosomoiwshs (0 <=), pi8anothta afikshs in unit of time (0,1) elaxisto kai megisto xrono e3yphrethshs (>=1) in unit of times )\n");
	scanf("%u %f %u %u",&xronos_prosomoiosis,&pithanotita_afiksis,&MINxronos, &MAXxronos);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai metaksu %d kai %d units of time .\n",MINxronos, MAXxronos);

	if (MAXxronos <= MINxronos || MINxronos >= MAXxronos ){
		printf("ERROR! Lathos xronoi, h prosomoiosi tha teleiwsei.\n");
		getchar();
		return 0;
	}


	for (i=0 ; i<plithos; i++){							/*dhmiourgia (plithos)* ourwn kai elegktwn */
		OuraDimiourgia(&oura);
		ControllerDimiourgia(&controller);
	}

	TOuras oyres [plithos];								/*dhmiourgia pinakwn gia apothikefsh ourwn kai elegktwn */
	TController elegktes [plithos];

	for (j=0 ; j<plithos ; j++){						/*apothiksefsh twn ourwn kai elegktwn stous pinakes */
		oyres[j] = oura;
		elegktes[j] = controller;
	}

	duration = 0;
	xronos = 0;
	xronos_anamonis = 0;
	srand(time(&t));
	k = 0;


	while( xronos < xronos_prosomoiosis )
	{																				/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX;
		if ( randomAfixi < pithanotita_afiksis ){
					/*sugkrish metritwn se kathe oyra*/
					PelatisSetXronoEisodou(&Pelatis, xronos);
					duration =  rand()%((MAXxronos - MINxronos +1) + MINxronos);
					PelatisSetXronoEksipiretisis;
					xronosEksipiretisis = Pelatis.XronosEksipiretisis;
					if (!OuraProsthesi(&oyres[k], Pelatis)){
              	    printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
             	     getchar();
              	    return 0;
        		};
    };

    																				    /* Tamias-Elegxos */
			if ( ControllerFree(elegktes[k]) )											/*eley8eros tamias*/
				if (!OuraKeni(oyres[k]))													/*yparxei pelaths*/
				{	OuraApomakrynsh(&oyres[k],&Pelatis);									/*phgainei sto tamio*/
					xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);		/*ypologismos xronoy paramonhs sthn oura*/
																					/*printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
					ControllerNewCustomer(&elegktes[k]);
					ControllerSetXrono(&elegktes[k], xronosEksipiretisis);
					ControllerBusy(&elegktes[k]); 										/* kallyptei to trexon unit time */
				}else ControllerNoWork(&elegktes[k]);
			else ControllerBusy(&elegktes[k]);											/*o tamias apasxolhmenos me pelath */

	xronos++;
																		/*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	}

																					/*telos prosomoiosis */
	for (i=0 ; i<plithos ; i++){

		if (elegktes[i].ArithmoPelaton == 0)
			mesos_xronos = 0.0;
		else
			mesos_xronos = ((float)xronos_anamonis)/((float)elegktes[i].ArithmoPelaton);
	}

	for (i=0 ; i<plithos ; i++){
		if(xronos == xronos_prosomoiosis){
			OuraGetSize(oyres[i]);
			GetCountIn(oyres[i]);
			GetCountOut(oyres[i]);
			ControllerGetInactiveXronos(elegktes[i]);
			ControllerGetArithmosPelatwn(elegktes[i]);
			ControllerGetBusyXronos(elegktes[i]);
		}
	}
			/*prin to  erwthma 5 */

	printf("\nEksyphreth8hkan %d pelates\n",controller.ArithmoPelaton);
	printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);
	printf("O tamias htan adranhs gia %d units of time\n", controller.TimeInactive);
	printf("%d pelates den eksyphreth8hkan\n", oura.metritis);
	printf("synolika mpikan %d pelates\n", oura.CountIn);
	printf("synolika vgikan %d pelates\n", oura.CountOut);

			/*meta to erwthma 5 */
	printf("........................................................................");
	for (i=0 ; i<plithos ; i++){
		printf("---------------------------------------------------------------\n");
		printf("o elegktis %d eksyphretise %d pelates\n", i+1, elegktes[i].ArithmoPelaton);
		printf("o elegkths %d htan apasxolhmenos gia %d units of time\n", i+1, elegktes[i].TimeBusy);
		printf("o elegkths% d htan adranhs gia %d units of time\n", i+1, xronos - elegktes[i].TimeInactive);
		printf("exoun meinei %d autokinhta sthn oura %d\n", oyres[i].metritis, i+1);
		printf("sthn oura %d mpikan %d autokinhta kai vghkan %d autokinhta\n", i+1, oyres[i].CountIn, oyres[i].CountOut);
		printf("sthn oura %d den eksyphretithikan %d autokinhta\n", i+1, oyres[i].metritis);
		printf("---------------------------------------------------------------\n");

	}
    getchar();
	return 0;
}
