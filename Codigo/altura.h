#ifndef _ALTURAARVORE_
#define _ALTURAARVORE_

int i = 0;
int *getMaisBaixo(Tree **t, int *maisbaixo, int *aux){
	//printf("%d Aux: %d\n", (*t)->reg.key, *aux);
	if((*t)->dir!= NULL && (*t)->esq != NULL){
		if(*getMaisBaixo(&(*t)->dir, maisbaixo, aux) > *getMaisBaixo(&(*t)->esq, maisbaixo, aux)){
			*getMaisBaixo(&(*t)->dir, maisbaixo, aux);
		}else{
			*getMaisBaixo(&(*t)->esq, maisbaixo, aux);
		}

	}

	if((*t)->dir && (*t)->esq == NULL){
		*maisbaixo = *getMaisBaixo(&(*t)->dir, maisbaixo, aux);
		*aux = (*t)->dir->reg.key;

	}
	if((*t)->esq && (*t)->dir == NULL){
		*maisbaixo = *getMaisBaixo(&(*t)->esq, maisbaixo, aux);
		*aux = (*t)->esq->reg.key;

	}
	return maisbaixo;
}


void getAltura(Tree **t, int *aux){
	if(*aux > (*t)->reg.key){
		getAltura(&(*t)->dir, aux); 
		i++;
		return;
	}
	if(*aux < (*t)->reg.key){
		getAltura(&(*t)->esq, aux);
		i++;
		return;
	}
};

void DescobrirAlturaDaArvore(Tree **t){
	//int altEsq = getAltEsq();
	//int altDir = getAltDir();
	
	int maisbaixo = 0;
	int *maisBaixo = &maisbaixo;

	int auxi = 0;
	int *aux = &auxi;

	getMaisBaixo(t, maisBaixo, aux);
	printf("Aux :%d\n", *aux);
	getAltura(t, aux);

	printf("Altura da arvore é %d\n", i);
}





















#endif