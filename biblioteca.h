#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#include"balanceamento.h"

typedef struct livro{
	char nome[100];//nome do livro
	char autor[100];//autor do livro
	char ano[10];//ano de lançamento 
	int  status;//status de disponibilidade do livro
	int altura;
	int fb;
	struct livro *esq,*dir;//postneiros filhos
}Livro;


Livro * criaLivro(char *n,char *a,char *an,int st){//funçãode criação do Nodo livro
	Livro *novo = (Livro *)malloc(sizeof(Livro));//alocação de memoria
	strcpy(novo->nome,n);//copiar a conteudda variável n para novo->nome
	strcpy(novo->autor,a);//copiar a conteudda variável a para novo->autor
	strcpy(novo->ano,an);//seta o ano do livro)
    novo->status = st;//seta o status do livro (0)disponível (1)indisponível
	novo->esq = NULL;//inicial os nodos filho
	novo->dir = NULL;//inicial os nodos filho
	novo->altura=0;
	novo->fb=0;
	return novo;//retiorna o livro
}

void insere(Livro **livro,char *nome,char *autor,char *ano,int st){//função de inserção do livro na Avr
     if(*livro == NULL){//se o livro em questão for == null
     	*livro = criaLivro(nome,autor,ano,st);//o nodo ira setar os dados no endereçõ indicado
	 }else if(strcmp(nome,(*livro)->nome)< 0){//senão se strcmp() retornar < 0 Esq.
	 	insere(&(*livro)->esq,nome,autor,ano,st);//chamoa recursão para a esqueda
	 }else if(strcmp(nome,(*livro)->nome)> 0){//senão se strcmp() retornar > 0 Esq.
	 		insere(&(*livro)->dir,nome,autor,ano,st);//chamoa recursão para a esqueda
	 }
}

void excluir(Livro **livro,char *nome){//função de exclusão de um nodo (livro)
	if(livro == NULL){
		return;
	}else if(strcmp(nome,(*livro)->nome) == 0){
		if((*livro)->esq == NULL && (*livro)->dir == NULL){//folha
			free(livro);
			*livro = NULL;
			
		}else if((*livro)->esq == NULL){//derivação esq.
			*livro = (*livro)->esq;
			free(livro);
		}else if((*livro)->dir == NULL){//derivação dir.
			*livro = (*livro)->dir;
			free(livro);
		}else{// derivação com 2 filhos
			
			Livro *pMaiorLivro = NULL;
            Livro *maiorLivro = (*livro)->esq;

            while(maiorLivro->dir != NULL){
                pMaiorLivro = maiorLivro;
                maiorLivro = maiorLivro->dir;
            }
            Livro *tempAux = *livro;
            
            *livro = maiorLivro;
            if(pMaiorLivro != NULL){
                pMaiorLivro->dir = maiorLivro->esq;
                (*livro)->esq = tempAux->esq;
            }
            (*livro)->dir = tempAux->dir;
            free(tempAux);   
		}	
	}else if(strcmp(nome,(*livro)->nome) < 0){
		excluir(&(*livro)->esq,nome);
	}else{
		excluir(&(*livro)->dir,nome);
	}
}



void  pesquisar(Livro *livro,char *nome){//busca um livro no biblioteca	 
	 if(livro == NULL){
	 	return;
	 	//printf("Nenhum Resultados encrontrados para %s\n",nome);
	 }else if(strcmp(nome,livro->nome)==0){	
		printf("%s  %s %s\n",livro->nome,livro->autor,livro->ano);
	 }else if(strcmp(nome,livro->nome) < 0){
	 	pesquisar(livro->esq,nome);
	 }else{
	 	pesquisar(livro->dir,nome);
	 }
}


Livro * pegarLivro(Livro *livro,char *str){//busca um livro no biblioteca
	 if(livro == NULL){
	 	//printf("O livro nao esta no acervo\n");
	 	return NULL;
	 }else if(strcmp(str,livro->nome)==0){
	 	return livro;
	 }else if(strcmp(str,livro->nome) < 0){//esq
	 	pegarLivro(livro->esq,str);
	 }else if(strcmp(str,livro->nome) > 0){//dir
	 	pegarLivro(livro->dir,str);
	 }
}

void  pesquisaAutor(Livro *livro,char *autor){
	 if(livro == NULL){
	 	return;
	 }else if(strstr(livro->autor,autor) != NULL){
	 	printf("%s : %s\n",livro->autor,livro->nome);
		 
		pesquisaAutor(livro->esq,autor);
		pesquisaAutor(livro->dir,autor);
	 }
}

void   pesquisaAno(Livro *livro,char *ano){
	if(livro == NULL){
	 	return;
	 	
	 }else if(strstr(livro->ano,ano)!=NULL){
	 	printf("%s  :%s %s\n",livro->ano,livro->nome,livro->autor);
		 
		 pesquisaAno(livro->esq,ano);
		 pesquisaAno(livro->dir,ano);
	 }
}

