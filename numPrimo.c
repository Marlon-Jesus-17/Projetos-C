#include<stdio.h>
#include<stdlib.h>

/*
        Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou não primo.
*/

int main(){

    int valor, resto, i;

    do{
        printf("\nEntre com um valor maior que 1: ");
        scanf("%d", &valor);
    }while(valor <= 1);

    if(valor == 2){
        printf("\nO valor %d é um número primo\n\n", valor);
        exit(0);
    }

    for(i = 2; i < valor; i++){
        resto = valor % i;
        if(resto == 0){
            printf("\nO valor %d não é um número primo\n\n", valor);
            break;
        }
        else
            printf("\nO valor %d é um número primo\n\n", valor);
            break;
   }

    return 0;
}