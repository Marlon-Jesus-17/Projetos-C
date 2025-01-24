#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
	char nome[30];
	int idade;
}Pessoa;

int cadastrarPessoa(Pessoa *cad, int *quant, int *tam){
	if(*quant < *tam){
		Pessoa novo;
		printf("Nome: ");
		fgets(novo.nome, sizeof(novo.nome), stdin);
		printf("Entre com a idade: ");
		scanf("%d", &novo.idade);
		printf("\n");
		cad[*quant] = novo;
		(*quant)++;
		return 1;
	}else{
		printf("\nA lista de cadastro está cheia\n\n");
		return 0;
	}
}

void imprimir(Pessoa *cad, int *quant){
	for(size_t i = 0; i < *quant; i++){
		printf("Nome: %s", cad[i].nome);
		printf("Idade: %d\n\n", cad[i].idade);
	}
}

int salvarArquivo(Pessoa *cad, int *quant){
	FILE *arq = fopen("lista.txt", "w");
	
	if(arq){
		fprintf(arq, "%d\n\n", *quant);
		for(size_t i = 0; i < *quant; i++){
			fprintf(arq, "%s", cad[i].nome);
			fprintf(arq, "%d\n\n", cad[i].idade);
			
		}
		return 1;
	}else{
		printf("\nErro ao abrir arquivo\n\n");
		return 0;
	}
	fclose(arq);
}

void salvarArquivoBin(Pessoa *cad, int *quant){
	FILE *arq = fopen("lista.bin", "wb");

	if(arq){
		fprintf(arq, "%d\n", *quant);
		fwrite(cad, sizeof(Pessoa), *quant, arq);
	}else{
		printf("\nErro ao abrir arquivo\n\n");
	}
	fclose(arq);
}

void lerArquivoBin(Pessoa *cad, int *quant){
	FILE *arq = fopen("lista.bin", "rb");

	if(arq){
		fscanf(arq, "%d\n\n", &(*quant));
		fread(cad, sizeof(Pessoa), *quant, arq);
	}else{
		printf("\nErro ao abrir arquivo\n\n");
	}
	fclose(arq);
}

void lerArquivo(Pessoa *cad, int *quant){
	FILE *arq = fopen("lista.txt", "r");

	if(arq){
		fscanf(arq, "%d\n\n", &(*quant));
		for(size_t i = 0; i < *quant; i++){
			Pessoa p;
			fgets(p.nome, sizeof(p.nome), arq);
			fscanf(arq, "%d\n\n", &p.idade);
			cad[i] = p;
		}
	}else{
		printf("\nErro ao abrir arquivo\n\n");
	}

	fclose(arq);
}

int main(){
	Pessoa cadastro[10];
	int quant = 0, tam = 10, op;

	do{
		printf("1 - Cadastrar uma pessoa\n2 - Salvar no arquivo\n3 - Ler do Arquivo\n4 - Salvar em arquivo binário\n5 - Ler do arquivo binário\n6 - Imprimir\n0 - Sair\n\n");
		scanf("%d", &op);
		getchar();
		printf("\n");

		switch(op){
		case 0:
			printf("\nSaindo...\n\n");
			break;
		case 1:
			cadastrarPessoa(cadastro, &quant, &tam);
			break;
		case 2:
			salvarArquivo(cadastro, &quant);
			break;
		case 3:
			lerArquivo(cadastro, &quant);
			break;
		case 4:
			salvarArquivoBin(cadastro, &quant);
			break;
		case 5:
			lerArquivoBin(cadastro, &quant);
			break;
		case 6:
			imprimir(cadastro, &quant);
			break;
		default:
			printf("\nOpção inválida\n\n");
		}
	}while(op != 0);

		
	return 0;
}
