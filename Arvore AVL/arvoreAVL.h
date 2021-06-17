
typedef struct NO* ArvAVL;


//funções auxiiares
// funções auxiliares
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
//informações
int ArvAVL_vazia(ArvAVL *Raiz);
int ArvAVL_Altura(ArvAVL *Raiz);
int ArvAVL_QuantNo(ArvAVL *Raiz);
//Percorrer Arvore
void PreOrdem_ArvAVL(ArvAVL *Raiz);
//Inserção, remoção e busca
int insere_ArvAVL(ArvAVL *Raiz, int elemento);
int remove_ArvAVL(ArvAVL *Raiz, int Valor);
int busca_ArvAVL(ArvAVL *Raiz, int Valor);

