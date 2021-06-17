
#define MAX 8
struct Aluno{
	char nome_aluno[60];
	int matricula;
	int idade;
	float nota1 = 0;
	float nota2 = 0;
	float mediafinal;
	char situacao[10] = "Cursando";
	char sobrenome[60];
};

struct Lista;
//
Lista* cria_Lista(); 
int tamanho_Lista(Lista *Pont);
int Lista_cheia(Lista *Pont);
int Lista_vazia(Lista *Pont);
int insere_Final(Lista *Pont, Aluno aluno);
int insere_Inicio(Lista *Pont, Aluno aluno);
int insere_Ordenado_Matricula(Lista *Pont, Aluno aluno);
void imprimir_Lista(Lista *Pont);
void liberar_Lista(Lista *Pont);
int remove_Final(Lista *Pont);
int remove_Inicio(Lista *Pont);
int remove_Ordenado_Matricula(Lista *Pont, int matricula_aluno);
int consulta_Lista_Pos(Lista *Pont, int Posicao, Aluno *aluno);
int consulta_Lista_Matricula(Lista *Pont, int matricula_b, Aluno *aluno);
