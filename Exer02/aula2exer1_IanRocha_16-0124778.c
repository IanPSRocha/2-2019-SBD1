#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro{
    char modelo[110];
    char cpf_dono[100];
    char marca[90];
    char cor[80];
}carro;

typedef struct proprietario{
    char nome[70];
    char cpf[100];
    char cep[50];
}proprietario;

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
void exibirCadastros();
void adicionarCadastros();
void apagarCarros();
void liberaStruct();

int main(){
    criaStruct();
    abrirArquivo();
    acessaMenu();
return 0;
}

void criaStruct(){
    cabeca = malloc(sizeof(proprietario));
}

void abrirArquivo(){
    fp = fopen(arquivo, "a+");
    if(fp == NULL){
        printf("Arquivo não encontrado\n");
        exit(1);
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
    printf(" (1) Exibir Lista de Cadastros\n");
    printf(" (2) Adicionar novo Cadastro\n");
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
                exibirCadastros();
                menu();
                break;
            case '2':
                adicionarCadastros();
                menu();
                break;
            case '3':
                system("clear");
                fecharArquivo();
                break;
            default:
                printf("\nEntrada Inválida, digite novamente: ");
        }
    }
}

void exibirCadastros(){
    char aux[500];
    fscanf(fp, "%s", aux);
    while(!feof(fp)){
        printf("%s\n", aux);
        fscanf(fp, "%s", aux);  
    }
}

void adicionarCadastros(){
    proprietario *novop;
    int aux, tam;
    novop = malloc(sizeof(proprietario));
    if(novop == NULL){
        printf("Erro ao alocar memoria(2)!\n");
        exit(-1);
    }
    printf("Digite o nome do propritário dono do veículo:\n");
    scanf("%s", novop->nome);
    printf("Digite o CPF do proprietário:\n");
    scanf("%s", novop->cpf);
    printf("Digite o CEP do proprietário:\n");
    scanf("%s", novop->cep);

    fprintf(fp, "Nome: %s\n", novop->nome);
    fprintf(fp, "CPF: %s\n", novop->cpf);
    fprintf(fp, "CEP: %s\n", novop->cep);

    tam = strlen(novop->cpf);
    
    printf("Quantos carros a pessoa citada possui?\n");
    scanf("%d", &aux);

    for(int i = 0; i < aux; i++){
        carro *novoc;
        novoc = malloc(sizeof(carro));
        if(novoc == NULL){
            printf("Erro ao alocar memoria(3)!\n");
            exit(-1);
        }
        printf("Qual o modelo do carro %d?\n", i+1);
        scanf("%s", novoc->modelo);
        printf("Qual a marca do carro %d?\n", i+1);
        scanf("%s", novoc->marca);
        printf("Qual a cor do carro %d?\n", i+1);
        printf("%s", novoc->cor);

        for(int j = 0; j < tam; j++){
            novoc->cpf_dono[j] = novop->cpf[j];
        }

        fprintf(fp, "Modelo: %s\n", novoc->modelo);
        fprintf(fp, "CPF_do_Proprietario: %s\n", novoc->cpf_dono);
        fprintf(fp, "Marca: %s\n", novoc->marca);
        fprintf(fp, "Cor: %s\n", novoc->cor);
    }

    printf("Cadastro Concluído!!\n");
}