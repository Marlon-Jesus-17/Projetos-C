//Cadastrar pessoas

#include<stdio.h>
#include<string.h>

typedef struct Clientes{
    char nome[50], email[50], cpf[12];
    int idade;
}CT;

int cadastrarCliente(CT *clientes, int *numClientes){

    printf("Nome: ");
    fgets(clientes[*numClientes].nome, sizeof(clientes[*numClientes].nome), stdin);
    clientes[*numClientes].nome[strcspn(clientes[*numClientes].nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &clientes[*numClientes].idade);
    getchar();

    printf("CPF: ");
    fgets(clientes[*numClientes].cpf, sizeof(clientes[*numClientes].cpf), stdin);
    clientes[*numClientes].cpf[strcspn(clientes[*numClientes].cpf, "\n")] = '\0';
    getchar();

    printf("e-mail: ");
    fgets(clientes[*numClientes].email, sizeof(clientes[*numClientes].email), stdin);
    clientes[*numClientes].email[strcspn(clientes[*numClientes].email, "\n")] = '\0';

    (*numClientes)++;

    return 1;
}

void imprimirClientesCadastrados(CT *clientes, int numClientes){

    printf("\n\n\t\tClientes cadastrados:\n\n");

    for(int aux = 0; aux < numClientes; aux++){
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("\t%d° Cliente:\n\n", aux + 1);
        printf("\tNome: %s\n", clientes[aux].nome);
        printf("\tIdade: %d\n", clientes[aux].idade);
        printf("\tCPF: %s\n", clientes[aux].cpf);
        printf("\te-mail: %s\n", clientes[aux].email);
    }
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n");
}

int editarCliente(CT *clientes, int numClientes){
    char cpfAux[12];

    printf("Digite o CPF do cliente que deseja editar: ");
    fgets(cpfAux, sizeof(cpfAux), stdin);
    cpfAux[strcspn(cpfAux, "\n")] = '\0';
    getchar();

    for(int aux = 0; aux < numClientes; aux++){
        if(strcmp(clientes[aux].cpf, cpfAux) == 0){
            printf("\nCliente encontrado!\n\n");
            printf("\t%d° Cliente:\n\n", aux + 1);
            printf("\tNome: %s\n", clientes[aux].nome);
            printf("\tIdade: %d\n", clientes[aux].idade);
            printf("\tCPF: %s\n", clientes[aux].cpf);
            printf("\te-mail: %s\n\n", clientes[aux].email);

            printf("Nome: ");
            fgets(clientes[aux].nome, sizeof(clientes[aux].nome), stdin);
            clientes[aux].nome[strcspn(clientes[aux].nome, "\n")] = '\0';

            printf("Idade: ");
            scanf("%d", &clientes[aux].idade);
            getchar();

            printf("CPF: ");
            fgets(clientes[aux].cpf, sizeof(clientes[aux].cpf), stdin);
            clientes[aux].cpf[strcspn(clientes[aux].cpf, "\n")] = '\0';
            getchar();

            printf("e-mail: ");
            fgets(clientes[aux].email, sizeof(clientes[aux].email), stdin);
            clientes[aux].email[strcspn(clientes[aux].email, "\n")] = '\0';
        }
    }
    return 1;
}

int removerCliente(CT *clientes, int *numClientes){
    char cpfAux[12];

    printf("Digite o CPF do cliente que deseja remover: ");
    fgets(cpfAux, sizeof(cpfAux), stdin);
    cpfAux[strcspn(cpfAux, "\n")] = '\0';

    for(int aux = 0; aux < *numClientes; aux++){
        if(strcmp(clientes[aux].cpf, cpfAux) == 0){

            printf("\nCliente encontrado!\n\n");
            printf("\t%d° Cliente:\n\n", aux + 1);
            printf("\tNome: %s\n", clientes[aux].nome);
            printf("\tIdade: %d\n", clientes[aux].idade);
            printf("\tCPF: %s\n", clientes[aux].cpf);
            printf("\te-mail: %s\n\n", clientes[aux].email);

            for(int j = aux; j < *numClientes - 1; j++){
                clientes[j] = clientes[j + 1];
            }
        }
    }

    (*numClientes)--;

    printf("\n\nCliente Removido...\n\n");
    return 1;
}

int main(){

    CT clientes[100];
    int numClientes = 0, op;
    
    do{
        printf("\n0 - Sair\n1 - Cadastrar cliente\n2 - Editar cliente\n3 - Remover cliente\n4 - Imprimir clientes cadastrados\n\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
                printf("\n\nSaindo...\n\n");
                break;
            case 1:
                cadastrarCliente(clientes, &numClientes);
                break;
            case 2:
                editarCliente(clientes, numClientes);
                break;
            case 3:
                removerCliente(clientes, &numClientes);
                break;
            case 4:
                imprimirClientesCadastrados(clientes, numClientes);
                break;
            default:
                printf("\n\nOpção inválida...\n\n");
        }

    }while(op != 0);

    return 0;
}