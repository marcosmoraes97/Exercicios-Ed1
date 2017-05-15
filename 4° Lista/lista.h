#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 100

typedef struct { //1° questão
	char nome[30];
	char cpf[11];
}cliente;

typedef struct {
	cliente dados[MAX];
	int qtd;
}Lista;

// lista
Lista* crialista();
int inserir(Lista* lista, cliente cliente, int pos);
cliente remover(Lista* lista, int pos);
int buscar(Lista* lista, cliente cliente);
void deletar(Lista* lista);

//pilha
Lista* criapilha();
int inserirPilha(Lista* lista, cliente cliente);
cliente removerPilha(Lista* lista);
void deletarPilha(Lista* lista);

//fila
Lista* criarfila();
int inserirFila(Lista* lista, cliente cliente);
cliente removerFila(Lista* lista);
void deletarFila(Lista* lista);




