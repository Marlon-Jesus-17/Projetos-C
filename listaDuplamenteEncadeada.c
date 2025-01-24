#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int N;
    struct no *prox, *ant;
}Tlista;

void inserirFinal(Tlista **lista, int chave){
    Tlista *novo = malloc(sizeof(Tlista));

    if(novo){

        novo->prox = NULL;
        novo->ant = NULL;
        novo->N = chave;

        if(!*lista){
            *lista = novo;
        }else{
            Tlista *aux = *lista;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->ant = aux;
        }

    }else{
        printf("Erro ao alocar memoria...");
    }
}

void inserirInicio(Tlista **lista, int chave){
    Tlista *novo = malloc(sizeof(Tlista));

    if(novo){
        novo->N = chave;
        novo->prox = NULL;
        novo->ant = NULL;

        if(!*lista){
            *lista = novo; 
        }else{
            novo->prox = *lista;
            (*lista)->ant = novo;
            *lista = novo;
        }
    }else
        printf("Erro ao alocar memória...");
}

Tlista* remover(Tlista *lista){

    if(!lista){
        printf("Lista vazia...");
        return NULL;
    }
    
    Tlista *aux = lista;

    if(!aux->prox){
        free(aux);
        lista = NULL;
        free(aux);
        return lista;
    }

    while(aux->prox){
        aux = aux->prox;
    }
    aux->ant->prox = NULL;
    free(aux);
    return lista;
}

void imprimir(Tlista *lista){
    Tlista *aux = lista;
    printf("Lista duplamente encadeada:\n");
    while(aux){
        printf("%d ", aux->N);
        aux = aux->prox;
    }
    printf("\n\n");
}

int main(){

    Tlista *lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 12);
    inserirInicio(&lista, 11);
    imprimir(lista);
    remover(lista);
    imprimir(lista);
    return 0;
}