#include <stdio.h>
#include <stdlib.h>
#include "./include/enderecos.h"

void modulo_enderecos(void){
    int operacao_principal;
    do{
        operacao_principal = tela_menu_enderecos();
        
        if (operacao_principal == 1)
        {
            tela_cadastrar_endereco();
        }
        else if (operacao_principal == 2)
        {
            tela_visualizar_endereco();
        } 
       else if (operacao_principal == 3)
        {
            tela_atualizar_endereco();
        }
        else if (operacao_principal == 4)
        {
            tela_deletar_endereco();
        }
        else if (operacao_principal == 5)
        {
            tela_listar_endereco();
        }

    } while (operacao_principal != 0);
}

int tela_menu_enderecos(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Menu endereços                               ///\n");
    printf("///                         (em desenvolvimento)                            ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar endereços                                                ///\n");
    printf("///   2. Visualizar endereços                                               ///\n");
    printf("///   3. Atualizar endereços                                                ///\n");
    printf("///   4. Deletar endereços                                                  ///\n");
    printf("///   5. Listar endereços                                                   ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}
void tela_cadastrar_endereco(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Cadastrar Endereço                             ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void tela_visualizar_endereco(void)
{
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///   Endereço salvo no momento:                                             ///\n");
    printf("///       Rua das Flores, 123                                                ///\n");
    printf("///       Bairro: Centro                                                     ///\n");
    printf("///       Cidade: São Paulo - SP                                             ///\n");
    printf("///       Complemento: Apto 45, Bloco B                                      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void tela_atualizar_endereco(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Atualizar Endereço                              ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void tela_deletar_endereco(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Deletar Endereço                               ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void tela_listar_endereco(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           listar Endereço                                ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}




