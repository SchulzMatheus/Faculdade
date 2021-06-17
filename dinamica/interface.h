struct aluno{
	int matricula;
	char nome[50];
	char idade[2];
	float nota1,nota2;
	float mediafinal;
	char situacao[10] = "Cursando";
	char sobrenome[60];
	int numero =1;
};
typedef struct elemento* Lista;
Lista * cria_Lista();
void Liberar_Lista(Lista* li);
int lista_vazia(Lista * li);
int insere_lista_final(Lista* li, struct aluno al);
int remove_lista_matricula(Lista* li, int mat);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
void imprime_lista(Lista* li);


