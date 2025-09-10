#include <stdio.h>
#include <stdlib.h>
#include "./include/funcionario.h"

void modulo_funcionario(void)
{
    int operacao_principal = tela_menu_funcionario();
    if (operacao_principal == 1)
    {
        tela_cadastrar_funcionario();
    }
    
    else if (operacao_principal == 2)
    {
        tela_listar_funcionarios();
    }
    
    else if (operacao_principal == 3)
    {
        tela_visualizar_funcionario();
    }
}

int tela_menu_funcionario(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Menu Funcionários                              ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Funcionário                                              ///\n");
    printf("///   2. Listar Funcionários                                                ///\n");
    printf("///   3. Visualizar Funcionário                                             ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_cadastrar_funcionario(void)
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Cadastrar Funcionários                           ///\n");
    printf("///                                                                         ///\n");
    printf("///   Para cadastrar o funcionário, informe:                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   - Nome completo:                                                      ///\n");
    printf("///   - Telefone:                                                           ///\n");
    printf("///   - CPF:                                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   - Cargo:                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

void tela_listar_funcionarios(void)
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Lista dos Funcionários                            ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Maria das Graças                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///    Digite o número do funcionário que deseja visualizar:                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_visualizar_funcionario(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                       Dados do Funcionário                               ///\n");
    printf("///                                                                          ///\n");
    printf("///   Nome completo:   Maria das Graças                                      ///\n");
    printf("///   Telefone:        (11) 11111-1111                                       ///\n");
    printf("///   CPF:             111.111.111-11                                        ///\n");
    printf("///                                                                          ///\n");
    printf("///   Cargo: Atendente                                                       ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}