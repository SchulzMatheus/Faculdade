#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED



typedef struct NO* ArvAVL;

//

ArvAVL* Cria_ArvAVL();

void Libera_ArvAVL(ArvAVL *Raiz);

//informa��es

int ArvAVL_vazia(ArvAVL *Raiz);

int ArvAVL_Altura(ArvAVL *Raiz);

int ArvAVL_QuantNo(ArvAVL *Raiz);

//Percorrer Arvore

void PreOrdem_ArvAVL(ArvAVL *Raiz);

//Inser��o, remo��o e busca

int insere_ArvAVL(ArvAVL *Raiz, int Valor);

int remove_ArvAVL(ArvAVL *Raiz, int Valor);

int busca_ArvAVL(ArvAVL *Raiz, int Valor);





#endif // ARVORE_H_INCLUDED
