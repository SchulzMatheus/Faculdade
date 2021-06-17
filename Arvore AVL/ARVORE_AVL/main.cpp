#include <stdio.h>

#include <stdlib.h>

#include <locale.h>

#include <math.h>

#include <iostream>

#include "arvore.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "PORTUGUESE");
    ArvAVL *arvore_avl;
    ArvAVL A, *raiz_av;
    raiz_av = &A;
    int m=1,aux=0;
    int h;
    char slc;
    system("clear || cls");
    do
    {
        system("clear || cls");
        cout<<"\n\n\t\t----Arvore de Numero---";
        cout<<"\n\n\t\t--------------- MENU ---------------";
        cout<<"\n\nA-Criar Arvore."<<endl;
        cout<<"B-Inserir Novo No na Arvore."<<endl;
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
        case 'A':
            system("clear || cls");
            arvore_avl = Cria_ArvAVL();
            cout<<"A Arvore foi criada Foi Criada."<<endl;
            system("pause");
            system("clear || cls");
            break;
        case 'B':
            system("clear || cls");
            cout<<"Insira o nœmero "<<endl;
            cin>>aux;
            if(insere_ArvAVL(arvore_avl, aux)){
            	cout<<"Inser‹o ok!"<<endl;
			}else {
				cout<<"Inser‹o falhou!"<<endl;
			}
			system("pause");
            system("clear || cls");

            break;

        case 'C':
            system("clear || cls");
            PreOrdem_ArvAVL(arvore_avl);
            system("pause");
            system("clear || cls");
            break;
        case 'D':
            system("clear || cls");
            cout<<"Digite o Numero Que Deseja Buscar: ";
            cin>>aux;
            busca_ArvAVL(arvore_avl, aux);
            system("pause");
            system("clear || cls");
        break;
        case 'F':
            system("clear || cls");
            cout<<"Qual Numero Deseja Remover?";
            remove_ArvAVL(arvore_avl, aux);
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
            aux = ArvAVL_QuantNo(arvore_avl);
            cout<<"A Quantidade de No da Arvore e: "<<aux<<endl;
            system("pause");
            system("clear || cls");
        break;
        case 'H':
            system("clear || cls");
            aux = ArvAVL_Altura(arvore_avl);
            cout<<"A altura da arvore Ž: "<<aux<<endl;
            system("pause");
            system("clear || cls");
        break;
        default:
            cout<<"\n\nLista Liberada da Memoria! Programa Encerrando"<<endl;
            system("pause");
            Libera_ArvAVL(arvore_avl);
            exit(0);
            break;
        }

    }
    while (m != 0);
    return 0;
}
