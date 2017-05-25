#include <stdio.h>
#include <stdlib.h>

typedef struct cel Celula;

typedef struct{
	char nome[30];
	char cpf[11];

}Cliente;


struct cel {

	Cliente cliente;
	struct cel *prox;

};

int count, tam;

void inserirEncadeada(Celula *l, Celula *c, int posicao){

	Celula *p = l;
	if(p->prox!=NULL){
		for(count=0; count < posicao; count++){
			p = p->prox;
			if(p->prox==NULL)
				break;

		}
	}

	c->prox = p->prox;
	p->prox = c;
}

Celula *retira(Celula *l, int pos){
	
	if(pos>0 && pos <= tam){
		if(pos==1)
			if(l->prox == NULL){
				printf("lista vazia");
					return NULL;
			}else{
				Celula *aux = l->prox;
				l->prox = aux->prox;
				tam--;
				return aux;
			}
		else{
			Celula *atual = l->prox,
			*anterior=l; 
			for(count=1 ; count < pos ; count++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tam--;
		return atual;
		}
			
	}else{
		printf("elemento invalido");
		return NULL;
	}
}

int buscar(Celula *l,int pos ){	
	if(l->prox == NULL){
		printf("lista vazia");
		return 0;
	}
	Celula *atual = l->prox,
	*anterior = l; 
	for(count=1 ; count < tam ; count++){
			if(pos == atual->cliente.cpf){
				
				return count;
			}
			anterior=atual;
			atual=atual->prox;
	}
	return 0;
}
void imprimir(Celula *l){
	if(l->prox == NULL)
		printf("lista vazia");
 
	Celula *tmp;
	tmp = l->prox;
	printf("Lista:");
	int qtd = 1;
	while( tmp != NULL){
		printf("\nCliente %d ", qtd);
		printf("\nNome: %s ", tmp->cliente.nome);
		printf("\nCPF: %d", tmp->cliente.cpf);
		tmp = tmp->prox;
		++qtd;
	}
}

void deletar(Celula *l){
	if(l->prox!=NULL){
		Celula *proxNode, *atual;
		atual = l->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inserirPilha(Celula *pilha, Celula * nova) {
	Celula * p;
	for(p=pilha->prox; p->prox != NULL; p=p->prox){
		nova->prox = p->prox;
		p->prox = nova;
	}
}

void removerPilha(Celula *pilha) {
	Celula * p;

	p = pilha->prox;
	pilha->prox = p->prox;
	free(p);	
}

void deletarPilha(Celula *pilha){
	if(pilha->prox!=NULL){
		Celula *proxNode, *atual;
		atual = pilha->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inserirFila(Celula *fila, Celula * nova) {
	Celula * p;
	for(p=fila->prox; p->prox != NULL; p=p->prox){
		nova->prox = p->prox;
		p->prox = nova;
	}
}

void removerFila(Celula * fila) {

	Celula * p;
	Celula * aux;
	for(p=fila->prox; p->prox != NULL; p=p->prox){
		aux = p;
	}
	aux->prox = p->prox;
	free(p);

}

void deletarFila(Celula *fila){
	if(fila->prox!=NULL){
		Celula *proxNode, *atual;
		atual = fila->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

int main() {


	Celula c, * lista;
	lista = &c;
	lista->prox = NULL;
	
	Celula c1, *pilha;
	pilha = &c1;
	pilha->prox = NULL;

	Celula c2, *fila;
	fila = &c2;
	fila->prox = NULL;
}
