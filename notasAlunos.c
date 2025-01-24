#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
        Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas acima da média da turma. Considerar que a turma tenha 50 alunos.
*/

#define N 50

typedef struct Aluno{
        char nome[30];
        float nota;
}Al;

int cadastrarAluno(Al *aluno, int *quant, float *soma){

        if(*quant == 50){
                printf("\nTodos os alunos já foram adicionados\n\n");
                return 0;
        }

        printf("\nEntre com o nome do aluno: ");
        fgets(aluno[*quant].nome, sizeof(aluno[*quant].nome), stdin);
        aluno[*quant].nome[strcspn(aluno[*quant].nome, "\n")] = '\0';

        printf("\nEntre com a nota do aluno: ");
        scanf("%f", &aluno[*quant].nota);
        getchar();

        *soma += aluno[*quant].nota;
        (*quant)++;

        return 0;

}

void mediaDaTurma(float *media, int quant, float soma){
        
        *media = soma / quant;
        printf("\nMédia atual da turma: %.2f\n", *media);
        return;
}

void MaioresNotasMaioresQueAMedia(Al *aluno, int quant, float media) {
        Al maioresNotas[N];
        int contador = 0;

        for (int i = 0; i < quant; i++) {
                if (aluno[i].nota > media) {
                        maioresNotas[contador] = aluno[i];
                        contador++;
                }
        }

        for (int i = 0; i < contador - 1; i++) {
                for (int j = 0; j < contador - i - 1; j++) {
                        if (maioresNotas[j].nota < maioresNotas[j + 1].nota) {
                                Al temp = maioresNotas[j];
                                maioresNotas[j] = maioresNotas[j + 1];
                                maioresNotas[j + 1] = temp;
                        }
                }
        }

        printf("\nAs cinco maiores notas acima da média são:\n");
        for (int i = 0; i < 5 && i < contador; i++) {
                printf("Nome: %s\nNota: %.2f\n", maioresNotas[i].nome, maioresNotas[i].nota);
        }

        if (contador == 0) {
                printf("Nenhum aluno possui nota acima da média.\n");
        }

        printf("\n");
}

void imprimir(Al *aluno, int quant){
        printf("\nLista de alunos:\n\n");
        for(int i = 0; i < quant; i++){
                printf("Nome: %s\nNota: %.2f\n", aluno[i].nome, aluno[i].nota);
        }
        printf("\n\n");
}

int main(){

        Al aluno[N];
        int quant = 0, op;
        float soma = 0.0, media = 0.0;

        do{
                printf("\n0 - Sair\n1 - Cadastrar nota do aluno\n2 - Imprimir\n3 - Maiores notas acima da média\n");
                scanf("%d", &op);
                getchar();

                switch (op){
                case 0:
                        printf("\nSaindo...\n\n");
                        break;
                case 1:
                        cadastrarAluno(aluno, &quant, &soma);
                        mediaDaTurma(&media, quant, soma);
                        break;
                case 2:
                        imprimir(aluno, quant);
                        break;
                case 3:
                        MaioresNotasMaioresQueAMedia(aluno, quant, media);
                        break;
                default:
                        printf("\nOpção inválida!\n\n");
                }

        }while(op != 0);
}