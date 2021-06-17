#include <iostream>

#include <locale.h>

#include <math.h>

#include <stdlib.h>

#include "interface.h"



using namespace std;



int main(){
	setlocale(LC_ALL, "Portuguese");

	Lista *lista_alunos; //ponteiro para ponteiro
	aluno P, *Pont_P; // antes era Ponto no come�o

   	Pont_P = &P;

	
	int i=1, Aux=0;
	lista_alunos= cria_Lista();

   	char Menu;
	cout<<"Uma lista de alunos foi criada."<<endl;
	while (i != 0){

      cout<<"Informe o que deseja realizar na Lista_de_alunos!\nOp��es:"<<endl;

      

      cout<<"I - Imprimir a Lista;"<<endl;   

      cout<<"W - Inserir aluno no Final da Lista;"<<endl;

     
      cout<<"V - Remover aluno Ordenado por 'Matricula' na Lista;"<<endl;
      cout<<"X - Buscar aluno Ordenado por 'Matricula' na Lista;"<<endl;

      cout<<"Qualquer outra op��o fechar� a execu��o do Programa!"<<endl;

      cin>>Menu;

      //

      Menu = toupper(Menu); //passa o caractere informado para maiusculo
      switch (Menu){
    	case'I':
    		imprime_lista(lista_alunos);
    		break;
    		
    	case'W':
    		cout<<"Informe o nome do aluno: "; cin>>P.nome;
    		cout<<"Informe o sobrenome do aluno: "; cin>>P.sobrenome;
            cout<<"Informe a matricula do aluno: "; cin>>P.matricula;
            cout<<"Informe a idade do aluno: "; cin>>P.idade;
            Aux = insere_lista_final(lista_alunos, P);
            if (Aux==0){
               cout<<"Inser��o do aluno falhou!";
            }
    		break;
    	
    	case'V':
    		cout<<"Informe a matricula do aluno que deseja remover: "; cin>>P.matricula;
            Aux = remove_lista_matricula(lista_alunos, P.matricula);
            cout<<"aluno removido com sucesso";
            if (Aux==0){
               cout<<"Remo��o do aluno falhou!";
            } 
            break;    
    		
    	
    		break;
    	case'X':
    		cout<<"Informe a matricula do aluno que deseja buscar: "; cin>>P.matricula;
            Aux = consulta_lista_mat(lista_alunos, P.matricula, Pont_P);
            if (Aux==0){
               cout<<"Busca do aluno falhou!";
            }else{
            cout<<"Aluno solicitado: "<<P.nome<<" "<<P.sobrenome<<""<<endl;
			
			
			char option;
			cout<<"Deseja fazer altera��es na nota do aluno? 'S' para sim 'N' para n�o: "; cin>>option;
			option = toupper(option);
				switch(option){
					case 'S':
						cout<<"Informe a primeira nota do aluno: "; cin>>P.nota1;
						cout<<"Informe a segunda nota do aluno: "; cin>>P.nota2;
						cout<<"Altera��es feitas"<<endl;
						P.mediafinal = P.nota1*0.4 + P.nota2*0.6;
						break;
					case 'N':
						cout<<"Nenhuma altera��o foi feita";
						break;	
				}
			cout<<"A m�dia final do aluno �: "<<P.mediafinal<<""<<endl;
			if(P.mediafinal>=6)
			{
				cout<<"O aluno est� Aprovado";
			} else
			{
				cout<<"O aluno est� Reprovado";
			}
		}
    		
    	
    		break;
    	default:
    		imprime_lista(lista_alunos);
    		cout<<"Lista liberada da mem�ria! Execu��o encerrada!"<<endl;

            Liberar_Lista(lista_alunos);

            exit(0);

            break;
      }
      

      cout<<endl<<endl;

   }

   return 0;
      
      
}
