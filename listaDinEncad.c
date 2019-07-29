


struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
	
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

void libera_lista (Lista* li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free (li);
	}
}

int tamanho_lista (Lista* li){
	if (li == NULL)return 0;
	int cont = 0;
	Elem* no = *li;
	while (no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
	
}

int lista_vazia(Lista* li){
	if (li == NULL)
		printf("A lista Encontra se Vazia::")
		return 1;
	if(*li == NULL)
			return 1;
		return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
	if(li == NULL) return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if (no == NULL) return 0;
	no->dados = al;
	no->prox = (*li);
	*li = no;
	return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
	if(li == NULL) return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if (no == NULL) return 0;
	no->dados = al;
	no->prox = NULL;
	if((*li) == NULL){
		*li = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;
}

int remove_lista_inicio(Lista* li){
	if(li == NULL) return 0;
	if ((*li) == NULL) return 0;
	
	Elem *no = *li;
	*li = no->prox;
	free(no);
	
	return 1;
}

int remove_lista_final(Lista* li){
	if(li == NULL) return 0; //lista vazia?
	if ((*li) == NULL) return 0;
	Elem *ant, *no = *li;
	while(no->prox != NULL){// faz a comparação se o no é o ultimo elemento da lista...
		ant = no;
		no = no->prox;
	}
	if(no == (*li)) //remove o primeiro
		*li = no->prox;
	else
		ant->prox = no->prox 
	free(no);
	return 1;
		
		
}

int remove_lista(Lista* li, int mat){
	if(li == NULL) return 0; //lista vazia?
	Elem *ant, *no = *li;
	while(no != NULL && no->dados.matricula != mat){// faz a comparação se o ultimo, o do meio ou o ultimo elemento da lista será removido...
		ant = no;
		no = no->prox;
	}
	if(no == NULL) return 0; //Não encontrado...
	
	if(no == *li)//remove o primeiro elemento...
		*li = no->prox
		
	else
		ant->prox = no->prox 
	free(no);
	return 1;
		
		
}

