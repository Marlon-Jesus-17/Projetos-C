/* Calculadora Simples com as 4 operações fundamentais */

#include<stdio.h>
#include<ctype.h>

float soma(float *a, float *b){
    return *a + *b;
}

float subtracao(float *a, float *b){
    return *a - *b;
}

float multiplicacao(float *a, float *b){
    return *a * *b;
}

float divisao(float *a, float *b){
    return *a / *b;
}

int main(){
    
    float x, y;
    int op;
    char SN;

    do{
        
        printf("Calculadora Simples");
        
        do{

            printf("Deseja realizar alguma operação com dois números? (S/N)");
            SN = getc(stdin);
            SN = toupper(SN);

        }while(SN != 'S' && SN != 'N');
        
        if(SN == 'N'){
            printf("\n\nOk! Saindo...\n\n");
            break;
        }

        printf("Entre com dois valores: ");
        scanf("%f %f", &x, &y);
        getchar();

        printf("\n0 - sair\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
                printf("Encerrando...");
                break;
            case 1:
                printf("Resultado: %.2f\n\n", soma(&x, &y));
                break;
            case 2:
                printf("Resultado: %.2f\n\n", subtracao(&x, &y));
                break;
            case 3:
                printf("Resultado: %.2f\n\n", multiplicacao(&x, &y));
                break;
            case 4:
                printf("Resultado: %.2f\n\n", divisao(&x, &y));
                break;
            default:
                printf("Opção inválida...");
        }

    }while(op != 0);

    return 0;
}