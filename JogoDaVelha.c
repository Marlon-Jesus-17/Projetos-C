//Jogo da velha

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define L 3
#define C 3
 
void criarJogo(char jogo[L][C], char *op);
void imprimirJogo(char jogo[L][C]);
void jogar(char jogo[L][C]);
int vitoria(char jogo[L][C]);

int main(){

    char jogo[L][C], op;

    do{
        printf("\nDeseja jogar(S/N)?: ");
        op = fgetc(stdin);
        getchar();
        op = toupper(op);
    }while(op != 'S' && op != 'N');
    
    if(op == 'N'){
        printf("\n\nEncerrando...\n\n");
        return 3;
    }else
        criarJogo(jogo, &op);
        jogar(jogo);

    return 0;
}

int vitoria(char jogo[L][C]){
    
    for(int i = 0; i < L; i++){
        if(jogo[i][0] == 'O' && jogo[i][1] == 'O' && jogo[i][2] == 'O')
            return 1;
        if(jogo[0][i] == 'O' && jogo[1][i] == 'O' && jogo[2][i] == 'O')
            return 1;
        if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O')
            return 1;
        if(jogo[2][0] == 'O' && jogo[1][1] == 'O' && jogo[0][2] == 'O')
        return 1;

        if(jogo[i][0] == 'X' && jogo[i][1] == 'X' && jogo[i][2] == 'X')
            return 2;
        if(jogo[0][i] == 'X' && jogo[1][i] == 'X' && jogo[2][i] == 'X')
            return 2;
        if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X')
            return 2;
        if(jogo[2][0] == 'X' && jogo[1][1] == 'X' && jogo[0][2] == 'X')
        return 2;
    }
}

void jogar(char jogo[L][C]){
    
    int jogadas = 0, jogador = 1;
    int linha, coluna;

    do{
        printf("\nJogador %d. Escolha as coordenadas de onde deseja jogar: ", jogador);
        scanf("%d %d", &linha, &coluna);
        getchar();
        if(jogador == 1){
            jogo[linha][coluna] = 'O';
            jogador = 2;
        }else{
            jogo[linha][coluna] = 'X';
            jogador = 1;
        }
        imprimirJogo(jogo);
        if(vitoria(jogo) == 1){
            printf("\n\nO jogador %d é o vencedor!\n\n", jogador - 1);
            return;
        }
        if(vitoria(jogo) == 2){
            printf("\n\nO jogador %d é o vencedor!\n\n", jogador + 1);
            return;
        }
        jogadas++;
    }while(jogadas < 9);
    
    if(jogadas == 9){
        printf("\n\nO jogo deu velha\n\n");
        return;
    }
}

void criarJogo(char jogo[L][C], char *op){
    if(*op == 'S'){
        for(int i = 0; i < L; i++){
            for(int j = 0; j < C; j++){
                jogo[i][j] = ' ';
            }
        }
    }
    imprimirJogo(jogo);
}

void imprimirJogo(char jogo[L][C]){

    printf("\n\n  Jogo da velha:\n\n");

    printf("\n     0     1     2\n\n");
    for(int i = 0; i < L; i++){
        if(i > 0 && i < L)
            printf("   -----------------\n");
        printf("%d  ", i);
        for(int j = 0; j < C; j++){
            printf("  %c ", jogo[i][j]);
            if(j < C - 1)
                printf(" |");
        }
        printf("\n");
    }
    printf("\n\n");
}