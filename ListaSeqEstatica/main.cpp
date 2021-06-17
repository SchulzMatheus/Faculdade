#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "Interface.h"

using namespace std;

int main(){
   setlocale(LC_ALL, "Portuguese");
   Lista *Lista_Alunos_Y;
   Aluno P, *Pont_P;
   Pont_P = &P;
   int i=1, Aux=0;
   char Menu;
   Lista_Alunos_Y= cria_Lista();
   cout<<"Uma lista de alunos foi criada."<<endl;

   while (i != 0){
      cout<<"Informe o que deseja realizar na Lista_de_Pontos!\nOpções:"<<endl;
      cout<<"C - Consultar Quantidade de alunos;"<<endl;
      cout<<"I - Imprimir a Lista;"<<endl;   
      cout<<"Q - Inserir aluno no Inicio da Lista;"<<endl;
      cout<<"W - Inserir aluno no Final da Lista;"<<endl;
      cout<<"E - Inserir aluno Ordenado por 'Matricula' na Lista;"<<endl;
      cout<<"Z - Remover aluno no Inicio da Lista;"<<endl;
      cout<<"X - Remover aluno no Final da Lista;"<<endl;
      cout<<"V - Remover aluno Ordenado por 'Matricula' na Lista;"<<endl;
      cout<<"N - Consultar um aluno Ordenado por 'Matricula' na Lista;"<<endl;
      cout<<"Qualquer outra opção fechará a execução do Programa!"<<endl;
      cin>>Menu;
      //
      Menu = toupper(Menu); //passa o caractere informado para maiusculo
      switch (Menu){
         case 'C': 
            Aux = tamanho_Lista(Lista_Alunos_Y);
            cout<<"Quantidade de alunos na Lista: "<<Aux<<endl;
            break;
         case 'I': 
            imprimir_Lista(Lista_Alunos_Y);
            break;
         case 'Q':
			cout<<"Informe o nome do aluno: "; cin>>P.nome_aluno;
			cout<<"Informe o sobrenome do aluno: "; cin>>P.sobrenome;
            cout<<"Informe a matricula do aluno: "; cin>>P.matricula;
            cout<<"Informe a idade do aluno: "; cin>>P.idade;
            Aux = insere_Inicio(Lista_Alunos_Y, P);
            if (Aux==0){
               cout<<"Inserção do aluno falhou!";
            }
            break;
         case 'W':
            cout<<"Informe o nome do aluno: "; cin>>P.nome_aluno;
            cout<<"Informe o sobrenome do aluno: "; cin>>P.sobrenome;
            cout<<"Informe a matricula do aluno: "; cin>>P.matricula;
            cout<<"Informe a idade do aluno: "; cin>>P.idade;
            Aux = insere_Final(Lista_Alunos_Y, P);
            if (Aux==0){
               cout<<"Inserção do aluno falhou!";
            }
            break;
         case 'E':
            cout<<"Informe o nome do aluno: "; cin>>P.nome_aluno;
            cout<<"Informe o sobrenome do aluno: "; cin>>P.sobrenome;
            cout<<"Informe a matricula do aluno: "; cin>>P.matricula;
            cout<<"Informe a idade do aluno: "; cin>>P.idade;
            Aux = insere_Ordenado_Matricula(Lista_Alunos_Y, P);
            if (Aux==0){
               cout<<"Inserção do aluno falhou!";
            } 
            break;
         case 'Z':
            Aux = remove_Inicio(Lista_Alunos_Y);
            if (Aux==0){

               cout<<"Remoção do aluno falhou!";

            } 
            break;            
         case 'X':
            Aux = remove_Final(Lista_Alunos_Y);
            if (Aux==0){
               cout<<"remoção do aluno falhou!";
            } 
            break;
          case 'V':
            cout<<"Informe a matricula do aluno que deseja remover: "; cin>>P.matricula;
            Aux = remove_Ordenado_Matricula(Lista_Alunos_Y, P.matricula);
            if (Aux==0){
               cout<<"Remoção do aluno falhou!";
            } 
            break;    
          case 'N':
            cout<<"Informe a matricula do aluno que deseja buscar: "; cin>>P.matricula;
            Aux = consulta_Lista_Matricula(Lista_Alunos_Y, P.matricula, Pont_P);
            if (Aux==0){
               cout<<"Busca do aluno falhou!";
            }else{
            cout<<"Aluno solicitado: "<<P.nome_aluno<<" "<<P.sobrenome<<""<<endl;
			
			char option;
			cout<<"Deseja fazer alterações na nota do aluno? 'S' para sim 'N' para não: "; cin>>option;
			option = toupper(option);
				switch(option){
					case 'S':
						cout<<"Informe a primeira nota do aluno: "; cin>>Pont_P->nota1;
						cout<<"Informe a segunda nota do aluno: "; cin>>Pont_P->nota2;
						cout<<"Alterações feitas"<<endl;
						Pont_P->mediafinal = Pont_P->nota1*0.4 + Pont_P->nota2*0.6;
						break;
					case 'N':
						cout<<"Nenhuma alteração foi feita";
						break;	
				}
			cout<<"A média final do aluno é: "<<Pont_P->mediafinal<<""<<endl;
			if(Pont_P->mediafinal>=6)
			{
				
				cout<<"O aluno está Aprovado";
			} else
			{
				cout<<"O aluno está Reprovado";
			}
		}
				
			
            break;     
         default: 
            cout<<"Lista liberada da memória! Execução encerrada!"<<endl;
            liberar_Lista(Lista_Alunos_Y);
            exit(0);
            break;

      }

      cout<<endl<<endl;

   }

   return 0;

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


