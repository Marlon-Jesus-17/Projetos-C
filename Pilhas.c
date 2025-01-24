#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
}no;

//Função para empilhar
no* empilhar(no *topo){
	no *novo = malloc(sizeof(no));
	
	if(novo){
		printf("\nEntre com um valor inteiro:\n");
		scanf("%d", &novo->valor);
		
		novo->prox = topo;
		return novo;
	}
	else
		printf("\nErro ao alocar memória\n\n");
	return NULL;
}

//função para desempilhar
no* desempilhar(no **topo){
	if(*topo){
		no *remover = *topo;
		*topo = remover->prox;
		return remover;
	}
	else
		printf("\nPilha vazia\n\n");
	return NULL;	
}

//função para imprimir a pilha
void imprimir(no *pilha){
	printf("\n");
	printf("Pilha:\n");
	while(pilha){
		printf("%d\n", pilha->valor);
		pilha = pilha->prox;
	}
	printf("\n\n");
}

int main(){
	no *topo = NULL, *remover;
	int op;
	
	do{
	printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
	scanf("%d", &op);
	
	switch(op){
	case 0:
		printf("\nSaindo...\n\n");
		break;
	case 1:
		topo = empilhar(topo);
		break;
	case 2:
		remover = desempilhar(&topo);
		if(remover){
			printf("\nElemento removido com sucesso\n\n");
		}
		else
			printf("\nSem nó a remover\n\n");
		break;
	case 3:
		imprimir(topo);
		break;
	default:
		printf("\nErro...(Opção inválida)");
	}
	
	
	}while(op != 0);
	
	return 0;
}
