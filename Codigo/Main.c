#include<stdio.h>
#include<stdlib.h>
#include "binaria.h"
#include "altura.h"


int main(){
	int reg[] = {5,3,7,2,4,6,1};
	Tree *raiz = CriarArvore();
	Tree *aux = CriarArvore();
	Record r;

	int tam = sizeof(reg)/sizeof(reg[0]);


	printf("ELEMENTOS A SEREM ADICIONADOS:");
	for (int i = 0; i<tam;i++)
		printf(" %d ", reg[i]);
	printf("\n");

	for(int i=0; i< tam; i++){
		r.key = reg[i];
		r.value = 1;
		InserirNaArvore(&raiz, r);
	}
	print2D(raiz);
	DescobrirAlturaDaArvore(&raiz);
}
