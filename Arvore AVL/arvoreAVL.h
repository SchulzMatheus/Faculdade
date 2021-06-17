
typedef struct NO* ArvAVL;


//fun��es auxiiares
// fun��es auxiliares
void Libera_NO_ArvAVL(NO* no);
int alt_NO(struct NO* no);
int fatorBalanceamento_NO(struct NO* no);
int maior (int x, int y);
void RotacaoLL(ArvAVL *Raiz);
void RotacaoRR(ArvAVL *Raiz);
void RotacaoLR(ArvAVL *Raiz);
void RotacaoRL(ArvAVL *Raiz);
struct NO* procuraMenor(struct NO* atual);
void galho(ArvAVL *Raiz, int Valor);

ArvAVL* Cria_ArvAVL();
void Libera_ArvAVL(ArvAVL *Raiz);
//informa��es
int ArvAVL_vazia(ArvAVL *Raiz);
int ArvAVL_Altura(ArvAVL *Raiz);
int ArvAVL_QuantNo(ArvAVL *Raiz);
//Percorrer Arvore
void PreOrdem_ArvAVL(ArvAVL *Raiz);
//Inser��o, remo��o e busca
int insere_ArvAVL(ArvAVL *Raiz, int elemento);
int remove_ArvAVL(ArvAVL *Raiz, int Valor);
int busca_ArvAVL(ArvAVL *Raiz, int Valor);

