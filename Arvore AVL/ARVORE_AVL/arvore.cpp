#include <stdio.h>

#include <stdlib.h>

#include <locale.h>

#include <math.h>

#include <iostream>

#include "arvore.h"



using namespace std;



struct NO {



	int Numero;

	int alt;

	struct NO *esq;

	struct NO *dir;



};

// fun›es auxiliares

void Libera_NO_ArvAVL(NO* no);

int alt_NO(struct NO* no);

int fatorBalanceamento_NO(struct NO* no);

int maior (int x, int y);

void RotacaoLL(ArvAVL *Raiz);

void RotacaoRR(ArvAVL *Raiz);

void RotacaoLR(ArvAVL *Raiz);

void RotacaoRL(ArvAVL *Raiz);

struct NO* procuraMenor(struct NO* atual);



// Implementa‹o das fun›es

struct NO* procuraMenor(struct NO* atual){

	struct NO *no1 = atual;

	struct NO *no2 = atual->esq;

	while(no2!=NULL){

		no1 = no2;

		no2 = no2->esq;

	}

	return no1;

}

ArvAVL* Cria_ArvAVL(){

	ArvAVL* Raiz = (ArvAVL*) malloc(sizeof(ArvAVL));

	if (Raiz != NULL)

		{

			*Raiz = NULL;

		}

	return Raiz;

}

void Libera_NO_ArvAVL(NO *no){

	if(no == NULL)

		{

			return;

		}

	Libera_NO_ArvAVL(no->esq);

	Libera_NO_ArvAVL(no->dir);

	free(no);

	no = NULL;



}

void Libera_ArvAVL(ArvAVL *Raiz){

	if (Raiz == NULL)

	{

		return;

	}

	Libera_NO_ArvAVL(*Raiz);

	free(Raiz);



}

int ArvAVL_vazia(ArvAVL *Raiz){

	if(Raiz == NULL || *Raiz == NULL)

		{

		return 1;

		}

	return 0;

}

int ArvAVL_Altura(ArvAVL *Raiz){

	if(Raiz == NULL || *Raiz == NULL)

		{

		return 0;

		}

	int alt_esq = ArvAVL_Altura(&(*Raiz)->esq);

	int alt_dir = ArvAVL_Altura(&(*Raiz)->dir);

		if(alt_esq>alt_dir)

		{

			return(alt_esq+1);

		}

		else

		{

			return(alt_dir+1);

		}

}

int ArvAVL_QuantNo(ArvAVL *Raiz){

		if(Raiz == NULL || *Raiz == NULL)

		{

		return 0;

		}

	int alt_esq = ArvAVL_Altura(&(*Raiz)->esq);

	int alt_dir = ArvAVL_Altura(&(*Raiz)->dir);

	return(alt_esq + alt_dir + 1);

}

void PreOrdem_ArvAVL(ArvAVL *Raiz){

	if(Raiz==NULL){

		cout<<"Erro";

		return;

	}

	if(*Raiz != NULL)

	{

		cout<<(*Raiz)->Numero<<"  ";

		PreOrdem_ArvAVL(&(*Raiz)->esq);

		PreOrdem_ArvAVL(&(*Raiz)->dir);

	}

}

int busca_ArvAVL(ArvAVL *Raiz, int Valor){

	if(Raiz==NULL)

	{

		cout<<"Erro"<<endl;

		return 0;

	} else{

		NO *atual = *Raiz;

		while(atual!=NULL){

			if(Valor == atual->Numero){

				return 1;

			}

			if(Valor > atual->Numero){

				atual = atual->dir;

			}else{

				atual = atual->esq;

			}

		}
        cout<<"o numeto encontrado e: " <<atual<<endl;
		return 0;

	}



}

int alt_NO(struct NO* no){

	if (no == NULL)

	{

		return -1;

	}else {

		return no->alt;

	}

}

int fatorBalanceamento_NO(struct NO* no){

	return labs(alt_NO(no->esq) - alt_NO(no->dir));

}

int maior (int x, int y){

	if(x>y)

		return x;

	else

		return y;

}

