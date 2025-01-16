//Anotações

#include<stdio.h>
#include<string.h>
#define N 100

typedef struct anotacoes{
    char titulo[100];
    char conteudo[1000];
}anotacoes;

void escreverNota(anotacoes *notas, int *quant){

        printf("\nTítulo: ");
        fgets(notas[*quant].titulo, sizeof(notas[*quant].titulo), stdin);
        printf("\nConteúdo: ");
        fgets(notas[*quant].conteudo, sizeof(notas[*quant].conteudo), stdin);

    (*quant)++;
}

void editarNota(anotacoes *notas, int quant){
    int nota;
    printf("\n\nQual nota deseja editar(Diga o número)? ");
    scanf("%d", &nota);
    getchar();

    printf("\nTítulo: ");
    fgets(notas[nota - 1].titulo, sizeof(notas[nota - 1].titulo), stdin);
    printf("\nConteúdo: ");
    fgets(notas[nota - 1].conteudo, sizeof(notas[nota - 1].conteudo), stdin);
}

void lerNota(anotacoes *notas, int quant){
    
    for(int i = 0; i < quant; i++){
        printf("\n\n%d.\t\t%s\n\n", i + 1, notas[i].titulo);
        printf("\t%s\n\n", notas[i].conteudo);
        printf("-------------------------------------------------------------------------------------------\n");
    }
}

void excluirNota(anotacoes *notas, int *quant){
    int nota;
    printf("\n\nQual nota deseja excluir(Diga o número)? ");
    scanf("%d", &nota);
    getchar();
    
    for(int i = 0; i < *quant; i++){
        if(i == nota - 1){
            for(int j = i; j < *quant - 1; j++){
                notas[j] = notas[j + 1];
            }
        }
    }
    (*quant)--;
}

int main(){
    anotacoes notas[N];
    int op, quant = 0;

    do{
        printf("\n0 - Encerrar\n1 - Inserir anotação\n2 - Editar anotação\n3 - Ler anotação\n4 - Excluir anotação\n\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
                printf("\n\nSaindo...\n\n");
                break;
            case 1:
                escreverNota(notas, &quant);
                break;
            case 2:
                editarNota(notas, quant);
                break;
            case 3:
                lerNota(notas, quant);
                break;
            case 4:
            excluirNota(notas, &quant);
                break;
            default:
                printf("\n\nOpção inválida...\n\n");
        }
    }while(op != 0);

    return 0;
}