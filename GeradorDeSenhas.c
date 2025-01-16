// Gerador de senhas

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


void SenhaAleatoria(int tamanho){
    const char maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    const char minusculas[] = "abcdefghijklmnopqrstuvxyz";
    const char numeros[] = "0123456789";
    const char Especiais[] = "!@#$%^&*()";
    char permitidos[100] = "";

    strcat(permitidos, maiusculas);
    strcat(permitidos, minusculas);
    strcat(permitidos, numeros);
    strcat(permitidos, Especiais);

    unsigned int seed = (unsigned int) time(NULL);

        printf("\nSenha gerada: ");
        for(size_t i = 0; i < tamanho; i++){
            size_t index = rand_r(&seed) % strlen(permitidos);
            printf("%c", permitidos[index]);
        }
        printf("\n\n");
}

int main(){

    char op;
    unsigned int tam;

        printf("\nGerador de senhas aleatórias.\n\n");
        printf("\nEspecificações da criação de senha:\n\n");
        printf("1. Pode ter caracteres especial;\n2. Pode ter letras maiúsculas;\n3. Pode ter números;\n4. Pode ter letras minúsculas.\n");

    do{

        printf("\nBem vindo ao gerador de senhas! Deseja gerar uma senha aleatória de 8 digitos?(S/N) ");
        op = fgetc(stdin);
        getchar();
        op = toupper(op);

    }while(op != 'S' && op != 'N');

    if(op == 'N'){
        printf("\n\nEncerrando...\n\n");
        return 1;
    }else
        printf("\nDiga o tamanho da senha que deseja: ");
        scanf("%d", &tam);
        getchar();
        SenhaAleatoria(tam);

    return 0;
}