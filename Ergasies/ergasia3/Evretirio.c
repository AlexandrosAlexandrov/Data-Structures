#include "Evretirio.h"

#define Simple 1 /* 0 for AVL - any Evr integer for Simple  */
#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;

EvrPtr EvrConstruct(int MaxSize){
	EvrPtr E = malloc(sizeof(EvrNode));
   typos_deikti TreeRoot;
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&TreeRoot);
   	E->DataArray = malloc(MaxSize*sizeof(TStoixeiouEvr));
	E->Index = 0;
	E->TreeRoot = TreeRoot;
#else   
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&TreeRoot);
    E->DataArray = malloc(MaxSize*sizeof(TStoixeiouEvr));
	E->Index = 0;
	E->TreeRoot = TreeRoot;
#endif

return E;
}

int Evr_Insert(EvrPtr E, TStoixeiouEvr Data){
	E->DataArray[E->Index] = Data;
	
	int *error;
	int *ypsilotero;
	
	TStoixeiouDDA insert;
	insert.arrayIndex = E->Index;
	insert.key = Data.Airport_ID;
	
	E->Index++; 
	
#if (Simple)
	Tree_eisagogi(E->TreeRoot, insert, error);
#else 
	AVLTree_eisagogi(E->TreeRoot, insert, ypsilotero, error);
#endif
	return 0;
}

int EvrSearch(EvrPtr E, keyType key, int InOut, int * found){
	
	typos_deikti *deiktis;
	TStoixeiouDDA search;
	search.key = key;
	
#if (Simple)
	Tree_anazitisi(E->TreeRoot, search, deiktis, found);
#else
	AVLTree_anazitisi(E->TreeRoot, search, deiktis, found);
#endif

	if(found)
		return InOut = 1;
	else
		return InOut = 0;
}


int Evr_PrintAll(EvrPtr E, FILE *out, int * counter){
typos_deikti a=E->TreeRoot;
TStoixeiouDDA *periexomeno;
char temparray[7200];


#if (Simple)
    a=Tree_apaidi(a);
#else   
    a=AVLTree_apaidi(a);
#endif
}

int Evr_katastrofi(EvrPtr *E){
	free((*E)->Index);
	free((*E)->DataArray); 			/*Lathos*/
	
#if (Sipmle)
	Tree_katastrofi((*E)->TreeRoot);
#else
	AVLTree_katastrofi((*E)->TreeRoot);
#endif
	free((*E));
	return 0;
}
