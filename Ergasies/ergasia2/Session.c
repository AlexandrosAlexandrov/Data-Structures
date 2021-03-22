/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/
#include <stdlib.h>
#include "Session.h"

typedef struct TabNode *TabNodePtr;		/* typos deikth se komvo tab*/
typedef struct SiteNode *SiteNodePtr;

struct InfoSession {					/*plhroforiakos komvos*/
	TabNodePtr FirstTab;
	TabNodePtr LastTab;
	TabNodePtr CurrTab;
	TabNodePtr AuxTab;
	char* 	  OpeningAddress;			/*default site address*/
};

struct TabNode {						/*komvos gia tab*/
	TabNodePtr PrevTab, NextTab;
	SiteNodePtr FirstSite;
	SiteNodePtr CurrSite;
};

struct SiteNode{						/*komvos gia sites*/
	SiteNodePtr PrevSite, NextSite;
	TabNodePtr UpTab;					/*deikths ston komvo tab pou anhkei*/
	char *Address;						/*dieuthinsh tou site*/
};


InfoSessionPtr SessionNew(char * OpeningAddress,InfoSessionPtr Session){
	Session = malloc(sizeof(Session));
	Session->CurrTab = malloc(sizeof(Session->AuxTab));
	Session->CurrTab->CurrSite = malloc(sizeof(Session->AuxTab->CurrSite));
	
	Session->FirstTab 	= Session->CurrTab;
	Session->LastTab 	= Session->CurrTab;
	Session->CurrTab 	= Session->CurrTab;
	Session->AuxTab 	= NULL;


	Session->CurrTab->CurrSite  = Session->OpeningAddress;
	Session->CurrTab->FirstSite = Session->CurrTab->CurrSite;
	Session->CurrTab->NextTab 	= NULL;
	Session->CurrTab->PrevTab 	= NULL;

	Session->CurrTab->CurrSite->PrevSite 	= NULL;
	Session->CurrTab->CurrSite->NextSite 	= NULL;
	Session->CurrTab->CurrSite->UpTab 		= Session->CurrTab;
	Session->CurrTab->CurrSite->Address 	= OpeningAddress;

	return Session;
}

void SessionNewTab(InfoSessionPtr Session){
	TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
	
	temptab->PrevTab 				= Session->CurrTab;
	temptab->NextTab 				= NULL;
	temptab->FirstSite 				= Session->OpeningAddress;
	temptab->CurrSite 				= Session->OpeningAddress;
	
	temptab->CurrSite->PrevSite 	= NULL;
	temptab->CurrSite->NextSite 	= NULL;
	temptab->CurrSite->UpTab		= temptab;
	temptab->CurrSite->Address		= Session->OpeningAddress;
	
	Session->LastTab = temptab;
}

char* SessionTabShow(InfoSessionPtr Session){
	printf("%c\n", Session->CurrTab->CurrSite);
	return Session->CurrTab->CurrSite;
}

void SessionTabNext(InfoSessionPtr Session){
	TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
	
	temptab->NextTab = Session->CurrTab->NextTab;
	temptab->PrevTab = Session->CurrTab;
	temptab = Session->CurrTab;
}

void SessionTabPrev(InfoSessionPtr Session){
	TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
	
	temptab->NextTab = Session->CurrTab;
	temptab->PrevTab = Session->CurrTab->NextTab;
	temptab = Session->CurrTab;
}

void TabMoveLeft(InfoSessionPtr Session, int *error){
	if(Session->CurrTab->PrevTab == NULL)
		*error = 1;
	else{
		TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
		
		temptab->NextTab = Session->CurrTab->PrevTab;
		temptab->PrevTab = Session->CurrTab->PrevTab->PrevTab;
		temptab = Session->CurrTab;
	}	
}

void TabMoveRight(InfoSessionPtr Session, int *error){
	if(Session->CurrTab->NextTab == NULL)
		*error = 1;
	else{
		TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
		
		temptab->NextTab = Session->CurrTab->NextTab->NextTab;
		temptab->PrevTab = Session->CurrTab->NextTab;
		temptab = Session->CurrTab;
	}
}

void SessionNewOpeningAddress(char* newsite, InfoSessionPtr Session){
	Session->OpeningAddress = newsite;
}

char* SessionShowOpeningAddress(InfoSessionPtr Session){
	return Session->OpeningAddress;
}

void SessionSiteNext(InfoSessionPtr Session, int *error){
	if(Session->CurrTab->CurrSite->NextSite == NULL)
		*error = 1;
	else{
		SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
		
		tempsite->NextSite = Session->CurrTab->CurrSite->NextSite;
		tempsite->PrevSite = Session->CurrTab->CurrSite;
		tempsite = Session->CurrTab->CurrSite;
	}
}

void SessionSitePrev(InfoSessionPtr Session, int* error){
	if(Session->CurrTab->CurrSite->PrevSite == NULL)
		*error = 1;
	else{
		SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
		
		tempsite->NextSite = Session->CurrTab->CurrSite;
		tempsite->PrevSite = Session->CurrTab->CurrSite->NextSite;
		tempsite = Session->CurrTab->CurrSite;
	}
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->PrevSite;
}

char* SessionSiteShow(InfoSessionPtr Session){
	printf("%c\n", Session->CurrTab->CurrSite);
	return Session->CurrTab->CurrSite;
}

void SessionTabClose(InfoSessionPtr Session){
	while(Session->CurrTab->CurrSite->NextSite != NULL){
		SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
			
		tempsite = Session->CurrTab->CurrSite;
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;
		free(tempsite);
	}
	free(Session->CurrTab->CurrSite);
	
	if(Session->CurrTab->NextTab == NULL){
		free(Session->CurrTab);
		free(Session);
	}
	else{
		TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
		
		temptab = Session->CurrTab;
		Session->CurrTab = Session->CurrTab->NextTab;
		free(temptab);
	}
}

void SessionClose(InfoSessionPtr Session){	
	while(Session->CurrTab->CurrSite->NextSite != NULL){
		SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
		
		tempsite = Session->CurrTab->CurrSite;
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;
		free(tempsite);
	}
	free(Session->CurrTab->CurrSite);
	
	while(Session->CurrTab->NextTab != NULL){
		TabNodePtr temptab = malloc(sizeof(Session->AuxTab));
		
		temptab = Session->CurrTab;
		Session->CurrTab = Session->CurrTab->NextTab;
		free(temptab);
	}
	free(Session->CurrTab);
	
	free(Session);
}

void SessionNewAddress(char* newsite, InfoSessionPtr Session){
	if (Session->CurrTab->CurrSite->NextSite != NULL){
		while(Session->CurrTab->CurrSite->NextSite !=  NULL){
			SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
			
			tempsite = Session->CurrTab->CurrSite->NextSite;
			Session->CurrTab->CurrSite->NextSite = Session->CurrTab->CurrSite->NextSite->NextSite;
			free(tempsite);
		}

	}
	SiteNodePtr tempsite = malloc(sizeof(Session->AuxTab->CurrSite));
	
	Session->CurrTab->CurrSite->NextSite = tempsite; 
	tempsite->PrevSite = Session->CurrTab->CurrSite;
	tempsite->NextSite = NULL;
	tempsite->Address = newsite;
}

void SessionOpenNewTab(InfoSessionPtr Session){
	
}
