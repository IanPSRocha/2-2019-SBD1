#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro{
    char nome[500];
    int cpf;
    int ano;
    char carro[500];
    char placa[8];
    struct cadastro *prox;
}cadastro;

FILE *fp;
char arquivo[] = "cadastro.txt";
int n;
int limite;
cadastro *pessoa;

void criaStruct();
void abrirArquivo();
void fecharArquivo();
void menu();
void acessaMenu();
void exibirCarros();
void adicionarCarros();
void apagarCarros();

int main(){
    criaStruct();
    abrirArquivo();
    menu();
return 0;
}

void criaStruct(){
    pessoa = malloc(sizeof(cadastro));
    pessoa->prox = NULL;
}

void abrirArquivo(){
    fp = fopen(arquivo, "a+");
    if(fp == NULL){
        printf("Arquivo não encontrado\n");
        exit(1);
    }
    else{
        while(!feof){
            fscanf(fp, "%s", pessoa->nome);
            fscanf(fp, "%d", pessoa->cpf);
            fscanf(fp, "%d", pessoa->ano);
            fscanf(fp, "%s", pessoa->carro);
            fscanf(fp, "%s", pessoa->placa);


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
    printf(" (2) Adicionar Carros cadastrados\n");
    printf(" (3) Apagar Carro\n");
    printf(" (4) Sair\n");
    printf("=======================================================\n");
    printf("Digite a opção:");
}

void acessaMenu(){
    char opcao = '0';
    menu();
    while(opcao != '4'){
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
            case '3':
                apagarCarros();
                menu();
                break;
            case '4':
                system("clear");
                fecharArquivo();
                break;
            default:
                printf("\nEntrada Inválida, digite novamente: ");
        }
    }
}

void exibirCarros(){}

void adicionarCarros(){}

void apagarCarros(){}