void imprimeLivros(Livro *livro) {//imprime toda a arvore com os livros
	if(livro != NULL){
		imprimeLivros(livro->esq);
		printf("Nome: %s Autor: %s Ano: %s -(%d)\n",livro->nome,livro->autor,livro->ano,livro->status);
		imprimeLivros(livro->dir);
	}
}

int altura(Livro *l){
	if(l != NULL){
		int alt_esq = altura(l->esq);
		int alt_dir = altura(l->dir);
		
		if(alt_esq > alt_dir){
			l->altura = alt_esq +1;
			return alt_esq + 1;
		}else{
		   l->altura = alt_dir + 1;	
			return alt_dir + 1;
		}
		
	}else{
		return 0;
	}
}


char * caixa_Alta(char *palavra){
	 int i;
	 
	 for(i=0; palavra[i] !='\0' ;i++){
	  palavra[i] =  toupper(palavra[i]); 
	 }
	 return palavra;
}


char  * pegaTrecho(char *str,int x,char c){
	 int i,j,cont;
	 char palavra[30];
	 
	 cont=0;
	 j=0;
	 
	 for(i=0;str[i]!='\0';i++){
	 	if(str[i] == c){
	 		cont++;
		 }	 
		 if(cont == x && str[i]!=','){
		 	palavra[j] = toupper(str[i]);
		 	j++;
		 }		 
	 }
	 
	palavra[j] = '\0';
	return palavra;
	palavra[0] = '\0'; 
}

void carrega_AVR(Livro **l,char *url,char *op){
	 FILE *f = fopen(url,op);
	 char linha[100];
     char palavra[30];
	 char nome[30],autor[30],ano[8],status[5];


	 while(fgets(linha,sizeof(linha),f)!=NULL){
	 	strcpy(nome,pegaTrecho(linha,0,','));
	 	strcpy(autor,pegaTrecho(linha,1,','));
	 	strcpy(ano,pegaTrecho(linha,2,','));
	    strcpy(status,pegaTrecho(linha,3,','));
	    int x = atoi(status);
		insere(&(*l),nome,autor,ano,x);
	 }	 
}

void salvar(Livro *raiz,char *url,char *x){//salva os dados da arvore em um txt @param.x: operação a ser utilizada
    FILE *arq = fopen(url,x);
    
    if(arq == NULL){
    	printf("Erro ao abrir o arquivo\n");
	}else{
		if(raiz != NULL){
			salvar(raiz->esq,url,x);
			fprintf(arq,"%s,%s,%s,%d\n",raiz->nome,raiz->autor,raiz->ano,raiz->status);
			 //printf("ok salvou\n");
			salvar(raiz->dir,url,x);
		}	
	}
	fclose(arq);
}




int calculaFB(Livro *l){
	
	if(l != NULL){
		int alt_esq = 0;
		int alt_dir = 0;
		
		if(l->dir != NULL){
			alt_dir = l->dir->altura;
		}
		
		if(l->esq != NULL){
			alt_esq = l->esq->altura;
		}
		
		l->fb = alt_dir - alt_esq;
		
		calculaFB(l->esq);
		calculaFB(l->dir);		
	}
}

void RSD(Livro **l){
	Livro *temp = *l;
	*l = (*l)->esq;
	temp->esq = (*l)->dir;
	(*l)->dir = temp;
}

void RSE(Livro **l){
	Livro *temp = *l;
	*l = (*l)->dir;
	temp->dir = (*l)->esq;
	(*l)->esq = temp;
}

void RDE(Livro **l){
	 RSD(&(*l)->dir);
	 RSE(&(*l));
}

void RDD(Livro **l){
    RSE(&(*l)->esq);
	RSD(&(*l));	
}

bool balanceamento(Livro ** n){

    if( *n != NULL){
        if( abs((*n)->fb) > 1 ){
            //printf("nodo desbalanceado: %s\n", (*n)->nome);

            if((*n)->fb < -1 && (*n)->esq->fb <= -1 ){
               // printf("R. S. D.\n");
                RSD(&*n);
            }else if((*n)->fb > 1 && (*n)->dir->fb >= 1 ){
                //printf("R. S. E.\n");
                RSE(&*n);

            }else if((*n)->fb < -1 && (*n)->esq->fb >= 0 ){
                //printf("R. D. D.\n");
                RDD(&*n);

            }else if((*n)->fb > 1 && (*n)->dir->fb <= 0 ){
                //printf("R. D. E.\n");
                RDE(&*n);

            }
            //printf("depois das rotacoes \n");
            return false;
        }else{

            bool ret_esq = balanceamento(&(*n)->esq);
            if(ret_esq == false)
                return false;

            bool ret_dir = balanceamento(&(*n)->dir);
            if(ret_dir == false)
                return false;
        }

    }
    return true;
}



void balanceamentoContinuo(Livro **l){
	 do{
	 	altura(*l);
	 	calculaFB(*l);
	 	printf("Balanceamento ...\n");
	 }while(balanceamento(l) == false);
}


