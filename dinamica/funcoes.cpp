#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"
using namespace std;
struct elemento{
	struct aluno dados; //primeiro eLEMEN
	struct elemento *prox;//proximo elemen
};
typedef struct	elemento Elem;
Lista * cria_Lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista)); //criando lista //reserva memoria com maloc
	if(li != NULL){ //verificando se deu certo
	
		*li = NULL;
	}
	return li;
}
void Liberar_Lista(Lista* li){
	if(li != NULL){ //lista valida	
		Elem* no;
		while((*li) != NULL){ //pega o inicio da lista 
			no = *li; //recebe o inicio
			*li = (*li) ->prox; //pega o proximo
			free(no);//libera
		}
		free(li);//ate a lista fica toda vazia
	}
}
int lista_vazia(Lista * li){
	if(li == NULL) //se  a lista for nulla, nao tem elemento
		return 1;
	if(*li == NULL) //se a conteudo lista for null, nao tem conteudo na lista 
		return 0;
	return 0; //nao passou por nenhum if entao nao esta vazia
}

int insere_lista_final(Lista* li, struct aluno al){
	if(li == NULL) return 0; //se a lista é valida
	Elem *no = (Elem*) malloc(sizeof(Elem)); //memoria
	if (no == NULL) return 0; //se alista é valida
	no->dados = al;////copia o dados para o novo nome
	no->prox = NULL;//proximo elemento null
	if((*li)== NULL){ // lista vazia
		*li = no; //o inicio é no final
		
	}else{ //percorre a lista ate o ultimo pont
		Elem *aux = *li;
		while(aux ->prox != NULL){
			aux = aux->prox;
	  }
	  aux ->prox = no;
		}
		return 1;
	}


int remove_lista_matricula(Lista* li, int mat){
	if(li == NULL)return 0;
	Elem *ant, *no =*li;
	while (no != NULL && no->dados.matricula !=mat){ //percorre a lista e verificar se é diferente de matricula
		ant = no;
		no = no->prox;
	}
	if (no == NULL) return 0; //nao encontrou a matricula
	
	if (no == *li){ //remove o primeiro elemento da lista	
	
		*li = no->prox;
	}else{ 
		ant->prox = no->prox;
	}
		
	free(no);
	return 1 ;
}
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
	if (li == NULL) return 0;
	Elem *no = *li;
	while (no != NULL && no->dados.matricula != mat){ //procura a matricula
		no = no->prox;
	}
	if (no == NULL){ //se n encontrou o numero da matricula
	
		return 0;
	}else{
		*al = no->dados; //se deu certo a busca.. a ponta oponteiro e mostra o dados
		 return 1;
	}	
};
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
  	int index =0;
    while(no != NULL){
    	
    	cout<< ""<<index+1<<"" "-";
    	index++;
        printf("Nome: %s\n",no->dados.nome);
        printf("sobrenome: %s\n",no->dados.sobrenome);
        printf("Matricula: %d\n",no->dados.matricula);
        printf("idade: %s\n",no->dados.idade);
        printf("situação: %s\n",no->dados.situacao);
        
        printf("-----------------------------\n");

        no = no->prox;
    }
}
