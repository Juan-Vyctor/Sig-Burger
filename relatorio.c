#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "util.h"
#include "funcionario.h"
#include "cardapio.h"
#include "relatorio.h"
#include "enderecos.h"
#define True 1
#define False 0



void menu_relatorio(){
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Menu Clientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. listar todos os clientes                                           ///\n");
    printf("///   2. listar todos os funcionarios                                       ///\n");
    printf("///   3. listar todos os produtos do cardapio                               ///\n");
    printf("///   4. listar todos os  endereços                                         ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("escolha uma opção: ");

}



void listar_todos_clientes(){
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

    arq_cliente = fopen("arq_cliente.dat", "rb");
    if (arq_cliente == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        getchar();
        return;
    }

    printf("\nLista de Clientes Cadastrados:\n");
    printf("-------------------------------\n");

    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {

            printf("Nome: %s\n", cli->nome);
            printf("CPF: %s\n", cli->cpf);
            printf("Telefone: %s\n", cli->numero);
            printf("-------------------------------\n");
        }


    fclose(arq_cliente);
    free(cli);
    getchar();
}



void listar_todos_funcionarios(){
    FILE *arq_funcionario;
    Funcionario* func;
    func = (Funcionario*)malloc(sizeof(Funcionario));

    arq_funcionario = fopen("arq_funcionario.dat", "rb");
    if (arq_funcionario == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        getchar();
        return;
    }

    printf("\nLista de Funcionarios Cadastrados:\n");
    printf("-------------------------------\n");

    while (fread(func, sizeof(Funcionario), 1, arq_funcionario)) {

            printf("Nome: %s\n", func->nome);
            printf("CPF: %s\n", func->cpf);
            printf("Telefone: %s\n", func->numero);
            printf("-------------------------------\n");
        }

    fclose(arq_funcionario);
    free(func);
    getchar();
}



void listar_todos_produtos(){
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));
    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        return;
    }
    printf("\nLista de Produtos Cadastrados:\n");
    printf("-------------------------------\n");
    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
            printf("Nome: %s\n", prod->nome);
            printf("Preço: R$ %s\n", prod->preco);
            printf("Ingredientes: %s\n", prod->ingredientes);
            printf("-------------------------------\n");

    }
    fclose(arq_cardapio);
    free(prod);
    getchar();
}



void relatorio(){
    int opcao_relatorio;
    do{
        menu_relatorio();
        scanf("%d", &opcao_relatorio);
        getchar();
        switch (opcao_relatorio){
            case 1:
                listar_todos_clientes();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }while(opcao_relatorio !=0);
}



