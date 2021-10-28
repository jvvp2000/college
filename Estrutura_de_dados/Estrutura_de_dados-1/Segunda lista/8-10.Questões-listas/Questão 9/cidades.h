scruct cidade{
	char nome[30][21];
	float popula[21][21];
};

Lista* cria_lista();

Lista* cria_lista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL){
		*lista = NULL;
	}
	return lista;
}

void libera_lista(Lista* lista);

int tamanho_lista(Lista* lista);

int lista_cheia(Lista* lista);

int lista_vazia(Lista* lista);

int insere_lista_inicio(Lista* lista, struct cidade c1);

int insere_lista_final(Lista* lista, struct cidade c1);

int insere_lista_ordenada(Lista* lista, struct cidade c1);

