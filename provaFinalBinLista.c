#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
}Pessoa;

typedef struct no{
    Pessoa dados;
    struct no *proximo;
}no;

void inserirFinal(no **lista, Pessoa p){

    no *novo = malloc(sizeof(no));

    if(novo){
        
        novo->dados = p;
        novo->proximo = NULL;

        if(*lista == NULL){ //Se a lista tá vazia
            *lista = novo;
        }else{

            no *aux = *lista;

            while(aux->proximo != NULL){    
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }

        return;

    }else{
        printf("\nErro ao alocar memória!\n\n");
        return;
    }
}

void lerArquivoBinario(no **lista){

    FILE *arquivo = fopen("prova.bin", "rb");

    if(arquivo){

        Pessoa p;

        while(fread(p.nome, sizeof(p.nome), 1, arquivo) == 1 && fread(&p.idade, sizeof(p.idade), 1, arquivo) == 1){
            inserirFinal(lista, p);
        }

        fclose(arquivo);
    }else{
        printf("\nErro ao abrir arquivo!\n\n");
        return;
    }

}

void imprimir(no *lista){
    
    no *aux = lista;

    while(aux != NULL){
        printf("\nNome: %s\nIdade: %d\n", aux->dados.nome, aux->dados.idade);
        aux = aux->proximo;
    }
}

int main(){

    no *lista = NULL;

    lerArquivoBinario(&lista);

    imprimir(lista);

    return 0;
}
