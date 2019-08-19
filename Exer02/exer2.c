#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro{
    char modelo[20];
    long int cpf_dono;
    char marca[20];
    char cor[10];
};

struct proprietario{
    char nome[20];
    char cpf[11];
    long int cep;
};

FILE *fp;
char arquivo[] = "cadastro.txt";
int n;
proprietario *cabeca;
carro *head;

void criaStruct();
void abrirArquivo();
void fecharArquivo();
void menu();
void acessaMenu();
void exibirCarros();
void adicionarCarros();
void apagarCarros();
void liberaStruct();

int main(){
    criaStruct();
    abrirArquivo();
    acessaMenu();
return 0;
}

void criaStruct(){
    cabeca = malloc(sizeof(cadastro));
    cabeca->prox = NULL;
}

void abrirArquivo(){
    fp = fopen(arquivo, "a+");
    if(fp == NULL){
        printf("Arquivo não encontrado\n");
        exit(1);
    }
    else{
        while(!feof){
            cadastro *novo;
            novo = malloc(sizeof(cadastro));
            if(novo == NULL){
                printf("Erro ao alocar memoria(1)!\n");
                exit(-1);
            }
            fscanf(fp, "%s", novo->nome);
            fscanf(fp, "%ld", novo->cpf);
            fscanf(fp, "%s", novo->carro);
            fscanf(fp, "%d", novo->ano);
            fscanf(fp, "%s", novo->placa);
            novo->prox = cabeca->prox;
            cabeca->prox = novo;
        }
    }
}

void fecharArquivo(){
    fclose(fp);
}

void menu(){
    printf("=======================================================\n");
    printf(">>>>>>>>>>>>>>>>>>> EXERCÍCIO 01 <<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=======================================================\n");
    printf("\t Por favor selecione a opção desejada:\n");
    printf(" (1) Exibir Carros cadastrados\n");
    printf(" (2) Adicionar Carros no cadastro\n");
    // printf(" (3) Apagar Carro\n");
    printf(" (3) Sair\n");
    printf("=======================================================\n");
    printf("Digite a opção:");
}

void acessaMenu(){
    char opcao = '0';
    menu();
    while(opcao != '3'){
        scanf(" %c", &opcao);
        switch(opcao){
            case '1':
                exibirCarros();
                menu();
                break;
            case '2':
                adicionarCarros();
                menu();
                break;
            // case '3':
            //     apagarCarros();
            //     menu();
            //     break;
            case '3':
                system("clear");
                fecharArquivo();
                liberaStruct();
                break;
            default:
                printf("\nEntrada Inválida, digite novamente: ");
        }
    }
}

void exibirCarros(){
    cadastro *aux;
    aux = cabeca;
    for(aux; aux->prox != NULL; aux = aux->prox){
        printf("to no for\n");
        printf("Proprietário: %s\n", aux->nome);
        printf("CPF: %ld\n", aux->cpf);
        printf("Carro: %s\n", aux->carro);
        printf("Ano: %d\n", aux->ano);
        printf("Placa: %s\n", aux->placa);
        printf("==============================\n");
    }
}

void adicionarCarros(){
    cadastro *novocarro;
    novocarro = malloc(sizeof(cadastro));
    if(novocarro == NULL){
        printf("Erro ao alocar memoria(2)!\n");
        exit(-1);
    }
    printf("Digite o nome do propritário dono do veículo:\n");
    scanf("%s", novocarro->nome);
    printf("Digite o CPF do proprietário:\n");
    scanf("%ld", &novocarro->cpf);
    printf("Digite o modelo do carro:\n");
    scanf("%s", novocarro->carro);
    printf("Qual o ano do carro:\n");
    scanf("%d", &novocarro->ano);
    printf("Placa do veículo:\n");
    scanf("%s", novocarro->placa);

    fprintf(fp, "%s\n", novocarro->nome);
    fprintf(fp, "%ld\n", novocarro->cpf);
    fprintf(fp, "%s\n", novocarro->carro);
    fprintf(fp, "%d\n", novocarro->ano);
    fprintf(fp, "%s\n", novocarro->placa);

    printf("Cadastro Concluído!!\n");
}

void liberaStruct(){
    cadastro *aux2, *prox1;
    prox1 = cabeca;
    while(prox1 != NULL){
        aux2 = prox1;
        prox1 = prox1->prox;
        free(aux2);
    }
}