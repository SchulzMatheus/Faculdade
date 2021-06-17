struct livro
{
	int pags;
	char nome[60];
	char autor [60];
};

typedef struct elemento* Pilha;
Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int insere_Pilha(Pilha* pi, struct livro li);
int remove_Pilha(Pilha* pi);
int consulta_Topo(Pilha* pi, struct livro *li);
void imprimir_Pilha(Pilha* pi);

