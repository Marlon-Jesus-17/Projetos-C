#include<stdio.h>
#include<string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
}Pessoa; 

int escreverArquivoTexto(){

    FILE *arq = fopen("prova.txt", "a+");

    if(arq){

        Pessoa novo;

        printf("\nNome: ");
        fgets(novo.nome, sizeof(novo.nome), stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';

        printf("\nIdade: ");
        scanf("%d", &novo.idade);
        getchar();

        fprintf(arq, "%s\n", novo.nome);
        fprintf(arq, "%d\n", novo.idade);

        fclose(arq);

        return 1;

    }else{
        printf("\nErro ao abrir arquivo!\n\n");
        return 0;
    }
}

int lerArquivoTexto(){

    FILE *arq = fopen("prova.txt", "r");

    if(arq){
        
        Pessoa novo;

        while(fscanf(arq, "%[^\n]\n%d\n", novo.nome, &novo.idade) > -1){
            printf("\nNome: %s\nIdade: %d\n", novo.nome, novo.idade);
        }

    }else{
        printf("\nErro ao abrir arquivo!\n\n");
        return 0;
    }
}

int main(){

    if(escreverArquivoTexto() == 1)
        printf("\nRegistrado com sucesso!\n\n");
    else
        printf("\nErro ao registrar!\n\n");

    lerArquivoTexto();

    return 0;
}