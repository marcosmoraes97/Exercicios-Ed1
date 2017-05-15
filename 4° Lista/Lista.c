#include "lista.h"

Lista lista;
int i, j;

// lista 2° questao

Lista* crialista(){  //criar lista vazia
	Lista *lista;
	lista = (Lista*) malloc(sizeof(Lista));
	lista->qtd = 0;
	return lista;
}
int inserir(Lista* lista, cliente cliente, int pos){ // inserir cliente na lista
	
	if(lista == NULL){
		return -1;
	}
	if(lista->qtd == MAX){
		return 0;
	}
	if(pos > lista->qtd){
		lista->dados[lista->qtd] = cliente;
		lista->qtd++;
		return 1;
	}
	
	for(i=0; i<lista->qtd; i++){
		if(i == pos){
			for(j=lista->qtd; j>= pos; j--)
				lista->dados[j+1] = lista->dados[j];
			
		}
	}

	lista->dados[pos] = cliente;
	lista->qtd++;
	return 1;
}

cliente remover(Lista* lista, int pos){ //remover cliente da lista
	cliente c1; //cliente que vai ser removido
	if(pos <= lista->qtd && pos > 0){
		strcpy(c1.nome, lista->dados[(pos - 1)].nome);
		strcpy(c1.cpf, lista->dados[(pos - 1)].cpf);
		for(i=(pos - 1); i<lista->qtd; i++){
			lista->dados[i] = lista->dados[i+1];
		}
		lista->qtd--;
		return c1;
	}else{
		printf("posiçao nao existe");
	}
	
	return c1;
}

int buscar(Lista* lista, cliente cliente){ // buscar cliente na lista e retonar indice
	if(lista == NULL)
		return -1;
	
	for(i=0; i<lista->qtd; i++){
		if((strcmp(cliente.nome, lista->dados[i].nome) == 0) && (strcmp(cliente.cpf, lista->dados[i].cpf) == 0))
						return (i + 1);
		
	}
	return 0;
}

void deletar(Lista* lista){ // deletar lista
	lista->qtd = 0;
}

// pilha 3° questão

Lista* criapilha(){ // criar pilha vazia
	Lista *pilha;
	pilha = (Lista*) malloc(sizeof(pilha));
	pilha->qtd = 0;
	return pilha;
}

int inserirPilha(Lista* pilha, cliente cliente){ //inserir pilha
	if(pilha == NULL)
		return -1;
	if(pilha->qtd == MAX)
		return 0;
	pilha->dados[pilha->qtd] = cliente;
	pilha->qtd++;
	return 1;
}

cliente removerPilha(Lista* pilha){ //remover pilha
	cliente c1;
	if(pilha->qtd > 0){
		strcpy(c1.nome, pilha->dados[(pilha->qtd - 1)].nome);
		strcpy(c1.cpf, pilha->dados[(pilha->qtd - 1)].cpf);
		pilha->qtd--;
		return c1;
	}else{
		printf("pilha vazia");
	}
	return c1;
}

void deletarPilha(Lista* pilha){
	pilha->qtd = 0;
}

//fila 4° questão

Lista* criarfila(){
	Lista *fila;
	fila = (Lista*) malloc(sizeof(fila));
	fila->qtd = 0;
	return fila;
}

int inserirFila(Lista* fila, cliente cliente){
	if(fila == NULL)
		return -1;
	if(fila->qtd == MAX)
		return 0;
	fila->dados[fila->qtd] = cliente;
	fila->qtd++;
	return 1;
}

cliente removerFila(Lista* fila){ 
	cliente c1;
	if(fila->qtd > 0){
		strcpy(c1.nome, fila->dados[0].nome);
		strcpy(c1.cpf, fila->dados[0].cpf);
		for(i=0; i<fila->qtd; i++)
			fila->dados[i] = fila->dados[i+1];
		fila->qtd--;
		return c1;
	}else{
		printf("fila vazia");
	}
	return c1;
}

void deletarFila(Lista* fila){
	fila->qtd = 0;
}
