#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"

using namespace std;

struct Aluno;
struct Lista {
	int Qtd;
	Aluno Lista_Alunos[MAX];
};
//
Lista* cria_Lista(){
	Lista *Pont;
	Pont =  (Lista*) malloc(sizeof(Lista));
	if (Pont == NULL){
		cout <<"Ta dando bom"<<endl;
	
		return 0;
	}
	Pont->Qtd=0;
	return Pont;
};
//
int tamanho_Lista(Lista *Pont){
		if (Pont == NULL)
		{
			cout<<"\nHouve um problema"<<endl;
			return -1;
		} else {
			return Pont->Qtd;
		}
};
//
int Lista_cheia(Lista *Pont){
			if (Pont == NULL)
		{
			cout<<"\nHouve um problema"<<endl;
			return -1;
		} else {
			return (Pont->Qtd == MAX); // = 1 se true = 0 se false
		}
	
};
int Lista_vazia(Lista *Pont){
				if (Pont == NULL)
		{
			cout<<"\nHouve um problema"<<endl;
			return -1;
		} else {
			return (Pont->Qtd == 0); // = 1 se true = 0 se false
		}
};
int insere_Final(Lista *Pont, Aluno aluno){
	if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Lista_cheia(Pont)){
		cout<<"\nLista está cheia! não é possivel inserir novos alunos"<<endl;
		return 0;
	}else {
		Pont->Lista_Alunos[Pont->Qtd] = aluno;
		Pont->Qtd++;
		return 1;
	}
};
int insere_Inicio(Lista *Pont, Aluno aluno){
		if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Lista_cheia(Pont)){
		cout<<"\nLista está cheia! não é possivel inserir novos alunos"<<endl;
		return 0;
	}else {
		for(int i=Pont->Qtd; i>=0; i--)
		{
			Pont->Lista_Alunos[i+1] = Pont->Lista_Alunos[i];
		}
		Pont->Lista_Alunos[0] = aluno;
		Pont->Qtd++;
		return 1;
	}
	
};
int insere_Ordenado_Matricula(Lista *Pont, Aluno aluno){
		if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Lista_cheia(Pont)){
		cout<<"\nLista está cheia! não é possivel inserir novos alunos"<<endl;
		return 0;
	}else {
		int j=0;
		while (j<Pont->Qtd && Pont->Lista_Alunos[j].matricula<aluno.matricula)
		{
			j++;
		}
		for(int i=Pont->Qtd-1; i>=j; i--)
		{
			Pont->Lista_Alunos[i+1] = Pont->Lista_Alunos[i];
		}
		Pont->Lista_Alunos[j] = aluno;
		Pont->Qtd++;
		return 1;
	}
	
};
void imprimir_Lista(Lista *Pont){
	for(int i = 0; i<Pont->Qtd; i++)
	{
		cout<< ""<<i+1<<"" "-";
		cout<<"Nome: "<<Pont->Lista_Alunos[i].nome_aluno<<"\n";
		cout<<"Sobrenome: "<<Pont->Lista_Alunos[i].sobrenome<<"\n";
		cout<<"Idade: "<<Pont->Lista_Alunos[i].idade<<"\n";
		cout<<"Matricula: "<<Pont->Lista_Alunos[i].matricula<<"\n";
		cout<<"Situacao: "<<Pont->Lista_Alunos[i].situacao<<"\n\n";
		
	}
};
void liberar_Lista(Lista *Pont)
{
	free(Pont);
};
int remove_Final(Lista *Pont){
	if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Pont->Qtd==0){
		cout<<"\nLista está vazia! não é possivel remover alunos"<<endl;
		return 0;
	}else {
		Pont->Qtd--;
		return 1;
	}
};

int remove_Inicio(Lista *Pont){
		if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Pont->Qtd==0){
		cout<<"\nLista está vazia! não é possivel remover alunos"<<endl;
		return 0;
	}else {
		for(int i=0; i<Pont->Qtd; i++)
		{
			Pont->Lista_Alunos[i] = Pont->Lista_Alunos[i+1];
		}
		Pont->Qtd--;
		return 1;
	}
	
	
};
int remove_Ordenado_Matricula(Lista *Pont, int matricula_aluno){
			if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Pont->Qtd==0){
		cout<<"\nLista está vazia! não é possivel remover alunos"<<endl;
		return 0;
	}else {
		int i=0;
		while(i<Pont->Qtd && Pont->Lista_Alunos[i].matricula != matricula_aluno)
		{
			i++;
		}
		if(i==Pont->Qtd)
		{
			cout<<"\nElemento não encontrado na lista.";
			return 0;
		}
		for(int j=i; j<Pont->Qtd; j++)
		{
			Pont->Lista_Alunos[j] = Pont->Lista_Alunos[j+1];
		}
		Pont->Qtd--;
		return 1;
	}
	
};
int consulta_Lista_Pos(Lista *Pont, int Posicao, Aluno *aluno){
			if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	}	else if(Posicao <= 0 || Posicao > Pont->Qtd){
		cout<<"\nPosição informada invalida"<<endl;
		return 0;
	}else {
		*aluno = Pont->Lista_Alunos[Posicao-1];
		return 1;
	}
	
};
int consulta_Lista_Matricula(Lista *Pont, int matricula_b, Aluno *aluno){
				if(Pont == NULL){
		cout<<"\nHouve algum problema"<<endl;
		return 0;
	} else {
		int i = 0;
		while(i<Pont->Qtd && Pont->Lista_Alunos[i].matricula != matricula_b){
			i++;
		}
		if(i==Pont->Qtd){
			cout<<"\nElemento não encontrado!";
			return 0;
		} 
		*aluno = Pont->Lista_Alunos[i];
		return 1;
		
	}
};






















