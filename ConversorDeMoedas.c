//Conversor de Moedas

#include<stdio.h>

float realParaDolar(float *valor){
    float taxaCambio = 6.1557; // Taxa de câmbio do real para o dólar
    return *valor / taxaCambio;
}

float realParaEuro(float *valor){
    float taxaCambio = 6.333; // Taxa de câmbio do real para o euro
    return *valor / taxaCambio;
}

float dolarParaReal(float *valor){
    float taxaCambio = 0.1624; // Taxa de câmbio do dólar para o real
    return *valor / taxaCambio;
}

float euroParaReal(float *valor){
    float taxaCambio = 0.1579; // Taxa de câmbio do euro para o real
    return *valor / taxaCambio;
}

int main(){

    float valor;
    int op;

    do{
        printf("\n0 - Sair\n1 - Converter de Real para Dólar\n2 - Converter de Real para Euro\n3 - Converter de Dólar para Real\n4 - Converter de Euro para Real\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
                printf("\nSaindo...\n\n");
                break;
            case 1:
                printf("\nDigite o valor em real que deseja converter: ");
                scanf("%f", &valor);
                getchar();
                printf("\n%.2f dolares\n\n", realParaDolar(&valor));
                break;
            case 2:
                printf("\nDigite o valor em real que deseja converter: ");
                scanf("%f", &valor);
                getchar();
                printf("\n%.2f euros\n\n", realParaEuro(&valor));
                break;
            case 3:
                printf("\nDigite o valor em dólar que deseja converter: ");
                scanf("%f", &valor);
                getchar();
                printf("\n%.2f reais\n\n", dolarParaReal(&valor));
                break;
            case 4:
                printf("\nDigite o valor em euro que deseja converter: ");
                scanf("%f", &valor);
                getchar();
                printf("\n%2.f reais\n\n", euroParaReal(&valor));
                break;
            default:
                printf("\nOpção inválida...\n\n");

        }

    }while(op != 0);

    return 0;
}