#include "Pilha.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>


struct elemento 
{
	struct livro dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha()
{

	Pilha*pi = (Pilha*) malloc(sizeof(Pilha));
	if (pi != NULL)
	*pi = NULL;
	return pi;

};
//
void libera_Pilha(Pilha* pi)
{
	if(pi!=NULL)
	{
		Elem* no;
		while((*pi)!= NULL)
		{
			no = *pi;
			*pi = (*pi)->prox;
			free(no);
		}
		free(pi);
	}
};
//
int tamanho_Pilha(Pilha* pi)
{
	if (pi == NULL) 
	return 0;

	int cont = 0;
	Elem* no = *pi;
	while(no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
};
//
int insere_Pilha(Pilha* pi, struct livro li)
{
	if(pi == NULL) return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if (no == NULL) return 0;
	no->dados = li;
	no->prox = (*pi);
	*pi = no;
	return 1;
};
//
int remove_Pilha(Pilha* pi)
{
	if (pi == NULL) return 0;
	if((*pi) == NULL) return 0;
	Elem *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}
//
int consulta_Topo(Pilha* pi, struct livro *li)
{
	if(pi==NULL) return 0;
	if((*pi)==NULL) return 0;
	*li = (*pi)->dados;
	return 1;
}
//
void imprimir_Pilha(Pilha* pi)
{
	    if(pi == NULL)
        return;
    Elem* no = *pi;
  	int index =0;
    while(no != NULL){
    	
    	
    	index++;
        printf("Nome do livro: %s\n",no->dados.nome);
        printf("Autor: %s\n",no->dados.autor);
        printf("Número de paginas: %d\n",no->dados.pags);
        
        printf("-----------------------------\n");

        no = no->prox;
    }

}

































