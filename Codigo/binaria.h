#ifndef _BINARIA_
#define _BINARIA_



typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree * CriarArvore(){
	return NULL;
}

void InserirNaArvore(Tree **raiz, Record r){
	if(*raiz == NULL){
		*raiz= (Tree *) malloc (sizeof(Tree));
		//Observa conteúdo do ponteiro
		(*raiz)->  esq = NULL;
		(*raiz)-> dir = NULL;
		(*raiz)-> reg = r;
	}else{
		if(r.key > (*raiz)->reg.key){
			InserirNaArvore(&(*raiz)->dir,r);
		}
		if(r.key < (*raiz)->reg.key){
			InserirNaArvore(&(*raiz)->esq,r);
		}
	}
}

void pesquisa(Tree **raiz, Tree **aux, Record r){
	if(*raiz == NULL){
		printf("[ERROR]: Record não encontrado\n");
		return;
	}

	if(r.key > (*raiz)->reg.key){pesquisa(&(*raiz)->dir,aux, r); return ;}
	if(r.key < (*raiz)->reg.key){pesquisa(&(*raiz)->esq,aux, r); return ;}

	*aux = *raiz;
}

void antecessor(Tree **raiz, Tree *aux){
	if((*raiz)->dir  != NULL){
		antecessor(&(*raiz)->dir, aux);
		return;
	}

	aux->reg = (*raiz)->reg;
	aux = *raiz;
	*raiz = (*raiz)->esq;
	free(aux);
}

void remover(Tree **raiz, Record r){
	Tree *aux;

	if(*raiz ==  NULL){
		printf("[ERROR]: Record não encontrado\n");
		return;
	}

	if(r.key > (*raiz)->reg.key){remover(&(*raiz)->dir, r); return;}
	if(r.key < (*raiz)->reg.key){remover(&(*raiz)->esq, r); return;}

	if((*raiz)->dir == NULL){
		aux = *raiz;
		*raiz = (*raiz)->esq;
		free(aux);
		return ;
	}

	if((*raiz)->esq != NULL){
		antecessor(&(*raiz)->esq, *raiz);
		return;
	}

	aux = *raiz;
	*raiz = (*raiz)->dir;
	free(aux);

}

void preOrdem(Tree **raiz){
	printf("%d\n", (*raiz)->reg.key);
	preOrdem(&(*raiz)->esq);
	preOrdem(&(*raiz)->dir);
}

void central(Tree **raiz){
	central(&(*raiz)->esq);
	printf("%d\n", (*raiz)->reg.key);
	central(&(*raiz)->dir);
}

void posOrdem(Tree **raiz){
	posOrdem(&(*raiz)->esq);
	posOrdem(&(*raiz)->dir);
	printf("%d\n", (*raiz)->reg.key);
}
 //Print Arvore
void print2DUtil(Tree *t, int space){ 
    if (t == NULL) 
        return; 

    space += 10; 
  
    print2DUtil(t->dir, space); 

    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", t->reg.key); 

    print2DUtil(t->esq, space); 
} 
  
void print2D(Tree *root){ 
	printf("===============================");
    print2DUtil(root, 0); 
	printf("===============================\n");
} 

#endif