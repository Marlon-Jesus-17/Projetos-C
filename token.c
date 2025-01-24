#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char nome[50] = "Marlon dos santos santana de jesus";
    char *pt;
    int cont = 0;

    printf("\n");
    pt = strtok(nome, " \n");
    while(pt){
        printf("token: %s\n", pt);
        pt = strtok(NULL, " \n");
        cont++;
    }
    printf("\n");
    printf("Quantidade de palavras: %d\n\n", cont);

    return 0;
}