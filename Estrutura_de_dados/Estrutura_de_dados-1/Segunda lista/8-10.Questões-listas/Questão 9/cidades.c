typedef struct elemento* Lista;

struct elemento{
	struct elemento *ant;
	struct cidade dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

void libera_lista(Lista* lista){
	if(lista != NULL){
		Elem* no;
	
		while((*lista) != NULL){
			no = *lista;
			*lista = (*lista) -> prox ;
			free(no);
		}
		free(lista);
	}
}



int tamanho_lista(Lista* lista);{
	if(lista == NULL) return 0;
	int cont = 0;
	Elem* no = *lista;
	while(no != NULL){
		cont++;
		no = no -> prox;
	}
	return cont;
}

int lista_cheia(Lista* lista){
	return 0;
}

int lista_vazia(LIsta* li){
	if(lista == NULL){
		return 1;
	}
	if(*lista == NULL){
		return 1;
	}
	return 0;
}



int insere_lista_inicio(Lista* lista, struct cidade c1){
	
	if(lista == NULL){
		
		
		Elem no =  (Elem) malloc (sizeof(Eleme));
		return 0;
	}
	
	if(no == NULL){
		
		no -> dados = c1;
		no -> prox = (lista*);
		no -> ant = NULL
		return 0;
	}

	if(lista != NULL)
		(*lista) -> ant = no;
		(*lista) = no;
		return 1;
	
}

int insere_lista_final(Lista* lista, struct cidade c1){
	
	
	if(lista == NULL){
	
	Elem *no = (*Elem) malloc (sizeof(Elem));
	return 0;	
	}
	
	if(no == NULL){
		
	no -> dados = c1;
	no -> prox = NULL;
	return 0;
	}
	
	if ((*lista) == NULL){ //lista vazia, insere inicio
	
	no -> ant = NULL;
	*lista = no;
		
	}
	else{
		
		Elem* aux = *lista;
		while(aux -> prox != NULL){
			
			aux = aux -> prox;
			aux -> prox = no;
			no -> ant = aux;
			
		}
		return 1;
    }
	
}

int insere_lista_ordenada(Lista* lista, struct cidade c1){
	
	if(lista == NULL){
		Elem *no = (*Elem) malloc (sizeof(Elem));
		return 0;
		
	}
	if(no == NULL){
	no -> dados = c1;
	return 0;
	}
	
	if(lista_vazia(lista)){ // insere inicio
	no -> prox == NULL;
	no -> ant == NULL;
	*lista = no;
	return 1; 
	}
	
	else{//procura onde inserir
		Elem *ant, *atual = *lista;
		
	while(atual != NULL && atual -> dados.matricula < al.matricula){
		ant = atual;
		atual = atual -> prox;
	}
	if(atual == *lista){//insere inicio
	no -> ant = NULL;
	(*lista) -> ant = no;
	no -> prox = (*lista);
	*lista = no;
	}
	else{
		no -> prox = ant -> prox;
		no -> ant = ant;
		ant -> prox = no;
		if(atual != NULL){
			atual -> ant = no;
		}
	return 1;
	}	
}
}






/*
NODE* listainversa (NODE* aux)
{
if(aux == NULL) return NULL;{
NODE* p = aux;
NODE* primeiro = NULL;
}

While(p != NULL){
	printf("Dado = %d\n", p -> num);
	primeiro = p;
	p = p -> ant;
}

return primeiro; //retorna o total de itens
}




char compara(cidade* nome,  cidade* popula, ){
	
	
}
*/
