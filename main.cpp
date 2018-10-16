#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"biblioteca.h"

/*
Gabriel Rodrigues 
*/
int main(){	
	Livro *acervo  =  NULL;
	Livro *deletar =  NULL;
	Livro *pesquisa=  NULL;

	carrega_AVR(&acervo,"Livro(2).txt","r");
	balanceamentoContinuo(&acervo);
		
	char nome[50],autor[30],ano[8];
	int res;
	char ok;
	
	do{
		system("cls");
		system("color 70");
		do{
		printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		printf("\n********************************************************************\n");
		printf("1 - Inserir novos Livros\n");
		printf("2 - Ver todos os  Livros\n");
		printf("3 - Pesquisar Livro(s) Por Nome\n");
		printf("4 - Pesquisar Por autor\n");
		printf("5 - Pesquisar Livro(s) Por ano\n");
		printf("6 - Excluir livro\n");
		printf("7 - Emprestimo\n");
		printf("8 - Devolucao\n");
		printf("9 - Sair\n");	
		printf("\nEscolha a operacao: ");
		scanf("%d", &res);
		fflush(stdin);
		
		if(res != 1 && res != 2 && res != 3&& res != 4 && res != 5 && res != 6 && res != 7 && res != 8 && res != 9){
			system("cls");
		}
	}while(res != 1 && res != 2 && res != 3&& res !=4 && res != 5 && res != 6 && res != 7 && res != 8 && res != 9);
	
	switch(res){				
		case 1:
			system("cls");
			printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
			printf("\n0 - Cancelar ");
		    printf("\n***************************( Inclusao de livros )********************\n");
			printf("Informe o nome: ");
			scanf("%[^\n]s", &nome);
		    fflush(stdin);
		    caixa_Alta(nome);
		    
			if(strcmp(nome,"0")==0){
				printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
			    ok = toupper(getch());
			    break;
			}
			
			printf("Informe o autor: ");
			scanf("%[^\n]s", &autor);
			fflush(stdin);
			caixa_Alta(autor);
			
			if(strcmp(autor,"0")==0){
				printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
			    ok = toupper(getch());
			    break;
			}
			
			
			printf("Informe o ano(lancamento do livro): ");
			scanf("%s", &ano);
			fflush(stdin);
				
			
			if(strcmp(ano,"0")==0){
				printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
			    ok = toupper(getch());
			    break;
			}
			
			printf("\n********************************************************************\n");
			printf("Livro incluido com sucesso !!\n\n");
			printf("Nome..:  %s\n",nome);
			printf("Autor.:  %s\n",autor);
			printf("Ano...:  %s\n",ano);
			printf("Status:  %d\n",0);
			
			insere(&acervo,nome,autor,ano,0);
			balanceamentoContinuo(&acervo);
			 printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
			ok = toupper(getch());
			break;
		
		case 2:
			system("cls");
			printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		    printf("\n**********************( Impressao de todos os livros )*************************\n");
			imprimeLivros(acervo);
			printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
			ok = toupper(getch());
		   break;
		   
		 case 3:
		 	system("cls");
		 	printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		    printf("\n**********************( Pesquisa de livro por Nome )***************************\n");
		 	printf("Informe o nome(Livro): ");
		 	scanf("%[^\n]s", &nome);
		 	fflush(stdin);
		 	caixa_Alta(nome);
		 	printf("   %s      \n",nome);
		 	
		 	
		 	pesquisar(acervo,nome);
		 	printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		 	ok = toupper(getch());
		   break;
		    
		  case 4:
		  	system("cls");
		  	printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		    printf("\n********************( Pesquisa de Livros por Autor )***************************\n");
		  	printf("Informe o autor(Livro): ");
		  	scanf("%[^\n]s", &autor);
		  	fflush(stdin);
		  	caixa_Alta(autor);
		  	printf("%s  \n",autor);
		  	
		  	pesquisaAutor(acervo,autor);
		  	printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		  	ok = toupper(getch());
		    break;  
		  
		  case 5:
		   system("cls");
		   printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		   printf("\n*********************( Pesquisa de Livros por Ano )****************************\n");
		   printf("Informe o ano de lancamento do livro: ");
		   scanf("%[^\n]s", &ano);
		   fflush(stdin);
		   
		   
		   
		   pesquisaAno(acervo,ano);
		   printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		   ok = toupper(getch());
		   break;
		  
		 case 6: 
		   system("cls");
		   printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		   printf("\n**********************( Exclusao de Livros )***********************************\n");
		   printf("Informe o nome completo do livro: ");
		   scanf("%[^\n]s", &nome);
		   fflush(stdin);
		   caixa_Alta(nome);
		   
		   printf("%s",nome);
		   
		   deletar = pegarLivro(acervo,nome);
		   if(deletar == NULL){
		   	 printf("Livro nao encontrado !!\n");
		   }else{
		   	 printf("Achou: %s",deletar->nome);
		   	 excluir(&acervo,deletar->nome);
		   }
		   	   
		   printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		   ok = toupper(getch());
		  break; 
		  
		  case 7:
		   system("cls");
		   printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		   printf("\n************************( Emprestimos )**************************************\n");
		    printf("Informa o nome(Livro): ");
		    scanf("%[^\n]s",&nome);
		    fflush(stdin);
		    caixa_Alta(nome);
		    printf("%s  \n",nome);
		    
		    
		    printf("\n********************************************************************\n");
		    pesquisa = pegarLivro(acervo,nome);
		    
			if(pesquisa == NULL){
		    	printf("Livro nao encontrado \n");
			}else if(pesquisa != NULL &&  pesquisa->status == 0){
				 printf("Nome.: %s \n",pesquisa->nome);
				 printf("Autor: %s \n",pesquisa->autor);
				 pesquisa->status = 1;
				 printf("Emprestimo feito com sucesso !\n");
			}else if(pesquisa != NULL &&  pesquisa->status == 1){
				printf("Livro Indisponivel no momento\n");
			}
			
		    printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		   ok = toupper(getch());
		  break;
		  
		  case 8:
		      system("cls");
		      printf("Data :%s          Biblioteca                Hora:%s\n",__DATE__,__TIME__);
		      printf("\n*************************( Devolucao )**************************************\n");
		      printf("Informa o nome(Livro): ");
		      scanf("%[^\n]s",&nome);
		      fflush(stdin);
		      caixa_Alta(nome);
		      printf("%s  \n",nome);
		      
		      printf("\n********************************************************************\n");
		      pesquisa = pegarLivro(acervo,nome);
		    
			  if(pesquisa == NULL){
		    	printf("Livro nao encontrado \n");
			  }else{
				 printf("Nome.: %s \n",pesquisa->nome);
				 printf("Autor: %s \n",pesquisa->autor);
				 pesquisa->status = 0;
				 printf("Devolucao feita com sucesso !\n");
			  }
			
		      printf("\nPresione 'Enter' para sair ou 'V' para voltar:");
		      ok = toupper(getch());
		  break;
		  
		  case 9:
		  	char c;
			printf("salvar os dados(S/N)?  ");
		  	c = toupper(getch());
		  	if(c == 'S'){
		  		printf("Salvando... \n");
		  		salvar(acervo,"livros.txt","a+");
			  }
		  	return 0;
		  
		  break;
	  }	
	  
	}while(ok == 'V');



	getch();
	return 0;
}
