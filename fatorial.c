#include<stdio.h>
#include<stdlib.h>

/*
        Escreva um programa em C que calcule o fatorial de um número inteiro positivo.
*/

int main(){

    int valor, fatorial = 1;

    printf("\nEntre com um valor: ");
    scanf("%d", &valor);

    for(int i = 1; i <= valor; i++){
        fatorial *= i; 
    }

    printf("\nO fatorial de %d é: %d\n\n", valor, fatorial);

    return 0;
}