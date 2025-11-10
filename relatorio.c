#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "util.h"
#include "funcionario.h"



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
    printf("escolha uma opção: \n");

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

    printf("Lista de Clientes Cadastrados:\n");
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



