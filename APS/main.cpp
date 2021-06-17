#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "pilha.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	Pilha *pi;
	livro L, *Livr_L;
  	Livr_L = &L;
	char Menu;
	int i=1, Aux=0;
	pi = cria_Pilha();
	cout<<"Uma pilha de livros foi criada"<<endl;
	
	while (i != 0)
	{
		cout<<"Informe o que deseja realizar na Pilha\nOpções:"<<endl;
		cout<<"Q - Inserir um novo livro"<<endl;
		cout<<"C - Consultar tamanho da pilha de livros:"<<endl;
		cout<<"R - Remover livro do inicio da pilha:"<<endl;
		cout<<"D - Destruir pilha:"<<endl;
		cout<<"S - Consulta livro do topo da pilha:"<<endl;
		cout<<"I - Imprimir pilha:"<<endl;
		
		cin>>Menu;
		Menu = toupper(Menu);
		
		switch (Menu)
		{
			case 'D': 
            	libera_Pilha(pi);
            	cout<<"Pilha liberada da memória!!"<<endl;
            	printf("-----------------------------\n");
            	exit(0);
            	break;
            case 'C':
            	Aux = tamanho_Pilha(pi);
            	cout<<"Quantidade de livros na pilha: "<<Aux<<endl;
            	printf("-----------------------------\n");
            	break;
            case 'Q':
            	cout<<"Informe o nome do livro: "; cin>>L.nome;
				cout<<"Informe o nome do autor: "; cin>>L.autor;
           	 	cout<<"Informe a quantidade de páginas: "; cin>>L.pags;
            	Aux = insere_Pilha(pi, L);
            	printf("Livro inserido na pilha!!\n");
            	printf("-----------------------------\n");
            	break;
            case 'R':
            	Aux = remove_Pilha(pi);
            	cout<<"O primeiro livro da pilha de livros foi removido"<<endl;
            	printf("-----------------------------\n");
            	break;
            case 'S':
            	Aux = consulta_Topo(pi, &L);
            	if(Aux != 1)
            	{
            		cout<<"A consulta de livro falhou"<<endl;
            		printf("-----------------------------\n");
				}
            	cout<<"O livro que está no topo é: "<<L.nome<<endl;
            	printf("-----------------------------\n");
            	break;
            case 'I':
            	imprimir_Pilha(pi);
            	break;
            default:
            	cout<<"Opção inválida!!!"<<endl;
            	printf("-----------------------------\n");
            	
            
            
		}
	
	
	}
	
	}
	
		



