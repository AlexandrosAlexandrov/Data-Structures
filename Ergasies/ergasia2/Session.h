/*************************************************
Onoma	: 	Aleksandros Aleksantrwf
AM	 	: 	1115201800270
**************************************************/
#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;		/* tupos deikth ston plhroforiako komvo*/


InfoSessionPtr SessionNew(char *,InfoSessionPtr);
void SessionNewTab(InfoSessionPtr);
char* SessionTabShow(InfoSessionPtr);
void SessionTabNext(InfoSessionPtr);
void SessionTabPrev(InfoSessionPtr);
void TabMoveLeft(InfoSessionPtr, int*);
void TabMoveRight(InfoSessionPtr, int*);
void SessionNewOpeningAddress(char*, InfoSessionPtr);
char* SessionShowOpeningAddress(InfoSessionPtr);
void SessionSiteNext(InfoSessionPtr, int*);
void SessionSitePrev(InfoSessionPtr, int*);
char* SessionSiteShow(InfoSessionPtr);
void SessionTabClose(InfoSessionPtr);
void SessionClose(InfoSessionPtr);
void SessionNewAddress(char *, InfoSessionPtr);
void SessionOpenNewTab(InfoSessionPtr Session);

#endif
