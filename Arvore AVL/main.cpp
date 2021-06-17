#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <iostream>
#include "arvoreAVL.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "PORTUGUESE");
	ArvAVL *raiz;
	raiz = Cria_ArvAVL();
	cout<<"Uma árvore binaria avl foi criada."<<endl;
    int m=1,aux=0;
    int h;
    char slc;
    
    do
    {
        
        cout<<"\n\n\t\t----Arvore de Numero---";
        cout<<"\n\n\t\t--------------- MENU ---------------";
        cout<<"\nB-Inserir Novo No na Arvore."<<endl;
        cout<<"C-Imprimir Arvore."<<endl;
        cout<<"D-Buscar na Arvore."<<endl;
        cout<<"F-Remover da Arvore."<<endl;
        cout<<"G-Quantidade de No da Arvore."<<endl;
        cout<<"H-Altura da Arvore."<<endl;
        cout<<">>\n\n\tDIGITE UM CARACTERE DIFERENTE PARA FECHAR O PROGRAMA<<."<<endl;
        cout<<"Escolha a Operacao deseja:  ";
        cin>>slc;
        slc= toupper (slc);

        switch(slc)
        {

        case 'B':
            system("clear || cls");
            cout<<"Insira o número "<<endl;
            cin>>aux;
            if(insere_ArvAVL(raiz, aux)){
            	cout<<"Inserção ok!"<<endl;
			}else {
				cout<<"Inserção falhou!"<<endl;
			}
			system("pause");
            system("clear || cls");
            
            break;

        case 'C':
            system("clear || cls");
            PreOrdem_ArvAVL(raiz);
            system("pause");
            system("clear || cls");
            break;
        case 'D':
            system("clear || cls");
            cout<<"Digite o Numero Que Deseja Buscar: ";
            cin>>aux;
            busca_ArvAVL(raiz, aux);
            system("pause");
            system("clear || cls");
        break;
        case 'F':
            system("clear || cls");
            cout<<"Qual Numero Deseja Remover?";
            remove_ArvAVL(raiz, aux);
            if(aux == 0){
                cout<<"A Remocao Falhou";
            }else{
                cout<<"A Remocao deu certo";
            }
            system("pause");
            system("clear || cls");
        break;
        case 'G':
            system("clear || cls");
            aux = ArvAVL_QuantNo(raiz);
            cout<<"A Quantidade de No da Arvore e: "<<aux<<endl;
            system("pause");
            system("clear || cls");
        break;
        case 'H':
            system("clear || cls");
            aux = ArvAVL_Altura(raiz);
            cout<<"A altura da arvore é: "<<aux<<endl;
            system("pause");
            system("clear || cls");
        break;
        default:
            cout<<"\n\nLista Liberada da Memoria! Programa Encerrando"<<endl;
            system("pause");
            Libera_ArvAVL(raiz);
            exit(0);
            break;
        }

    }
    while (m != 0);
    return 0;
}