void RotacaoLL(ArvAVL *Raiz){

	struct NO *no;

	no = (*Raiz)->esq;

	(*Raiz)->esq = no->dir;

	no->dir = *Raiz;

	(*Raiz)->alt = maior(alt_NO((*Raiz)->esq), alt_NO((*Raiz)->dir)) +1;

	no->alt = maior(alt_NO(no->esq), (*Raiz)->alt) +1;



	*Raiz = no;

}

void RotacaoRR(ArvAVL *Raiz){

		struct NO *no;

	no = (*Raiz)->dir;

	(*Raiz)->dir = no->esq;

	no->esq = *Raiz;

	(*Raiz)->alt = maior(alt_NO((*Raiz)->esq), alt_NO((*Raiz)->dir)) +1;

	no->alt = maior(alt_NO(no->dir), (*Raiz)->alt) +1;



	*Raiz = no;

}

void RotacaoLR(ArvAVL *Raiz){

	RotacaoRR(&(*Raiz)->esq);

	RotacaoLL(Raiz);

}

void RotacaoRL(ArvAVL *Raiz){

	RotacaoLL(&(*Raiz)->dir);

	RotacaoRR(Raiz);

}

int insere_ArvAVL(ArvAVL *Raiz, int Valor){

	int res;

	if(*Raiz == NULL){

		struct NO *novo;

		novo = (struct NO*)malloc(sizeof(struct NO));

		if(novo == NULL)

			return 0;



		novo->Numero = Valor;

		novo->alt = 0;

		novo->esq = NULL;

		novo->dir = NULL;

		*Raiz = novo;

		return 1;



		struct NO *atual = *Raiz;

		if(Valor < atual->Numero)

		{

			if((res = insere_ArvAVL(&(atual->esq), Valor)) == 1)

			{

				if(fatorBalanceamento_NO(atual) >= 2) {

					if(Valor<(*Raiz)->esq->Numero){

						RotacaoLL(Raiz);

					}else{

						RotacaoLR(Raiz);

					}

				}

			}

		}else{

			if(Valor>atual->Numero){

				if((res = insere_ArvAVL(&(atual->dir), Valor)) == 1)

				{

					if(fatorBalanceamento_NO(atual)>=2){

						if((*Raiz)->dir->Numero < Valor)

						{

							RotacaoRR(Raiz);

						}else  {

							RotacaoRL(Raiz);

						}

					}

				}

			}else{

				printf("Valor duplicado!!\n");

				return 0;

			}

		}

		atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) +1;

		return res;

	}

}

int remove_ArvAVL(ArvAVL *Raiz, int Valor){

	if(*Raiz==NULL)

	{

		printf("Valor n‹o existe!!\n");

		return 0;

	}

	int res;

	if(Valor<(*Raiz)->Numero)

	{

		if((res = remove_ArvAVL(&(*Raiz)->esq, Valor))==1)

			if(fatorBalanceamento_NO(*Raiz)>=2){

				if(alt_NO((*Raiz)->dir->esq) <= alt_NO((*Raiz)->dir->dir))

					RotacaoRR(Raiz);

				else

					RotacaoRL(Raiz);

			}

	}

	if((*Raiz)->Numero < Valor){

		if((res = remove_ArvAVL(&(*Raiz)->dir, Valor))==1)

			if(fatorBalanceamento_NO(*Raiz)>=2){

				if(alt_NO((*Raiz)->esq->dir) <= alt_NO((*Raiz)->esq->esq) )

					RotacaoLL(Raiz);

				else

					RotacaoLR(Raiz);

			}

	}

	if((*Raiz)->Numero == Valor){

		if(((*Raiz)->esq==NULL || (*Raiz)->dir==NULL )){

			struct NO *oldNode = (*Raiz);

			if((*Raiz)->esq != NULL)

				*Raiz = (*Raiz)->esq;

			else

				*Raiz = (*Raiz)->dir;

			free(oldNode);

		} else { //no tem dois filhos

			struct NO* temp = procuraMenor((*Raiz)->dir);

			(*Raiz)->Numero = temp->Numero;

			remove_ArvAVL(&(*Raiz)->dir, (*Raiz)->Numero);

			if(fatorBalanceamento_NO(*Raiz) >= 2){

				if(alt_NO((*Raiz)->esq->dir)<= alt_NO((*Raiz)->esq->esq))

					RotacaoLL(Raiz);

				else

					RotacaoLR(Raiz);

			}

		}

		return 1;

	}

	return res;

}
